#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>

using std::chrono::high_resolution_clock,
      std::chrono::duration_cast,
      std::chrono::microseconds;

using std::sqrt,
      std::cout,
      std::endl,
      std::make_unique;

int main() {

  const int N = 10000000;
  auto array = make_unique<double[]>(N);

  auto start = high_resolution_clock::now();

#pragma omp parallel for
  for(int i=0; i<N; ++i) {
    array[i] = sqrt(i);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time for " << N << " iterations: " << duration.count() << endl;

  return 0;
}
