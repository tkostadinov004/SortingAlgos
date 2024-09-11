#include "QuickSort.h"

int QuickSort::partition(int low, int high)
{
	int pivot = _data[high];
	int partitionIndex = low - 1;
	for (size_t i = low; i < high; i++)
	{
		if (_data[i] < pivot)
		{
			partitionIndex++;
			std::swap(_data[i], _data[partitionIndex]);
		}
	}
	std::swap(_data[high], _data[partitionIndex + 1]);
	return partitionIndex + 1;
}

void QuickSort::execute(int low, int high)
{
	if (low >= high)
	{
		return;
	}

	int partitionIndex = partition(low, high);
	execute(low, partitionIndex - 1);
	execute(partitionIndex + 1, high);
}

QuickSort::QuickSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* QuickSort::clone()
{
	return new QuickSort(*this);
}

void QuickSort::execute()
{
	execute(0, _data.size() - 1);
}
