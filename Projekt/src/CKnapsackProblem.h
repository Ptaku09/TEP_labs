//
// Created by Mateusz Ptak on 30/12/2022.
//

#ifndef PROJEKT_CKNAPSACKPROBLEM_H
#define PROJEKT_CKNAPSACKPROBLEM_H

#include <vector>

class CKnapsackProblem {
public:
    CKnapsackProblem();

    CKnapsackProblem(int iNumberOfItems, float iCapacity, float viWeights[], float viValues[]);

    float calcFitness(std::vector<bool> vbGenotype);

    void readFromFile(const std::string &sFileName);

    int getNumberOfItems() const;

private:
    int i_number_of_items;
    float i_capacity;
    float *i_values;
    float *i_weights;
};


#endif //PROJEKT_CKNAPSACKPROBLEM_H
