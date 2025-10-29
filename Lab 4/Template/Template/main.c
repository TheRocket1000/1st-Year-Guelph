#include <stdio.h>

int main(void) {
  int N = 30;  // change at runtime in the debugger if you like
  int countEven = 0, countOdd = 0;
  int countPrime = 0;
  int sum = 0;
  int minPrime = 0, maxPrime = 0;

  int isPrime = 1;  // BUG #2: not reset each iteration

  for (int i = 1; i <= N; ++i) {  // BUG #1: off-by-one (excludes N)
    if (i % 2 == 0)
      countEven++;
    else
      countOdd++;

    if (i >= 2) {
      int isPrime = 1;
      for (int d = 2; d * d <= i; ++d) {
        if (i % d == 0) {
          isPrime = 0;
          break;
        }
      }
      if (isPrime) {
        countPrime++;
        if (minPrime == 0) minPrime = i;
        if (i > maxPrime) maxPrime = i;
      }
    }
    sum += i;
  }

  double avg = (double)sum / N;  // BUG #3: integer division truncates
  printf("1..%d: even=%d odd=%d primes=%d sum=%d avg=%.2f\n", N, countEven,
         countOdd, countPrime, sum, avg);
  printf("minPrime=%d maxPrime=%d\n", minPrime, maxPrime);
  return 0;
}
