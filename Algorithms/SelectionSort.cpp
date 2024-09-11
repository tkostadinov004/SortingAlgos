#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* SelectionSort::clone()
{
	return new SelectionSort(*this);
}

void SelectionSort::execute()
{
	size_t size = _data.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (_data[j] < _data[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(_data[i], _data[minIndex]);
		}
	}
}
