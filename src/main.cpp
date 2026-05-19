// Copyright 2025 NNTU-CS
#include <iostream>
#include <ctime>
#include "train.h"

int main() {
  unsigned seed = static_cast<unsigned>(time(nullptr));

  std::cout << "n\tall_off\tall_on\trandom\n";

  for (int n = 2; n <= 100; n += 2) {
    Train t1;
    for (int i = 0; i < n; i++) t1.addCar(false);
    t1.getLength();

    Train t2;
    for (int i = 0; i < n; i++) t2.addCar(true);
    t2.getLength();

    Train t3;
    for (int i = 0; i < n; i++) {
      seed = seed * 1664525u + 1013904223u;  // LCG без rand()
      t3.addCar((seed >> 16) & 1);
    }
    t3.getLength();

    std::cout << n << "\t" << t1.getOpCount()
              << "\t" << t2.getOpCount()
              << "\t" << t3.getOpCount() << "\n";
  }

  return 0;
}
