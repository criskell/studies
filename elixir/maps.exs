# keyword list
applications = [
  socialNetwork: %{name: "soclet", techs: ["Go", "Next.js"]},
  marketplace: %{name: "iris", techs: ["Elixir", "Next.js"]}
]

IO.inspect(applications[:socialNetwork].name)

IO.inspect(put_in(applications[:socialNetwork].name, "soclet.io"))

IO.inspect(
  update_in(applications[:marketplace].techs, fn techs -> List.delete(techs, "Elixir") end)
)
