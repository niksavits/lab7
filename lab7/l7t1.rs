use std::io;

fn can_install_programs(computers: &mut Vec<i32>, programs: &Vec<i32>, index: usize) -> bool {
    if index == programs.len() {
        return true;
    }

    for i in 0..computers.len() {
        if computers[i] >= programs[index] {
            computers[i] -= programs[index];
            if can_install_programs(computers, programs, index + 1) {
                return true;
            }
            computers[i] += programs[index];
        }
    }

    false
}

fn can_install(mut computers: Vec<i32>, mut programs: Vec<i32>) -> bool {
    // Sort programs by descending memory requirement
    programs.sort_by(|a, b| b.cmp(a));

    can_install_programs(&mut computers, &programs, 0)
}

fn main() {
    let mut input = String::new();

    println!("Введите количество компьютеров: ");
    let mut num_computers = 0;
    while num_computers <= 0 {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        num_computers = input.trim().parse::<i32>().unwrap_or(0);
        if num_computers <= 0 {
            println!("Количество компьютеров должно быть положительным!");
            println!("Пожалуйста, введите корректное значение: ");
        }
    }

    println!("Введите количество программных систем: ");
    let mut num_programs = 0;
    while num_programs <= 0 {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        num_programs = input.trim().parse::<i32>().unwrap_or(0);
        if num_programs <= 0 {
            println!("Количество программных систем должно быть положительным!");
            println!("Пожалуйста, введите корректное значение: ");
        }
    }

    let mut computers = Vec::new();
    for i in 0..num_computers {
        println!("Введите количество свободной памяти для компьютера {}: ", i + 1);
        let mut mem = 0;
        while mem <= 0 {
            input.clear();
            io::stdin().read_line(&mut input).unwrap();
            mem = input.trim().parse::<i32>().unwrap_or(0);
            if mem <= 0 {
                println!("Количество свободной памяти должно быть положительным!");
                println!("Пожалуйста, введите корректное значение для компьютера {}: ", i + 1);
            }
        }
        computers.push(mem);
    }

    let mut programs = Vec::new();
    for i in 0..num_programs {
        println!("Введите требуемое количество памяти для программы {}: ", i + 1);
        let mut mem = 0;
        while mem <= 0 {
            input.clear();
            io::stdin().read_line(&mut input).unwrap();
            mem = input.trim().parse::<i32>().unwrap_or(0);
            if mem <= 0 {
                println!("Требуемое количество памяти должно быть положительным!");
                println!("Пожалуйста, введите корректное значение для программы {}: ", i + 1);
            }
        }
        programs.push(mem);
    }

    if can_install(computers, programs) {
        println!("Можно установить все программы.");
    } else {
        println!("Нельзя установить все программы.");
    }
}
