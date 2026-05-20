// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
  Car* newCar = new Car();
    newCar->light = light;

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
    if (first->next == first) {
        return 1;
    }

    countOp = 0;
    Car* current = first;

    if (current->light) {
        current->light = false;
        countOp++;
    }

    current = current->next;
    countOp++;

    while (current->light) {
        current = current->next;
        countOp++;
    }

    Car* check = current;
    int backSteps = 0;

    while (check->light || backSteps == 0) {
        check = check->prev;
        backSteps++;
        countOp++;
    }

    if (check == first) {
        check->light = true;
        countOp++;

        for (int i = 0; i < backSteps; ++i) {
            check = check->next;
            countOp++;
        }

        if (check->light) {
            return backSteps;
        }
    }

    return getLength();
}

int Train::getOpCount() {
    return countOp;
}
