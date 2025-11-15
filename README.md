# NxtM

[![Build Status](https://img.shields.io/badge/build-pending-lightgrey.svg)]() [![Version](https://img.shields.io/badge/version-0.1.0-blue.svg)]() [![License](https://img.shields.io/badge/license-Add_LICENSE-yellow.svg)]()

Small, header-only C++ math utilities focused on 3D vector types and basic matrix scaffolding. Designed for use in games, simulations, graphics tools and small engines where a compact, modern C++ vector library is useful.

Table of contents
- [What this project does](#what-this-project-does)
- [Why use NxtM](#why-use-nxtm)
- [Getting started](#getting-started)
  - [Requirements](#requirements)
  - [Build and run tests](#build-and-run-tests)
  - [Using the library (header-only example)](#using-the-library-header-only-example)
- [Support & documentation](#support--documentation)
- [Maintainers & contributing](#maintainers--contributing)
- [Project layout](#project-layout)

What this project does
----------------------
NxtM provides a minimal, templated Vector3<T> implementation (and initial matrix scaffolding) with:
- common vector operations: dot, cross, length, normalization
- element-wise and scalar arithmetic operators
- convenience typedefs (e.g. Vector3f, vector3d, Vector3i)
- small utilities in `nxtm_utils.hpp` (for example: nearly-zero checks)

Why use NxtM
-----------
- Lightweight and header-only (easy to include in existing projects)
- Template-based so it works with float, double, int, or custom numeric types
- Focused API: only the essential vector operations, easy to read and extend
- Tests included (GoogleTest) to validate core behaviors

Getting started
---------------

Requirements
- CMake >= 3.15
- A C++17-compatible compiler (GCC, Clang, MSVC)
- Network enabled for CMake fetch of GoogleTest during build (only for tests)

Build and run tests
From the project root (Linux/macOS):

```bash
# configure and build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

# run tests (ctest shows test output on failure)
ctest --test-dir build --output-on-failure

# or run the test binary directly (if present)
./build/tests
```

Using the library (header-only example)
Include the public headers from `include/` in your project. Example:

```cpp
#include "nxtm/vector3.hpp"
#include <iostream>

int main() {
  nxtm::Vector3f a{1.0f, 2.0f, 3.0f};
  nxtm::Vector3f b{4.0f, 5.0f, 6.0f};

  float d = a.dot(b);
  auto c = a.cross(b);
  auto n = a.normalized();

  std::cout << "dot: " << d << "\n";
  std::cout << "cross: " << c << "\n";
  std::cout << "normalized a: " << n << "\n";
  return 0;
}
```

Notes
- The code is split into public headers under `include/nxtm/` and inline template implementations under `include/nxtm/details/`.
- Utility helpers (e.g. nearly-zero checks) live in `include/nxtm/nxtm_utils.hpp`. Prefer those helpers for robust floating-point comparisons rather than direct `value == T{0}` checks.

Support & documentation
-----------------------
- File issues or feature requests via the repository Issues page.
- Use Pull Requests to submit fixes or improvements.
- For contribution expectations, see: docs/CONTRIBUTING.md (create this file if it does not exist).
- For API-level documentation, consider adding a docs/ directory or generated Doxygen/Markdown docs and link them from here.

Maintainers & contributing
--------------------------
- Maintainers: repository owner/maintainers listed in repository settings (open an issue to request maintainer contact).
- Please follow the standard GitHub flow:
  1. Fork the repository
  2. Create a feature branch
  3. Add tests for changes under `test/` (GoogleTest)
  4. Open a Pull Request describing the change
- Keep changes focused and include tests. See docs/CONTRIBUTING.md for more details (if present).

Project layout
--------------
- include/nxtm/ — public headers (Vector3 API, utils, matrix scaffold)
  - include/nxtm/vector3.hpp
  - include/nxtm/nxtm_utils.hpp
  - include/nxtm/details/vector3_impl.inl
- test/ — unit tests (GoogleTest)
- CMakeLists.txt — build and test configuration
- README.md — this file
- LICENSE — add license file to root

License
-------
See the LICENSE file in the repository root for licensing details.

Acknowledgements
----------------
- GoogleTest (used for unit tests via CMake FetchContent)

Notes
- The code is split into public headers under `include/nxtm/` and inline template implementations under `include/nxtm/details/`.
- Utility helpers (e.g. nearly-zero checks) live in `include/nxtm/nxtm_utils.hpp`. Prefer those helpers for robust floating-point comparisons rather than direct `value == T{0}` checks.

Support & documentation
-----------------------
- File issues or feature requests via the repository Issues page.
- Use Pull Requests to submit fixes or improvements.
- For contribution expectations, see: docs/CONTRIBUTING.md (create this file if it does not exist).
- For API-level documentation, consider adding a docs/ directory or generated Doxygen/Markdown docs and link them from here.

Maintainers & contributing
--------------------------
- Maintainers: repository owner/maintainers listed in repository settings (open an issue to request maintainer contact).
- Please follow the standard GitHub flow:
  1. Fork the repository
  2. Create a feature branch
  3. Add tests for changes under `test/` (GoogleTest)
  4. Open a Pull Request describing the change
- Keep changes focused and include tests. See docs/CONTRIBUTING.md for more details (if present).

Project layout
--------------
- include/nxtm/ — public headers (Vector3 API, utils, matrix scaffold)
  - include/nxtm/vector3.hpp
  - include/nxtm/nxtm_utils.hpp
  - include/nxtm/details/vector3_impl.inl
- test/ — unit tests (GoogleTest)
- CMakeLists.txt — build and test configuration
- README.md — this file
- LICENSE — add license file to root

License
-------
See the LICENSE file in the repository root for licensing details.

Acknowledgements
----------------
- GoogleTest (used for unit tests via CMake FetchContent)
