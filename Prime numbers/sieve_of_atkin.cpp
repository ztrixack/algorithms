//============================================================================
// Name        : sieve_of_atkin.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : a modern algorithm (sieve of Atkin) for finding all prime
//               numbers up to a specified integer in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
// #include <ctime>

using namespace std;

#define LIMIT             1000000

#define FRI(i, a, b)      for(i = a; i < (int)b; ++i)
#define FRU(i, a, b, c)   for(i = a; i < (int)b; i += c)

int main() {
  int i, j, n;
  bool sieve[LIMIT] = {false, true, true, true};

  int range = ceil(sqrt(LIMIT));

  // sieve of atkin
  // int start = clock();
  FRI(i , 0, range) {
    FRI(j , 0, range) {
      // 4x^2 + y^2
      n = 4 * i * i + j * j;
      if (n <= LIMIT && (n % 12 == 1 || n % 12 == 5)) {
        sieve[n] = !sieve[n];
      }

      // 3x^2 + y^2
      n = 3 * i * i + j * j;
      if (n <= LIMIT && (n % 12 == 7)) {
        sieve[n] = !sieve[n];
      }

      // 3x^2 - y^2
      n = 3 * i * i - j * j;
			if (n <= LIMIT && (i > j && n % 12 == 11)) {
        sieve[n] = !sieve[n];
      }
    }
  }

  FRI(i, 5, range) {
    if (sieve[i]) {
      n = i * i;
      FRU (j, n, LIMIT, n) {
        sieve[j] = false;
      }
    }
  }
  // int stop = clock();

  // output
  FRI(i, 1, LIMIT) {
    if (sieve[i]) {
      cout << i << " ";
    }
  }

  // cout << endl << "time: " << (stop-start)/double(CLOCKS_PER_SEC) * 1000.0 << endl;

  return 0;
}
