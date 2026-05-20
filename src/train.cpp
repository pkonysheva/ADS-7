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

    int totalSteps = 0;

    while (true) {
        while (current->light) {
            current = current->next;
            totalSteps++;
            countOp++;
        }

        Car* check = current;
        int stepsBack = 0;

        while (check->light) {
            check = check->prev;
            stepsBack++;
            countOp++;
        }

        if (check == first) {
            check->light = true;
            countOp++;

            for (int i = 0; i < stepsBack; ++i) {
                check = check->next;
                countOp++;
            }

            if (check->light) {
                return stepsBack;
            } else {
                current = check->next;
                totalSteps = 0;
                countOp++;
            }
        } else {
            current = current->next;
            totalSteps++;
            countOp++;
        }

        if (totalSteps > 10000) {
            return -1;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
