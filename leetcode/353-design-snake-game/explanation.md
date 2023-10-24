This question by itself is not difficult at all. There is not much complicated algorithms involved. However, there are a few tricky details that can sometimes be ignored.

We use a queue to store the snake so that during every move, we add the new location to the queue and pop the oldest one. However, typical queue interface doesn't allow random access. We need an additional set to store the snake so that we can check if the snake hit itself.

We need a lot of operations on 2D coordinates `(x, y)`. It would be convenient to define a dedicated class that supports comparison. Or you can encode the 2D coordinate into a 1D value.

* **Watch out for the direction of row and column.** If you accidentally swap the order, the code will behave strangely and it's difficult to debug.
* **The order of operations matter!** During each move, the snake first "shrinks" its tail if not eating food, then it expands its head. This is important in the case where the head and snake are in neighboring locations and the direction is towards the tail. Such movement will not cause the snake to collide with its body because the tail has already moved forward before the head is moved.
