#include <iostream>
#include <string>

using namespace std;

bool isTruthAdd(const string& s, const string& p, int s_i, int p_i) { // рекурсия
    // если достигнут конец строки и шаблона, то совпадение найдено
    if (s.length() < 2000 && s.length() > 0) {
    if (s_i == s.length() && p_i == p.length()) {
        return true;
    }

    // если достигнут конец строки, но не шаблона, то совпадение не найдено
    if (s_i == s.length() || p_i == p.length()) {
        return false;
    }

    // если текущие символы совпадают или шаблонный символ - ?, то следующий символ
    if (s[s_i] == p[p_i] || p[p_i] == '?') {
        return isTruthAdd(s, p, s_i + 1, p_i + 1);
    }

    /* если текущий символ шаблона - *, то сопоставляем подстроки,
    начиная со следующего символа в строке и текущего символа в шаблоне,
    пока не найдется совпадение или не наступит конец строки */
    if (p[p_i] == '*') {
        for (int i = s_i; i <= s.length(); ++i) {
            if (isTruthAdd(s, p, i, p_i + 1)) {
                return true;
            }
        }
    }
    } else {
    cout << "Некорректный размер строки!" << endl;
    }

    return false;
}

bool isTruth(const string& s, const string& p) { // вместо постоянной инициализации
    return isTruthAdd(s, p, 0, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    string s, p;
    cout << "Введите строку s: ";
    getline(cin, s);
    cout << "Введите шаблон p: ";
    getline(cin, p);

    if (isTruth(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
