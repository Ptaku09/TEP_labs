//
// Created by Mateusz Ptak on 15/10/2022.
//

#include <iostream>
#include <algorithm>
#include "CTable.h"

CTable::CTable() {
    s_name = S_DEFAULT_TABLE_NAME;
    i_table_len = I_DEFAULT_TABLE_LEN;
    i_table = new int[I_DEFAULT_TABLE_LEN];

    std::cout << "bezp: '" + s_name + "'" << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    i_table_len = iTableLen;
    i_table = new int[iTableLen];

    std::cout << "parametr: '" + sName + "'" << std::endl;
}

CTable::CTable(const CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    i_table_len = pcOther.i_table_len;
    i_table = new int[i_table_len];

    for (int i = 0; i < i_table_len; i++) {
        i_table[i] = pcOther.i_table[i];
    }

    std::cout << "kopiuj: '" + s_name + "'" << std::endl;
}

CTable::~CTable() {
    delete i_table;

    std::cout << "usuwam: '" + s_name + "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen > 0 && iTableLen < INT16_MAX) {
        int *i_new_array;
        i_new_array = new int[iTableLen];

        std::copy(i_table, i_table + std::min(iTableLen, i_table_len), i_new_array);

        delete[] i_table;
        i_table = i_new_array;
        i_table_len = iTableLen;

        return true;
    }

    std::cout << "iTableLength should be positive!" << std::endl;
    return false;
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset >= 0 && iOffset < i_table_len) {
        i_table[iOffset] = iNewVal;
    } else {
        std::cout << "iOffset should be positive and smaller than i_table_len!" << std::endl;
    }
}

void CTable::vPrint() {
    std::cout << "CTable: '" + s_name + "' length: " << i_table_len << std::endl;

    for (int i = 0; i < i_table_len; i++) {
        std::cout << i_table[i] << " ";
    }

    std::cout << std::endl;
}

CTable CTable::operator=(const CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    i_table_len = pcOther.i_table_len;
    i_table = new int[i_table_len];

    for (int i = 0; i < i_table_len; i++) {
        i_table[i] = pcOther.i_table[i];
    }

    std::cout << "kopiuj: '" + s_name + "'" << std::endl;

    return *this;
}

CTable CTable::operator=(CTable &&pcOther) noexcept {
    s_name = pcOther.s_name;
    i_table_len = pcOther.i_table_len;
    i_table = pcOther.i_table;

    pcOther.i_table = nullptr;
    pcOther.i_table_len = 0;
    pcOther.s_name = "";

    std::cout << "Move operator" << std::endl;

    return *this;
}

CTable CTable::operator+(CTable &pcOther) {
    CTable c_new_table(s_name + "_" + pcOther.s_name, i_table_len + pcOther.i_table_len);

    for (int i = 0; i < i_table_len; i++) {
        c_new_table.i_table[i] = i_table[i];
    }

    for (int i = i_table_len; i < c_new_table.i_table_len; i++) {
        c_new_table.i_table[i] = pcOther.i_table[i - i_table_len];
    }

    std::cout << "operator +\n\n";

    return std::move(c_new_table);
}
