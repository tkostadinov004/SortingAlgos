#pragma once
#include "../Contracts/SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
	BubbleSort() = default;
	explicit BubbleSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};