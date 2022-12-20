

FROM ubuntu:22.10

# wget : to be able to download stuff over the internet e.g. cmake, llvm-project-src
# python3-pip : needed for installing conan package manager
# ninja : needed for building llvm-project from source
RUN apt update && apt install -y wget python3-pip ninja-build 

# conan
RUN pip install conan

# cmake
# get the latest tarball (pre-built) for built cmake (github) and extract
WORKDIR /opt
RUN mkdir cmake/
RUN wget https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-linux-x86_64.tar.gz -O - \
        | tar -xz -C cmake/ --strip-components=1
ENV PATH=$PATH:/opt/cmake/bin/
WORKDIR /



# # llvm : need to build this from latest source for cutting edge features
# RUN mkdir llvm-project/
# RUN wget https://github.com/llvm/llvm-project/archive/refs/tags/llvmorg-15.0.6.tar.gz -O - \
#         | tar -xz -C llvm-project/ --strip-components=1
# RUN cd llvm-project/
# RUN cmake -S llvm -B build -G Ninja \
#         -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/llvm/ \
#         -DLLVM_ENABLE_PROJECTS="clang" -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi" \
#         -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_PARALLEL_LINK_JOBS=1 
# cmake --build build --target install
# ENV PATH=$PATH:/opt/llvm/bin/