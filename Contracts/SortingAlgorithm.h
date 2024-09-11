#pragma once
#include <vector>
class SortingAlgorithm
{
protected:
	std::vector<int> _data;
public:
	SortingAlgorithm() = default;
	explicit SortingAlgorithm(std::vector<int>& data);
	virtual SortingAlgorithm* clone() = 0;
	virtual ~SortingAlgorithm() = default;
	virtual void execute() = 0;
	const std::vector<int>& getData() const;
	void setData(const std::vector<int>& data);
};