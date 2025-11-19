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

json = <<~JSON
{
  "charge": {
    "status": "ACTIVE",
    "customer": {
      "name": "Dan",
      "email": "email0@example.com",
      "phone": "5511999999999",
      "taxID": {
        "taxID": "31324227036",
        "type": "BR:CPF"
      }
    },
    "value": 100,
    "comment": "good",
    "correlationID": "9134e286-6f71-427a-bf00-241681624586",
    "paymentLinkID": "7777a23s-6f71-427a-bf00-241681624586",
    "paymentLinkUrl": "https://woovi.com/pay/9134e286-6f71-427a-bf00-241681624586",
    "qrCodeImage": "https://api.woovi.com/openpix/charge/brcode/image/9134e286-6f71-427a-bf00-241681624586.png",
    "expiresIn": 2592000,
    "expiresDate": "2021-04-01T17:28:51.882Z",
    "createdAt": "2021-03-02T17:28:51.882Z",
    "updatedAt": "2021-03-02T17:28:51.882Z",
    "brCode": "000201010212261060014br.gov.bcb.pix2584https://api.woovi.com/openpix/testing?transactionID=867ba5173c734202ac659721306b38c952040000530398654040.015802BR5909LOCALHOST6009Sao Paulo62360532867ba5173c734202ac659721306b38c963044BCA",
    "additionalInfo": [
      {
        "key": "Product",
        "value": "Pencil"
      },
      {
        "key": "Invoice",
        "value": "18476"
      },
      {
        "key": "Order",
        "value": "302"
      }
    ],
    "paymentMethods": {
      "pix": {
        "method": "PIX_COB",
        "transactionID": "9134e286-6f71-427a-bf00-241681624586",
        "identifier": "9134e286-6f71-427a-bf00-241681624586",
        "additionalInfo": [],
        "fee": 50,
        "value": 200,
        "status": "ACTIVE",
        "txId": "9134e286-6f71-427a-bf00-241681624586",
        "brCode": "000201010212261060014br.gov.bcb.pix2584https://api.woovi.com/openpix/testing?transactionID=867ba5173c734202ac659721306b38c952040000530398654040.015802BR5909LOCALHOST6009Sao Paulo62360532867ba5173c734202ac659721306b38c963044BCA",
        "qrCodeImage": "https://api.woovi.com/openpix/charge/brcode/image/9134e286-6f71-427a-bf00-241681624586.png"
      }
    }
  }
}
JSON

parsed = JSON.parse(json)

puts to_elixir(parsed, atom_keys: false)