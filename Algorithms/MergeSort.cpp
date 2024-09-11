#include "MergeSort.h"

void MergeSort::merge(int low, int mid, int high)
{
	size_t leftSize = mid - low + 1;
	size_t rightSize = high - mid;
	std::vector<int> left(leftSize);
	for (size_t i = 0; i < leftSize; i++)
	{
		left[i] = _data[low + i];
	}
	std::vector<int> right(rightSize);
	for (size_t i = 0; i < rightSize; i++)
	{
		right[i] = _data[mid + 1 + i];
	}

	int i = 0, j = 0, k = low;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			_data[k++] = left[i++];
		}
		else
		{
			_data[k++] = right[j++];
		}
	}
	while (i < leftSize)
	{
		_data[k++] = left[i++];
	}
	while (j < rightSize)
	{
		_data[k++] = right[j++];
	}
}

void MergeSort::execute(int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int mid = low + (high - low) / 2; // (low + high) / 2
	execute(low, mid);
	execute(mid + 1, high);
	merge(low, mid, high);
}

MergeSort::MergeSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* MergeSort::clone()
{
	return new MergeSort(*this);
}

void MergeSort::execute()
{
	execute(0, _data.size() - 1);
}
