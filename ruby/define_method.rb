class Person
  [:portuguese, :english, :espanol].each do |language|
    # define dinamicamente o método em runtime.
    define_method("speak_#{language}") do
      puts "Speaking in #{language.capitalize}"
    end
  end
end

p = Person.new
p.speak_portuguese
p.speak_english

class Calculator
  define_method(:sum) do |x, y|
    x + y
  end
end

calculator = Calculator.new
puts calculator.sum(1, 2)
