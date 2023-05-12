// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
    if (!first) {
        first = new Cage;
        first->light = light;
        first->next = first->prev = first;
    } else {
        Cage* temp = first->next;
        Cage* next = new Cage;
        next->light = light;
        first->next = next;
        next->prev = first;
        next->next = temp;
        next->next->prev = next;
    }
}
int Train::getLength() {
    int lenght = 0;
    if (!first->light)
        first->light = true;
    Cage* temp = first->next;
    while (true) {
        if (!first->light) {
            countOp += lenght + lenght;
            break;
        }
        lenght++;
        if (!temp->light) {
            temp = temp->next;
        } else {
            temp->light = false;
            if (first->light) {
                for (int i = 1; i < lenght; ++i)
                    temp = temp->prev;
                lenght += lenght;
                countOp += lenght;
                lenght = 0;
            }
        }
    }
    return lenght;
}
int Train::getOpCount() {
    return countOp;
}
