class Output
  def initialize()
    @data = []
  end

  def <<(data)
    @data << data
    self
  end

  def to_s()
    @data.join(", ")
  end
end

object = Output.new
object << "hi" << "criskell" << "teste"

puts object
