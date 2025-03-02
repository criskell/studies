# PORT=4001 elixir --sname foo@criskell -S mix test --only distributed
# elixir --sname foo@criskell -S mix test
# nn esqueça de rodar o nó bar: iex --sname bar@criskell -S mix

defmodule KV.RouterTest do
  use ExUnit.Case

  setup_all do
    current = Application.get_env(:kv, :routing_table)

    Application.put_env(:kv, :routing_table, [{?a..?m, :foo@criskell}, {?n..?z, :bar@criskell}])

    on_exit(fn -> Application.put_env(:kv, :routing_table, current) end)
  end

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
