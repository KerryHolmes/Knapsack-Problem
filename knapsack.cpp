#include <iostream>
#include <vector>
#include "knapsack.hpp"

using vector = std::vector<int>;
using table = std::vector<std::vector<int>>;

vector 
knapsack(vector values, vector weights, int weight_lim)
{
    table subproblems = (values.size() + 1, vector(weight_lim + 1 , 0));
    vector solution = vector(values.size(), 0);

    for(int i = 1; i < values.size(); ++i)
    {
        for(int j = 0; j < weight_lim; ++j)
        {
            if(weights[i] > j)
            {
                subproblems[i][j] = subproblems[i-1][j];
            }
            else
            {
                subproblems[i][j] = std::max(subproblems[i-1][j], 
                                    subproblems[i-1][j-weights[i]] + values[i]);
                solution[i] = 1;
            }
        }
    }
    
    return solution;
}