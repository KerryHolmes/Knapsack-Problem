#include "knapsack.hpp"
#include <vector>
#include <iostream>
#include <random>

int main(int argc, char* argv[])
{
    std::vector<int> values (10), weights (10);
    std::srand(0);

    for(int i = 0; i < 10; ++i)
    {
        values[i] = rand() % 20;
        weights[i] = rand() % 10;    
    }

    for(int i = 0; i < values.size(); ++i)
        std::cout << i << ": VAL: " << values[i] << " WT: " << weights[i] << std::endl;

    auto results = knapsack(values, weights, 10);

    for(int i = 0; i < results.size(); ++i)
        std::cout << i << ": " << results[i] << std::endl;

    return 0;
}