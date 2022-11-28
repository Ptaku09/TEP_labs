//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CNODESTATIC_H
#define LISTA3_CNODESTATIC_H


#include <vector>

class CNodeStatic {
public:
    CNodeStatic();

    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetValue() const;

    int iGetChildrenNumber();

    void vAddNewChild();

    void vRemoveChild(CNodeStatic *pcChildToRemove);

    CNodeStatic *pcGetChild(int iChildOffset);

    CNodeStatic *pcGetParent();

    void vPrint();

    void vPrintAllBelow();

    void vPrintUp();

    void vPrintUp(CNodeStatic *pcNode);

    void vPrintAllBelow(CNodeStatic *pcNode);

private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

};


#endif //LISTA3_CNODESTATIC_H
