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

private:

public:
	vector<Edge*> edges; // Tableau de pointeurs vers les vrais elements
	uint32_t index;	 // Index in static tab, value given at tab init
	uint32_t height; // Push-relabel height
	uint32_t excess; // Push-relabel excess

	Noeud();
	int setEdge(Edge* arc, Noeud* ohterNode);
	int getEdgesNb(){return edges.size();}

}; //class Node



#endif 