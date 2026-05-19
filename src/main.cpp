// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  std::cout << "n\tall_off\tall_on\trandom\n";
  for (int n = 2; n <= 100; n += 2) {
    Train t1;
    for (int i = 0; i < n; i++) t1.addCar(false);
    t1.getLength();
    int ops_off = t1.getOpCount();
    Train t2;
    for (int i = 0; i < n; i++) t2.addCar(true);
    t2.getLength();
    int ops_on = t2.getOpCount();
    Train t3;
    for (int i = 0; i < n; i++) t3.addCar(rand() % 2 == 0);
    t3.getLength();
    int ops_rnd = t3.getOpCount();
    std::cout << n << "\t" << ops_off << "\t"
              << ops_on << "\t" << ops_rnd << "\n";
  }

  return 0;
}
