class Test
  def method_missing(name, *args, &block)
    puts "nome do método: #{name}"
    puts "argumentos: #{args}"
  end
end

test = Test.new
test.qualquer_coisa "omeufilho", 123, "xiquexiquebahia"

