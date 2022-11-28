//
// Created by Mateusz Ptak on 20/11/2022.
//

#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
    pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

CNodeDynamic *CTreeDynamic::pcGetRoot() {
    return pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    if (pcNewChildNode->pcGetParent()) {
        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
    }

    pcParentNode->vAddNewChild(pcNewChildNode);

    return true;
}

CNodeDynamic *CTreeDynamic::pcFindNode(int iVal) {
    return pcFindNodeHelper(pcGetRoot(), iVal);
}

CNodeDynamic *CTreeDynamic::pcFindNodeHelper(CNodeDynamic *node, int iVal) {
    if (node->iGetValue() == iVal) return node;

    for (int i = 0; i < node->iGetChildrenNumber(); i++) {
        if (node->pcGetChild(i)->iGetValue() == iVal) {
            return node->pcGetChild(i);
        } else {
            pcFindNodeHelper(node->pcGetChild(i), iVal);
        }
    }
}


