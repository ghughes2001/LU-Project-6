// File: GrapgForMinimum.hpp
// Author: Grant H
// Date: 4/2023
// Purpose: Implementation for finding the minimum cost using union-find and Kruskal's algorithm

#include "Minimum.hpp"

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void
Minimum::createEdge(int v)
{
    _parent = new int[v];
    _rank = new int[v];

    for (int i = 0; i < v; i++)
    {
        _parent[i] = -1;
        _rank[i] = 1;
    }
}

int
Minimum::find(int node)
{
    if (_parent[node] == -1)
        return node;
    
    return _parent[node] = find(_parent[node]);
}

void
Minimum::unionFind(int x, int y)
{
    int node1 = find(x);
    int node2 = find(y);

    // comparing checking if ranks higher
    if (node1 != node2)
    {
        if (_rank[node1] > _rank[node2])
        {
            _parent[node2] = node1;
        }
        else if (_rank[node1] < _rank[node2])
        {
            _parent[node1] = node2;
        }
        else
        {
            _parent[node2] = node1; // anyone can be parent b/c same rank
            _rank[node1] += 1; // increase rank
        }
    }
}

int
Minimum::findMinimumCost(map<string, vector<pair<string, int>>> &graph, int vertexes, vector<pair<int, pair<string, string>>> &edge, map<string, int> v)
{
    //declaring variables
    int i = 0;
    long long unsigned int j = 0;
    int sum = 0;
    vector<pair<string, int>> minimumCost;

    //sorting by edges and aking sure it does it by the integers
    sort(edge.begin(), edge.end(), [](const std::pair<int, pair<string, string>> &left, const std::pair<int, pair<string, string>> &right) {
    return left.first < right.first;
    });

    while (i < vertexes - 1 && j < edge.size())
    {
        pair<int, pair<string, string>> currEdge = edge.at(j); // variable for currEdge
        string name1 = currEdge.second.first; // getting the first string for currEdge
        string name2 = currEdge.second.second; // getting second string in currEdge

        int parent = find(v.at(name1));
        int nodeToParent = find(v.at(name2));

        if (parent == nodeToParent) // checks for cycle
        {
            j++; // iterate to the j so we look at next
            continue; // goes back up to loop
        }
        unionFind(parent, nodeToParent); // not a cycle so combine them
        sum = sum + currEdge.first; //adding the minimum edges to get cost
    }
    return sum;
}