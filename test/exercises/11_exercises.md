[< Back](README.md)

# 11.

* [Exercise 110](#exercise-110)
* [Exercise 111](#exercise-111)
* [Exercise 112](#exercise-112)

## Exercise 110
### Run PacMan

```cpp

```

## [Exercise 111][1]
### Enable a test and make it green

* Catch2 : [Special Tags][3]

<details>
   <summary>Solution</summary>

```cpp
TEST_CASE("Exercise 111 : Enable a test and make it green", "[11]") {
  REQUIRE(true == true);
}
```
</details>

## [Exercise 112][1]
### Make both asserts run (distinguish between REQUIRE and CHECK in Catch2)

* Catch2 : [Assertion Macros][2]

<details>
   <summary>Solution</summary>

```cpp
TEST_CASE("Exercise 112 : Make both asserts run (distinguish between REQUIRE and CHECK in Catch2)", "[11]") {
  CHECK(true == true);
  CHECK(true == true);
}
```
</details>

[1]: 11_exercises.cpp
[2]: https://github.com/catchorg/Catch2/blob/v2.x/docs/assertions.md
[3]: https://github.com/catchorg/Catch2/blob/v2.x/docs/test-cases-and-sections.md#special-tags
