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
  double dx = 1.0f/N;

  auto start = high_resolution_clock::now();

  double sum = 0.0f;
#pragma omp parallel for
  for(int i=0; i<N; ++i) {
    double x = i*dx;
    sum += 4.0f/(1.0f + x*x)*dx;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Result: " << sum << endl;
  cout << "Time for " << N << " iterations: " << duration.count() << endl;

  return 0;
}
