defmodule Recursion do
  def print_multiple_times(string, n \\ 5)

  def print_multiple_times(string, n) when n > 0 do
    IO.puts(string)
    print_multiple_times(string, n - 1)
  end

  def print_multiple_times(_, _), do: nil
end

defmodule RecursionA do
  def print_multiple_times(string)

  def print_multiple_times(string) do
    print_multiple_times(string, 5)
  end

  defp print_multiple_times(string, n) when n > 0 do
    IO.puts(string)
    print_multiple_times(string, n - 1)
  end

  defp print_multiple_times(_, _), do: nil
end

Recursion.print_multiple_times("hello world")
Recursion.print_multiple_times("hello world", 7)
RecursionA.print_multiple_times("xuxu beleza")
