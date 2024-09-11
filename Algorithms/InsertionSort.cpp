#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* InsertionSort::clone()
{
	return new InsertionSort(*this);
}

void InsertionSort::execute()
{
	size_t size = _data.size();
	for (size_t i = 1; i < size; i++)
	{
		int j = i - 1;
		int key = _data[i];
		while (j >= 0 && key < _data[j])
		{
			_data[j + 1] = _data[j];
			j--;
		}
		_data[j + 1] = key;
	}
}
