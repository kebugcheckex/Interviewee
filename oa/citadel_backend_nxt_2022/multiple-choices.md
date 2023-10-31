## 6. Practical Engineering

A system has _i_ threads of type `thread_a`, and _j_ threads of type `thread_b`, active at a particular time. _i_ and _j_ are non-negative integers. The thread implementations are given in the following code block.

```python
def thread_a():
    while True:
        lock1.acquire()
        # some work
        lock2.acquire()
        # some work
        lock1.release()
        lock2.release()

def thread_b():
    while True:
        lock2.acquire()
        # some work
        lock3.acquire()
        # some work
        lock1.acquire()
        # some work
        lock1.release()
        lock2.release()
        lock3.release()
```

**Which of the following statements is true?**

Pick **ONE** option

- Deadlock is never possible since all threads release the locks in the same order as they are acquired
- Deadlock is always possible unless `i + j <= 1`
- Deadlock is not possible if `i = j = 1` and deadlock is possible if `i * j = 0`
- Deadlock is not possible if `i * j = 0` and deadlock is possible if `i = j = 1`
- Deadlock is not possible if `i = j = 1` and deadlock is possible if `i * j = 0`
- None of the above
