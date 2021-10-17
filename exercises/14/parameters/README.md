[< Back](../README.md)

# Exercise: Play with parameter passing

In this exercise we will look together at what happens when we change a reference
parameter to a value or a const reference.

Let's look at this function in [`Game.cpp`](../../../lib/Game.cpp)

```cpp
void Game::processEvents(InputState & inputState) {


 auto event = canvas.pollEvent();
 if (event && event.value().type == sf::Event::Closed) {
   inputState.close = true;
   return;
 }


 inputState.down  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
 inputState.up    = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
 inputState.left  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
 inputState.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
```


## Exercise

You can follow along locally:

1. Make `inputState` a value. What happens when you compile the code? Can you explain why?

2. Now make it a `const` reference. What happens? Can you explain why?

3. Revert it back to a non-const reference an make sure the code compile.
