#!/usr/bin/env ruby

require "json"

def to_elixir(value, atom_keys: false, indent: 0)
  space = "  " * indent

  case value
  when Hash
    items = value.map do |k, v|
      key = if atom_keys
                k.to_s.match?(/\A[a-zA-Z_][a-zA-Z0-9_]*\z/) ? ":#{k}" : "\"#{k}\""
      else
        "\"#{k}\""
      end   

      "#{space}  #{key} => #{to_elixir(v, atom_keys: atom_keys, indent: indent + 1)}"
    end

    "%{\n#{items.join(",\n")}\n#{space}}"
  when Array
    return "[]" if value.empty?

    if value.any? { |v| v.is_a?(Hash) }
      inner = value.map do |v|
        to_elixir(v, atom_keys: atom_keys, indent: indent + 1)
      end

      "[\n#{inner.map { |i| (("  ") * (indent + 1)) + i }.join(",\n")}\n#{space}]"
    else
      items = value.map { |v| to_elixir(v, atom_keys: atom_keys, indent: indent) }
      "[#{items.join(", ")}]"
    end
  when String
    "\"#{value}\""
  when Numeric, TrueClass, FalseClass
    value.to_s
  when NilClass
    "nil"
  else
    raise "Unsupported JSON type: #{value.class}"
  end
end

input =
  if ARGV[0]
    File.read(ARGV[0])
  else
    $stdin.read
  end

atom_keys = ARGV.include?("--atoms")

parsed = JSON.parse(input)
puts to_elixir(parsed, atom_keys: atom_keys)