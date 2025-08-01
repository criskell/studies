package com.criskell.tasks;

import org.springframework.web.bind.annotation.*;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

@RestController
@RequestMapping("/tasks")
public class TaskController {

    private final TaskRepository taskRepository;

    public TaskController(TaskRepository taskRepository) {
        this.taskRepository = taskRepository;
    }

    @GetMapping
    public Flux<Task> list() {
        return taskRepository.findAll();
    }

    @PostMapping
    public Mono<Task> create(@RequestBody Task task) {
        return taskRepository.save(task);
    }

    @PutMapping("/{id}")
    public Mono<Task> update(@PathVariable Long id, @RequestBody Task updatedTask) {
        return taskRepository.findById(id)
                .flatMap(task -> {
                    task.setTitle(updatedTask.getTitle());
                    task.setIsCompleted(updatedTask.getIsCompleted());
                    return taskRepository.save(task);
                });
    }

    @DeleteMapping("/{id}")
    public Mono<Void> delete(@PathVariable Long id) {
        return taskRepository.deleteById(id);
    }
}
