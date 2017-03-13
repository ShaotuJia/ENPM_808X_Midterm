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
#include <algorithm>
#include "map.hpp"
#include "node.hpp"


using namespace std;



//shared_ptr<Node> start=make_shared<node>(1,1);
//Node current =start;
//vector<Node> openSet;
//vector<Node> closedSet;
//vector<Node> path={};

Map map;
Node start(1,1); //start point
Node goal(5,5); //end point
vector<int> path;






/*
 * This function is to compute heuristic_estimate cost using Manhattan distance
 */
int heuristic (Node current, Node goal)
{
	return abs(current.col-goal.col)+abs(current.row-goal.row);
}





/*
bool operator == (Node a, Node b) throw(){

		if (a.row==b.row && a.col==b.col)
			return true;
		else return false;
	}
*/

void remove(vector<int>& Set, int current)
{
	for (vector<int>::iterator i= Set.begin(); i!=Set.end(); i++)
	{
		if ((*i)==current)
			Set.erase(i);
	}
}


void removeElement(vector<Node>&Set, Node current)
{
	for (vector<Node>::iterator i=Set.begin(); i!=Set.end();i++)
	{
		if ((*i)==current)
			Set.erase(i);
	}
}

/*
void removeElement(vector<Node>& Set, Node current)
{

	for (vector<Node>::iterator i=Set.begin(); i != Set.end(); i++)
	{

		if (*i==current)
		{
			Set.erase(i);

		}


		if (*i==current)
		{
			(*i).col=0;
		    (*i).row=0;
		}
*/

void findNeighbors(Node& current)
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


vector<Node> dataSet()
{
	vector<Node> data;
	for (int j=1; j<= map.rowSize;j++)
	{
	for (int i=1; i<= map.colSize; i++)
		{
		  Node temp(j,i);
		  temp.h= heuristic(temp, goal);
		  if (j != 1)
			  temp.neighborlabels.push_back(temp.label-map.rowSize);

		  if (j != map.rowSize)
		      temp.neighborlabels.push_back(temp.label+map.rowSize);

		  if (i != 1)
		  	  temp.neighborlabels.push_back(temp.label-map.colSize);

		  if (i != 1)
			  temp.neighborlabels.push_back(temp.label-map.colSize);

		  data.push_back(temp);
		}

     }
	return data;
}

vector<Node>data=dataSet();

void findPath()
{

	start.previouslabel=0;
	int current=start.label;
	vector<int> openSet;
	vector<int> closedSet;
	openSet.push_back(current);

	data[current].g=0;
	data[current].f=data[current].g+data[current].h;

	while (! openSet.empty())
	{
		int winner=1;
		for (int i=1; i<=openSet.size(); i++)
		{
			if (data[i].f<data[winner].f)
				winner=i;
		}

		current=winner;

		if (current==goal.label)
		{

			int temp=current;
			path.push_back(temp);

			while (data[temp].previouslabel != -1)
			{
				path.push_back(data[temp].previouslabel);
				temp=data[temp].previouslabel;
			}


			//print out
			for (auto x: path)
			{
				cout<<x<<" ";
			}

		}

		remove(openSet,current);
		closedSet.push_back(current);

		vector<int> neighbors= data[current].neighborlabels;

		for (int j=0; j< neighbors.size(); j++)
		{
			int neighbor=neighbors[j];

			vector<int>::iterator iterClose;
			 iterClose=find (closedSet.begin(),closedSet.end(),neighbor);
			 if (iterClose == closedSet.end())
			 {
				 double tempG=data[current].g+1;

				 vector<int>::iterator iterOpen;
				 if (iterOpen != openSet.end())
				 {
					 if (tempG<data[neighbor].g)
						 data[neighbor].g=tempG;
				 }
				 else
				 {
					 data[neighbor].g=tempG;
					 openSet.push_back(neighbor);
				 }

				 data[neighbor].f=data[neighbor].g+ data[neighbor].h;

				 data[neighbor].previouslabel=current;
			 }

		}




	}


}


int main()
{
	//vector<Node> data= dataSet();
	findPath();

	//cout<<data[1].col;


}
