//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include "Exercise2.h"
#include "Helpers.h"

bool bAllocTable2Dim(int ***piTable, int iSizeX, int iSizeY) {
    if (bIsNumberPositive(iSizeX) && bIsNumberPositive(iSizeY) && bIsNumberSmallerThenMaxInt(iSizeX) &&
        bIsNumberSmallerThenMaxInt(iSizeY)) {
        (*piTable) = new int *[iSizeX];

        for (int i = 0; i < iSizeX; i++) {
            (*piTable)[i] = new int[iSizeY];
        }

        return true;
    }

    std::cout << "iSizeX and iSizeY should be positive!" << std::endl;
    return false;
}
