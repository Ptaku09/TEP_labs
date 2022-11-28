#include <iostream>
#include "src/CTreeStatic/CTreeStatic.h"
#include "src/CTreeDynamic/CTreeDynamic.h"


void v_tree_test() {
    CNodeStatic c_root;

    c_root.vAddNewChild();
    c_root.vAddNewChild();

    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);

    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();

    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();

    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_tree_test_dynamic() {
    CNodeDynamic c_root;

    c_root.vAddNewChild();
    c_root.vAddNewChild();

    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);

    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();

    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();

    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_exercise6_test_static() {
    CTreeStatic c_tree1;
    CTreeStatic c_tree2;
    c_tree1.pcGetRoot()->vSetValue(0);
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();

    c_tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree2.pcGetRoot()->vSetValue(50);
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

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

void v_exercise6_test_dynamic() {
    CTreeDynamic c_tree1;
    CTreeDynamic c_tree2;

    c_tree1.pcGetRoot()->vSetValue(0);
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();
    c_tree1.pcGetRoot()->vAddNewChild();

    c_tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree2.pcGetRoot()->vSetValue(50);
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

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

void v_mod_test_static() {
    CTreeStatic c_tree;

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

    CNodeStatic *node = c_tree.pcFindNode(55);

    c_tree.pcGetRoot()->vPrintUp(node);
    std::cout << std::endl;
    c_tree.pcGetRoot()->vPrintAllBelow(node);
}

void v_mod_test_dynamic() {
    CTreeDynamic c_tree;

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

    CNodeDynamic *node = c_tree.pcFindNode(54);

    c_tree.pcGetRoot()->vPrintUp(node);
    std::cout << std::endl;
    c_tree.pcGetRoot()->vPrintAllBelow(node);
}

int main() {
//    v_tree_test();
//    std::cout << std::endl;
//    v_tree_test_dynamic();
//    std::cout << std::endl;
//    v_exercise6_test_static();
//    std::cout << "----------------------------------------" << std::endl;
//    v_exercise6_test_dynamic();

    v_mod_test_static();
    std::cout << std::endl;
    std::cout << "-------------" << std::endl;
    v_mod_test_dynamic();
    return 0;
}
