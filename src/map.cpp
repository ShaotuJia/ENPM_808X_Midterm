/*
 * map.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: viki
 */

#include "map.hpp"

/*
void Map::setMapSize(int x, int y)
{
	rows=x;
	cols=y;
}
\*/

#if 0
void map::getStart(int x, int y)
{
	start.row=x;
	start.col=y;
}


void map::getGoal(int x, int y)
{
	goal.row=x;
	goal.col=y;

}


void map::getobstacles()
{

	do
	{

		cout<<"input row number for this obstacle\n";
		cin>>obstacle.row;
		cout<<"input column number for this obstacle\n";
		cin>>obstacle.col;

		if (rows > obstacle.row> 0 && cols > obstacle.col >0)
		break;
		else obstacleList.push_back(obstacle);

	}while(1);

}

#endif
