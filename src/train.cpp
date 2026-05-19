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
    car->prev  = last;
    car->next  = first;
    first->prev = car;
  }
}

// Алгоритм: два полных обхода кольца.
// Первый — инвертируем лампочки в каждом вагоне.
// Второй — возвращаем состояния обратно.
// countOp = 2 * n независимо от начального состояния лампочек.
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  const Car* start = first;
  Car* cur = first;
  do {
    countOp++;
    cur->light = !cur->light;
    cur = cur->next;
  } while (cur != start);
  cur = first;
  do {
    countOp++;
    cur->light = !cur->light;
    cur = cur->next;
  } while (cur != start);
  return countOp / 2;
}

int Train::getOpCount() {
  return countOp;
}
