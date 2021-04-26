#include "MainHeader.h"
#include <time.h>
int getRand() 
{
	int i = rand() % 4;
	return i;
}



void AllocationTest(void * ptr)
{
	if (!ptr)
	{
		cout << "Allocation error\n";
		exit(1);
	}
}
