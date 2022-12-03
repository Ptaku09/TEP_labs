//
// Created by Mateusz Ptak on 20/11/2022.
//

#ifndef LISTA3_CNODEDYNAMIC_H
#define LISTA3_CNODEDYNAMIC_H


#include <vector>
#include <iostream>

template<typename T>
class CNodeDynamic {
public:
    CNodeDynamic();

    ~CNodeDynamic();

    void vSetValue(T iNewVal);

    int iGetChildrenNumber();

    T iGetValue() const;

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *pcNewChild);

    void vRemoveChild(CNodeDynamic *pcChildToRemove);

    CNodeDynamic *pcGetChild(int iChildOffset);

    CNodeDynamic *pcGetParent();

    void vPrint();

    void vPrintAllBelow();

    void vPrintUp();

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    T i_val;
};


template<typename T>
CNodeDynamic<T>::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        delete v_children[i];
    }
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
    i_val = iNewVal;
}

template<typename T>
T CNodeDynamic<T>::iGetValue() const {
    return i_val;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic *c_new_child;
    c_new_child = new CNodeDynamic();
    c_new_child->pc_parent_node = this;
    v_children.push_back(c_new_child);
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic *pcNewChild) {
    pcNewChild->pc_parent_node = this;
    v_children.push_back(pcNewChild);
}

template<typename T>
void CNodeDynamic<T>::vRemoveChild(CNodeDynamic *pcChildToRemove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (v_children[i] == pcChildToRemove) {
            v_children.erase(v_children.begin() + i);
            return;
        }
    }
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset >= 0 && iChildOffset < iGetChildrenNumber()) {
        return v_children[iChildOffset];
    }

    return NULL;
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetParent() {
    return pc_parent_node;
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
    std::cout << " " << i_val;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
    vPrint();

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

#endif //LISTA3_CNODEDYNAMIC_H
