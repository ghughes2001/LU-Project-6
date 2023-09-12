// File: GrapgForMinimum.hpp
// Author: Grant H
// Date: 4/2023
// Purpose: Definition of fininding mimnimum cost

#ifndef _MINIMUM_HPP_
#define _MINIMUM_HPP_

#include <iostream>
#include <map>
#include <vector>

class Minimum
{
    private:
        int *_parent;
        int *_rank;
    public:
        Minimum(): _parent(nullptr), _rank(nullptr) {}


        //creating edges
        void createEdge(int v);
        //method for locating edge
        int find(int node);
        //adding edges
        void unionFind(int x, int y);
        // find the minimum cost set of phone lines that would allow all islands to be able to call each
        int findMinimumCost(std::map<std::string, std::vector<std::pair<std::string, int>>> &graph, int vertexes, std::vector<std::pair<int, std::pair<std::string, std::string>>> &edge, std::map<std::string, int> v);
};

#endif