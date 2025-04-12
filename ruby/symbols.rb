def assert(condition)
  raise "Assertion error" unless condition
end

# Símbolos são strings imutáveis e únicas.
assert :name == :name
assert :name.object_id == :name.object_id && :name.object_id != :nome.object_id
assert "name".object_id != "name".object_id && :name.object_id != "name".object_id

# Utilizações:
person1 = { name: "John Doe", age: 20 }

# O mesmo que:
person2 = { :name => "John Doe", :age => 20 }

puts person1[:name] # => "John Doe"
puts person2[:age]  # => 20

class Test
  def test(msg)
    puts "Test", msg
  end

  def method_missing(name, *args, &block)
    puts "Calling #{name}"
    puts name.class
    puts "Test", :hahahaha
  end
end

test = Test.new
test.send(:test, "hello")
test.send(:huehue, "br")
