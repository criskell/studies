import kotlin.reflect.KProperty

class ObservableProperty<T>(var value: T) {
    operator fun getValue(thisRef: Any?, property: KProperty<*>): T {
    	println("reading property ${property.name}")
        return value
    }
    
    operator fun setValue(thisRef: Any?, property: KProperty<*>, newValue: T) {
        println("changing property ${property.name} from $value to $newValue")
        value = newValue
    }
}

class Person {
    var name: String by ObservableProperty()
}

fun main() {
	val p = Person()
    p.name = "eren"
    println(p.name)
}