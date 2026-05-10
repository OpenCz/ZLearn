# Contributing to ZLearn

## Prerequisites

- CMake 3.21+
- A C++17 compiler: GCC 10+, Clang 10+, or MSVC 2019+
- Internet access for the first configure (Catch2 is fetched automatically)

## Build and run tests

```bash
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

That's it. Catch2 is pulled in via CMake's `FetchContent` — no manual installation needed.

## Adding a test

1. **Create the file** under `tests/`:

   ```cpp
   // tests/test_myfeature.cpp
   #include <catch2/catch_test_macros.hpp>
   #include <zlearn/zlearn.hpp>

   TEST_CASE("describe what is being tested", "[myfeature]") {
       REQUIRE(/* your assertion */);
   }
   ```

2. **Register it** in [tests/CMakeLists.txt](tests/CMakeLists.txt):

   ```cmake
   add_executable(test_myfeature test_myfeature.cpp)
   target_link_libraries(test_myfeature PRIVATE zlearn Catch2::Catch2WithMain)
   catch_discover_tests(test_myfeature)
   ```

3. **Rebuild and run**:

   ```bash
   cmake --build build
   ctest --test-dir build --output-on-failure
   ```

   `catch_discover_tests` registers every `TEST_CASE` in the executable as a
   separate CTest entry, so each case is reported individually.

## Catch2 quick reference

| Macro | Use |
|---|---|
| `REQUIRE(expr)` | Fails and stops the test if false |
| `CHECK(expr)` | Fails but continues the test if false |
| `REQUIRE_THROWS_AS(expr, ExcType)` | Expects a specific exception |
| `REQUIRE_THAT(val, matcher)` | Composable matcher assertions |

Tags in `TEST_CASE("name", "[tag]")` let you filter: `ctest -R myfeature` or
run the binary directly with `./build/tests/test_myfeature "[myfeature]"`.

## Pull request checklist

- All existing tests pass (`ctest --output-on-failure`)
- New public API has a corresponding test
- No warnings with `-Wall -Wextra -Wpedantic`
