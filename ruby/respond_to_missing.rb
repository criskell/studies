class Person
  def method_missing(name, *args, &block)
    if name.to_s.start_with?("speak_")
      language = name.to_s.split("speak_").last
      puts "Speaking in #{language}"
    else
      super
    end
  end

  # por padrão, chamadas object.respond_to? vão retornar false para métodos dinâmicos
  # ak modificamos esse comportamento
  def respond_to_missing?(name, include_private = false)
    name.to_s.start_with?("speak_") || super
  end
end

person = Person.new

person.speak_portuguese
person.speak_english

puts person.respond_to?(:speak_espanol)
puts person.respond_to?(:teste)
