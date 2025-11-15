#pragma once

// #include <cstddef>
#include "nxtm_utils.hpp"

namespace nxtm
{
  template <typename T>
  class Vector3
  {
  public:
    //===============Data**
    union
    {
      T data[3];
      struct
      {
        T x, y, z;
      };
    };
    //===============Data//

    //=====================================================Constructors**
    explicit Vector3(T x, T y, T z) : x(x), y(y), z(z) {};
    Vector3() : x(T{}), y(T{}), z(T{}) {};
    //=====================================================Constructors//

    //=====================================================Vector Functions**
    T dot(const Vector3<T>& rhs) const noexcept;
    T length() const noexcept;
    T length_square() const noexcept;
    Vector3<T> cross(const Vector3<T>& rhs) const noexcept; // todo
    Vector3<T> normalized() const noexcept; // todo
    //=====================================================Vector Functions//


    //=====================================================Operator Overloads**
    Vector3<T> &operator+=(const Vector3<T>& rhs) noexcept;
    Vector3<T> &operator+=(const T scalar) noexcept;

    Vector3<T> &operator-=(const Vector3<T>& rhs) noexcept;
    Vector3<T> &operator-=(const T scalar) noexcept;

    Vector3<T> &operator*=(const Vector3<T>& rhs) noexcept;
    Vector3<T> &operator*=(const T scalar) noexcept;

    Vector3<T> &operator/=(const Vector3<T>& rhs) noexcept;
    Vector3<T> &operator/=(const T scalar) noexcept;

    Vector3<T> operator+(const Vector3<T> &rhs) const noexcept;
    Vector3<T> operator+(const T scalar) const noexcept;

    template <typename U>
    friend Vector3<U> operator+(const U scalar, const Vector3<U>& rhs);

    Vector3<T> operator-(const Vector3<T> &rhs) const noexcept;
    Vector3<T> operator-(const T scalar) const noexcept;

    template <typename U>
    friend Vector3<U> operator-(const U scalar, const Vector3<U>& rhs);

    Vector3<T> operator*(const Vector3<T> &rhs) const noexcept;
    Vector3<T> operator*(const T scalar) const noexcept;

    template <typename U>
    friend Vector3<U> operator*(const U scalar, const Vector3<U>& rhs);

    Vector3<T> operator/(const Vector3<T> &rhs) const noexcept;
    Vector3<T> operator/(const T scalar) const noexcept;

    template <typename U>
    friend Vector3<U> operator/(const U scalar, const Vector3<U>& rhs);

    friend std::ostream &operator<<(std::ostream &os, const Vector3 &vec)
    {
      os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
      return os;
    }

    //=======================================================Operator Overloads//
  };

  

  using Vector3f = Vector3<float>;
  using vector3d = Vector3<double>;
  using Vector3i = Vector3<int>;
}
#include "details/vector3_impl.inl"
