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
#include <stdio.h>
#include "map.hpp"
#include "node.hpp"


using namespace std;



//shared_ptr<Node> start=make_shared<node>(1,1);
//Node current =start;
//vector<Node> openSet;
//vector<Node> closedSet;
//vector<Node> path={};


Map map;
Node start(0,0); //start point
Node goal(4,4); //end point
vector<int> path;




/*
 * This function is to compute heuristic_estimate cost using Manhattan distance
 */
int heuristic (Node current, Node goal)
{
	return abs(current.col-goal.col)+abs(current.row-goal.row);
}



bool operator == (Node a, Node b) throw(){

		if (a.row==b.row && a.col==b.col)
			return true;
		else return false;
	}

#if 0

//wrong function
void remove(vector<int>& Set, int current)
{

	for (vector<int>::iterator i= Set.begin(); i!=Set.end(); i++)
	{
		if ((*i)==current && Set.size()>1)
			Set.erase(i);
		else Set.clear();
	}
}
#endif


//new remove function
void remove(vector<int>& Set, int current)
{
	vector<int>::iterator it;
	it=find(Set.begin(),Set.end(),current);
	if (it != Set.end())
	Set.erase(it);
}

int main()
{
	vector<Node> dataSet;

			for (int j=0; j< map.rowSize;++j)
			{
			for (int i=0; i< map.colSize; ++i)
				{
				  Node temp(j,i);
				  temp.neighborlabels={};
				  temp.h= heuristic(temp, goal);
				  if (j != 0)
					  temp.neighborlabels.push_back(temp.label-map.rowSize);

				  if (j != map.rowSize-1)
				      temp.neighborlabels.push_back(temp.label+map.rowSize);

				  if (i != 0)
				  	  temp.neighborlabels.push_back(temp.label-1);

				  if (i != map.colSize-1)
					  temp.neighborlabels.push_back(temp.label+1);

				  dataSet.push_back(temp);


				   }
			}

		dataSet[start.label].previouslabel=-1;
		int current=start.label;
		vector<int> openSet;
		vector<int> closedSet;

		openSet={current};
		//openSet.push_back(current);


		dataSet[current].g=0;
		dataSet[current].f=dataSet[current].g+dataSet[current].h;


		while (! openSet.empty())

		{

			int winner=openSet[0];


			for (int i=0; i< openSet.size(); i++)
			{

				if (dataSet[openSet[i]].f<dataSet[winner].f)
					winner=openSet[i];
			}

			current=winner;

			if (current==goal.label)
			{

				cout<<"find goal"<<endl;


				int temp=current;
				path.push_back(temp);


				while (dataSet[temp].previouslabel != -1)
				{
					path.push_back(dataSet[temp].previouslabel);
					temp=dataSet[temp].previouslabel;
				}

				//print out
				cout<<"path: ";
				for (auto x: path)
				{
					cout<<x<<" ";
				}
				cout<<endl;
				return 0;

			}

            //test current and delete later
            getchar();
            cout<<"current: "<<current<<endl;

            /**********************************/

            if (openSet.size()>1)
			remove(openSet,current);
            else openSet.clear();

            //test and delete later
            cout<<"pass remove: current "<<current<<endl;
            getchar();


            closedSet.push_back(current);

            //delete above later




			vector<int> neighbors= dataSet[current].neighborlabels;

			//test neighborlabels and delete after
			cout<<"neighbors: ";
			for (auto x: neighbors)
			{
				cout<<x<<" ";
			}
			cout<<endl;



			for (int j=0; j< neighbors.size(); j++)
			{
				int neighbor=neighbors[j];

				vector<int>::iterator iterClose;
		    	 iterClose=find (closedSet.begin(),closedSet.end(),neighbor);

				 if (iterClose == closedSet.end())
				 {
					 double tempG=dataSet[current].g+1;

					 vector<int>::iterator iterOpen;
					 iterOpen= find(openSet.begin(),openSet.end(),neighbor);

					 if (iterOpen != openSet.end())
					 {
						 if (tempG < dataSet[neighbor].g)
							 {
							   dataSet[neighbor].g = tempG;
							 }
					 }

					 else
					 {

						 dataSet[neighbor].g = tempG;



						 //test and delete later
						 getchar();

						 cout<<"neighbor = "<<neighbor<<endl;
						 openSet.push_back(neighbor);

                         cout<<"Size of openSet: "<<openSet.size()<<endl;
						 cout<<"openSet: ";

						 for(int i=0; i<openSet.size(); i++)
						 {
							 cout<<openSet[i]<<" ";
						 }
						 cout<<endl;

						 cout<<" closedSet: ";
						 for(auto x: closedSet)
						 {
							 cout<<x<<" ";
						 }
						 cout<<endl;

						 // delete above after test









						 /*

						 if (openSet.empty())
						 {
							 openSet={neighbor};

						 }
						 else
						 {
                             openSet.push_back(neighbor);
						 }
						 */

					 }

					 dataSet[neighbor].f=dataSet[neighbor].g+ dataSet[neighbor].h;

					 dataSet[neighbor].previouslabel=current;

				 }


			}


		}



}

