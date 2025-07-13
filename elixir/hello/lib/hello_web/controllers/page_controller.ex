defmodule HelloWeb.PageController do
  use HelloWeb, :controller

  def home(conn, _params) do
    conn
    |> put_flash(:error, "my message")
    |> redirect(to: ~p"/redirect_test")
  end

  def redirect_test(conn, _params) do
    render(conn, :home, items: [%{name: "Item A"}, %{name: "Item B"}], layout: false)
  end
end
