require 'socket'

server = TCPSocket.open('localhost', 4001)

server.puts 'Hello, server!'

response = ''

while line = server.gets
    response += line
end

puts "Response received: #{response}"

server.close