#ifndef BASES_H // include guard
#define BASES_H


template <template <typename> class Child, typename T>
class Tuple2 {
public:
    static const int nDimensions = 2;
    Tuple2() = default;
    Tuple2(T x, T y) : x(x), y(y) {}
    bool HasNaN() const {
        return std::isnan(x) || std::isnan(y);
    }
    template <typename U>
    auto operator+(Child<U> c) const -> Child<decltype(T{}+U{})> {
        return {x+c.x, y+c.y};
    }
    template <typename U>
    Child<T> &operator+=(Child<U> c) {
        x += c.x;
        y += c.y;
        return static_cast<Child<T>&>(*this);
    }
    template <typename U>
    auto operator-(Child<U> c) const -> Child<decltype(T{}-U{})> {
        return {x-c.x, y-c.y};
    }
    template <typename U>
    Child<T> &operator-=(Child<U> c) {
        x -= c.x;
        y -= c.y;
        return static_cast<Child<T>&>(*this);
    }
    bool operator==(const Child<T> &c) const {
        return x == c.x && y == c.y;
    }
    bool operator!=(const Child<T> &c) const {
        return x != c.x || y != c.y;
    }
    template <typename U>
    auto operator*(U s) const -> Child<decltype(T{} * U{})> {
        return {s * x, s * y};
    }
    template <typename U>
    Child<T> &operator*=(U s) {
        x *= s;
        y *= s;
        return static_cast<Child<T>&>(*this);
    }
    template <typename U>
    auto operator/(U s) const -> Child<decltype(T{} / U{})> {
        return {x / s, y / s};
    }
    template <typename U>
    Child<T> &operator/=(U s) {
        x /= s;
        y /= s;
        return static_cast<Child<T>&>(*this);
    }
    Child<T> operator-() const {
        return {-x, -y};
    }
    T operator[](int i) const {
        return (i == 0) ? x : y;
    }
    T &operator[](int i) {
        return (i == 0) ? x : y;
    }
    std::string ToString() const { return internal::ToString2(x, y); }
    T x{}, y{};

};










#endif // BASES_H;