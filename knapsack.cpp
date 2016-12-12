#include <iostream>
#include <vector>
#include "knapsack.hpp"

using vector = std::vector<int>;
using table = std::vector<std::vector<int>>;

vector 
knapsack(vector values, vector weights, int weight_lim)
{
    table subproblems(values.size() + 1, vector(weight_lim + 1 , 0));
    table inclusion(values.size() + 1, vector(weight_lim + 1 , 0));
    vector solution;
    
    for(int i = 1; i < values.size(); ++i)
    {
        for(int j = 0; j < weight_lim; ++j)
        {
            if(weights[i] > j)
            {
                subproblems[i][j] = subproblems[i-1][j];
            }
            else if((subproblems[i-1][j-weights[i]] + values[i]) 
                     > subproblems[i-1][j] )
            {
                subproblems[i][j] = subproblems[i-1][j-weights[i]] + values[i];
                inclusion[i][j] = 1; 
            }
            else
            {
                subproblems[i][j] = subproblems[i-1][j];
            }
        }
    }

    int W = weight_lim;

    for(int i = inclusion.size()-1; i >= 0; --i)
    {
        if(inclusion[i,W] == 1)
        {
            solution.push_back(i);
            W -= weights[i];
        }
    }
    
    return solution;
}