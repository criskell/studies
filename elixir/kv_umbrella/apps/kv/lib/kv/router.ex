defmodule KV.Router do
  @doc """
  vou mandar o modulo, função e args para um nó apropriado
  de acordo com o roteamento feito pelo nome do bucket.
  """
  def route(bucket, mod, fun, args) do
    # pego o primeiro caractere (na vdd o primeiro byte do binary)
    first = :binary.first(bucket)

    entry = Enum.find(table(), fn {enum, _node} -> first in enum end) || no_entry_error(bucket)

    if elem(entry, 1) == node() do
      # nn precisamos ir pra outra máquina
      apply(mod, fun, args)
    else
      # elem(entry, 1) é o nó
      # mandamos pro primeiro argumento de .async usando o pipe operator
      {KV.RouterTasks, elem(entry, 1)}
      |> Task.Supervisor.async(KV.Router, :route, [bucket, mod, fun, args])
      # espero o resultado dessa computação
      |> Task.await()
    end
  end

  defp no_entry_error(bucket) do
    raise "could not find entry for #{inspect(bucket)} in table #{inspect(table())}"
  end

  # a tabela de roteamento que vai definir para quais nodes vamos enviar as requests de acordo com o bucket
  # lembrando que se o bucket for roteado para o nó atual, não precisamos enviar uma request para um nó remoto
  def table do
    # criskell é o hostname de minha máquina
    Application.fetch_env!(:kv, :routing_table)
  end
end
