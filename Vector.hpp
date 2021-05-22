#include <bits/stdc++.h>
#include <type_traits>

template<typename T, std::size_t size, typename=std::enable_if_t<std::is_arithmetic<T>::value>>
class Vector {
protected:
    T m_array[size];
    std::size_t free_idx = 0;
    void construct(T obj) {
        m_array[free_idx] = obj;
        ++free_idx;
    }
public:
    //Vector(Vector& copy) { std::copy(copy.m_array, m_array); }
    template<typename _T, typename ...Ts, typename = std::enable_if<std::conjunction_v<std::is_same<T,Ts>...>>>
    Vector(_T first, Ts... other) {
        construct(first);
        construct(other...);
    }

    Vector() = default;
    T& operator[](const std::size_t& idx) { return m_array[idx]; }

    T magnitude() const {
        T sum_sqr = 0;
        for (std::size_t i; i < size; ++i) {
            sum_sqr += this[i]*this[i];
        }
        return sqrt(sum_sqr);
    }

    T magnitude_sqr() const {
        T sum_sqr = 0;
        for (std::size_t i = 0; i < size; ++i) {
            sum_sqr += this[i]*this[i];
        }
        return sum_sqr;
    }

    Vector<T,size> operator*(const T& multiple) {
        Vector<T,size> ret = m_array;
        for (std::size_t i = 0; i < size; ++i) {
            ret[i] = ret[i]*multiple;
        }
        return ret;
    }

    Vector<T,size> operator/(const T& divisor) {
        Vector<T,size> ret = m_array;
        for (std::size_t i = 0; i < size; ++i) {
            ret[i] = ret[i]/divisor;
        }
        return ret;
    }

    Vector<T,size>& operator*=(const T& multiple) {
        *this = *this*multiple;
        return *this;
    }
    Vector<T,size>& operator/=(const T& divisor) {
        *this = *this/divisor;
        return *this;
    }

    Vector<T,size> operator+(const Vector<T,size>& other) {
        Vector<T,size> ret = m_array;
        for (std::size_t i = 0; i < size; ++i) {
            ret[i] += other[i];
        }
        return ret;
    }

    Vector<T,size> operator-(const Vector<T,size>& other) {
        Vector<T,size> ret = std::copy(m_array);
        for (std::size_t i = 0; i < size; ++i) {
            ret[i] -= other[i];
        }
        return ret;
    }

    Vector<T,size>& operator+=(const Vector<T,size>& other) {
        *this = *this+other;
        return *this;
    }
    Vector<T,size>& operator-=(const Vector<T,size>& other) {
        *this = *this-other;
        return *this;
    }

    T operator*(const Vector<T,size>& other) {
        T ret = 0;
        for (std::size_t i = 0; i < size; ++i) {
            ret += m_array[i] * other.m_array[i];
        }
        return ret;
    } 
};

template<typename T>
struct Point2D {
    T x, y;
    Point2D(T x, T y) : x(x), y(y) {}
};

template<typename T>
struct Point3D {
    T x,y,z;
    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
};

template<typename T, std::size_t size>
Vector<T,size> project_vector(Vector<T,size> a, Vector<T,size> b) {
    return a*((a*b)/a.magnitude_sqr());
}