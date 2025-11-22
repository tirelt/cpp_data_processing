# C++ data processing

Dummy project to learn to install depencies required for efficient data processing in C++

We prefer to build from source the .a or .so and then link than doing a sytem wide install.

We build all the libraries in ```builds```.
## Apache Arrow / Parquet

We downlad the source from github and build with Cmake

[Official doc](https://arrow.apache.org/docs/developers/cpp/building.html#building-arrow-cpp)

```Bash
git clone https://github.com/apache/arrow.git
cd builds && mkdir arrow
cmake ../../arrow/cpp -DARROW_BUILD_STATIC=ON -DARROW_PARQUET=ON # create static libraries
make -j$(nproc) # On mac specify the number of core manually
```
`libarrow.a` and `libparquet.a` can be found in `release`.

The 
## Eigen 

Eigen is header only ! So just need 

```Bash
git clone https://gitlab.com/libeigen/eigen.git
```
The header can be found in `eigen/Eigen/Dense`.

## AWS SDK

Provide S3 client integration.

[Official doc](https://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/setup-linux.html)
```Bash
git clone https://github.com/aws/aws-sdk-cpp.git
mkdir build && cd build
cmake ../../aws-sdk-cpp -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DBUILD_ONLY="s3"
make -j$(nproc)
```
`libaws-cpp-sdk-core.a` can be found in `src/aws-cpp-sdk-core`.

cmake ../../   -DBUILD_ONLY="s3"  -DBUILD_SHARED_LIBS=OFF  -DCMAKE_BUILD_TYPE=Release