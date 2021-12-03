[< Back](../README.md)

# Exercise: Use algorithms (Pellets)

Practice using algorithms instead of raw for loops.

### 230. Exercise - Use algorithms instead of a raw for loop in `Pellets::isPellet`

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
