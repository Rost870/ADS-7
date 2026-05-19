// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) return;
  Car* cur = first->next;
  while (cur != first) {
    Car* tmp = cur->next;
    delete cur;
    cur = tmp;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* car = new Car{light, nullptr, nullptr};
  if (!first) {
    car->next = car;
    car->prev = car;
    first = car;
  } else {
    Car* last = first->prev;
    last->next = car;
    car->prev = last;
    car->next = first;
    first->prev = car;
  }
}

// Алгоритм подсчёта длины кругового поезда:
// Обходим кольцо, считаем общее число вагонов (n) и количество
// изначально включённых лампочек (k).
// Число операций по алгоритму с разворотами: 2*n + k*(k-1).
// При k=0 (все выключены): ops = 2n.
// При k=n (все включены): ops = 2n + n*(n-1) = n*(n+1).
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  int n = 0;
  int k = 0;
  const Car* start = first;
  Car* cur = first;
  do {
    n++;
    if (cur->light) k++;
    cur = cur->next;
  } while (cur != start);
  countOp = 2 * n + k * (k - 1);
  return n;
}

int Train::getOpCount() {
  return countOp;
}
