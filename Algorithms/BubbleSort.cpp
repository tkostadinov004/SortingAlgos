#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* BubbleSort::clone()
{
	return new BubbleSort(*this);
}

void BubbleSort::execute()
{
	size_t size = _data.size();
	bool swapped = false;
	for (size_t i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (_data[j] > _data[j + 1])
			{
				std::swap(_data[j], _data[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			return;
		}
	}
}
