#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
int ni2si(int ni)
{
	int16_t si [15] = {0b00, 0b010, 0b011, 0b100, 0b101, 0b110, 0b1110, 0b11110, 0b111110, 0b1111110, 
					   0b11111110, 0b111111110, 0b1111111110, 0b11111111110, 0b111111111110};
	return si[ni];
}

int findMax(int16_t r[], int numElements)
{
	int max = INT_MIN;
	for (int i = 0; i < numElements; i++)
	{
		if (r[i] > max)
			max = r[i];

	}
	return max;
}

//Function to return lower n bits of 16 bit number.
int16_t lowernBits(uint16_t origNum, int n)
{
	uint16_t mask = 0;
	for (int i = 0; i < n; i++)
	{
		mask |= 1 << i;

	}
	printf("%"PRIu16 "\n", mask);
	return (origNum & mask);
}

int * lec(int16_t r[], int numElements)
{
	//Compress
	int * d = malloc(sizeof(int) * numElements);
	int * n = malloc(sizeof(int) * numElements);
	int * s = malloc(sizeof(int) * numElements);
	int * a = malloc(sizeof(int) * numElements);
	int * bs = malloc(sizeof(int) * numElements);

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

	//Encode
	for (int i = 0; i < numElements; i++)
	{
		
		if (d[i] == 0)
			n[i] = 0;
		else
			n[i] = log(d[i]);

		s[i] = ni2si(n[i]);
		if (n[i] == 0)
			bs[i] = s[i];
		else
		{
			if (d[i] > 0)
			{

			}
			else
			{

			}

		}
	}
	


	return d;
	
}



int main ()
{
	
	int16_t r[3] = {0b010,0b001,0b011};
	//lec(r, 3);
	uint16_t num = 0b1111111111111111;
	lowernBits(num, 4);
	return 0;
}