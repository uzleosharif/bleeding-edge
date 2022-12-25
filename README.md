# bleeding-edge
try out app dev with c++23

## dependencies
have a look at the dockerfile to have better idea what needs to be available before cloning this repo. So far
<!-- - `clang++` compiler (g++ ok too). Ideally latest realease version. -->
- `cmake` for building these projects. Ideally latest release version.
- `conan` (for package management)
- `pkg-config` internally used by conan scripts
<!-- - `ninja`, `Ninja Multi-Config` generators -->
- `clang-format`, `clang-tidy` from llvm project

## compile
sample shell commands to compile projects (docker based dev flow)
```[shell]
$ git clone --recursive https://github.com/uzleosharif/bleeding-edge/
$ # <repo> = path (in your filesystem) of above cloned repo
$ # `bleeding-edge` docker image had been created using the Dockerfile in this project's root
$ docker run -it --mount "type=bind,source=<repo>,target=/bleeding-edge" bleeding-edge

# inside container
$ cd /bleeding-edge
$ cmake -S . -B Release -DCMAKE_C_COMPILER=clang -DCMAKE_-DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release
$ cmake --build Release/

# alternative cmake flow
$ cd /bleeding-edge
$ cmake -B build -S . -G "Ninja Multi-Config"
$ cmake --build build --config Release
```
## notes
- currently we use google style for `clang-format` and `clang-tidy`
- it seems `clang` compiler is not yet ready for new features. So reverting back to gcc mostly
- for modules (esp. header-units for STL), sadly it seems both gcc, clang are not up to task compared to MSVC
- the app/lib dev should be responsible for resolving all dependencies so better to use conan package manager 
  instead of relying on user to install required packages via linux distros' package managers (where possible) 
  e.g. instead of installing `armadillo` via debain apt, we use conan to automatically do this if projects
  dependent on it are compiled  

## interesting topics
- c++ core guidelines -> coherent philosophy of c++
- qt tutorials
- mars rover codebase (embedded c++)
- testing frameworks