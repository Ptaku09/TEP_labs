#include <iostream>

#include "src/CTable.h"
#include "src/CTab.h"
#include "src/CMySmartPointer.h"

void v_ex1_2_test() {
    CMySmartPointer<CTable> point1(new CTable("new_table", 5));
    CMySmartPointer<CTable> point2(new CTable("new_table2", 10));

    std::cout << std::endl;
    std::cout << "point2 before assignment" << std::endl;
    point2->vPrint();

    point2 = point1;

    std::cout << std::endl;
    std::cout << "point3 after assignment" << std::endl;
    point2->vPrint();
}

void v_ex4_test() {
    CTab ctab1, ctab2, ctab3;

    ctab2.bSetSize(5);
    ctab3.bSetSize(7);

    ctab2 = std::move(ctab3);

    std::cout << "ctab2: " << ctab2.iGetSize() << std::endl;
}

void v_ex5_test() {
    CTable c_table;
    CTable c_other;
    std::cout << "c_table: " << &c_table << std::endl;
    std::cout << "C_other: " << &c_other << std::endl;
    c_table = std::move(c_other);
}

void v_ex5_test_wo_move() {
    CTable c_table;
    CTable c_other;
    std::cout << "c_table: " << &c_table << std::endl;
    std::cout << "C_other: " << &c_other << std::endl;
    c_table = c_other;
}

//void v_ex5_test2() {
//    CTable tab1("one", 1);
//    CTable tab2("two", 2);
//    CTable tab3("three", 3);
//
//    CTable tab4;
//
//    tab4 = tab2 + tab3;
//
//}

int main() {
    v_ex1_2_test();
//    v_ex4_test();
//    v_ex5_test();
//    std::cout << std::endl;
//    v_ex5_test_wo_move();
    return 0;
}
