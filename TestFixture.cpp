#include "TestFixture.h"
#include <Windows.h>
#include <stdexcept>
#include <random>
#include <iostream>
#include <unordered_set>
#include <set>

TestFixture::TestFixture(SortingAlgorithm* algorithm)
{
	setAlgorithm(algorithm);
}

std::vector<int> buildRandomizedVector(bool getUnique, int startRange, int endRange, size_t sampleSize)
{
	std::vector<int> data;
	srand((unsigned)time(0));
	std::set<int> nums;
	for (size_t i = 0; i < sampleSize; i++)
	{
		int random = rand();
		int range = endRange + abs(startRange) - 1;

		int generated = (random % range) - abs(startRange);
		while (getUnique && nums.find(generated) != nums.end())
		{
			generated = (rand() % range) - abs(startRange);
		}
		nums.emplace(generated);
		data.push_back(generated);
	}
	return data;
}
bool compare(const std::vector<int>& left, const std::vector<int>& right)
{
	if (left.size() != right.size())
	{
		return false;
	}

	int size = left.size();
	for (size_t i = 0; i < size; i++)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}
	return true;
}
void printVector(const std::vector<int>& data)
{
	std::cout << "{";
	if (!data.empty())
	{
		std::cout << data[0];
	}
	for (size_t i = 1; i < data.size(); i++)
	{
		std::cout << ", " << data[i];
	}
	std::cout << "}";
}
TestResult TestFixture::runRandomizedTests(size_t testsCount, bool generateRandomNums, int startRange, int endRange, size_t sampleSize)
{
	unsigned failed = 0;
	for (size_t i = 0; i < testsCount; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::vector<int> randomData = buildRandomizedVector(generateRandomNums, startRange, endRange, sampleSize);
		std::cout << "Test " << i + 1 << " out of " << testsCount << ": ";
		/*std::cout << "Sample: ";
		printVector(randomData);*/
		//std::cout << std::endl;

		SortingAlgorithm* algo = _algorithm->clone();
		algo->setData(randomData);
		algo->execute();
		std::vector<int> sortedByAlgo = algo->getData();
		std::sort(randomData.begin(), randomData.end());

		bool isPassed = compare(sortedByAlgo, randomData);
		if (isPassed)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			std::cout << "Passed!" << std::endl;
		}
		else
		{
			/*printVector(sortedByAlgo);
			std::cout << std::endl << std::endl;
			printVector(randomData);*/

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << "Failed!" << std::endl;
			failed++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		delete algo;
	}
	return TestResult(testsCount - failed, failed);
}

const SortingAlgorithm* TestFixture::getAlgorithm() const
{
	return _algorithm;
}

void TestFixture::setAlgorithm(SortingAlgorithm* algorithm)
{
	if (!algorithm)
	{
		throw std::invalid_argument("Invalid algorithm passed!");
	}
	_algorithm = algorithm;
}
