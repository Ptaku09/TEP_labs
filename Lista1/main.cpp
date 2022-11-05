#include <iostream>
#include "src/Exercise1.h"
#include "src/Exercise2.h"
#include "src/Exercise3.h"
#include "src/CTable.h"

int main() {
    std::cout << "Exercise 1" << std::endl;
    vAllocTableFill34(5);

    std::cout << std::endl << std::endl << "Exercise 2" << std::endl;
    int **piTable;
    std::cout << "Status [1 = true, 0 = false]: " << bAllocTable2Dim(&piTable, 5, 3) << std::endl << std::endl;

    std::cout << "Exercise 3" << std::endl;
    std::cout << "Status [1 = true, 0 = false]: " << bDeallocTable2Dim(&piTable, 5) << std::endl << std::endl;

    std::cout << "Exercise 4" << std::endl;
    std::cout << "Init with default constructor" << std::endl;
    CTable cTableDefaultConstructor;

    std::cout << std::endl << "Init with param constructor" << std::endl;
    CTable cTableParamConstructor("Custom", 10);

    std::cout << std::endl << "Init with copying constructor" << std::endl;
    CTable cTableCopy1(cTableDefaultConstructor);
    CTable cTableCopy2(cTableParamConstructor);

    std::cout << std::endl << "Change s_name" << std::endl;
    cTableDefaultConstructor.vSetName("NotDefault");

    std::cout << std::endl << "Change i_table_len" << std::endl;
    cTableParamConstructor.bSetNewSize(12);

    std::cout << std::endl << "Clone CTable object" << std::endl;
    CTable *pcTableClone;
    pcTableClone = cTableParamConstructor.pcClone();

    std::cout << std::endl << "Test - vModTab by value" << std::endl;
    vModTab(cTableCopy1, 24);

    std::cout << std::endl << "Test - vModTab by reference" << std::endl;
    vModTab(pcTableClone, 32);

    std::cout << std::endl << "Static allocation" << std::endl;
    CTable cTableStatic1;
    CTable cTableStatic2("static", 2);
    CTable cTableStatic3(cTableStatic2);

    std::cout << std::endl << "Dynamic allocation" << std::endl;
    CTable *cTableDynamic1 = new CTable();
    CTable *cTableDynamic2 = new CTable("dynamic", 2);
    CTable *cTableDynamic3 = new CTable(*cTableDynamic2);

    std::cout << std::endl << "Destructors" << std::endl;
    std::cout << "normal:" << std::endl;
    delete cTableDynamic1;

    std::cout << std::endl << "delete array of CTable objects:" << std::endl;

    CTable *cTableArray = new CTable[2];
    cTableArray[0] = *cTableDynamic2;
    cTableArray[1] = *cTableDynamic3;
    delete[] cTableArray;

    std::cout << std::endl;
}
