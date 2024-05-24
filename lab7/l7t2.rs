use std::io::{self, Write};

fn is_truth_add(s: &str, p: &str, s_i: usize, p_i: usize) -> bool {
    // if the length of the string is not within the acceptable range, return false
    if s.len() >= 2000 || s.len() == 0 {
        println!("Некорректный размер строки!");
        return false;
    }

    // if we reach the end of both the string and the pattern, we have a match
    if s_i == s.len() && p_i == p.len() {
        return true;
    }

    // if we reach the end of the string but not the pattern, we don't have a match
    if s_i == s.len() || p_i == p.len() {
        return false;
    }

    // if current characters match, or pattern character is '?', move to the next character
    if s.chars().nth(s_i) == p.chars().nth(p_i) || p.chars().nth(p_i) == Some('?') {
        return is_truth_add(s, p, s_i + 1, p_i + 1);
    }

    // if the pattern character is '*', try to match the rest of the string
    if p.chars().nth(p_i) == Some('*') {
        for i in s_i..=s.len() {
            if is_truth_add(s, p, i, p_i + 1) {
                return true;
            }
        }
    }

    false
}

fn is_truth(s: &str, p: &str) -> bool {
    is_truth_add(s, p, 0, 0)
}

fn main() {
    let mut s = String::new();
    let mut p = String::new();

    print!("Введите строку s: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();

    print!("Введите шаблон p: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut p).unwrap();
    let p = p.trim();

    if is_truth(s, p) {
        println!("true");
    } else {
        println!("false");
    }
}
