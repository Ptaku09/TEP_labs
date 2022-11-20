//
// Created by Mateusz Ptak on 20/11/2022.
//

#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
    c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {
}

CNodeStatic *CTreeStatic::pcGetRoot() {
    return &c_root;
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    vCopySubtree(pcParentNode, pcNewChildNode);

    if (pcNewChildNode->pcGetParent()) {
        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
    }

    return true;
}

void CTreeStatic::vCopySubtree(CNodeStatic *pcDestination, CNodeStatic *pcSource) {
    pcDestination->vAddNewChild();
    pcDestination->pcGetChild(pcDestination->iGetChildrenNumber() - 1)->vSetValue(pcSource->iGetValue());

    for (int i = 0; i < pcSource->iGetChildrenNumber(); i++) {
        vCopySubtree(pcDestination->pcGetChild(pcDestination->iGetChildrenNumber() - 1), pcSource->pcGetChild(i));
    }
}
