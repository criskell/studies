defmodule KV.Bucket do
  # a responsabilidade de um supervisor não é apenas
  # reiniciar processos, mas também garantir um shutdown e startup apropriado.
  use Agent, restart: :temporary

  @doc """
  Start a new bucket.
  """
  def start_link(_opts) do
    Agent.start_link(fn -> %{} end)
  end

  @doc """
  Gets a value from the `bucket` by `key`.
  """
  def get(bucket, key) do
    Agent.get(bucket, &Map.get(&1, key))
  end

  @doc """
  Puts the `value` for the given `key` in the `bucket`.
  """
  def put(bucket, key, value) do
    Agent.update(bucket, &Map.put(&1, key, value))
  end

  @doc """
  Deletes the `key` from the `bucket`.

  end
  Returns the current value of `key`, if it exists.
  """
  def delete(bucket, key) do
    Agent.get_and_update(bucket, &Map.pop(&1, key))
  end
end
