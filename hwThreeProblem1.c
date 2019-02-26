// Andrew Humphreys CS 2560
// HW 3 Problem 1

# include <stdio.h>

const float PI = 3.14159;

int GetChoice();
void GetRadius(float *radius);
void GetLengthWidth(float *length, float *width);
void GetBaseHeight(float *base, float *height);
float CircleArea(float radius);
float RectangleArea(float length, float width);
float TriangleArea(float base, float height);

int main()
{
	int run = 1;	// Variable that changes to 0 when user wants to quit program

	int userChoice;

	float radius;
	float length;
	float width;
	float base;
	float height;
	float area;

	while(run == 1)
	{
		userChoice = GetChoice();

		switch(userChoice)
		{
		case 1 :
			do
			{
				GetRadius(&radius);
				if(radius < 0)
				{
					printf("Error! Value Must Be Positive.\n\n");
				}
			}while(radius < 0);

			area = CircleArea(radius);

			printf("The area of the circle is: %.2f\n\n", area);
			break;

		case 2 :
			do
			{
				GetLengthWidth(&length, &width);
				if(length < 0 || width < 0)
				{
					printf("Error! Values Must Be Positive.\n\n");
				}
			}while(length < 0 || width <0);
				area = RectangleArea(length, width);
				printf("The area of the rectangle is: %.2f\n\n", area);
			break;
		case 3 :
			do
			{
				GetBaseHeight(&base, &height);
				if(base < 0 || height <0)
				{
					printf("Error! Values Must Be Positive.\n\n");
				}
			}while(base < 0 || height <0);
				area = TriangleArea(base, height);
				printf("The area of the triangle is: %.2f\n\n", area);
			break;

		case 4 :
			run = 0;
			break;

		default :
			printf("Error! Please Enter a Valid Choice (1-4)\n\n");
			break;

		}
	}
	return 0;
}

int GetChoice()
{

	int choice;

	printf("Geometry Calculator\n\n");
	printf("\t1. Calculate the Area of a Circle\n");
	printf("\t2. Calculate the Area of a Rectangle\n");
	printf("\t3. Calculate the Area of a Triangle\n");
	printf("\t4. Quit\n\n");
	printf("\tEnter your choice (1-4): ");
	fflush(stdout);

	scanf("%d",&choice);
	fflush(stdout);

	printf("\n");

	return choice;
}

void GetRadius(float *radius)
{
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",radius);
	fflush(stdout);
}
void GetLengthWidth(float *length, float *width)
{
	printf("Enter the length: ");
	fflush(stdout);
	scanf("%f",length);
	fflush(stdout);

	printf("Enter the width: ");
	fflush(stdout);
	scanf("%f",width);
	fflush(stdout);
}

void GetBaseHeight(float *base, float *height)
{
	printf("Enter the base: ");
	fflush(stdout);
	scanf("%f",base);
	fflush(stdout);

	printf("Enter the height: ");
	fflush(stdout);
	scanf("%f",height);
	fflush(stdout);
}

float CircleArea(float radius)
{
	return PI * radius * radius;
}

float RectangleArea(float length, float width)
{
	return length * width;
}

float TriangleArea(float base, float height)
{
	return base * height * .5;
}

