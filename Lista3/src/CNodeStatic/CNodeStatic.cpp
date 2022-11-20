//
// Created by Mateusz Ptak on 20/11/2022.
//

#include "CNodeStatic.h"
#include <iostream>

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {
}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetValue() const {
    return i_val;
}

int CNodeStatic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic c_new_child;
    c_new_child.pc_parent_node = this;
    v_children.push_back(c_new_child);
}

void CNodeStatic::vRemoveChild(CNodeStatic *cChildToRemove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (&v_children[i] == cChildToRemove) {
            v_children.erase(v_children.begin() + i);
            return;
        }
    }
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return &v_children[iChildOffset];
    }

    return NULL;
}

CNodeStatic *CNodeStatic::pcGetParent() {
    return pc_parent_node;
}

void CNodeStatic::vPrint() {
    std::cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i].vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp() {
    vPrint();

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}
