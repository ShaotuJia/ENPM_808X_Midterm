/*
 * node.hpp
 *
 *  Created on: Mar 10, 2017
 *      Author: viki
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include<vector>
#include "map.hpp"
using namespace std;

/*
 * class node is save information for each node in map
 * @param coordinate This is array to save 2D coordinate (x,y) for node
 * @param g This is gScore, movement cost
 * @param h This is hScore, heuristic_cost_estimate between current point to goal point
 * @param f This is fScore, fScore=gScore+hScore, to evaluate each node
 * @param neighbor This is the neighbor node Number of current node
 * @param previous This is parent node of current node; used to reconstruct path
 *
 */

class Node
{
public:

	int colSize=5;
	int rowSize=5;
    int row;
    int col;
    Node(int x, int y):row(x),col(y){}
	double g=0;
	double h=0;
	double f=0;
	vector<int> neighborlabels;
	int previouslabel;
	vector<Node> neighbors;
	vector<Node> previous;
	int label=row*colSize+col; //label node with Number and easy for tracking


#if 0
	//overload operator == for node comparison
	friend bool operator == (Node a, Node b) throw(){

		if (a.row==b.row && a.col==b.col)
			return true;
		else return false;
	}
#endif


};


#endif /* NODE_HPP_ */
