#include "Noeud.hpp"
#include <iostream>

Noeud::Noeud()
:edges(6), index(0), height(0), excess(0)
{
	edges.resize(0);
}


/*
	Set arc as an edge between calling instance and otherNode
*/
int Noeud::setEdge(Edge* arc, Noeud* otherNode){
	arc->setNodes(this, otherNode);
	this->     edges.push_back(arc);
	otherNode->edges.push_back(arc);
	return 1;
}