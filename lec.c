#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

int ni2si(int ni)
{
	int16_t si [15] = {0b00, 0b010, 0b011, 0b100, 0b101, 0b110, 0b1110, 0b11110, 0b111110, 0b1111110, 
					   0b11111110, 0b111111110, 0b1111111110, 0b11111111110, 0b111111111110};
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