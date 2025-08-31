package com.criskell.cbabchallenge.backend;

import java.math.BigDecimal;

import javax.sql.DataSource;

import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.ItemProcessor;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.database.JdbcBatchItemWriter;
import org.springframework.batch.item.database.builder.JdbcBatchItemWriterBuilder;
import org.springframework.batch.item.file.FlatFileItemReader;
import org.springframework.batch.item.file.builder.FlatFileItemReaderBuilder;
import org.springframework.batch.item.file.transform.Range;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.FileSystemResource;
import org.springframework.transaction.PlatformTransactionManager;

@Configuration
public class BatchConfig {

    private PlatformTransactionManager transactionManager;
    private JobRepository jobRepository;

    public BatchConfig(PlatformTransactionManager transactionManager, JobRepository jobRepository) {
        this.transactionManager = transactionManager;
        this.jobRepository = jobRepository;
    }

    @Bean
    Job job(Step step) {
        return new JobBuilder("job", jobRepository)
                .start(step)
                .incrementer(new RunIdIncrementer())
                .build();
    }

    @Bean
    Step step(ItemReader<CnabTransaction> reader, ItemProcessor<CnabTransaction, Transaction> processor, ItemWriter<Transaction> writer) {
        return new StepBuilder("step", jobRepository)
                .<CnabTransaction, Transaction>chunk(1000, transactionManager)
                .reader(reader)
                .processor(processor)
                .writer(writer)
                .build();
    }

    @Bean
    FlatFileItemReader<CnabTransaction> reader() {
        return new FlatFileItemReaderBuilder<CnabTransaction>()
                .name("reader")
                .resource(new FileSystemResource("files/cnab.txt"))
                .fixedLength()
                .columns(
                        new Range(1, 1),
                        new Range(2, 9),
                        new Range(10, 19),
                        new Range(20, 30),
                        new Range(31, 42),
                        new Range(43, 48),
                        new Range(49, 62),
                        new Range(63, 80)
                )
                .names(
                        "type",
                        "date",
                        "value",
                        "cpf",
                        "card",
                        "hour",
                        "storeOwner",
                        "storeName"
                )
                .targetType(CnabTransaction.class)
                .build();
    }

    @Bean
    ItemProcessor<CnabTransaction, Transaction> processor() {
        return item -> {
            var transaction = new Transaction(
                    null,
                    item.type(),
                    null,
                    null,
                    item.cpf(),
                    item.card(),
                    null,
                    item.storeOwner().trim(),
                    item.storeName().trim()
            ).withValue(item.value().divide(BigDecimal.valueOf(100))).withDate(item.date()).withHour(item.hour());

            return transaction;
        };
    }

    @Bean
    JdbcBatchItemWriter<Transaction> writer(DataSource dataSource) {
        return new JdbcBatchItemWriterBuilder<Transaction>()
                .dataSource(dataSource)
                .sql("""
                INSERT INTO transactions (
                    type, date, value, cpf, card,
                    hour, store_owner, store_name
                ) VALUES (
                    :type, :date, :value, :cpf, :card,
                    :hour, :storeOwner, :storeName
                )
            """)
                .beanMapped()
                .build();
    }
}
