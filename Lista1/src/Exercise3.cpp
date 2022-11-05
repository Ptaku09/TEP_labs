//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include "Exercise3.h"
#include "Helpers.h"

bool bDeallocTable2Dim(int ***piTable, int iSizeX) {
    if (bIsNumberPositive(iSizeX) && bIsNumberSmallerThenMaxInt(iSizeX)) {
        for (int i = 0; i < iSizeX; i++) {
            delete[] (*piTable)[i];
        }

        delete[] (*piTable);
        return true;
    }

    std::cout << "iSizeX should be positive!" << std::endl;
    return false;
}

