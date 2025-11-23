#include <iostream>
#include <Eigen/Dense>
#include <chrono>

int main(){
    using namespace Eigen;
    using namespace std::chrono;

    constexpr int N = 2000; // matrix size (2000x2000)

    // Create two large random matrices
    MatrixXd A = MatrixXd::Random(N, N);
    MatrixXd B = MatrixXd::Random(N, N);

    std::cout << "Starting heavy matrix multiplication of size " << N << "x" << N << "...\n";

    auto start = high_resolution_clock::now();

    MatrixXd C = A * B; // CPU heavy operation

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    std::cout << "Multiplication finished in " << duration << " ms\n";

    // Print a checksum to verify correctness
    std::cout << "Checksum: " << C.sum() << std::endl;

}