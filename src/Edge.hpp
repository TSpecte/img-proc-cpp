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
	vector<Noeud*> _nodes; // Tableau de pointeurs vers les vrais elements
	uint32_t _capacity;
	uint32_t _index;	 // Index in static tab, value given at tab init
	uint32_t _flow;
	uint32_t _residu;
	
public:

	Edge();
	bool isPushable();
	int setNodes(Noeud* n1, Noeud* n2);
	const uint32_t index()    const {return _index;}  //R-value
	uint32_t&      index()          {return _index;}  //L-value
	const uint32_t capacity() const {return _capacity;} //R-value
	uint32_t&      capacity()       {return _capacity;} //L-value
	const uint32_t flow()     const {return _flow;} //R-value
	uint32_t&      flow()           {return _flow;} //L-value
	const uint32_t residu()   const {return _residu;} //R-value
	uint32_t&      residu()         {return _residu;} //L-value
	
}; //class Edge


#endif