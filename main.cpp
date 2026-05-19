#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
struct point {
    int x;
    int y;
    std::string s;
    point() : x(0), y(0), s("") {}
    point(int x_, int y_, const std::string& s_)
        : x(x_), y(y_), s(s_) {
    }
};
point operator+(const point& A, const point& B) {
    return point(
        A.x + B.x,
        A.y + B.y,
        A.s + B.s
    );
}
std::istream& operator>>(std::istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}
std::ostream& operator<<(std::ostream& os, const point& p) {
    os << p.x << ' ' << p.y << ' ' << p.s;
    return os;
}

int main() {
    std::fstream file("Сname.txt", std::ios::in);
    if (!file) {
        std::cout << "Ошибка чтения файла";
        return 1;
    }
    std::vector<point> V;
    std::copy(
        std::istream_iterator<point>(file),
        std::istream_iterator<point>(),
        std::back_inserter(V)
    );
    file.close();
    std::transform(
        V.begin(),
        V.end(),
        V.begin(),
        [](const point& p) {
            return p + point(10, 20, "Z");
        }
    );
    file.open("name.txt", std::ios::out);
    if (!file) {
        std::cout << "File write error";
        return 1;
    }
    std::copy(
        V.begin(),
        V.end(),
        std::ostream_iterator<point>(file, "\n")
    );
    file.close();
    return 0;
}