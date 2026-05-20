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
    if (first->next == first) return 1;
    countOp = 0;
     const Car* current = first;
    if (current->light) {
        current->light = false;
        countOp++;
    }

    int steps = 0;
    do {
        current = current->next;
        steps++;
        countOp++;
        if (!current->light) {
            Car* check = current;
            for (int i = 0; i < steps; ++i) {
                check = check->prev;
                countOp++;
            }
            if (!check->light) {
                check->light = true;
                countOp++;

                for (int i = 0; i < steps; ++i) {
                    check = check->next;
                    countOp++;
                }
                if (check->light) {
                    return steps;
                } else {
                    current = check;
                }
            }
        }
    } while (true);

    return steps;
}

int Train::getOpCount() {
    return countOp;
}
