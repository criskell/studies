fn calculate_squares(max: i32) -> Vec<i32> {
    let mut result = Vec::new();

    let mut i = 0;
    while i * i <= max {
        result.push(i);
        i += 1;
    }

    result
}

fn calculate_squares2(max: i32) -> Vec<i32> {
    // `0..`: cria um iterador infinito de inteiros começando do zero.
    // `.take_while`: pega valores enquanto a condição for verdadeira.
    // `.collect`: transforma o iterador em Vec<i32>
    (0..).take_while(|&i| i * i <= max).collect()
}

fn main() {
    let squares = calculate_squares(103);

    for current in squares {
        print!("{} ", current);
    }

    println!();

    let squares2 = calculate_squares2(103);

    for current in squares2 {
        print!("{} ", current);
    }

    println!();
}
