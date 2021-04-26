#ifndef __MAZE_H
#define __MAZE_H

class Point;

class Maze
{
public:
	void FinishMaze();
	void TakeOffWallBetweenNeighbors(const Point &curr, const Point& Neighbor);
	Point GetRandNeighbor(Point &point);
	void MarkAsVisited(Point &p);
	bool IsOnMaze(const Point &p);
	bool NotVisited(const Point & p);
	bool StillNotVisited(Point p);
	bool IsOnMazeAndNotVisited(Point p1);
	char **MakeNewMaze(int rows, int cols);
	void PrintMaze();
	void InitMaze();
	Point FindRandNeighbor(Point &point);

	void setRows(int rows);
	void setCols(int cols);
	void setMaze(char **maze);


	int getRows();
	int getCols();
	char **getMaze() const;
	
	Maze(int rows, int cols, char **maze = nullptr);
	~Maze();

private:
	int m_rows;
	int m_cols;
	char **m_maze;
};
#endif // ! __MAZE_H
