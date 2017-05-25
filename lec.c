#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

int ni2si(int ni)
{
	int16_t si [15] = {00, 010, 011, 100, 101, 110, 1110, 11110, 111110, 1111110, 11111110, 111111110, 1111111110, 11111111110, 111111111110};
	return si[ni];
}

int findMax(int r[], int numElements)
{
	int max = INT_MIN;
	for (int i = 0; i < numElements; i++)
	{
		if (r[i] > max)
			max = r[i];

	}
	return max;

}


int * lec(int r[], int numElements)
{
	
	int * d = malloc(sizeof(int) * numElements);
	int max = findMax(r, numElements);
	int firstR = log((max));

	for (int i = 0; i < numElements; i++)
	{
		if (i == 0)
		{
			d[i] = r[i] - firstR;

		}
		else
			d[i] = r[i] - r[i-1];

	}
	return d;
	
}



int main ()
{
	
	int r[3] = {2,1,3};
	lec(r, 3);

	return 0;
}