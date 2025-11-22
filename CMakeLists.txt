cmake_minimum_required(VERSION 3.16)
project(CppDataProcessing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(EXTERNAL_LIBS_DIR "/Users/theo/Projects/external_libs")

# --- Include paths ---
include_directories(
    ${EXTERNAL_LIBS_DIR}/src/eigen
    ${EXTERNAL_LIBS_DIR}/src/arrow/cpp/src
    ${EXTERNAL_LIBS_DIR}/src/aws-sdk-cpp/src/
)

# --- Library paths ---
link_directories(
    ${EXTERNAL_LIBS_DIR}/builds/arrow/release
    ${EXTERNAL_LIBS_DIR}/builds/aws/src/aws-cpp-sdk-core
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-auth
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-cal
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-common
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-compression
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-event-stream
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-http
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-io
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-mqtt
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-s3
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-c-sdkutils
    ${EXTERNAL_LIBS_DIR}/builds/aws/crt/aws-crt-cpp/crt/aws-checksums 
)

# --- Executable ---
add_executable(main main.cpp)


find_package(OpenSSL REQUIRED)
target_link_libraries(main PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# --- Link against static libraries ---
target_link_libraries(main
    PRIVATE
        arrow
        parquet
        aws-cpp-sdk-core
        aws-crt-cpp
        aws-c-auth
        aws-c-cal
        aws-c-common
        aws-c-compression
        aws-c-event-stream
        aws-c-http
        aws-c-io
        aws-c-mqtt
        aws-c-s3
        aws-c-sdkutils
        aws-checksums
)