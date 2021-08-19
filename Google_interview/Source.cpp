#include <iostream>

void Del_matrix(int** matrix, const int rows, const int colomns);

int main()
{
	int rows = 0, colomns = 0;

	while (rows < 3)
	{
		std::cout << "Rows: ";
		std::cin >> rows;
	}
	while (colomns < 3)
	{
		std::cout << "Colomns: ";
		std::cin >> colomns;
	}
	int** matrix = new (std::nothrow) int*[rows];
	if (!matrix)
	{
		return -1;
	}
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new (std::nothrow) int[colomns];
		if (!matrix[i])
		{
			for (size_t j = 0; j < i; j++)
			{
				delete[]matrix[j];
			}
			delete[]matrix;
			return -1;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colomns; j++)
		{
			std::cin >> matrix[i][j];
			if (matrix[i][j] != 0 || matrix[i][j] != 1)
			{
				Del_matrix(matrix, rows, colomns);
				return 1;
			}
		}
	}

	Del_matrix(matrix, rows, colomns);
	return 0;
}

void Del_matrix(int** matrix, const int rows, const int colomns)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}