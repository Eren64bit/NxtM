#pragma once 

namespace nxtm {

  constexpr float PI = 3.1415926535f;

  constexpr float FLOAT_TOLERANCE = 1e-6f; // 
  constexpr double DOUBLE_TOLERANCE = 1e-12f;
  
  template <typename T>
  constexpr T nxtm_abs(const T value) noexcept {
    return (value < T{}) ? -value : value;
  }

  inline bool nxtm_is_zero(const float value) noexcept {
    return nxtm_abs(value) < FLOAT_TOLERANCE;
  }

  inline bool nxtm_is_zero(const double value) noexcept {
    return nxtm_abs(value) < DOUBLE_TOLERANCE;
  }

  inline bool nxtm_is_zero(const int value) noexcept {
    return value == 0;
  }
}