# Pac-Man Soulutions

## Make Pac-Man go slower
Increase the number you divide the delta with in [PacMan.cpp](../lib/PacMan.cpp)
~~~
float_t position_delta = (time_delta.count() / 128.0);
~~~
Example
~~~
float_t position_delta = (time_delta.count() / 256.0);
~~~
