use std::cell::RefCell;
use std::rc::Rc;

fn main() {
    let data = Rc::new(RefCell::new(5));
    let data_clone = Rc::clone(&data);

    *data_clone.borrow_mut() += 1;

    println!("data: {:?}", data.borrow());
}
