#include <iostream>
#include "src/CTable.h"
#include "src/CMatrix.h"


int main() {
    // Exercise 1
//    CTable c_tab_0, c_tab_1;
//    c_tab_0.bSetNewSize(6);
//    c_tab_1.bSetNewSize(4);
//    c_tab_0 = c_tab_1;

    // Exercise 3
//    c_tab_0.vSetValueAt(0, 1);
//    c_tab_0.vSetValueAt(1, 2);
//    c_tab_0.vSetValueAt(2, 3);
//    c_tab_0.vSetValueAt(3, 4);
//    c_tab_0.vSetValueAt(4, 5);
//    c_tab_0.vSetValueAt(5, 6);
//
//    c_tab_1.vSetValueAt(0, 51);
//    c_tab_1.vSetValueAt(1, 52);
//    c_tab_1.vSetValueAt(2, 53);
//    c_tab_1.vSetValueAt(3, 54);
//
//    c_tab_0.vPrint();
//    c_tab_1.vPrint();
//
//    c_tab_0 = c_tab_1;
//    c_tab_1.vSetValueAt(2, 123);
//    c_tab_0.vPrint();
//    c_tab_1.vPrint();

    // Exercise 4
//    CTable c_tab_res = c_tab_0 + c_tab_1;
//    c_tab_res.vPrint();

    // Mod
    CMatrix matrix1 = CMatrix(2, 2);
    CMatrix matrix2 = CMatrix(2, 2);

    matrix1.vSetValueAt(0, 0, 1);
    matrix1.vSetValueAt(0, 1, 2);
    matrix1.vSetValueAt(1, 0, 3);
    matrix1.vSetValueAt(1, 1, 4);

    matrix2.vSetValueAt(0, 0, 5);
    matrix2.vSetValueAt(0, 1, 6);
    matrix2.vSetValueAt(1, 0, 7);
    matrix2.vSetValueAt(1, 1, 8);
    
    CMatrix matrix3 = matrix1 + matrix2;

    matrix1.vPrint();
    std::cout << std::endl;
    matrix2.vPrint();
    std::cout << std::endl;
    matrix3.vPrint();

    return 0;
}
