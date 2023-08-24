#include <iostream>
#include "Management.h"

using namespace std;

void main()
{
	Management management;
	while (1)
	{
		if(!management.ManageScores()) break;
	}
}