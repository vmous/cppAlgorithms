/*
 * graph_test.cpp
 *
 *  Created on: Jun 2, 2013
 *      Author: billy
 */

#include "graph.h"
#include "vertex.h"
#include "edge.h"

#include <iostream>
#include <stdlib.h>


Graph<int> * initializeGraph();
void finalizeGraph(Graph<int> * g);
void testCountVertices();


int main (int argc, char ** argv)
{
    testCountVertices();

    return EXIT_SUCCESS;
}


Graph<int> * initializeGraph()
{
    Vertex<int> * _01 = new Vertex<int>(1);
    Vertex<int> * _02 = new Vertex<int>(2);
    Vertex<int> * _03 = new Vertex<int>(3);
    Vertex<int> * _04 = new Vertex<int>(4);
    Vertex<int> * _05 = new Vertex<int>(5);
    Vertex<int> * _06 = new Vertex<int>(6);

    Graph<int> * g = new Graph<int>();

    g->addVertex(_01);
    g->addVertex(_02);
    g->addVertex(_03);
    g->addVertex(_04);
    g->addVertex(_05);
    g->addVertex(_06);

    return g;
}


void finalizeGraph(Graph<int> * g)
{
    g->destroy();
}


void testCountVertices()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    Graph<int> * g = initializeGraph();

    std::cout << "Graph vertices count: " << g->countVertices() << "." << std::endl;
    g->destroy();
    std::cout << "Graph vertices count: " << g->countVertices() << "." << std::endl;

    g->destroy();
    std::cout << std::endl;
}
