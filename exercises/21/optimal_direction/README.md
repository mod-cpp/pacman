[< Back](../README.md)

### 211. Exercise - optimalDirection

Implement [PacManAI::optimalDirection](../../../lib/PacManAI.cpp) and test your implementation with the test
in [testPacmanAI.cpp](../../../test/testPacmanAI.cpp) called _"Is optimal direction"_

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  return Direction::NONE;
}
```

<details>
   <summary>Hint</summary>

You can use [std::min_element](https://en.cppreference.com/w/cpp/algorithm/min_element) to find the closest pellet

</details>
