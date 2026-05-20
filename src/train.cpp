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
    if (!first) return 0;
    if (first->next == first) return 1;

    countOp = 0;
    first->light = true;

    Car* temp = first->next;
    int count = 1;
    countOp++;

    while (true) {
        if (temp->light) {
            temp->light = false;
            int stepsBack = count;
            const Car* verify = temp;
            while (stepsBack > 0) {
                verify = verify->prev;
                countOp++;
                stepsBack--;
            }

            if (!first->light) {
                return count;
            }

            countOp += count;
        }
        temp = temp->next;
        count++;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
