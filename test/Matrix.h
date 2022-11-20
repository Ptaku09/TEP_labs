//
// Created by Mateusz Ptak on 13/11/2022.
//

#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#define I_ROWS 3
#define I_COL 3

class CMatrix {
public:
    CMatrix();

    CMatrix(int iRows, int iCol);

    CMatrix(const CMatrix &pcOther);

    ~CMatrix();

    void vSetValueAt(int iRowOffset, int iColOffset, int iNewVal);

    void vPrintMatrix();

    CMatrix operator+(const CMatrix &pcOther);

    CMatrix operator-(const CMatrix &pcOther);

private:
    int **i_matrix;
    int i_rows;
    int i_col;
};


#endif //TEST_MATRIX_H
