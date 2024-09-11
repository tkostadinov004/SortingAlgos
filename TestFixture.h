#pragma once
#include "Contracts\SortingAlgorithm.h"

struct TestResult
{
	unsigned passed = 0;
	unsigned failed = 0;
	TestResult(unsigned passed, unsigned failed) : passed(passed), failed(failed) {}
};
class TestFixture
{
	SortingAlgorithm* _algorithm = nullptr;
public:
	explicit TestFixture(SortingAlgorithm* algorithm);
	TestResult runRandomizedTests(size_t testsCount, bool generateRandomNums, int startRange, int endRange, size_t sampleSize);
	const SortingAlgorithm* getAlgorithm() const;
	void setAlgorithm(SortingAlgorithm* algorithm);
};