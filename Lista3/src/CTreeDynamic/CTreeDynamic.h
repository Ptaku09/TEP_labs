//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CTREEDYNAMIC_H
#define LISTA3_CTREEDYNAMIC_H

#include "../CNodeDynamic/CNodeDynamic.h"

class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

    CNodeDynamic *pcFindNode(int iVal);

    CNodeDynamic *pcFindNodeHelper(CNodeDynamic *node, int iVal);

private:
    CNodeDynamic *pc_root;
};

#endif //LISTA3_CTREEDYNAMIC_H
