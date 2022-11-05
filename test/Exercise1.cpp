//
// Created by Mateusz Ptak on 14/10/2022.
//

#include <iostream>
#include "Exercise1.h"

using namespace std;

void v_alloc_table_fill_34(int iSize) {
    if (iSize <= 0) {
        cout << "iSize should be positive!" << endl;
        return;
    }

    int *piTable;
    piTable = new int[iSize];

    for (int i = 0; i < iSize; i++) {
        piTable[i] = NUMBER_FOR_FILLING_ARRAY;
    }

    for (int i = 0; i < iSize; i++) {
        cout << piTable[i] << " ";
    }

    delete piTable;
}
