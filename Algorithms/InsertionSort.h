#pragma once
#include "../Contracts/SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm
{
public:
	InsertionSort() = default;
	explicit InsertionSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};