open class Animal
class Dog : Animal()

// Se A é subtipo de B, então C<B> é subtipo de C<A>.
// Consumer é contravariante em T.
// `in` somente pode ser utilizado em parâmetros.
// Imagine Dog <: Animal, posso passar um Consumer<Animal> no lugar de um Consumer<Dog>.
// Se Dog é um Animal, então deve funcionar quando passar um Consumer<Animal>
interface Consumer<in T> {
  fun consume(item: T)
}

fun feedDog(consumer: Consumer<Dog>) {
  consumer.consume(Dog())
}

fun main() {
  val animalConsumer: Consumer<Animal> = object : Consumer<Animal> {
    override fun consume(item: Animal) {
      println("Consumindo um animal")
    }
  }

  feedDog(animalConsumer)
}