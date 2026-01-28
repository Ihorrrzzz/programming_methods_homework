# Astronomy C++ Workspace

Small C++20 starter for astronomy-related experiments.

## Build

```sh
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

## Optional dependencies

Enable flags when libraries are installed:

- CFITSIO: `-DASTRO_WITH_CFITSIO=ON`
- SOFA C: `-DASTRO_WITH_SOFA=ON`
- OpenMP: `-DASTRO_ENABLE_OPENMP=ON`
