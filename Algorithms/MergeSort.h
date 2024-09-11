#pragma once
#include "../Contracts/SortingAlgorithm.h"
class MergeSort : public SortingAlgorithm
{
	void merge(int low, int mid, int high);
	void execute(int low, int high);
public:
	MergeSort() = default;
	explicit MergeSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};