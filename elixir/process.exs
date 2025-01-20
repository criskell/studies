parent = self()

spawn(fn -> send(parent, {:hello, self()}) end)

receive do
  {:hello, pid} -> IO.puts("Got hello from #{inspect(pid)}")
end
