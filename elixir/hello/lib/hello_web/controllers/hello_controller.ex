defmodule HelloWeb.HelloController do
  use HelloWeb, :controller

  def index(conn, _params) do
    render(conn, :index)
  end

  def show(conn, %{"messenger" => messenger} = _params) do
    # conn
    # |> assign(:messenger, messenger)
    # |> assign(:test, "oi")
    # |> render(:show)

    render(conn, :show,
      messenger: messenger,
      items: [%{name: "Item A"}, %{name: "Item B"}],
      test: "oi"
    )
  end
end
