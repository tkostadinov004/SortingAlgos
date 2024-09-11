#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(std::vector<int>& data) : _data(data)
{
}

const std::vector<int>& SortingAlgorithm::getData() const
{
	return _data;
}

void SortingAlgorithm::setData(const std::vector<int>& data)
{
	_data = data;
}
