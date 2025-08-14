open class Animal
class Dog : Animal()

// A relação entre subtipos é preservada entre tipos genéricos.
// Producer é covariante em T.
interface Producer<out T> {
  fun produce(): T
}

fun feedAnimal(producer: Producer<Animal>) {
  val animal: Animal = producer.produce()
  
  println(animal)
}

fun main() {
  val dogProducer: Producer<Dog> = object : Producer<Dog> {
    override fun produce(): Dog = Dog()
  }

  feedAnimal(dogProducer)
}