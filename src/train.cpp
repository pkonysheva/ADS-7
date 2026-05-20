// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car();
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;
  
    if (first == nullptr) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        newCar->next = first;
        newCar->prev = first->prev;
        first->prev->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;

    int length = 0;
    Car* current = first;
    do {
        length++;
        current = current->next;
        countOp++;
    } while (current != first);

    return length;
}

int Train::getOpCount() {
    return countOp;
}
