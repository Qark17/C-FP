#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main() {
    cout << "Введите элементы: ";
    vector<int> v((istream_iterator<int>(cin)), istream_iterator<int>());
    if (v.empty())
        return 0;
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end();) {
        auto ub = upper_bound(it, v.end(), *it);
        const auto cnt = static_cast<size_t>(ub - it);
        cout << *it << ' ' << cnt << " раз(а)\n";
        it = ub;
    }
    return 0;
}