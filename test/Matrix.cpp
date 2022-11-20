//
// Created by Mateusz Ptak on 13/11/2022.
//

#include <iostream>
#include "Matrix.h"

CMatrix::CMatrix() {
    i_rows = I_ROWS;
    i_col = I_COL;
    i_matrix = new int *[i_rows];

    for (int i = 0; i < i_rows; i++) {
        i_matrix[i] = new int[i_col];
    }
}

CMatrix::CMatrix(int iRows, int iCol) {
    i_rows = iRows;
    i_col = iCol;
    i_matrix = new int *[i_rows];

    for (int i = 0; i < i_rows; i++) {
        i_matrix[i] = new int[i_col];
    }
}

CMatrix::CMatrix(const CMatrix &pcOther) {
    i_rows = pcOther.i_rows;
    i_col = pcOther.i_col;
    i_matrix = new int *[i_rows];

    for (int i = 0; i < i_rows; i++) {
        i_matrix[i] = new int[i_col];
    }

    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_col; j++) {
            i_matrix[i][j] = pcOther.i_matrix[i][j];
        }
    }
}

CMatrix::~CMatrix() {
    for (int i = 0; i < i_rows; i++) {
        delete[] i_matrix[i];
    }

    delete[] i_matrix;
}

void CMatrix::vSetValueAt(int iRowOffset, int iColOffset, int iNewVal) {
    if (iRowOffset < 0 || iRowOffset >= i_rows || iColOffset < 0 || iColOffset >= i_col) {
        std::cout << "Wrong offset!" << std::endl;
        return;
    }

    i_matrix[iRowOffset][iColOffset] = iNewVal;
}

void CMatrix::vPrintMatrix() {
    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_col; j++) {
            std::cout << i_matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

CMatrix CMatrix::operator+(const CMatrix &pcOther) {
    if (i_rows != pcOther.i_rows || i_col != pcOther.i_col) {
        std::cout << "Matrices should have the same size!" << std::endl;
        return CMatrix();
    }

    CMatrix cResult(i_rows, i_col);

    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_col; j++) {
            cResult.i_matrix[i][j] = i_matrix[i][j] + pcOther.i_matrix[i][j];
        }
    }

    return cResult;
}

CMatrix CMatrix::operator-(const CMatrix &pcOther) {
    if (i_rows != pcOther.i_rows || i_col != pcOther.i_col) {
        std::cout << "Matrices should have the same size!" << std::endl;
        return CMatrix();
    }

    CMatrix cResult(i_rows, i_col);

    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_col; j++) {
            cResult.i_matrix[i][j] = i_matrix[i][j] - pcOther.i_matrix[i][j];
        }
    }

    return cResult;
}
