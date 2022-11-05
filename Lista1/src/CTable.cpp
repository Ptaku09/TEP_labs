//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include "CTable.h"
#include "Helpers.h"

const std::string CTable::S_DEFAULT_TABLE_NAME = "Default";
const int CTable::I_DEFAULT_TABLE_LEN = 5;

CTable::CTable() {
    this->s_name = S_DEFAULT_TABLE_NAME;
    this->i_table_len = I_DEFAULT_TABLE_LEN;
    this->i_array = new int[I_DEFAULT_TABLE_LEN];

    std::cout << "bezp: '" + s_name + "'" << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    this->s_name = sName;
    this->i_table_len = iTableLen;
    this->i_array = new int[iTableLen];

    std::cout << "parametr: '" + sName + "'" << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    this->s_name = pcOther.s_name + "_copy";
    this->i_table_len = pcOther.i_table_len;
    this->i_array = new int[this->i_table_len];

    for (int i = 0; i < this->i_table_len; i++) {
        this->i_array[i] = pcOther.i_array[i];
    }

    std::cout << "kopiuj: '" + this->s_name + "'" << std::endl;
}

CTable::~CTable() {
    delete i_array;

    std::cout << "usuwam: '" + this->s_name + "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    this->s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (bIsNumberPositive(iTableLen) && bIsNumberSmallerThenMaxInt(iTableLen)) {
        int *i_new_array;
        i_new_array = new int[iTableLen];

        std::copy(this->i_array, this->i_array + std::min(iTableLen, this->i_table_len), i_new_array);

        delete[] this->i_array;
        this->i_array = i_new_array;
        this->i_table_len = iTableLen;

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


