#include "Edge.hpp"

Edge::Edge()
:_index(0), _flow(0), _residu(0), _capacity(0), _nodes(2)
{
	_nodes.resize(0);
}


/*
	Sets the 2 nodes connected by the calling edge
*/
int Edge::setNodes(Noeud* n1, Noeud* n2){
	assert(_nodes.empty()); //Check wether vector is initially empty
	_nodes.push_back(n1);
	_nodes.push_back(n2);
	return 1;
}
