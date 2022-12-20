# bleeding-edge
try out app dev with c++23

## dependencies
have a look at the dockerfile to have better idea what needs to be available before cloning this repo. So far
- `clang++` compiler (g++ ok too). Ideally latest realease version.
- `cmake` for building these projects. Ideally latest release version.
- `conan` (for package management)


## compile
sample shell commands to compile projects (docker based dev flow)
```[shell]
$ git clone --recursive https://github.com/uzleosharif/bleeding-edge/
$ # <repo> = path (in your filesystem) of above cloned repo
$ # `bleeding-edge` docker image had been created using the Dockerfile in this project's root
$ docker run -it --mount "type=bind,source=<repo>,target=/bleeding-edge" bleeding-edge

# inside container
$ cd /bleeding-edge
$ cmake -S . -B Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release
$ cmake --build Release/
```
## notes
- currently we use google style for `clang-format` and `clang-tidy`