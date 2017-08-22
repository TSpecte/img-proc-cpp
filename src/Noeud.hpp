#ifndef _NODE_HPP_
#define _NODE_HPP_

#include "stdint.h"
#include "Edge.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Noeud
{

protected:
	uint32_t _index;	 // Index in static tab, value given at tab init
	uint32_t _height; // Push-relabel height
	uint32_t _excess; // Push-relabel excess
	vector<Edge*> _edges; // Tableau de pointeurs vers les vrais elements

public:

	Noeud();
	int setEdge(Edge* arc, Noeud* otherNode);
	vector<Edge*> getEdgeList()   {return _edges;}
	const uint32_t index()  const {return _index;}  //R-value
	uint32_t&      index()        {return _index;}  //L-value
	const uint32_t height() const {return _height;} //R-value
	uint32_t&      height()       {return _height;} //L-value
	const uint32_t excess() const {return _excess;} //R-value
	uint32_t&      excess()       {return _excess;} //L-value


}; //class Noeud

class STNoeud : public Noeud
{
public:
	STNoeud(int nb_edges, int height, int excess);
}; //class STNoeud


#endif 