struct Counter {
    current: u32,
    max: u32,
}

impl Counter {
    fn new(max: u32) -> Self {
        Counter { current: 0, max: max }
    }
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.current < self.max {
            self.current += 1;
            Some(self.current)
        } else {
            None
        }
    }
}

fn main() {
    let mut counter = Counter::new(50);

    while let Some(number) = counter.next() {
        println!("{number}");
    }

    let sum: u32 = Counter::new(10)
        .filter(|x| x % 2 == 0)
        .map(|x| x * x)
        .sum();

    println!("Soma dos quadrados pares: {sum}");
}
