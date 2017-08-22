#include "Noeud.hpp"
#include <iostream>

Noeud::Noeud()
:_edges(6), _index(0), _height(0), _excess(0)
{
	_edges.resize(0);
}

STNoeud::STNoeud(int nb_edges, int height, int excess)
{
	_edges  = vector<Edge*>(nb_edges);
	_height = height;
	_excess = excess;
	_edges.resize(0);
}

/*
	Set arc as an edge between calling instance and otherNode
*/
int Noeud::setEdge(Edge* arc, Noeud* otherNode){
	arc->setNodes(this, otherNode);
	this->     _edges.push_back(arc);
	otherNode->_edges.push_back(arc);
	return 1;
}