/*
 * findPath.hpp
 *
 *  Created on: Mar 10, 2017
 *      Author: viki
 */

#ifndef FINDPATH_HPP_
#define FINDPATH_HPP_


#if 0
void findPath(Node start, Node goal, vector<Node> path)
{
	vector<Node> dataset=dataSet();

	Node current=start;

	Node Negative(-1,-1);
	vector<Node> openSet;
	vector<Node> closedSet={};
	openSet.push_back(Negative);

	openSet.push_back(current);
/*
	vector<int> openSet={};
    vector<int> closedSet={};
    openSet.push_back(current.label);
*/
	current.g=0;
	current.h=heuristic(current,goal);
	current.f=current.g+current.h;
	current.previous={};

	cout<<current.row<<" "<<current.col;

	while (!openSet.empty())
	{
		Node winner=start;


		for (vector<Node>::iterator iter=openSet.begin(); iter !=openSet.end();iter++)
		{
			if ((*iter).f < winner.f)
				winner= *iter;
		}

/*
		for (vector<int>::iterator iter=openSet.begin(); iter!= openSet.end(); iter++)
		{

		}
		*/
		/*
		for (vector<int>::iterator iter=openSet.begin();iter != openSet.end(); iter++)
		{
			if
		}
		*/

		//set the node with min F as current node
		current=winner;

		/*
		 * Path reconstruction
		 */
		//set start.previous as (0,0)

		if (current == goal)
		{
			Node temp=current;
			path.push_back(temp);
			while (! temp.previous.empty())
			{
				path.push_back(*(temp.previous.begin()));
				temp=*(temp.previous.begin());

			}
		}

		/*
		 * update openSet and closeSet
		 * remove current from openSet
		 * add current to closeSet
		 */
    	removeElement(openSet,current);

		closedSet.push_back(current);

		findNeighbors(current);

		for (vector<Node>::iterator iterN =current.neighbors.begin(); iterN != current.neighbors.end(); iterN++)
		{
			//Check whether current. neighbor in closedSet
			vector<Node>::iterator itClose;
			itClose=find(closedSet.begin(),closedSet.end(),*iterN);

			if (itClose == closedSet.end())
			{	double tempG=current.g+1;

			//Check whether current.neighbor in openSet
			vector<Node>::iterator itOpen;
			itOpen=find(openSet.begin(),openSet.end(),*iterN);
			if (itOpen!=openSet.end())
			{
				if (tempG<(*iterN).g)
					(*iterN).g=tempG;
			} else
			{
				(*iterN).g=tempG;
				openSet.push_back(*iterN);
			}

			(*iterN).h=heuristic(*iterN,goal);
			(*iterN).f=(*iterN).g+(*iterN).h;
			*((*iterN).previous.begin())=current;


			}


		}


	}



}


#endif


#if 0

int main() {


	Node start(1,1);
	Node goal(5,5);

	//cout<<start.col<<" "<<start.row;

	vector<Node> path;



	findPath(start,goal,path);

/*
	vector<Node> openlist;
	openlist.push_back(start);
	openlist.push_back(goal);

	//removeElement(openlist,start);
	//vector<Node>::iterator iter=openlist.begin();
	//cout<<(*iter).col<<" "<<(*iter).row;
	//removeElement(openlist,goal);

*/


	//int h=heuristic(start,goal);
	//cout<<h;


/*
	if (path.empty())
		cout<<" the path is empty";
	else
		cout<<" path has element";

*/
	/*
	//print path
	for (vector<Node>::iterator i=path.begin(); i !=path.end(); i++)
	{
		cout<<*i<<" ";
	}
	*/

	//cout<<"This is good";


	return 0;
}

#endif



#endif /* FINDPATH_HPP_ */
