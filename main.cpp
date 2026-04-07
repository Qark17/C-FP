#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    deque<int> d;
    string line;
    cout << "Введите элементы вектора: ";
    for (;;) {
        if (!getline(cin, line)) {
            cerr << "Ошибка чтения ввода.\n";
            return 1;
        }
        istringstream iss(line);
        vector<int> temp((istream_iterator<int>(iss)), istream_iterator<int>());
        if (!iss.eof()) {
            cout << "Ошибка: строка должна содержать только целые числа. Повторите ввод: ";
            continue;
        }
        if (temp.empty() || temp.size() % 2 != 0) {
            cout << "Ошибка: количество элементов вектора должно быть положительным и чётным. Повторите ввод: ";
            continue;
        }
        v = move(temp);
        break;
    }
    cout << "Введите элементы дека: ";
    for (;;) {
        if (!getline(cin, line)) {
            cerr << "Ошибка чтения ввода.\n";
            return 1;
        }
        istringstream iss(line);
        deque<int> temp((istream_iterator<int>(iss)), istream_iterator<int>());
        if (!iss.eof()) {
            cout << "Ошибка: строка должна содержать только целые числа. Повторите ввод: ";
            continue;
        }
        if (temp.empty() || temp.size() % 2 != 0) {
            cout << "Ошибка: количество элементов дека должно быть чётным. Повторите ввод: ";
            continue;
        }
        d = move(temp);
        break;
    }
    const size_t v_half = v.size() / 2;
    const size_t d_half = d.size() / 2;
    v.insert(v.end(), d.begin(), d.begin() + static_cast<ptrdiff_t>(d_half));
    d.insert(d.begin(),
        v.rbegin() + static_cast<ptrdiff_t>(d_half),
        v.rbegin() + static_cast<ptrdiff_t>(d_half + v_half));
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
    for (size_t i = 0; i < d.size(); ++i)
        cout << d[i] << (i + 1 < d.size() ? ' ' : '\n');
    return 0;
}