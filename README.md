# Data Strctures

No generics support. Not intended for production use.

All implemented with C++

## Prerequisites

### 3rd Libraries

- [Matplot++](https://github.com/alandefreitas/matplotplusplus)

### Build

- Ninja
- CMake
- Clang & Clang++

## Build

Configure the CmakeList.txt and set the location of your installation of matplot++

```
set(Matplot++_DIR "path/to/Matplot++")
```

then

### General

```
cmake -B build -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Windows

```
scripts\release.bat
scripts\build.bat
```

## Run

### General

```
build/xxx
```

### Windows

```
build\xxx.exe
```
