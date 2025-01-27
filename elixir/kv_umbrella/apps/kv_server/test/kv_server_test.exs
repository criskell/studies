defmodule KVServerTest do
  use ExUnit.Case

  # previne exibição de warnings
  # faz com que o exunit pegue os logs
  # mostra quando o teste crasha, caso contrário nn vai mostrar
  @moduletag :capture_log

  setup do
    Application.stop(:kv)
    :ok = Application.start(:kv)
  end

  setup do
    opts = [:binary, packet: :line, active: false]
    {:ok, socket} = :gen_tcp.connect(~c"localhost", 4042, opts)
    %{socket: socket}
  end

  test "test interaction", %{socket: socket} do
    assert send_and_recv(socket, "UNKNOWN shopping eggs\r\n") ==
      "UNKNOWN COMMAND\r\n"

    assert send_and_recv(socket, "GET shopping eggs\r\n") ==
      "NOT FOUND\r\n"

    assert send_and_recv(socket, "CREATE shopping\r\n") ==
      "OK\r\n"

    assert send_and_recv(socket, "PUT shopping eggs 1\r\n") ==
      "OK\r\n"

    # É a mesma resposta.
    # 1\r\nOK\r\n.
    assert send_and_recv(socket, "GET shopping eggs\r\n") == "1\r\n"
    assert send_and_recv(socket, "") == "OK\r\n"

    assert send_and_recv(socket, "DELETE shopping eggs\r\n") ==
      "OK\r\n"

    assert send_and_recv(socket, "GET shopping eggs\r\n") == "\r\n"
    assert send_and_recv(socket, "") == "OK\r\n"
  end

  defp send_and_recv(socket, command) do
    :ok = :gen_tcp.send(socket, command)
    {:ok, data} = :gen_tcp.recv(socket, 0, 1000)
    data
  end
end
