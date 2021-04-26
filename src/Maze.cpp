#include "Point.h"
#include "Maze.h"
#include "MainHeader.h"

Maze::Maze(int rows, int cols, char **maze)
{
	setRows(rows);
	setCols(cols);
	setMaze(maze);
}

Maze::~Maze()
{
	for (int i = 0; i < this->m_rows; i++)
		delete[] m_maze[i];
	delete m_maze;
}

void Maze::FinishMaze()
{
	int rows = this->m_rows;
	int cols = this->m_cols;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (m_maze[i][j] == '$')
				m_maze[i][j] = ' ';
}

void Maze::TakeOffWallBetweenNeighbors(const Point & curr, const Point & neighbor)
{
	Point wall((curr.m_row + neighbor.m_row) / 2, (curr.m_col + neighbor.m_col) / 2);
	m_maze[wall.m_row][wall.m_col] = '$';
}

Point Maze::GetRandNeighbor(Point & point)
{
#define RIGHT 0
#define LEFT 1
#define UP  2
#define DOWN 3
	Point Neighbor(point);
	int rand = getRand();
	if (rand == RIGHT)
		Neighbor.m_row += 2;
	if (rand == LEFT)
		Neighbor.m_row -= 2;
	if (rand == UP)
		Neighbor.m_col -= 2;
	if (rand == DOWN)
		Neighbor.m_col += 2;
#undef RIGHT 
#undef LEFT 
#undef UP 
#undef DOWN 
	return Neighbor;
}

void Maze::MarkAsVisited(Point & p)
{
	m_maze[p.m_row][p.m_col] = '$';
}

bool Maze::IsOnMaze(const Point &p)
{
	if ((p.m_row <= this->m_rows - 1) && p.m_row >= 0)
		if ((p.m_col <= this->m_cols - 1) && p.m_col >= 0)
				return true;
	return false;
}

bool Maze::StillNotVisited(Point p)
{
	if (IsOnMaze(p.PointLeft()))
	{
		if (IsOnMazeAndNotVisited(p.PointLeft()))
			return true;
	}
	if (IsOnMaze(p.PointRight()))
	{
		if (IsOnMazeAndNotVisited(p.PointRight()))
			return true;
	}
	if (IsOnMaze(p.PointUp())) {
		if (IsOnMazeAndNotVisited(p.PointUp()))
			return true;
	}
	if (IsOnMaze(p.PointDown())) {
		if (IsOnMazeAndNotVisited(p.PointDown()))
			return true;
	}
	return false;
}

bool Maze::NotVisited(const Point & p)
{
	if (m_maze[p.m_row][p.m_col] == '$')
		return false;
	return true;
}

bool Maze::IsOnMazeAndNotVisited(Point p1)
{
	if ((p1.m_row <= this->m_rows - 1) && p1.m_row >= 0)
		if ((p1.m_col <= this->m_cols - 1) && p1.m_col >= 0)
			if (m_maze[p1.m_row][p1.m_col] == ' ' )
				return true;
	return false;
}

char ** Maze::MakeNewMaze(int rows, int cols)
{
	char** NewMaze = new char*[rows];
	AllocationTest(NewMaze);
	for (int i = 0; i < rows; i++) {
		NewMaze[i] = new char[cols];
		AllocationTest(NewMaze[i]);
	}
	return NewMaze;
}

void Maze::PrintMaze()
{
	int rows = this->m_rows;
	int cols = this->m_cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cout << m_maze[i][j];
		}
		cout << endl;
	}
}

void Maze::InitMaze()
{
	int rows = this->m_rows;
	int cols = this->m_cols;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (i == 0 || i == rows - 1)
				m_maze[i][j] = '*';
			else if (i % 2 == 0)
				m_maze[i][j] = '*';
			else if (j % 2 == 1 && i % 2 == 1)
				m_maze[i][j] = ' ';
			else
				m_maze[i][j] = '*';
	m_maze[1][0] = ' ';
	m_maze[rows - 2][cols - 1] = ' ';
}

Point Maze::FindRandNeighbor(Point &point)
{
	Point Neighbor = GetRandNeighbor(point);
	while (!IsOnMazeAndNotVisited(Neighbor))
		Neighbor = GetRandNeighbor(point);
	return Neighbor;
}

void Maze::setRows(int rows)
{
	m_rows = rows;
}

void Maze::setCols(int cols)
{
	m_cols = cols;
}


void Maze::setMaze(char ** maze)
{
	m_maze = maze;
}

int Maze::getRows()
{
	return this->m_rows;
}

int Maze::getCols()
{
	return this->m_cols;
}

char ** Maze::getMaze() const
{
	return m_maze;
}
