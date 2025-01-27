defmodule KVServer.Application do
  use Application

  @impl true
  def start(_type, _args) do
    port = String.to_integer(System.get_env("PORT") || "4042")

    children = [
      {Task.Supervisor, name: KVServer.TaskSupervisor},
      Supervisor.child_spec({Task, fn -> KVServer.accept(port) end}, restart: :permanent)
    ]

    opts = [strategy: :one_for_one, name: KVServer.Supervisor]
    Supervisor.start_link(children, opts)
  end
end
