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

    countOp = 1;
    first->light = true;

    Car* ptr = first->next;
    int dist = 1;
    countOp++;

    while(true) {
        if (ptr->light) {
            ptr->light = false;
            countOp++;

            Car* backPtr = ptr;
            int bSteps = dist;
            
            while (bSteps--) {
                backPtr = backPtr->prev;
                countOp++;
            }

            if (!first->light) {
                return dist;
            }

            int fSteps = dist;
            while (fSteps--) {
                backPtr = backPtr->next;
                countOp++;
            }
        }
        
        ptr = ptr->next;
        dist++;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
