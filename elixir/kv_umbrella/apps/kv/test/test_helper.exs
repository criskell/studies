# executa os testes se estivermos em um nó de um sistema distribuído
exclude = if Node.alive?(), do: [], else: [distributed: true]
# o else faz os testes com a tag :distributed serem excluídos dessa execução

# podemos utilizar a linha de comando para customizar quais tags vamos incluir, excluir ou executar exclusivamente
# elixir --sname nomedomeunó -S mix test --only distributed -- somente os testes com a tag distributed.
# elixir --sname nomedonó -S mix test --exclude distributed -- todos os testes menos com a tag distributed.
# elixir --sname nomedonó -S mix test --include distributed -- todos os testes incluindo com a tag :distributed, mesmo que tenhamos adicionado essa tag na opção "exclude" do ExUnit.start/1
ExUnit.start(exclude: exclude)
