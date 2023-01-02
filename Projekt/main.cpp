#include <iostream>
#include "src/CGeneticAlgorithm.h"
#include "src/CKnapsackProblem.h"

void test_knapsack4_5() {
    CKnapsackProblem cProblem;
    CGeneticAlgorithm cAlgorithm(5, 100, 0.1, 0.65);

    cProblem.readFromFile(
            "/Users/mateusz/Desktop/Studia/Semestr III/[L] Techniki efektywnego programowania/Projekt/src/knapsack_4_5.txt");

    cAlgorithm.run(cProblem);

    std::cout << "Best individual (4_5): " << std::endl;
    cAlgorithm.getBestIndividual()->printGenotype();
}

void test_knapsack6_5() {
    CGeneticAlgorithm cAlgorithm(5, 100, 0.1, 0.65);
    CKnapsackProblem cProblem;

    cProblem.readFromFile(
            "/Users/mateusz/Desktop/Studia/Semestr III/[L] Techniki efektywnego programowania/Projekt/src/knapsack_6_5.txt");

    cAlgorithm.run(cProblem);

    std::cout << "Best individual (6_5): " << std::endl;
    cAlgorithm.getBestIndividual()->printGenotype();
}

int main() {
    test_knapsack4_5();
    test_knapsack6_5();

    return 0;
}
