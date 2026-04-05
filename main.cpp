#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Введите число элементов: ";
    if (!(cin >> n))
        return 0;
    vector<int> v(n);
    cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ) {
        auto ub = upper_bound(it, v.end(), *it);
        const auto cnt = static_cast<size_t>(ub - it);
        cout << *it << ' ' << cnt << " раз(а) \n";
        it = ub;
    }
    return 0;
}