#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstallPrograms(vector<int>& computers, vector<int>& programs, int index) { // ��������
    /* ���� � ��� ������ ��� �������� ��� ���������,
    �� ��� ��������, ��� �� ������� ���������� ��� ��������� */
    if (index == programs.size()) {
        return true;
    }

    /* ���������� �������� ���������� ��������� �� ������ ����������,
    ������� � ������ �������� ���������� ������������ */
    for (int i = 0; i < computers.size(); ++i) {
        if (computers[i] >= programs[index]) {
            computers[i] -= programs[index]; // ��������� ��������� ����� �� ����������
            // ����������� ����� ��� ��������� ��������� ���������
            if (canInstallPrograms(computers, programs, index + 1)) {
                return true;
            }
            // ���� ��������� �� �������, ���������� �������� ���������
            computers[i] += programs[index];
        }
    }

    /* ���� �� ����� �� ����� �������, ������ �� �� ����� �� �����������
    ���������� ���������� ������� ��������� */
    return false;
}

bool canInstall(vector<int>& computers, vector<int>& programs) {
    // ��������� ��������� �� �������� ��������� ������
    sort(programs.begin(), programs.end(), greater<int>());

    // �������� ����������� ������� ��� ��������� ��������
    return canInstallPrograms(computers, programs, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numComputers, numPrograms;

    cout << "������� ���������� �����������: ";
    cin >> numComputers;

    while (numComputers <= 0) {
        cout << "���������� ����������� ������ ���� �������������!" << endl;
        cout << "����������, ������� ���������� ��������: ";
        cin >> numComputers;
    }

    cout << "������� ���������� ����������� ������: ";
    cin >> numPrograms;

    while (numPrograms <= 0) {
        cout << "���������� ����������� ������ ������ ���� �������������!" << endl;
        cout << "����������, ������� ���������� ��������: ";
        cin >> numPrograms;
    }

    vector<int> computers(numComputers);
    vector<int> programs(numPrograms);

    cout << "������� ���������� ��������� ������ ��� ������� ����������:\n";
    for (int i = 0; i < numComputers; ++i) {
        cout << "��������� " << i + 1 << ": ";
        cin >> computers[i];

        while (computers[i] <= 0) {
            cout << "���������� ��������� ������ ������ ���� �������������!" << endl;
            cout << "����������, ������� ���������� �������� ��� ���������� " << i + 1 << ": ";
            cin >> computers[i];
        }
    }

    cout << "������� ��������� ���������� ������ ��� ������ ����������� �������:\n";
    for (int i = 0; i < numPrograms; ++i) {
        cout << "��������� " << i + 1 << ": ";
        cin >> programs[i];

        while (programs[i] <= 0) {
            cout << "��������� ���������� ������ ������ ���� �������������!" << endl;
            cout << "����������, ������� ���������� �������� ��� ��������� " << i + 1 << ": ";
            cin >> programs[i];
        }
    }

    if (canInstall(computers, programs)) {
        cout << "����� ���������� ��� ���������.\n";
    } else {
        cout << "������ ���������� ��� ���������.\n";
    }

    return 0;
}
