#include <iostream>

// 2D array is actually an array of array

int main()
{
	// 1D array: a pointer to an integer
	int* array = new int[50];
	// 2D array: a pointer to an integer pointer
	int** array_2d = new int* [50];  // all we have done here is allocating 200 bytes memory.
	// we can use these memory to store integer or floats.
	// what we have done for 1D array intializing is the same as what we have done for 2D array initializing.

	array[0] = 0; // Here, we talk about integer.
	array_2d[0] = nullptr; // Here, we talk about integer pointer.

	// Allocate memory for the second dimension.
	for (int i = 0; i < 50; i++)
	{
		array_2d[i] = new int[50];
	}

	// 3D array
	int*** array_3d = new int** [50];
	for (int i = 0; i < 50; i++)
	{
		array_3d[i] = new int* [50];
		for (int j = 0; j < 50; j++)
		{
			array_3d[i][j] = new int[50];
		}
	}
	// assignment
	array_3d[0][0][1] = 0;
	array_3d[0][0][2] = 0;
	array_3d[0][0][3] = 0;
	
	// delete 1D array
	delete[] array;
	// delete 2D array
	for (int i = 0; i < 50; i++)
	{
		delete[] array_2d[i];
	}
	delete[] array_2d;
	// delete 3D array
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			delete[] array_3d[i][j];
		}
		delete[] array_3d[i];
	}
	delete[] array_3d;

	// normal 2D array
	int** array_d = new int* [50];
	for (int i = 0; i < 50; i++)
	{
		array_d[i] = new int[50];
	}

	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			array_d[x][y] = 1;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		delete[] array_d[i];
	}
	delete[] array_d;

	// 2D array stored in 1D array, an optimal way, which is faster.
	int* array_t = new int[50 * 50];
	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++)
		{
			array_t[x * 50 + y] = 1;
		}
	}
	delete[] array_t;
	// In this way, we can store 2D images and textures like a 2D array in a 1D array.

	return 0;
}