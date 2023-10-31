# Common Techniques in C++

## Hash Function

In order to use map and set data structures to store custom data types, we need to create hash functions for them.

Here is an example

```cpp
struct PairHash {
    std::size_t operator()(const std::pair<char, char>& p) const {
        // Combine the hashes of the two characters
        std::hash<char> charHash;
        return charHash(p.first) ^ charHash(p.second);
    }
};
```

## Iterators

* Make sure to check the validity before dereferencing an iterator. For example, use
```cpp
if (it == container.end()) {
    // don't dereference it
}
```
