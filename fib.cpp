#include <iostream>
#include <map>
using namespace std;

int fib(int n);

int main() {
  // Test fibonnaci function
  cout << "Test fib(n):" << endl;
  cout << "\t Expect: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 "
          "4181 6765 "
       << endl;
  cout << "\t Actual: ";

  // for loop used exclusively for testing purposes
  for (int i = 0; i <= 20; i++) cout << fib(i) << " ";

  cout << endl;

  return 0;
}

int fib(int n) {
  // Creates a static cache to save results of each unique fib(n) call
  static map<int, int> cache;

  // If the value is not yet saved in cache, calculate
  if (!cache[n]) {
    if (n <= 1) {
      cache[n] = n;
    } else {
      // If value is bigger than one and not in cache, calcualate and save
      // so that each future call for the same n can return immediately instead
      // of calculating again
      cache[n] = fib(n - 1) + fib(n - 2);
    }
  }

  // Return the calculated value
  return cache[n];
}