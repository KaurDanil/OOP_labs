#pragma once

#include <iostream>
#include <concepts>
#include <string>

// Концепт, определённый вне класса
template <typename T>
concept Number = (std::integral<T> || std::floating_point<T>) && !std::same_as<T, bool> && !std::same_as<T, char>;

template <Number T>
class Point
{
public:
    Point();
    Point(T x, T y);
    Point(const Point &other);

    Point &operator=(const Point &right);

    T x_{};
    T y_{};

    template <typename F>
    friend inline Point<F> operator+(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline Point<F> operator-(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator==(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator!=(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator<(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator>(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator<=(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline bool operator>=(const Point<F> &left, const Point<F> &right);

    template <typename F>
    friend inline std::istream &operator>>(std::istream &is, Point<F> &p);

    template <typename F>
    friend inline std::ostream &operator<<(std::ostream &os, const Point<F> &p);
};

template <Number T>
inline Point<T>::Point() : x_{0}, y_{0} {}

template <Number T>
inline Point<T>::Point(T x, T y) : x_{x}, y_{y} {}

template <Number T>
inline Point<T>::Point(const Point<T> &other) : x_(other.x_), y_(other.y_) {}

template <Number T>
inline Point<T> &Point<T>::operator=(const Point<T> &right)
{
    if (this != &right)
    {
        x_ = right.x_;
        y_ = right.y_;
    }
    return *this;
}

template <Number T>
inline Point<T> operator+(const Point<T> &left, const Point<T> &right)
{
    return Point<T>(left.x_ + right.x_, left.y_ + right.y_);
}

template <Number T>
inline Point<T> operator-(const Point<T> &left, const Point<T> &right)
{
    return Point<T>(left.x_ - right.x_, left.y_ - right.y_);
}

template <Number T>
inline bool operator==(const Point<T> &left, const Point<T> &right)
{
    return (left.x_ == right.x_) && (left.y_ == right.y_);
}

template <Number T>
inline bool operator!=(const Point<T> &left, const Point<T> &right)
{
    return !(left == right);
}

template <Number T>
inline bool operator<(const Point<T> &left, const Point<T> &right)
{
    return (left.x_ < right.x_) || ((left.x_ == right.x_) && (left.y_ < right.y_));
}

template <Number T>
inline bool operator>(const Point<T> &left, const Point<T> &right)
{
    return (left.x_ > right.x_) || ((left.x_ == right.x_) && (left.y_ > right.y_));
}

template <Number T>
inline bool operator<=(const Point<T> &left, const Point<T> &right)
{
    return !(left > right);
}

template <Number T>
inline bool operator>=(const Point<T> &left, const Point<T> &right)
{
    return !(left < right);
}

template <Number T>
inline std::istream &operator>>(std::istream &is, Point<T> &p)
{
    is >> p.x_ >> p.y_;
    return is;
}

template <Number T>
inline std::ostream &operator<<(std::ostream &os, const Point<T> &p)
{
    os << "(x: " << p.x_ << ", y: " << p.y_ << ")";
    return os;
}
