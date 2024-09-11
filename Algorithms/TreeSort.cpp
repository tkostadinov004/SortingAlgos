#include "TreeSort.h"

static TreeNode* buildBST(TreeNode* root, int val)
{
	if (!root)
	{
		return new TreeNode(val);
	}
	if (val < root->value)
	{
		root->left = buildBST(root->left, val);
	}
	else if (val > root->value)
	{
		root->right = buildBST(root->right, val);
	}
	return root;
}
static TreeNode* buildBSTFromArray(const std::vector<int>& arr)
{
	if (arr.empty())
	{
		return nullptr;
	}

	TreeNode* root = new TreeNode(arr[0]);
	size_t size = arr.size();
	for (size_t i = 1; i < size; i++)
	{
		root = buildBST(root, arr[i]);
	}
	return root;
}
void inOrderTraversal(const TreeNode const* root, std::vector<int>& resultArr)
{
	if (!root)
	{
		return;
	}
	inOrderTraversal(root->left, resultArr);
	resultArr.push_back(root->value);
	inOrderTraversal(root->right, resultArr);
}

TreeSort::TreeSort(std::vector<int>& data) : SortingAlgorithm(data)
{
}

SortingAlgorithm* TreeSort::clone()
{
	return new TreeSort(*this);
}

void TreeSort::execute()
{
	TreeNode* root = buildBSTFromArray(_data);
	size_t size = _data.size();
	std::vector<int> result;
	inOrderTraversal(root, result);
	for (size_t i = 0; i < size; i++)
	{
		_data[i] = result[i];
	}
	delete root;
}
