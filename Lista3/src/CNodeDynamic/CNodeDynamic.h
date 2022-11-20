//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CNODEDYNAMIC_H
#define LISTA3_CNODEDYNAMIC_H


#include <vector>

class CNodeDynamic {
public:
    CNodeDynamic();

    ~CNodeDynamic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *pcNewChild);

    void vRemoveChild(CNodeDynamic *pcChildToRemove);

    CNodeDynamic *pcGetChild(int iChildOffset);

    CNodeDynamic *pcGetParent();

    void vPrint();

    void vPrintAllBelow();

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};


#endif //LISTA3_CNODEDYNAMIC_H
