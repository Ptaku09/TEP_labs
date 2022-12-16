#include <iostream>
#include "src/CTreeDynamic.h"

void v_test_int() {
    CTreeDynamic<int> c_tree;

    c_tree.pcGetRoot()->vSetValue(50);
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();

    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    c_tree.vPrintTree();
}

void v_test_string() {
    CTreeDynamic<std::string> c_tree;

    c_tree.pcGetRoot()->vSetValue("fifty");
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();

    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue("fifty-four");
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue("fifty-five");

    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("fifty-six");
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("fifty-seven");

    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue("fifty-eight");

    c_tree.vPrintTree();
}

void v_test_char() {
    CTreeDynamic<char> c_tree1;
    CTreeDynamic<char> c_tree2;

    c_tree1.pcGetRoot()->vSetValue('a');
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();

    c_tree1.pcGetRoot()->pcGetChild(0)->vSetValue('l');
    c_tree1.pcGetRoot()->pcGetChild(1)->vSetValue('a');
    c_tree1.pcGetRoot()->pcGetChild(2)->vSetValue('m');

    c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue('a');

    c_tree2.pcGetRoot()->vSetValue('k');
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue('o');
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue('t');

    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue('a');
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue('l');

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue('i');

    c_tree1.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;

    c_tree1.bMoveSubtree(c_tree1.pcGetRoot()->pcGetChild(2), c_tree2.pcGetRoot()->pcGetChild(0));

    c_tree1.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
}

int main() {
    v_test_int();
    std::cout << std::endl;
    v_test_char();
    std::cout << std::endl;
    v_test_string();
    std::cout << std::endl;

    return 0;
}
