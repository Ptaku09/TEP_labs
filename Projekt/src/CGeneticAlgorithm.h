//
// Created by Mateusz Ptak on 30/12/2022.
//

#ifndef PROJEKT_CGENETICALGORITHM_H
#define PROJEKT_CGENETICALGORITHM_H


#include "CIndividual.h"
#include "CKnapsackProblem.h"

class CGeneticAlgorithm {
public:
    CGeneticAlgorithm();

    CGeneticAlgorithm(int iPopulationSize, int iIterations, float fMutationChance, float fCrossoverChance);

    void run(CKnapsackProblem &cProblem);

    CIndividual *getBestIndividual() const;

private:
    int i_population_size;
    int i_iterations;
    float f_crossover_chance;
    float f_mutation_chance;
    CIndividual *c_best_individual;
    std::vector<CIndividual *> vc_population;
    std::default_random_engine generator;

    void initPopulation(int iGenotypeLength);

    void calcFitness(CKnapsackProblem &cProblem);

    void makeCrossover();

    void makeMutation();
};


#endif //PROJEKT_CGENETICALGORITHM_H
