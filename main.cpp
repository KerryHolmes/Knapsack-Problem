#include "knapsack.hpp"
#include <vector>
#include <iostream>
#include <random>

constexpr int NUM_ITEMS = 10;
constexpr int MAX_WEIGHT = 10;

int main(int argc, char* argv[])
{
    //Declare and initialize random weights and values for items
    std::vector<int> values (NUM_ITEMS), weights (NUM_ITEMS);
    std::srand(0);

    for(int i = 0; i < NUM_ITEMS; ++i)
    {
        values[i] = rand() % 20;
        weights[i] = rand() % 10;    
    }
    //Display the generated data
    for(int i = 0; i < values.size(); ++i)
        std::cout << i << ": VAL: " 
        << values[i] << " WT: " << weights[i] << std::endl;
    
    //Call the knapsack function on this data and store the result.
    auto results = knapsack(values, weights, MAX_WEIGHT);

    //Display the result
    for(int i = 0; i < results.size(); ++i)
        std::cout << i << ": " << results[i] << std::endl;

    return 0;
}