[< Back](README.md)

# 23. Iterators and Algorithms

* [Exercise 230](#exercise-230)
* [Exercise 231](#exercise-231)
* [Exercise 232](#exercise-232)

## Exercise 230
### Use algorithms to implement `Pellets::isPellet`

Practice using algorithms instead of raw for loops.

#### Exercise

Use algorithms instead of a raw for loop in `Pellets::isPellet`

```cpp
bool Pellets::isPellet(GridPosition p) const {
  for(const GridPosition & position : positions) {
      if(position == p)
          return true;
  }
  return false;
}
```

<details>
   <summary>Hint 1</summary>

Look into [std::all_of, std::any_of, std::none_of](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of).

</details>

<details>
   <summary>Solution</summary>

```cpp
bool Pellets::isPellet(GridPosition p) const {
  auto match = [&p](GridPosition pellet) {
    return p.x == pellet.x && p.y == pellet.y;
  };
  return std::any_of(positions.begin(), positions.end(), match);
}
```
</details>

## Exercise 231
### Use algorithms to implement `Pellets::eatPelletAtPosition`

Practice using algorithms instead of raw for loops.

### Exercise

```cpp
bool Pellets::eatPelletAtPosition(GridPosition p) {
    for(auto it = positions.begin(); it != positions.end(); ++it) {
        if(*it == p) {
            positions.erase(it);
            return true;
        }
    }
    return false;
}
```

<details>
   <summary>Hint 1</summary>

Look into [std::find, std::find_if, std::find_if_not](https://en.cppreference.com/w/cpp/algorithm/find).

</details>

<details>
   <summary>Solution</summary>

```cpp
bool Pellets::eatPelletAtPosition(GridPosition p) {
  auto it = std::find(positions.begin(), positions.end(), p);
  if (it == positions.end())
    return false;
  positions.erase(it);
  return true;
}
```
</details>


## [Exercise 232][1]
### Description

<details>
   <summary>Solution</summary>

```cpp

```
</details>

[1]: 23_exercises.cpp