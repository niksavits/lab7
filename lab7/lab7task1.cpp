#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstallPrograms(vector<int>& computers, vector<int>& programs, int index) { // рекурсия
    /* если у нас больше нет программ для установки,
    то это означает, что мы успешно установили все программы */
    if (index == programs.size()) {
        return true;
    }

    /* рекурсивно пытаемся установить программу на каждом компьютере,
    начиная с самого большого свободного пространства */
    for (int i = 0; i < computers.size(); ++i) {
        if (computers[i] >= programs[index]) {
            computers[i] -= programs[index]; // уменьшаем свободное место на компьютере
            // рекурсивный вызов для установки следующей программы
            if (canInstallPrograms(computers, programs, index + 1)) {
                return true;
            }
            // если установка не удалась, возвращаем исходное состояние
            computers[i] += programs[index];
        }
    }

    /* если мы дошли до этого момента, значит ни на одном из компьютеров
    невозможно установить текущую программу */
    return false;
}

bool canInstall(vector<int>& computers, vector<int>& programs) {
    // сортируем программы по убыванию требуемой памяти
    sort(programs.begin(), programs.end(), greater<int>());

    // вызываем рекурсивную функцию для установки программ
    return canInstallPrograms(computers, programs, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numComputers, numPrograms;

    cout << "Введите количество компьютеров: ";
    cin >> numComputers;

    while (numComputers <= 0) {
        cout << "Количество компьютеров должно быть положительным!" << endl;
        cout << "Пожалуйста, введите корректное значение: ";
        cin >> numComputers;
    }

    cout << "Введите количество программных систем: ";
    cin >> numPrograms;

    while (numPrograms <= 0) {
        cout << "Количество программных систем должно быть положительным!" << endl;
        cout << "Пожалуйста, введите корректное значение: ";
        cin >> numPrograms;
    }

    vector<int> computers(numComputers);
    vector<int> programs(numPrograms);

    cout << "Введите количество свободной памяти для каждого компьютера:\n";
    for (int i = 0; i < numComputers; ++i) {
        cout << "Компьютер " << i + 1 << ": ";
        cin >> computers[i];

        while (computers[i] <= 0) {
            cout << "Количество свободной памяти должно быть положительным!" << endl;
            cout << "Пожалуйста, введите корректное значение для компьютера " << i + 1 << ": ";
            cin >> computers[i];
        }
    }

    cout << "Введите требуемое количество памяти для каждой программной системы:\n";
    for (int i = 0; i < numPrograms; ++i) {
        cout << "Программа " << i + 1 << ": ";
        cin >> programs[i];

        while (programs[i] <= 0) {
            cout << "Требуемое количество памяти должно быть положительным!" << endl;
            cout << "Пожалуйста, введите корректное значение для программы " << i + 1 << ": ";
            cin >> programs[i];
        }
    }

    if (canInstall(computers, programs)) {
        cout << "Можно установить все программы.\n";
    } else {
        cout << "Нельзя установить все программы.\n";
    }

    return 0;
}
