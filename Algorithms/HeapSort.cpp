#include "HeapSort.h"

HeapSort::HeapSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* HeapSort::clone()
{
	return new HeapSort(*this);
}

void HeapSort::heapify(size_t size, int index)
{
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2; //leftChild + 1
	int largest = index;
	if (leftChild < size && _data[leftChild] > _data[largest])
	{
		largest = leftChild;
	}
	if (rightChild < size && _data[rightChild] > _data[largest])
	{
		largest = rightChild;
	}

	if (largest != index)
	{
		std::swap(_data[largest], _data[index]);
		heapify(size, largest);
	}
}

void HeapSort::execute()
{
	size_t size = _data.size();
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(_data[0], _data[i]);
		heapify(i, 0);
	}
}
