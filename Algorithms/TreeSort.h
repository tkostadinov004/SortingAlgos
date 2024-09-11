#pragma once
#include "../Contracts/SortingAlgorithm.h"

struct TreeNode
{
	int value = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int value) : value(value) {}
	TreeNode(int value, TreeNode* left, TreeNode* right) : value(value), left(left), right(right) {}
};

class TreeSort : public SortingAlgorithm
{
public:
	TreeSort() = default;
	explicit TreeSort(std::vector<int>& data);
	virtual SortingAlgorithm* clone() override;
	virtual void execute() override;
};