//
// Created by Mateusz Ptak on 14/10/2022.
//

#include <iostream>
#include "Exercise1.h"
#include "Helpers.h"

void vAllocTableFill34(int iSize) {
    if (bIsNumberPositive(iSize) && bIsNumberSmallerThenMaxInt(iSize)) {
        int *piTable;
        piTable = new int[iSize];

        for (int i = 0; i < iSize; i++) {
            piTable[i] = I_NUMBER_TO_FILL_ARRAY;
        }

        for (int i = 0; i < iSize; i++) {
            std::cout << piTable[i] << " ";
        }

        delete[] piTable;
    } else {
        std::cout << "iSize should be positive!" << std::endl;
    }
}
