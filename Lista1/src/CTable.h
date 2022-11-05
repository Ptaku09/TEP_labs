//
// Created by Mateusz Ptak on 15/10/2022.
//

#ifndef LISTA1_CTABLE_H
#define LISTA1_CTABLE_H

#include <string>

class CTable {
public:
    CTable();

    CTable(std::string sName, int iTableLen);

    CTable(const CTable &pcOther);

    ~CTable();

    void vSetName(std::string sName);

    bool bSetNewSize(int iTableLen);

    CTable *pcClone();

private:
    static const std::string S_DEFAULT_TABLE_NAME;
    static const int I_DEFAULT_TABLE_LEN;
    std::string s_name;
    int i_table_len;
    int *i_array;
};

void vModTab(CTable *pcTab, int iNewSize);

void vModTab(CTable cTab, int iNewSize);

#endif //LISTA1_CTABLE_H
