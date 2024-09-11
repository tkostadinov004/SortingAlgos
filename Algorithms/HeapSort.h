#pragma once
#include "../Contracts/SortingAlgorithm.h"
class HeapSort : public SortingAlgorithm
{
	void heapify(size_t size, int index);
public:
	HeapSort() = default;
	explicit HeapSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};