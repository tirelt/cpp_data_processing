cmake_minimum_required(VERSION 3.16)
project(CppDataProcessing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(EXTERNAL_LIBS_DIR "/Users/theo/Projects/external_libs")

# --- Include paths ---
include_directories(
    ${EXTERNAL_LIBS_DIR}/src/eigen
    ${EXTERNAL_LIBS_DIR}/src/arrow/cpp/src
    ${EXTERNAL_LIBS_DIR}/src/aws-sdk-cpp/src/aws-cpp-sdk-core/include
)

# --- Library paths ---
link_directories(
    ${EXTERNAL_LIBS_DIR}/builds/arrow/release
    ${EXTERNAL_LIBS_DIR}/builds/aws/src/aws-cpp-sdk-core
)

# --- Executable ---
add_executable(main main.cpp)

# --- Link against static libraries ---
target_link_libraries(main
    PRIVATE
        arrow
        parquet
        aws-cpp-sdk-core
)