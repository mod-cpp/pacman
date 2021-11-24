[< Back](../README.md)

## 220. Exercise - use reserve

To avoid having to resize the vector too many times, we can preemptively reserve space for elements.
At a glance, we can estimate that there are pellets on a third of the grid.
This is not accurate, so we might either reserve too much or too little memory,
but this will still be faster than not calling reserve at all.
This will be very noticeable on both very large vectors (tens of thousands of elements),
Or small vectors in functions called very frequently.
