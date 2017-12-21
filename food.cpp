//
//  food.cpp
//  CplusAlgorithm_PNU2017
//
//  Created by MJMacBook on 2017. 12. 21..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
using namespace std;

int count = 0;
class Edge
{
public:
    int u;  //
    int v;  //
    Edge(int u, int v);
};

Edge::Edge(int u, int v)
{
    this -> u = u;
    this -> v = v;
}

class Graph
{
    int V;
    int E;
    list<int> *adj;
  
public:
    Graph(int V);
    void addEdge(int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}

int main()
{
    ifstream inp("");
    
    return 0;
}
