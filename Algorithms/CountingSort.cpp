#include "CountingSort.h"

void CountingSort::sortArr(std::vector<int>& data)
{
	int max = INT_MIN, min = INT_MAX;
	size_t size = data.size();
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
		}
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	std::vector<int> occurrences(max - min + 1, 0);
	for (size_t i = 0; i < size; i++)
	{
		occurrences[data[i] - min]++;
	}
	for (size_t i = 0; i < occurrences.size() - 1; i++)
	{
		occurrences[i + 1] += occurrences[i];
	}

	std::vector<int> result(size);
	for (int i = size - 1; i >= 0; i--)
	{
		result[--occurrences[data[i] - min]] = data[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		data[i] = result[i];
	}
}

CountingSort::CountingSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* CountingSort::clone()
{
	return new CountingSort(*this);
}

void CountingSort::execute()
{
	std::vector<int> negativeNums, nonNegativeNums;
	size_t size = _data.size();
	for (size_t i = 0; i < size; i++)
	{
		if (_data[i] >= 0)
		{
			nonNegativeNums.push_back(_data[i]);
		}
		else
		{
			negativeNums.push_back(-_data[i]);
		}
	}
	sortArr(negativeNums);
	size_t negativeSize = negativeNums.size(), nonNegativeSize = nonNegativeNums.size();
	for (size_t i = 0; i < negativeSize; i++)
	{
		negativeNums[i] *= -1;
	}
	for (size_t i = 0; i < negativeSize / 2; i++)
	{
		std::swap(negativeNums[i], negativeNums[negativeSize - i - 1]);
	}
	sortArr(nonNegativeNums);
	for (size_t i = 0; i < negativeSize; i++)
	{
		_data[i] = negativeNums[i];
	}
	for (size_t i = 0; i < nonNegativeSize; i++)
	{
		_data[i + negativeSize] = nonNegativeNums[i];
	}
}
