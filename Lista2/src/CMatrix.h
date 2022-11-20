//
// Created by Mateusz Ptak on 14/11/2022.
//

#ifndef LISTA2_CMATRIX_H
#define LISTA2_CMATRIX_H

#define I_ROWS 3
#define I_COLS 3

class CMatrix {
public:
    CMatrix();

    CMatrix(int iRows, int iCols);

    CMatrix(const CMatrix &pcOther);

    ~CMatrix();

    void vSetValueAt(int iRow, int iCol, int iNewVal);

    void vPrint();

    CMatrix operator+(const CMatrix &pcOther);

private:
    int i_rows;
    int i_cols;
    int **i_matrix;
};


#endif //LISTA2_CMATRIX_H
