#include "MainHeader.h"
#include "Point.h"
#include "Node.h"
#include "Maze.h"
#include "Stack.h"
#include "Queue.h"
#include <time.h>
#include <iostream>
#include <string.h>

void Print(char**maze, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}

bool CheckInputLine(char *line, int cols)
{
	int size = strlen(line);
	if (size != cols)
	{
		cout << "invalid input\n";
		exit(1);
	}
	for (int i = 0; i < size; i++)
		if (line[i] != ' ' && line[i] != '*')
		{
			cout << "invalid input\n";
			exit(1);
		}
	return true;
}

bool CheckWallsOfMaze(char** maze, int rows, int cols)
{
	for (int i = 0; i < cols; i++)
		if (maze[0][i] != '*')
		{
			cout << "invalid input\n";
			exit(1);
		}
	for (int i = 0; i < rows; i++)
		if (i != 1)
			if (maze[i][0] != '*')
			{
				cout << "invalid input\n";
				exit(1);
			}
	for (int i = 0; i < rows; i++)
		if (i != rows - 2)
			if (maze[i][cols - 1] != '*')
			{
				cout << "invalid input\n";
				exit(1);
			}
	for (int i = 0; i < cols; i++)
		if (maze[rows - 1][i] != '*')
		{
			cout << "invalid input\n";
			exit(1);
		}
}

char **InputMaze(int rows, int cols)
{
	char line[81];
	char** new_maze = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		if (i == 0)
			cin.ignore();
		cin.getline(line, 81);
		if (i != rows - 2) {
			if (CheckInputLine(line, cols)) {
				new_maze[i] = strdup(line);
			}
			else
			{
				cout << "invalid input\n";
				return nullptr;
			}
		}
		else
			new_maze[i] = strdup(line);
	}
	CheckWallsOfMaze(new_maze, rows, cols);
	if (new_maze[1][0] != ' ' || new_maze[rows - 2][cols - 1] != ' ')
	{
		cout << "invalid input\n";
		exit(1);
	}
	return new_maze;
}

void InputRowsAndCols(int rows, int cols)
{
	if (rows % 2 == 0)
	{
		cout << "you have entered an even number of rows, input is invalid\n";
		exit(1);
	}
	if (cols % 2 == 0)
	{
		cout << "you have entered an even number of cols, input is invalid\n";
		exit(1);
	}
}

void SolveMaze(Maze &input_maze) {
	int rows = input_maze.getRows();
	int cols = input_maze.getCols();
	Queue new_queue(rows, cols);
	new_queue.InitQueue();
	Point curr_point;
	while (new_queue.IsEmpty() != true)
	{
		curr_point = new_queue.DeQueue();
		input_maze.getMaze()[curr_point.getRow()][curr_point.getCol()] = '$';
		if (curr_point.AtFinishLine(rows, cols))
		{
			input_maze.getMaze()[curr_point.getRow()][curr_point.getCol()] = '$';
			break;
		}
		new_queue.AddAllNeighbors(curr_point, input_maze.getMaze(), rows, cols);
	}
	Print(input_maze.getMaze(), rows, cols);
}


void CreateMaze(Maze& NewMaze, Stack& stack)
{
	Point RandNeighbor;
	stack.InitStack();
	while (stack.isEmpty() != true)
	{
		Point CurrP = stack.Pop();
		if (NewMaze.StillNotVisited(CurrP))
		{
			NewMaze.MarkAsVisited(CurrP);
			RandNeighbor = NewMaze.FindRandNeighbor(CurrP);
			NewMaze.TakeOffWallBetweenNeighbors(CurrP, RandNeighbor);
			stack.Push(CurrP);
			stack.Push(RandNeighbor);
		}
		else
			stack.VoidPop();
	}
	NewMaze.FinishMaze();
	NewMaze.PrintMaze();
}


int main() {
	srand((unsigned)time(NULL));
	int rows, cols;
	int solve_or_make;
	cout << "Maze: 1) From input 2) Random\n";
	cin >> solve_or_make;
	cin >> rows >> cols;
	if (solve_or_make == 1)
	{
		char** user_maze = InputMaze(rows, cols);
		Maze input_maze(rows, cols, user_maze);
		SolveMaze(input_maze);
	}
	else
	{
		InputRowsAndCols(rows, cols);
		Maze new_maze(rows, cols);
		new_maze.setMaze(new_maze.MakeNewMaze(rows, cols));
		Stack new_stack;
		new_maze.InitMaze();
		CreateMaze(new_maze, new_stack);
		SolveMaze(new_maze);
	}
	return 0;
}
