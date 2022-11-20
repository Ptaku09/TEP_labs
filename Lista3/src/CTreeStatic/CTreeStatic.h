//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CTREESTATIC_H
#define LISTA3_CTREESTATIC_H

#include "../CNodeStatic/CNodeStatic.h"

class CTreeStatic {
public:
    CTreeStatic();

    ~CTreeStatic();

    CNodeStatic *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

    void vCopySubtree(CNodeStatic *pcDestination, CNodeStatic *pcSource);

private:
    CNodeStatic c_root;
};


#endif //LISTA3_CTREESTATIC_H
