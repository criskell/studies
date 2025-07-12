trait Component {}

impl Component for &str {}

fn filter<'a, T, P>(components: &'a [T], predicate: P) -> Vec<&'a T>
where
    T: Component + 'a,
    P: Fn(&T) -> bool + 'a,
{
    components
        .iter()
        .filter(|&component| predicate(component))
        .collect()
}

fn main() {
    let word1 = String::from("world");
    let word2 = String::from("hello");
    let components = vec![word2.as_str(), word1.as_str()];

    let prefix = String::from("wo");
    // tudo que a closure usa (captura) deve viver pelo menos até o lifetime 'a.
    let result = filter(&components, |s| s.starts_with(&prefix));

    println!("{:?}", result);
}
