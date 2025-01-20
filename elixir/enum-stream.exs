multiplesOfTwo = Enum.map(1..10, fn x -> x * 2 end)
keyMultipledByValue = Enum.map(%{1 => 2, 3 => 4, 5 => 6}, fn {k, v} -> k * v end)

range = 1..3
transformedRange = Enum.map(range, fn x -> x * 2 end)

sumOfTransformedRange = Enum.reduce(transformedRange, 0, &+/2)
