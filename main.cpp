#include <deque>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int main() {
    int n = 0, m = 0;
    cout << "Введите число элементов вектора и дека: ";
    for (;;) {
        if (!(cin >> n >> m)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: нужны два целых числа. Повторите ввод: ";
            continue;
        }
        if (n > 0 && m > 0 && n % 2 == 0 && m % 2 == 0)
            break;
        cout << "Ошибка: оба числа должны быть положительными и чётными. Повторите ввод: ";
    }
    vector<int> v(static_cast<size_t>(n));
    cout << "Введите элементы вектора: ";
    for (size_t i = 0; i < v.size(); ++i) {
        while (!(cin >> v[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите целое число (элемент " << i + 1 << "): ";
        }
    }
    deque<int> d(static_cast<size_t>(m));
    cout << "Введите элементы дека: ";
    for (size_t i = 0; i < d.size(); ++i) {
        while (!(cin >> d[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите целое число (элемент " << i + 1 << "): ";
        }
    }
    const auto v_half = n / 2;
    const auto d_half = m / 2;
    v.insert(v.end(), d.begin(), d.begin() + static_cast<ptrdiff_t>(d_half));
    d.insert(d.begin(), v.rbegin() + static_cast<ptrdiff_t>(d_half),
        v.rbegin() + static_cast<ptrdiff_t>(d_half + v_half));
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
    for (size_t i = 0; i < d.size(); ++i)
        cout << d[i] << (i + 1 < d.size() ? ' ' : '\n');

    return 0;
}