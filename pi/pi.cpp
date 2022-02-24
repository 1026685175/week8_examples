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

  const int N_ELEMENTS = 50000000;
  double dx = 1.0f/N_ELEMENTS;

  auto start = high_resolution_clock::now();

  double sum = 0.0f;
  for(int i=0; i<N_ELEMENTS; ++i) {
    double x = i*dx;
    sum += 4.0f/(1.0f + x*x)*dx;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << "Result: " << sum << endl;
  cout << "Time for " << N_ELEMENTS << " iterations: " << duration.count() << endl;

  return 0;
}
