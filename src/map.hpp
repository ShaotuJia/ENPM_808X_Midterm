/*
 * map.hpp
 *
 *  Created on: Mar 10, 2017
 *      Author: viki
 */

#ifndef MAP_HPP_
#define MAP_HPP_
/*
 * This class is to save map information for path finding
 * Bitmap used path finding
 * The bitmap canvas is rectangle and the origin is up-left corner
 * @param
 * @func labelNode This fuction is to label each grid as a No. for linklist
 */

using namespace std;

class Map{
public:
	int rowSize =5; // the map size in x-axis
	int colSize = 5; // the map size in y-axis
	//node start; //start node
	//node goal; //goal node
	//node obstacle;
	//vector<node> obstacleList;

	//Map(int rowmax, int colmax):rowSize(rowmax),colSize(colmax){}
	//void getStart(int x,int y);
	//void getGoal(int x, int y);
	//void getobstacles();
	//void setMapSize(int x, int y);


};
















#endif /* MAP_HPP_ */
