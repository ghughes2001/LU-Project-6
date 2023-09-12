// File: main.hpp
// Author: Grant Hughes
// Date: 4/2023
// Purpose: file o run program

#include "Minimum.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int
main(int argc, char *argv[])
{
    string arr;
    string name1;
    string name2;
    string cost;

    vector<pair<int, pair<string, string>>> edgeList;
    map <string, vector<pair<string, int>>> graph;
    map<string, int> vertex;
    int counter = 0;

    fstream file;
    file.open(argv[1], ios::in);

    if (file.is_open()) //making sure file is open for reading it
    {
        while (!file.eof())
        {
            file >> name1 >> name2 >> cost;

            edgeList.push_back(make_pair(atoi(cost.c_str()), make_pair(name1, name2)));

            if (graph.find(name1) == graph.end())
            {
                //create one vector
                vector <pair<string, int>> n1;
                //insert pair into vector
                n1.push_back(make_pair(name2, atoi(cost.c_str())));
                //insert vector into map
                graph.insert({name1, n1});
                vertex.insert({name1, counter});
                counter++;
            }
            else //already have one able to create
            {
                graph[name1].push_back(make_pair(name2, atoi(cost.c_str())));
            }

            if (graph.find(name2) == graph.end())
            {
                //create one vector
                vector <pair<string, int>> n2;
                //insert pair into vector
                n2.push_back(make_pair(name1, atoi(cost.c_str())));
                //insert vector into map
                graph.insert({name2, n2});
                vertex.insert({name2, counter});
                counter++;
            }
            else ////already have one able to create
            {
                graph[name2].push_back(make_pair(name1, atoi(cost.c_str())));
            }
        }
    }
    Minimum min;
    min.createEdge(graph.size());
    int lowestCost = min.findMinimumCost(graph, graph.size(), edgeList, vertex);

    cout << "Minimum cost set: " << lowestCost << endl;

    return 0;
}