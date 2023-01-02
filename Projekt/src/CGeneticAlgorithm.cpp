//
// Created by Mateusz Ptak on 30/12/2022.
//

#include <iostream>
#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm() {
    i_population_size = 0;
    i_iterations = 0;
    f_crossover_chance = 0;
    f_mutation_chance = 0;
    c_best_individual = nullptr;
}

CGeneticAlgorithm::CGeneticAlgorithm(int iPopulationSize, int iIterations, float fMutationChance,
                                     float fCrossoverChance) {
    if (iPopulationSize > 0) {
        i_population_size = iPopulationSize;
    } else {
        std::cout << "Population size must be greater or equal 0" << std::endl;
        i_population_size = 0;
    }

    if (iIterations > 0) {
        i_iterations = iIterations;
    } else {
        std::cout << "Iterations must be greater or equal 0" << std::endl;
        i_iterations = 0;
    }
    
    f_crossover_chance = fCrossoverChance;
    f_mutation_chance = fMutationChance;
    c_best_individual = nullptr;
}

void CGeneticAlgorithm::run(CKnapsackProblem &cProblem) {
    c_best_individual = nullptr;
    initPopulation(cProblem.getNumberOfItems());
    calcFitness(cProblem);

    for (int i = 0; i < i_iterations; i++) {
//        std::cout << "Iteration: " << i + 1 << std::endl;
        makeCrossover();
        makeMutation();
        calcFitness(cProblem);
    }
}

void CGeneticAlgorithm::initPopulation(int iGenotypeLength) {
    std::uniform_int_distribution<int> random(0, 1);

    for (int i = 0; i < i_population_size; i++) {
        std::vector<bool> vbGenotype;

        for (int j = 0; j < iGenotypeLength; j++) {
            vbGenotype.push_back(random(generator));
        }

        vc_population.push_back(new CIndividual(vbGenotype, iGenotypeLength));
    }
}

void CGeneticAlgorithm::calcFitness(CKnapsackProblem &cProblem) {
    for (int i = 0; i < i_population_size; i++) {
        vc_population[i]->calcFitness(cProblem);
        float fFitness = vc_population[i]->getFitness();

        if (c_best_individual == nullptr || fFitness > c_best_individual->getFitness()) {
            c_best_individual = vc_population[i];
        }
    }
}

void CGeneticAlgorithm::makeCrossover() {
    std::uniform_int_distribution<int> randomParent(0, i_population_size - 1);
    std::uniform_int_distribution<int> random(0, 100);
    std::vector<CIndividual *> vcNewPopulation;

    for (int i = 0; i < i_population_size / 2; i++) {
        int iParent1 = randomParent(generator);
        int iParent2 = randomParent(generator);

        if (random(generator) / 100.0 < f_crossover_chance) {
            std::vector<CIndividual *> vcChildren = vc_population[iParent1]->cross(*vc_population[iParent2]);

            vcNewPopulation.push_back(vcChildren[0]);
            vcNewPopulation.push_back(vcChildren[1]);
        } else {
            vcNewPopulation.push_back(vc_population[iParent1]);
            vcNewPopulation.push_back(vc_population[iParent2]);
        }
    }

    if (i_population_size % 2 == 1) {
        int iParentIndex = randomParent(generator);
        vcNewPopulation.push_back(vc_population[iParentIndex]);
    }

    vc_population = std::move(vcNewPopulation);
}

void CGeneticAlgorithm::makeMutation() {
    for (int i = 0; i < i_population_size; i++) {
        vc_population[i]->mutate(f_mutation_chance);
    }
}

CIndividual *CGeneticAlgorithm::getBestIndividual() const {
    return c_best_individual;
}
