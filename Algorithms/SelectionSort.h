#pragma once
#include "../Contracts/SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
	SelectionSort() = default;
	explicit SelectionSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};
