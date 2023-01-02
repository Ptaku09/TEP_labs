//
// Created by Mateusz Ptak on 30/12/2022.
//

#ifndef PROJEKT_CINDIVIDUAL_H
#define PROJEKT_CINDIVIDUAL_H


#include <vector>
#include <random>
#include "CKnapsackProblem.h"

class CIndividual {
public:
    CIndividual();

    CIndividual(std::vector<bool> vbGenotype, int iLength);

    void mutate(float fChance);

    std::vector<CIndividual *> cross(CIndividual &cOther);

    void printGenotype();

    void calcFitness(CKnapsackProblem &cProblem);

    float getFitness() const;

private:
    std::default_random_engine generator;
    std::vector<bool> vb_genotype;
    int i_length;
    float f_fitness;
};


#endif //PROJEKT_CINDIVIDUAL_H
