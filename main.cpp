#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
template <typename Container>
void container(Container& c, const string& prompt, const string& name) {
    string line;
    for (;;) {
        cout << prompt;
        if (!getline(cin, line))
            throw runtime_error("Ошибка чтения ввода.");
        istringstream iss(line);
        Container temp((istream_iterator<int>(iss)), istream_iterator<int>());
        if (!iss.eof() || temp.empty() || temp.size() % 2 != 0) {
            cout << "Ошибка: строка должна содержать только чётное число целых числа. Повторите ввод.\n";
            continue;
        }
        c = move(temp);
        break;
    }
}
int main() {
    vector<int> v;
    deque<int> d;
    try {
        container(v, "Введите элементы вектора: ", "вектора");
        container(d, "Введите элементы дека: ", "дека");
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
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