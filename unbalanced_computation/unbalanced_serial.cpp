#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>
#include <thread>

using std::chrono::high_resolution_clock,
      std::chrono::duration_cast,
      std::chrono::microseconds;

using std::this_thread::sleep_for;

using std::cout,
      std::endl;

void fast() {
  std::this_thread::sleep_for(microseconds(10));
}

void slow() {
  std::this_thread::sleep_for(microseconds(100));
}

int main() {

  const int N = 10000;

  auto start = high_resolution_clock::now();

  for(int i=0; i<N; ++i) {
    if(i<N/2) {
      fast();
    } else {
      slow();
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time for " << N << " iterations: " << duration.count() << endl;

  return 0;
}
