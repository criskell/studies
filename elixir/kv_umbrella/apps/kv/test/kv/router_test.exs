# elixir --sname foo@criskell -S mix test
# nn esqueça de rodar o nó bar: iex --sname bar@criskell -S mix

defmodule KV.RouterTest do
  use ExUnit.Case, async: true

  # equivalente a escrever @tag distributed: true
  @tag :distributed
  test "route requests across nodes" do
    # Kernel.node é uma função
    # [] é os argumentos
    assert KV.Router.route("hello", Kernel, :node, []) == :foo@criskell
    assert KV.Router.route("world", Kernel, :node, []) == :bar@criskell
  end

  test "raises on unknown entries" do
    assert_raise RuntimeError, ~r/could not find entry/, fn ->
      KV.Router.route(<<0>>, Kernel, :node, [])
    end
  end
end
