#include "Edge.hpp"

Edge::Edge()
:index(0), flow(0), residu(0), capacity(0), nodes(2)
{
	nodes.resize(0);
}


/*
	Sets the 2 nodes connected by the calling edge
*/
int Edge::setNodes(Noeud* n1, Noeud* n2){
	assert(nodes.empty()); //Check wether vector is initially empty
	nodes.push_back(n1);
	nodes.push_back(n2);
	return 1;
}
