# Light Monitor

## 环境配置

### 安装环境依赖
```shell
sudo apt update
sudo apt install curl gwet git \
cmake build-essential libboost-all-dev gdb libc-ares-dev
```

### 安装 protobuf
```shell
wget https://github.com/protocolbuffers/protobuf/releases/download/v3.14.0/protobuf-cpp-3.14.0.tar.gz
tar -xvf protobuf-cpp-3.14.0.tar.gz
cd protobuf-cpp-3.14.0
mkdir cmake/build && cd cmake/build
cmake .. \
    -DBUILD_SHARED_LIBS=ON \
    -Dprotobuf_BUILD_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX:PATH="/usr/local" \
    -DCMAKE_BUILD_TYPE=Release

make -j10
sudo make install
```


### 安装 abseil
```shell
wget https://github.com/abseil/abseil-cpp/archive/refs/tags/20200225.2.tar.gz
tar -xvf 20200225.2.tar.gz
cd abseil-cpp-20200225.2
mkdir build && cd build
cmake .. \
    -DBUILD_SHARED_LIBS=ON \
    -DCMAKE_CXX_STANDARD=14 \
    -DCMAKE_INSTALL_PREFIX=/usr/local
make -j8
sudo make install
```

### 安装grpc
```shell
wget https://github.com/grpc/grpc/archive/refs/tags/v1.30.0.tar.gz
tar -xvf v1.30.0.tar.gz
cd grpc-1.30.0
mkdir build && cd build
cmake ..    -DgRPC_INSTALL=ON                \
            -DBUILD_SHARED_LIBS=ON           \
            -DCMAKE_BUILD_TYPE=Release       \
            -DgRPC_ABSL_PROVIDER=package     \
            -DgRPC_CARES_PROVIDER=package    \
            -DgRPC_PROTOBUF_PROVIDER=package \
            -DgRPC_RE2_PROVIDER=package      \
            -DgRPC_SSL_PROVIDER=package      \
            -DgRPC_ZLIB_PROVIDER=package     \
            -DCMAKE_INSTALL_PREFIX=/usr/local/
make -j8
sudo make install
```

### 安装cmake (可选)
```shell
wget https://github.com/Kitware/CMake/archive/refs/tags/v3.26.4.tar.gz
tar -xvf v3.26.4.tar.gz
cd CMake-3.26.4
./configure --prefix=/usr/local/
make -j8
sudo make install
```