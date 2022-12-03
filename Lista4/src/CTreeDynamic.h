//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CTREEDYNAMIC_H
#define LISTA3_CTREEDYNAMIC_H

#include "CNodeDynamic.h"

template<typename T>
class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);

private:
    CNodeDynamic<T> *pc_root;
};


template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
    pc_root = new CNodeDynamic<T>();
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template<typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    if (pcNewChildNode->pcGetParent()) {
        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
    }

    pcParentNode->vAddNewChild(pcNewChildNode);

    return true;
}

#endif //LISTA3_CTREEDYNAMIC_H
