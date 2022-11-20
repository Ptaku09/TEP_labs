//
// Created by Mateusz Ptak on 15/10/2022.
//

#ifndef LISTA2_CTABLE_H
#define LISTA2_CTABLE_H

#define S_DEFAULT_TABLE_NAME "Default"
#define I_DEFAULT_TABLE_LEN 5

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


    void vSetValueAt(int iOffset, int iNewVal);

    void vPrint();

//    void operator=(const CTable &pcOther);

    CTable operator+(const CTable &pcOther);

    CTable &operator=(const CTable &pcOther);

private:
    std::string s_name;
    int i_table_len;
    int *i_table;
};

#endif //LISTA2_CTABLE_H
