CREATE TABLE IF NOT EXISTS "transaction" (
  id SERIAL PRIMARY KEY,
  type INT,
  date date,
  "value" decimal,
  cpf bigint,
  card varchar(255),
  "hour" time,
  store_owner varchar(255),
  store_name varchar(255)
);