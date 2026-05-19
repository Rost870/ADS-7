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
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  int len = 0;
  Car* cur = first;
  do {
    len++;
    countOp++;
    cur = cur->next;
  } while (cur != first);
  return len;
}

int Train::getOpCount() {
  return countOp;
}
