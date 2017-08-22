#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "stdint.h"
// #include "Noeud.hpp"
#include <cassert>
#include <vector>

using namespace std;

class Noeud;

class Edge
{
private:
	vector<Noeud*> nodes; // Tableau de pointeurs vers les vrais elements
public:
	uint32_t capacity;
	uint32_t index;	 // Index in static tab, value given at tab init

	uint32_t flow;
	uint32_t residu;

	Edge();
	bool isPushable();
	int setNodes(Noeud* n1, Noeud* n2);
	
}; //class Edge


#endif