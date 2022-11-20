//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include "CTable.h"
#include "Helpers.h"

const std::string CTable::S_DEFAULT_TABLE_NAME = "Default";
const int CTable::I_DEFAULT_TABLE_LEN = 5;

CTable::CTable() {
    s_name = S_DEFAULT_TABLE_NAME;
    i_table_len = I_DEFAULT_TABLE_LEN;
    i_array = new int[I_DEFAULT_TABLE_LEN];

    std::cout << "bezp: '" + s_name + "'" << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    i_table_len = iTableLen;
    i_array = new int[iTableLen];

    std::cout << "parametr: '" + sName + "'" << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    i_table_len = pcOther.i_table_len;
    i_array = new int[i_table_len];

    for (int i = 0; i < i_table_len; i++) {
        i_array[i] = pcOther.i_array[i];
    }

    std::cout << "kopiuj: '" + s_name + "'" << std::endl;
}

CTable::~CTable() {
    delete i_array;

    std::cout << "usuwam: '" + s_name + "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (bIsNumberPositive(iTableLen) && bIsNumberSmallerThenMaxInt(iTableLen)) {
        int *i_new_array;
        i_new_array = new int[iTableLen];

        std::copy(i_array, i_array + std::min(iTableLen, i_table_len), i_new_array);

        delete[] i_array;
        i_array = i_new_array;
        i_table_len = iTableLen;

        return true;
    }

    std::cout << "iTableLength should be positive!" << std::endl;
    return false;
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void vModTab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

void vModTab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}


