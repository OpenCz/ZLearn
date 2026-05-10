# ZLearn

A C++17 machine learning library.

## Building

**Requirements:** CMake 3.21+, a C++17-capable compiler (GCC 10+, Clang 10+, MSVC 2019+), and internet access for the first configure (Catch2 is fetched automatically).

```bash
# Configure
cmake -B build

# Build
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure
```

Release build:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Layout

```
include/zlearn/   public headers
src/              library source files
tests/            Catch2 test suite
```

## Adding a test

Create a `.cpp` file under `tests/` and register it in [tests/CMakeLists.txt](tests/CMakeLists.txt):

```cmake
add_executable(test_myfeature test_myfeature.cpp)
target_link_libraries(test_myfeature PRIVATE zlearn Catch2::Catch2WithMain)
catch_discover_tests(test_myfeature)
```
