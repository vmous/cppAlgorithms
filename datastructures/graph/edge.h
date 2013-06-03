/*
 * edge.h
 *
 *  Created on: Jun 2, 2013
 *      Author: billy
 */

#ifndef EDGE_H_
#define EDGE_H_

template<class T>
class Edge {
public:
    Edge();
    virtual ~Edge();

    int weight();
private:
    int m_weight;
};


template<class T>
Edge<T>::Edge()
    : m_weight(0)
{

}


template<class T>
Edge<T>::~Edge()
{

}


template<class T>
int Edge<T>::weight()
{
    return m_weight;
}


#endif /* EDGE_H_ */
