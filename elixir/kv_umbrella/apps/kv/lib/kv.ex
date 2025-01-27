defmodule KV do
  use Application

  # O comportamento `Application` permite definir "application callback".
  # Um supervisor pode ter supervisores que monitoram seus próprios filhos
  # o que nos leva a uma "supervision tree"
  @impl true
  def start(_type, _args) do
    KV.Supervisor.start_link(name: KV.Supervisor)
  end
end
