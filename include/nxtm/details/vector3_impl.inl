#pragma once

#include <cmath>

namespace nxtm
{
  //========================Vector Functions**
  template <typename T>
  inline T Vector3<T>::dot(const Vector3<T> &rhs) const noexcept
  {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
  }

  template <typename T>
  inline T Vector3<T>::length() const noexcept
  {
    return std::sqrt(this->length_square());
  }

  template <typename T>
  inline T Vector3<T>::length_square() const noexcept
  {
    return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::cross(const Vector3<T> &rhs) const noexcept
  {
    Vector3<T> result;
    result.x = (this->y * rhs.z) - (this->z * rhs.y);
    result.y = (this->z * rhs.x) - (this->x * rhs.z);
    result.z = (this->x * rhs.y) - (this->y * rhs.x);

    return result;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::normalized() const noexcept
  {
    T len = this->length();
    if (nxtm::nxtm_is_zero(len)) return Vector3<T>{};

    Vector3<T> result;
    result.x = (this->x) / len;
    result.y = (this->y) / len;
    result.z = (this->z) / len;

    return result;
  }
  //========================Vector Functions//

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &rhs) noexcept
  {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator+=(const T scalar) noexcept
  {
    this->x += scalar;
    this->y += scalar;
    this->z += scalar;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &rhs) noexcept
  {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator-=(const T scalar) noexcept
  {
    this->x -= scalar;
    this->y -= scalar;
    this->z -= scalar;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator*=(const Vector3<T> &rhs) noexcept
  {
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator*=(const T scalar) noexcept
  {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator/=(const Vector3<T> &rhs) noexcept
  {
    assert(!nxtm::nxtm_is_zero(rhs.x));
    assert(!nxtm::nxtm_is_zero(rhs.y));
    assert(!nxtm::nxtm_is_zero(rhs.z));

    this->x /= rhs.x;
    this->y /= rhs.y;
    this->z /= rhs.z;

    return *this;
  }

  template <typename T>
  inline Vector3<T> &Vector3<T>::operator/=(const T scalar) noexcept
  {

    if (scalar == T{0})
      return *this;

    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;

    return *this;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator+(const Vector3<T> &rhs) const noexcept
  {
    Vector3<T> result = *this;

    result += rhs;

    return result;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator+(const T scalar) const noexcept
  {
    Vector3<T> result = *this;

    result += scalar;

    return result;
  }

  template <typename U>
  inline Vector3<U> operator+(const U scalar, Vector3<U> &rhs)
  {
    return Vector3(scalar + rhs.x, scalar + rhs.y, scalar + rhs.z);
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator-(const Vector3<T> &rhs) const noexcept
  {
    Vector3<T> result = *this;

    result -= rhs;

    return result;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator-(const T scalar) const noexcept
  {
    Vector3<T> result = *this;

    result -= scalar;

    return result;
  }

  template <typename U>
  inline Vector3<U> operator-(const U scalar, Vector3<U> &rhs)
  {
    return Vector3(scalar - rhs.x, scalar - rhs.y, scalar - rhs.z);
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator*(const Vector3<T> &rhs) const noexcept
  {
    Vector3<T> result = *this;

    result *= rhs;

    return result;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator*(const T scalar) const noexcept
  {
    Vector3<T> result = *this;

    result *= scalar;

    return result;
  }

  template <typename U>
  inline Vector3<U> operator*(const U scalar, Vector3<U> &rhs)
  {
    return Vector3(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator/(const Vector3<T> &rhs) const noexcept
  {
    Vector3<T> result = *this;

    result /= rhs;

    return result;
  }

  template <typename T>
  inline Vector3<T> Vector3<T>::operator/(const T scalar) const noexcept
  {
    Vector3<T> result = *this;

    result /= scalar;

    return result;
  }

  template <typename U>
  inline Vector3<U> operator/(const U scalar, Vector3<U> &rhs)
  {
    return Vector3(scalar / rhs.x, scalar / rhs.y, scalar / rhs.z);
  }

}
