use std::rc::Rc;

fn main() {
    let a = Rc::new(5);
    let b = Rc::clone(&a);

    println!("a: {}, b: {}", a, b);
    println!("count: {}", Rc::strong_count(&a));
}