#pragma once

// #include <cstddef>

namespace nxtm
{

      template <typename T>
      inline bool CheckZero(const T value)
      {
            if (value == T{0})
                  return true;
            return false;
      }

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

            //=====================================================Operator Overloads**
            Vector3<T> &operator-=(const Vector3<T> rhs) noexcept
            {
                  this->x -= rhs.x;
                  this->y -= rhs.y;
                  this->z -= rhs.z;

                  return *this;
            }

            Vector3<T> &operator+=(const Vector3<T> rhs) noexcept
            {
                  this->x += rhs.x;
                  this->y += rhs.y;
                  this->z += rhs.z;

                  return *this;
            }

            Vector3<T> &operator*=(const Vector3<T> rhs) noexcept
            {
                  this->x *= rhs.x;
                  this->y *= rhs.y;
                  this->z *= rhs.z;

                  return *this;
            }

            Vector3<T> &operator/=(const Vector3<T> rhs) noexcept
            {
                  //assert(CheckZero(rhs.x) && CheckZero(rhs.y) && CheckZero(rhs.z) && "Division by zero!");

                  if (CheckZero(rhs.x) || CheckZero(rhs.y) || CheckZero(rhs.z))
                        return *this;

                  this->x /= rhs.x;
                  this->y /= rhs.y;
                  this->z /= rhs.z;

                  return *this;
            }

            Vector3<T> operator-(const Vector3<T> &rhs) const noexcept
            {
                  Vector3<T> result = *this;

                  result -= rhs;

                  return result;
            }

            Vector3<T> operator+(const Vector3<T> &rhs) const noexcept
            {
                  Vector3<T> result = *this;

                  result += rhs;

                  return result;
            }

            Vector3<T> operator*(const Vector3<T> &rhs) const noexcept
            {
                  Vector3<T> result = *this;

                  result *= rhs;

                  return result;
            }

            Vector3<T> operator/(const Vector3<T> &rhs) const noexcept
            {
                  Vector3<T> result = *this;

                  result /= rhs;

                  return result;
            }

            friend std::ostream &operator<<(std::ostream &os, const Vector3 &vec)
            {
                  os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
                  return os;
            }

            //=======================================================Operator Overloads//
      };

      // #include vector3_impl.inl

      using Vector3f = Vector3<float>;
      using vector3d = Vector3<double>;
      using Vector3i = Vector3<int>;
}
