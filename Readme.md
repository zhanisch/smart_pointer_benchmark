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