#pragma once
#include "../Contracts/SortingAlgorithm.h"

class CountingSort : public SortingAlgorithm
{
	static void sortArr(std::vector<int>& data);
public:
	CountingSort() = default;
	explicit CountingSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};