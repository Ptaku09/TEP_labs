//
// Created by Mateusz Ptak on 16/12/2022.
//

#include "CTab.h"
#include <iostream>

CTab::CTab(const CTab &cOther) {
    v_copy(cOther);
    std::cout << "Copy ";
}

CTab::~CTab() {
    if (pi_tab != NULL) delete pi_tab;
    std::cout << "Destr ";
}

CTab::CTab(CTab &&cOther) {
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;

    cOther.pi_tab = NULL;

    std::cout << "MOVE ";
}

CTab CTab::operator=(const CTab &cOther) {
    v_copy(cOther);
    std::cout << "op= ";
    return (*this);
}

CTab CTab::operator=(CTab &&cOther) noexcept {
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = nullptr;
    cOther.i_size = 0;

    std::cout << "op=MOVE " << std::endl;

    return *this;
}

void CTab::v_copy(const CTab &cOther) {
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}

bool CTab::bSetSize(int iNewSize) {
    if (iNewSize <= 0)
        return false;

    int *new_table = new int[iNewSize];

    if (i_size < iNewSize) {
        for (int i = 0; i < i_size; i++) {
            new_table[i] = pi_tab[i];
        }
    } else {
        for (int i = 0; i < iNewSize; i++) {
            new_table[i] = pi_tab[i];
        }
    }

    i_size = iNewSize;

    delete[] pi_tab;
    pi_tab = new_table;

    return true;
}
