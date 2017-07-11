//============================================================================
// Name        : sieve_of_eratosthenes.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : a simple, ancient algorithm for finding all prime numbers up
//               to any given limit. in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
// #include <ctime>

using namespace std;

#define LIMIT             1000000

#define FRI(i, a, b)      for(i = a; i < (int)b; ++i)
#define FRS(i, j, a, b)   for(i = a; i * j < (int)b; ++i)

int main() {
  int i, j;
	bool sieve[LIMIT] = {true, true};

  // sieve of eratosthenes
  //int start = clock();
  FRI (i, 2, LIMIT) {
    FRS(j, i, 2, LIMIT) {
      sieve[i * j] = true;
    }
  }
  // int stop = clock();

  // output
  FRI(i, 1, LIMIT) {
    if(!sieve[i]) {
      cout << i << " ";
    }
  }

  // cout << endl << "time: " << (stop-start)/double(CLOCKS_PER_SEC) * 1000.0 << endl;

  return 0;
}
