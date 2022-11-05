//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include "CTable.h"
#include "Helpers.h"

CTable::CTable() {
    this->s_name = S_DEFAULT_TABLE_NAME;
    this->i_table_len = I_DEFAULT_TABLE_LEN;
    this->i_table = new int[I_DEFAULT_TABLE_LEN];

    std::cout << "bezp: '" + s_name + "'" << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    this->s_name = sName;
    this->i_table_len = iTableLen;
    this->i_table = new int[iTableLen];

    std::cout << "parametr: '" + sName + "'" << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    this->s_name = pcOther.s_name + "_copy";
    this->i_table_len = pcOther.i_table_len;
    this->i_table = new int[this->i_table_len];

    for (int i = 0; i < this->i_table_len; i++) {
        this->i_table[i] = pcOther.i_table[i];
    }

    std::cout << "kopiuj: '" + this->s_name + "'" << std::endl;
}

CTable::~CTable() {
    delete i_table;

    std::cout << "usuwam: '" + this->s_name + "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    this->s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (bIsNumberPositive(iTableLen) && bIsNumberSmallerThenMaxInt(iTableLen)) {
        int *i_new_array;
        i_new_array = new int[iTableLen];

        std::copy(this->i_table, this->i_table + std::min(iTableLen, this->i_table_len), i_new_array);

        delete[] this->i_table;
        this->i_table = i_new_array;
        this->i_table_len = iTableLen;

        return true;
    }

    std::cout << "iTableLength should be positive!" << std::endl;
    return false;
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset >= 0 && iOffset < this->i_table_len) {
        this->i_table[iOffset] = iNewVal;
    } else {
        std::cout << "iOffset should be positive and smaller than i_table_len!" << std::endl;
    }
}

void CTable::vPrint() {
    std::cout << "CTable: '" + this->s_name + "' length: " << this->i_table_len << std::endl;

    for (int i = 0; i < this->i_table_len; i++) {
        std::cout << this->i_table[i] << " ";
    }

    std::cout << std::endl;
}

void CTable::operator=(const CTable &pcOther) {
    this->i_table = pcOther.i_table;
    this->i_table_len = pcOther.i_table_len;
}

CTable CTable::operator+(const CTable &pcOther) {
    CTable c_new_table(this->s_name + "_" + pcOther.s_name, this->i_table_len + pcOther.i_table_len);

    for (int i = 0; i < this->i_table_len; i++) {
        c_new_table.i_table[i] = this->i_table[i];
    }

    for (int i = this->i_table_len; i < c_new_table.i_table_len; i++) {
        c_new_table.i_table[i] = pcOther.i_table[i - this->i_table_len];
    }

    return c_new_table;
}

