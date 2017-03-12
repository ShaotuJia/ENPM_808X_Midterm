//============================================================================
// Name        : Mid_Term_Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * This project is to use A star algorithm to find path
 * in a given map and without hit any obstacle
 */
#include <iostream>
#include <memory>
#include <cmath>
#include "map.hpp"
#include "node.hpp"


using namespace std;


//Node start(1,1); //start point
//shared_ptr<Node> start=make_shared<node>(1,1);
//Node goal(5,5); //end point
//Node current =start;
vector<Node> openSet;
vector<Node> closeSet;
Map map(5,5);
vector<Node> path;

/*
 * This function is to compute heuristic_estimate cost using Manhattan distance
 */
int heuristic (Node current, Node goal)
{
	return abs(current.col-goal.col)+abs(current.row-goal.row);
}

void removeElment(vector<Node> Set, Node current)
{
	for (vector<Node>::iterator iter =0; iter != Set.end(); iter++)
	{
		if (*iter==current)
			Set.erase(iter);
	}
}


void findNeighbors(Node current)
{
	if (current.row !=1)
		{
		   Node neighbor(current.row-1, current.col);
		   current.neighbors.push_back(neighbor);
		}
	if (current.row != map.rowSize)
	{
		Node neighbor(current.row+1, current.col);
		current.neighbors.push_back(neighbor);
	}

	if (current.col !=1)
			{
			   Node neighbor(current.row, current.col-1);
			   current.neighbors.push_back(neighbor);
			}
		if (current.col != map.colSize)
		{
			Node neighbor(current.row, current.col+1);
			current.neighbors.push_back(neighbor);
		}

}

void findPath(Node start, Node goal)
{
	Node current=start;
	vector<Node> openSet={start};
	vector<Node> closeSet={};
	current.g=0;
	current.h=heuristic(current,goal);
	current.f=current.g+current.h;
	current.previous={};

	while (!openSet.empty())
	{
		Node winner=start;
		for (vector<Node>::iterator iter=openSet.begin(); iter !=openSet.end();iter++)
		{
			if ((*iter).f < winner)
				winner= *iter;
		}

		//set the node with min F as current node
		current=winner;

		/*
		 * Path reconstruction
		 */
		//set start.previous as (0,0)
		start.previous(0,0);

		if (current == goal)
		{
			Node temp=current;
			path.push_back(temp);
			while (temp.previous.row!=0)
			{
				path.push_back(temp.previous);
				temp=temp.previous;

			}
		}

		/*
		 * update openSet and closeSet
		 * remove current from openSet
		 * add current to closeSet
		 */





	}



}

int main() {

	/*
	 * overloaded equal operator test
	 */
	/*
	node a(1,1);
	node b(1,1);

	if (a==b) cout<<"a==b";
	else cout<<"a!=b";
	*/


	/*
	 * Test parameter initializtion functions
	 */
	//shared_ptr<> pid = make_shared < PID > (0.1, 0.01, 0.5)







	return 0;
}

