use std::ptr::addr_of;

fn get() -> usize {
    extern "C" {
        #[link_name = "symbol"]
        static SYM: u8;
    }

    addr_of!(SYM) as usize
}

fn main() {
    let addr = get();

    println!("The symbol address is {}", addr);
}
