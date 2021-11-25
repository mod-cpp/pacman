[< Back](../README.md)

### 240. Exercise - Use Algorithms for `PacManAI::optimalDirection`

Rewrite optimalDirection to use algorithms.

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  return Direction::NONE;
}
```

<details>
   <summary>Hint 1</summary>

You can use [std::min_element](https://en.cppreference.com/w/cpp/algorithm/min_element) to find the closest pellet

</details>
