#pragma once
#include "../Contracts/SortingAlgorithm.h"
class QuickSort : public SortingAlgorithm
{
	int partition(int low, int high);
	void execute(int low, int high);
public:
	QuickSort() = default;
	explicit QuickSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};