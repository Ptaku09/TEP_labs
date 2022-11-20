#include <iostream>
#include "Exercise1.h"
#include "Matrix.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    v_alloc_table_fill_34(5);

    CMatrix m1(2, 2);
    CMatrix m2(2, 2);

    m1.vSetValueAt(0, 0, 1);
    m1.vSetValueAt(0, 1, 2);
    m1.vSetValueAt(1, 0, 3);
    m1.vSetValueAt(1, 1, 4);

    m2.vSetValueAt(0, 0, 5);
    m2.vSetValueAt(0, 1, 6);
    m2.vSetValueAt(1, 0, 7);
    m2.vSetValueAt(1, 1, 8);

    CMatrix m3 = m1 + m2;

    m1.vPrintMatrix();
    std::cout << std::endl;
    m2.vPrintMatrix();
    std::cout << std::endl;
    m3.vPrintMatrix();

    return 0;
}
