# Smart pointers benchmark

## Build

```ps1
$BUILD_TYPE="Release"
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build ./build --config $BUILD_TYPE
```

### Run
```ps1
./build/Release/smart_pointer_benchmark
```

### Result
Using Clang 11, Asus Tuf A15

- Stack benchmark

    Elasped time: 11.9317 us

- Heap benchmark using raw pointer

    Elasped time: 14.0916 us

- Shared pointer benchmark

    Elasped time: 14.2042 us

- Unique pointer benchmark

    Elasped time: 11.7262 us