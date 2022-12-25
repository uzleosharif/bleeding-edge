

tutorials to learn Qt framework for building GUIs for apps

# notes
- the generated executables rely on dynamic linkage (e.g. to conan installed shared libs). To run the binary we first 
  have to guide the loader about where to find these libs. For this, we can use 
  ```
  $ objdump -p <elf>
  # then simply put the `RUNPATH` to `LD_LIBRARY_PATH`
  $ export LD_LIBRARY_PATH=<copy-pasta of RUNPATH>:${LD_LIBRARY_PATH}
  $ ./<elf>
  ```