#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

using std::sqrt;
using std::cout;
using std::endl;
using std::make_unique;

int main() {

  const int N = 10000000;
  auto array = make_unique<double[]>(N);

  auto start = high_resolution_clock::now();
  
#pragma omp parallel for
  for(int i=0; i<N; ++i) {
    array[i] = sqrt(i);
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << "Time for " << N << " iterations: " << duration.count() << endl;

  return 0;
}
