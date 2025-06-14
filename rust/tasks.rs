use std::io::{self, Write};

#[derive(Debug)]
enum Status {
    Pending,
    Done,
}

#[derive(Debug)]
struct Task {
    description: String,
    status: Status,
}

impl Task {
    fn new(description: String) -> Self {
        Task {
            description,
            status: Status::Pending,
        }
    }

    fn mark_done(&mut self) {
        self.status = Status::Done;
    }

    #[allow(dead_code)]
    fn is_pending(&self) -> bool {
        matches!(self.status, Status::Pending)
    }
}

struct TodoList {
    tasks: Vec<Task>,
}

impl TodoList {
    fn new() -> Self {
        TodoList { tasks: Vec::new() }
    }

    fn add_task(&mut self, description: String) {
        self.tasks.push(Task::new(description));
    }

    fn list_tasks(&self) {
        if self.tasks.is_empty() {
            println!("No tasks found.");
            return;
        }

        for (i, task) in self.tasks.iter().enumerate() {
            let status = match task.status {
                Status::Pending => "[ ]",
                Status::Done => "[x]",
            };

            println!("{}: {} {}", i, status, task.description);
        }
    }

    fn mark_done(&mut self, index: usize) -> Result<(), String> {
        if let Some(task) = self.tasks.get_mut(index) {
            task.mark_done();
            return Ok(());
        }

        Err(format!("Invalid index: {}", index))
    }

    fn remove_task(&mut self, index: usize) -> Result<(), String> {
        if index < self.tasks.len() {
            self.tasks.remove(index);
            return Ok(());
        }

        Err(format!("Invalid index: {}", index))
    }
}

fn read_line() -> String {
    let mut input = String::new();

    io::stdout().flush().unwrap();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line.");
    input.trim().to_string()
}

fn print_menu() {
    println!();
    println!("Menu:");
    println!("1 - Add task");
    println!("2 - List tasks");
    println!("3 - Mark task as done");
    println!("4 - Remove task");
    println!("5 - Quit");
    println!();
    print!("Choose an option: ");
}

fn main() {
    let mut todo_list = TodoList::new();

    loop {
        print_menu();
        let choice = read_line();

        match choice.as_str() {
            "1" => {
                print!("Task description: ");
                let description = read_line();
                todo_list.add_task(description);
                println!("Task added!");
            }

            "2" => {
                println!("Task list:");
                todo_list.list_tasks();
            }

            "3" => {
                print!("Task index to mark as done: ");
                let idx = read_line();

                match idx.parse::<usize>() {
                    Ok(i) => match todo_list.mark_done(i) {
                        Ok(_) => println!("Task marked as done."),
                        Err(e) => println!("Err: {}", e),
                    },
                    Err(_) => println!("Please, type an valid number."),
                }
            }

            "4" => {
                print!("Task index to remove: ");
                let idx = read_line();
                match idx.parse::<usize>() {
                    Ok(i) => match todo_list.remove_task(i) {
                        Ok(_) => println!("Task removed."),
                        Err(e) => println!("Erro: {}", e),
                    },
                    Err(_) => println!("Please, enter an valid number."),
                }
            }

            "5" => {
                println!("Quitting...");
                break;
            }

            _ => println!("Invalid option. Try again."),
        }
    }
}
