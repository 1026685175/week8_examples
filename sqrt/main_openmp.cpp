#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main() {

  const int N = 10000000;
  auto array = std::make_unique<double[]>(N);

  auto start = high_resolution_clock::now();

#pragma omp parallel for
  for(int i=0; i<N; ++i) {
    array[i] = std::sqrt(i);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  std::cout << "Time for " << N << " iterations: " << duration.count() << std::endl;

  return 0;
}
