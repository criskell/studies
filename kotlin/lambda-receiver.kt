class HTML {
  private val children = mutableListOf<String>()

  fun body(block: BODY.() -> Unit) {
    val body = BODY()
    body.block()
    children.add(body.render())
  }

  fun render() = "<html>${children.joinToString("")}</html>"
}

class BODY {
  private val children = mutableListOf<String>()

  fun p(text: String) {
    children.add("<p>$text</p>")
  }

  fun render() = "<body>${children.joinToString()}</body>"
}

fun html(block: HTML.() -> Unit): HTML {
  val html = HTML()

  html.block()

  return html
}

fun main() {
  val page = html {
    body {
      p("Olá, mundo!")
    }
  }

  println(page.render())
}