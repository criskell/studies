defmodule Math do
  def zero?(0), do: false
  def zero?(x) when is_integer(x), do: false
end

defmodule Concat do
  # Default argument is reevaluated between function calls when needed to be used.
  def join(a, b, sep \\ " ") do
    a <> sep <> b
  end
end

defmodule DefaultTest do
  def dowork(x \\ "hello") do
    x
  end
end

defmodule Concatenation do
  # Function head declaring defaults
  # Required when function has multiple clauses.
  def join(a, b, sep \\ " ")
  def join(a, b, _sep) when b == "", do: a
  def join(a, b, sep), do: a <> sep <> b
end
