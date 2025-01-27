defmodule KV.Supervisor do
  use Supervisor

  def start_link(opts) do
    Supervisor.start_link(__MODULE__, :ok, opts)
  end

  @impl true
  def init(:ok) do
    children = [
      {KV.Registry, name: KV.Registry}
    ]

    # :one_for_one -> somente o processo filho vai ser reiniciado quando o mesmo vir a crashar.
    Supervisor.init(children, strategy: :one_for_one)
    # quando o processor supervisor inicia, ele chama a função child_spec em cada módulo.
    # essa função retorna uma especificação que descreve pro supervisor como iniciar o processo.
    # define se o processo filho é permanente, transitório ou temporário, se é um worker ou um supervisor.
    # definida automaticamente ao utilizar os comportamentos GenServer, Agent e Supervisor.
  end
end
