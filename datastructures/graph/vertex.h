/*
 * vertex.h
 *
 *  Created on: Jun 2, 2013
 *      Author: billy
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "edge.h"

#include <stdlib.h>

template<class T>
class Vertex {
public:
    Vertex(T element);
    virtual ~Vertex();

    bool operator==(const Vertex & other);
    bool operator!=(const Vertex & other);

    T element() const;
    Vertex<T> * next();
    void setNext(Vertex<T> * next);
    Edge<T> * edges();

    int addEdge(Edge<T> * edge);
private:
    T m_element;
    Vertex<T> * m_next;
    Edge<T> * m_edges;
};


template<class T>
Vertex<T>::Vertex(T element)
    : m_element(element), m_next(0), m_edges(0)
{

}


template<class T>
Vertex<T>::~Vertex()
{

}


template<class T>
bool Vertex<T>::operator==(const Vertex<T> & other)
{
    return m_element == other.element();
}


template<class T>
bool Vertex<T>::operator!=(const Vertex<T> & other)
{
    return m_element != other.element();
}


template<class T>
T Vertex<T>::element() const
{
    return m_element;
}


template<class T>
Vertex<T> * Vertex<T>::next()
{
    return m_next;
}


template<class T>
void Vertex<T>::setNext(Vertex<T> * next)
{
    m_next = next;
}


template<class T>
Edge<T> * Vertex<T>::edges()
{
    return m_edges;
}


template<class T>
int Vertex<T>::addEdge(Edge<T> * edge)
{
    return EXIT_SUCCESS;
}


#endif /* VERTEX_H_ */
