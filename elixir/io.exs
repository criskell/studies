IO.puts("Hello, world!")

reply = IO.gets("yes or no?")

IO.puts(:stderr, "sending message to standard error device :D")

{:ok, file} = File.open("output.exs", [:write])

IO.binwrite(file, "IO.puts(\"Hello, world!\")")

File.close(file)

IO.puts(File.read!("output.exs"))

# IO functions expects chardata or iodata
# in iodata, integer represent byte.
# in chardata, integer represent unicode code point.
IO.puts(["hello", "world"])
