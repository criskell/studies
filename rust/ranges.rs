struct Range {
    start: u32,
    end: u32,
}

// para conseguir utilizar o "for .. in"
impl IntoIterator for Range {
    type Item = u32;
    type IntoIter = RangeIter;

    fn into_iter(self) -> Self::IntoIter {
        RangeIter { current: self.start, end: self.end }
    }
}

struct RangeIter {
    current: u32,
    end: u32,
}

impl Iterator for RangeIter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.current < self.end {
            let value = self.current;
            self.current += 1;
            Some(value)
        } else {
            None
        }
    } 
}

fn main() {
    let range = Range { start: 3, end: 7 };

    for number in range {
        println!("{number}");
    }
}
