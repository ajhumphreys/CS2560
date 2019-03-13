// Andrew Humphreys CS2560
// Midterm Problem 3

#include <iostream>

using namespace std;

class FloatAr 
{
private:
	float* ar;
	int size;

public:
	FloatAr(int s)
	{
		ar = new float a[s];
	}
	

	void StoreNum(int i, float num)
	{
		ar[i] = num;
	}


	float GetNum(int i)
	{
		return ar[i];
	}

	float GetHigh()
	{
		float high = ar[0];

		for (int i = 0; i < size - 1; i++)
		{
			if (ar[i + 1] > ar[i])
			{
				high = ar[i + 1];
			}
		}

		return high;
	}

	float GetLow()
	{
		float low = ar[0];

		for (int i = 0; i < size - 1; i++)
		{
			if (ar[i + 1] < ar[i])
			{
				low = ar[i + 1];
			}
		}

		return low;
	}

};
int main()
{




	return 0;
}