/*
 * graph.h
 *
 *  Created on: Jun 2, 2013
 *      Author: billy
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "vertex.h"
#include "edge.h"

#include <iostream>

template<class T>
class Graph {
public:
    Graph();
    virtual ~Graph();

    void destroy();

    Vertex<T> * getVertices();
    void setVertices(Vertex<T> * vertices);
    bool addVertex(Vertex<T> * vertex);
    int countVertices();


private:
    Vertex<T> * m_vertices;
    int m_nvertices;
    int m_nedges;
    bool m_directed;
};


template<class T>
Graph<T>::Graph()
    : m_vertices(0), m_nvertices(0), m_nedges(0), m_directed(false)
{

}


template<class T>
Graph<T>::~Graph()
{

}


template<class T>
void Graph<T>::destroy()
{
    // TODO: Destroy edges and vertices!
}


template<class T>
Vertex<T> * Graph<T>::getVertices()
{
    return m_vertices;
}


template<class T>
void Graph<T>::setVertices(Vertex<T> * vertices)
{
    m_vertices = vertices;
}


template<class T>
bool Graph<T>::addVertex(Vertex<T> * vertex)
{
    if (!m_vertices)
    {
        m_vertices = vertex;
        return true;
    }

    Vertex<T> * prev = 0;
    Vertex<T> * curr = m_vertices;


    while (curr)
    {
        if (*curr == *vertex)
        {
            std::cout << "Vertex " << vertex->element() << " already present." << std::endl;
            return false;
        }

        prev = curr;
        curr = curr->next();
    }

    if (!curr)
    {
        prev->setNext(vertex);
        return true;
    }

    return false;
}


template<class T>
int Graph<T>::countVertices()
{
    Vertex<T> * v = m_vertices;
    int counter = 0;

    while (v)
    {
        counter++;
        v = v->next();
    }

    return counter;
}


#endif /* GRAPH_H_ */

