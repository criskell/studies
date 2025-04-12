class Person
end

# `class_eval` serve para abrir uma classe ou módulo em tempo de execução e adicionar código.
Person.class_eval do
  def greeting
    "Hi"
  end
end

p = Person.new
puts p.greeting

DynamicClass = Class.new
# <<-RUBY ... RUBY é uma heredoc.
# O token "-" serve para especificar que o último marcador pode ter indentação.
DynamicClass.class_eval <<-RUBY
  def say
    puts "Hello, world!"
  end
RUBY

obj = DynamicClass.new
obj.say

