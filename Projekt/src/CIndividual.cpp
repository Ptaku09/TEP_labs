//
// Created by Mateusz Ptak on 30/12/2022.
//

#include <iostream>
#include "CIndividual.h"
#include "CKnapsackProblem.h"

CIndividual::CIndividual() {
    f_fitness = 0;
}

CIndividual::CIndividual(std::vector<bool> vbGenotype, int iLength) {
    f_fitness = 0;
    vb_genotype = std::move(vbGenotype);
    i_length = iLength;
}

void CIndividual::calcFitness(CKnapsackProblem &cProblem) {
    f_fitness = cProblem.calcFitness(vb_genotype);
}

void CIndividual::mutate(float fChance) {
    std::uniform_int_distribution<int> random(0, 100);

    for (int i = 0; i < i_length; i++) {
        if (random(generator) / 100.0 < fChance) {
            vb_genotype[i] = !vb_genotype[i];
        }
    }
}

std::vector<CIndividual *> CIndividual::cross(CIndividual &cOther) {
    std::uniform_int_distribution<int> random(0, i_length - 1);
    int i_crossPoint = random(generator);

    std::vector<CIndividual *> vcChildren;
    std::vector<bool> vbChild1;
    std::vector<bool> vbChild2;

    for (int i = 0; i < i_length; i++) {
        if (i < i_crossPoint) {
            vbChild1.push_back(vb_genotype[i]);
            vbChild2.push_back(cOther.vb_genotype[i]);
        } else {
            vbChild1.push_back(cOther.vb_genotype[i]);
            vbChild2.push_back(vb_genotype[i]);
        }
    }

    vcChildren.push_back(new CIndividual(vbChild1, i_length));
    vcChildren.push_back(new CIndividual(vbChild2, i_length));

    return vcChildren;
}

void CIndividual::printGenotype() {
    for (int i = 0; i < i_length; i++) {
        std::cout << vb_genotype[i] << " ";
    }

    std::cout << std::endl;
}

float CIndividual::getFitness() const {
    return f_fitness;
}
