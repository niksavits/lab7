#include <iostream>
#include <string>

using namespace std;

bool isTruthAdd(const string& s, const string& p, int s_i, int p_i) { // ��������
    // ���� ��������� ����� ������ � �������, �� ���������� �������
    if (s.length() < 2000 && s.length() > 0) {
    if (s_i == s.length() && p_i == p.length()) {
        return true;
    }

    // ���� ��������� ����� ������, �� �� �������, �� ���������� �� �������
    if (s_i == s.length() || p_i == p.length()) {
        return false;
    }

    // ���� ������� ������� ��������� ��� ��������� ������ - ?, �� ��������� ������
    if (s[s_i] == p[p_i] || p[p_i] == '?') {
        return isTruthAdd(s, p, s_i + 1, p_i + 1);
    }

    /* ���� ������� ������ ������� - *, �� ������������ ���������,
    ������� �� ���������� ������� � ������ � �������� ������� � �������,
    ���� �� �������� ���������� ��� �� �������� ����� ������ */
    if (p[p_i] == '*') {
        for (int i = s_i; i <= s.length(); ++i) {
            if (isTruthAdd(s, p, i, p_i + 1)) {
                return true;
            }
        }
    }
    } else {
    cout << "������������ ������ ������!" << endl;
    }

    return false;
}

bool isTruth(const string& s, const string& p) { // ������ ���������� �������������
    return isTruthAdd(s, p, 0, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    string s, p;
    cout << "������� ������ s: ";
    getline(cin, s);
    cout << "������� ������ p: ";
    getline(cin, p);

    if (isTruth(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
