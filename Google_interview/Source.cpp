#include <iostream>

void Del_matrix(int** matrix, const int rows, const int colomns);
bool IsBorder(int** matrix, const int i, const int j, const int rows, const int colomns, const int from_i, const int from_j);

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
			if (matrix[i][j] != 0 && matrix[i][j] != 1)
			{
				Del_matrix(matrix, rows, colomns);
				return 1;
			}
		}
	}
	for (size_t i = 1; i < rows - 1; i++)
	{
		for (size_t j = 1; j < colomns - 1; j++)
		{
			if (matrix[i][j] == 1 && !IsBorder(matrix, i, j, rows, colomns, -1, -1))
			{
				matrix[i][j] = 0;
			}
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colomns; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
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
bool IsBorder(int** matrix, const int i, const int j, const int rows, const int colomns, const int from_i, const int from_j)
{
	if (i == 0 || i == rows - 1 || j == 0 || j == colomns - 1)
	{
		return true;
	}
	if (matrix[i - 1][j] == 1 && !(i - 1 == from_i && j == from_j) && IsBorder(matrix, i - 1, j, rows, colomns, i, j))
	{
		return true;
	}
	if (matrix[i][j + 1] == 1 && !(i == from_i && j + 1 == from_j) && IsBorder(matrix, i, j + 1, rows, colomns, i, j))
	{
		return true;
	}
	if (matrix[i + 1][j] == 1 && !(i + 1 == from_i && j == from_j) && IsBorder(matrix, i + 1, j, rows, colomns, i, j))
	{
		return true;
	}
	if (matrix[i][j - 1] == 1 && !(i == from_i && j - 1 == from_j) && IsBorder(matrix, i, j - 1, rows, colomns, i, j))
	{
		return true;
	}
	return false;
}