//
// Created by Mateusz Ptak on 20/11/2022.
//

#include "CNodeDynamic.h"
#include <iostream>

CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        delete v_children[i];
    }
}

void CNodeDynamic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeDynamic::iGetValue() const {
    return i_val;
}

int CNodeDynamic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *c_new_child;
    c_new_child = new CNodeDynamic();
    c_new_child->pc_parent_node = this;
    v_children.push_back(c_new_child);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *pcNewChild) {
    pcNewChild->pc_parent_node = this;
    v_children.push_back(pcNewChild);
}

void CNodeDynamic::vRemoveChild(CNodeDynamic *pcChildToRemove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (v_children[i] == pcChildToRemove) {
            v_children.erase(v_children.begin() + i);
            return;
        }
    }
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset >= 0 && iChildOffset < iGetChildrenNumber()) {
        return v_children[iChildOffset];
    }

    return NULL;
}

CNodeDynamic *CNodeDynamic::pcGetParent() {
    return pc_parent_node;
}

void CNodeDynamic::vPrint() {
    std::cout << " " << i_val;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

void CNodeDynamic::vPrintUp() {
    vPrint();

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

void CNodeDynamic::vPrintUp(CNodeDynamic *pcNode) {
    pcNode->vPrint();

    if (pcNode->pc_parent_node != NULL) {
        vPrintUp(pcNode->pc_parent_node);
    }
}

void CNodeDynamic::vPrintAllBelow(CNodeDynamic *pcNode) {
    pcNode->vPrint();

    for (int i = 0; i < pcNode->v_children.size(); i++) {
        vPrintAllBelow(pcNode->pcGetChild(i));
    }
}
