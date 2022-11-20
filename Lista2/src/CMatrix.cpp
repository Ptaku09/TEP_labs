//
// Created by Mateusz Ptak on 14/11/2022.
//

#include "CMatrix.h"
#include <iostream>

CMatrix::CMatrix() {
    i_rows = I_ROWS;
    i_cols = I_COLS;
    i_matrix = new int *[I_ROWS];

    for (int i = 0; i < I_ROWS; i++) {
        i_matrix[i] = new int[I_COLS];
    }

    for (int i = 0; i < I_ROWS; i++) {
        for (int j = 0; j < I_COLS; j++) {
            i_matrix[i][j] = 0;
        }
    }
}

CMatrix::CMatrix(int iRows, int iCols) {
    i_rows = iRows;
    i_cols = iCols;
    i_matrix = new int *[iRows];

    for (int i = 0; i < iRows; i++) {
        i_matrix[i] = new int[iCols];
    }

    for (int i = 0; i < iRows; i++) {
        for (int j = 0; j < iCols; j++) {
            i_matrix[i][j] = 0;
        }
    }
}

CMatrix::CMatrix(const CMatrix &pcOther) {
    i_rows = pcOther.i_rows;
    i_cols = pcOther.i_cols;
    i_matrix = new int *[i_rows];

    for (int i = 0; i < i_rows; i++) {
        i_matrix[i] = new int[i_cols];
    }

    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_cols; j++) {
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

void CMatrix::vSetValueAt(int iRow, int iCol, int iNewVal) {
    if (iRow < 0 || iRow >= i_rows || iCol < 0 || iCol >= i_cols) {
        std::cout << "Wrong offsets!" << std::endl;
        return;
    }

    i_matrix[iRow][iCol] = iNewVal;
}

void CMatrix::vPrint() {
    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_cols; j++) {
            std::cout << i_matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

CMatrix CMatrix::operator+(const CMatrix &pcOther) {
    if (i_rows != pcOther.i_rows || i_cols != pcOther.i_cols) {
        std::cout << "Matrices should have the same size!" << std::endl;
        return CMatrix();
    }

    CMatrix c_result = CMatrix(i_rows, i_cols);

    for (int i = 0; i < i_rows; i++) {
        for (int j = 0; j < i_cols; j++) {
            c_result.i_matrix[i][j] = i_matrix[i][j] + pcOther.i_matrix[i][j];
        }
    }

    return c_result;
}
