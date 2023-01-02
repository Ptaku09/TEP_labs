//
// Created by Mateusz Ptak on 30/12/2022.
//

#include <fstream>
#include <iostream>
#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem() {
    i_number_of_items = 0;
    i_capacity = 0;
    i_values = nullptr;
    i_weights = nullptr;
}

CKnapsackProblem::CKnapsackProblem(int iNumberOfItems, float iCapacity, float *viWeights, float *viValues) {
    if (iNumberOfItems > 0) {
        i_number_of_items = iNumberOfItems;
    } else {
        std::cout << "Number of items must be greater or equal 0" << std::endl;
        i_number_of_items = 0;
    }

    if (iCapacity > 0) {
        i_capacity = iCapacity;
    } else {
        std::cout << "Capacity must be greater or equal 0" << std::endl;
        i_capacity = 0;
    }

    i_weights = new float[i_number_of_items];
    i_values = new float[i_number_of_items];

    for (int i = 0; i < i_number_of_items; i++) {
        if (viWeights[i] > 0) {
            i_weights[i] = viWeights[i];
        } else {
            std::cout << "Weight must be greater or equal 0" << std::endl;
            i_weights[i] = 0;
        }

        if (viValues[i] > 0) {
            i_values[i] = viValues[i];
        } else {
            std::cout << "Value must be greater or equal 0" << std::endl;
            i_values[i] = 0;
        }
    }
}

float CKnapsackProblem::calcFitness(std::vector<bool> vbGenotype) {
    float i_weight = 0;
    float i_value = 0;

    for (int i = 0; i < i_number_of_items; i++) {
        if (vbGenotype[i]) {
            i_weight += i_weights[i];
            i_value += i_values[i];
        }
    }

    if (i_weight > i_capacity) {
        return 0;
    }

    return i_value;
}

void CKnapsackProblem::readFromFile(const std::string &sFileName) {
    std::ifstream file(sFileName);

    if (!file.is_open()) {
        std::cout << "Error opening file - setting default data" << std::endl;

        i_number_of_items = 0;
        i_capacity = 0;
        i_values = nullptr;
        i_weights = nullptr;

        return;
    }

    file >> i_number_of_items;

    if (i_number_of_items < 0) {
        std::cout << "Number of items must be greater or equal 0" << std::endl;
        i_number_of_items = 0;
    }

    file >> i_capacity;

    if (i_capacity < 0) {
        std::cout << "Capacity must be greater or equal 0" << std::endl;
        i_capacity = 0;
    }

    delete i_weights;
    delete i_values;

    i_weights = new float[i_number_of_items];
    i_values = new float[i_number_of_items];

    for (int i = 0; i < i_number_of_items; i++) {
        file >> i_weights[i];

        if (i_weights[i] < 0) {
            std::cout << "Weight must be greater or equal 0" << std::endl;
            i_weights[i] = 0;
        }

        file >> i_values[i];

        if (i_values[i] < 0) {
            std::cout << "Value must be greater or equal 0" << std::endl;
            i_values[i] = 0;
        }
    }

    file.close();
}

int CKnapsackProblem::getNumberOfItems() const {
    return i_number_of_items;
}
