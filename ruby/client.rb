require 'socket'

server = TCPSocket.open('localhost', 4002)

server.puts 'Hello, server!'

response = ''

while line = server.gets
    response += line
end

puts "Response received: #{response}"

server.close