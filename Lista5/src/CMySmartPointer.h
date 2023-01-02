//
// Created by Mateusz Ptak on 16/12/2022.
//

#ifndef LISTA5_CMYSMARTPOINTER_H
#define LISTA5_CMYSMARTPOINTER_H

class CRefCounter {
public:
    CRefCounter() {
        i_count;
    }

    int iAdd() {
        return ++i_count;
    }

    int iDec() {
        return --i_count;
    }

    int iGet() const {
        return i_count;
    }

private:
    int i_count;
};

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer);

    CMySmartPointer(const CMySmartPointer<T> &pcOther);

    ~CMySmartPointer();

    T &operator*() {
        return *pc_pointer;
    };

    T *operator->() {
        return pc_pointer;
    };

    CMySmartPointer<T> &operator=(const CMySmartPointer<T> &pcOther);

private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};


template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
    pc_pointer = pcPointer;
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T> &pcOther) {
    pc_counter = pcOther.pc_counter;
    pc_pointer = pcOther.pc_pointer;
    pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    if (pc_counter->iDec() == 0) {
        delete pc_pointer;
        delete pc_counter;
    }
}

template<typename T>
CMySmartPointer<T> &CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pcOther) {
    if (this != &pcOther) {
        pc_counter->iDec();
        std::cout << "coutnter: " << pc_counter->iGet() << std::endl;

        if (pc_counter->iGet() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }

        pc_counter = pcOther.pc_counter;
        pc_pointer = pcOther.pc_pointer;
        pc_counter->iAdd();

        std::cout << "coutnter: " << pc_counter->iGet() << std::endl;
    }

    return *this;
}

#endif //LISTA5_CMYSMARTPOINTER_H
