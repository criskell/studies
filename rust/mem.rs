use std::mem;

fn main() {
    let mut x = Some(10);

    let old = mem::replace(&mut x, None);
    println!("old = {:?}, x = {:?}", old, x);

    let mut y = Some(20);
    mem::take(&mut y);

    println!("old = {:?}, y = {:?}", old, y);
}
