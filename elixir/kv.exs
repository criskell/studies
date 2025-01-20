defmodule KeyValueStore do
  def start_link() do
    Task.start_link(fn -> loop(%{}) end)
  end

  defp loop(map) do
    receive do
      {:get, key, caller} ->
        send(caller, Map.get(map, key))
        loop(map)

      {:put, key, value} ->
        loop(Map.put(map, key, value))
    end
  end
end

{:ok, pid} = KeyValueStore.start_link()

Process.register(pid, :kv)

send(:kv, {:put, :message, "Hello, world!"})
send(:kv, {:get, :message, self()})

receive do
  value -> IO.puts("Received from key-value store 1: #{inspect(value)}")
end

{:ok, pid} = Agent.start_link(fn -> %{} end, name: :keyvalue)

Agent.update(pid, fn map -> Map.put(map, :hello, :world) end)

IO.puts(
  "Received from key-value store 2: #{inspect(Agent.get(pid, fn map -> Map.get(map, :hello) end))}"
)
