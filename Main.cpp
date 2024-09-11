#include <iostream>
#include "Algorithms\BubbleSort.h"
#include "Algorithms\CountingSort.h"
#include "Algorithms\HeapSort.h"
#include "Algorithms\InsertionSort.h"
#include "Algorithms\MergeSort.h"
#include "Algorithms\QuickSort.h"
#include "Algorithms\SelectionSort.h"
#include "Algorithms\TreeSort.h"
#include "TestFixture.h"

int main()
{
	unsigned totalPassed = 0, totalFailed = 0;

	size_t testsCount = 50;
	size_t start = -2000;
	size_t end = 2000;
	size_t sampleSize = 1000;
	{
		SortingAlgorithm* ts = new TreeSort();
		TestFixture test(ts);
		std::cout << "Tree sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, true, start, end, 30);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete ts;
	}
	{
		SortingAlgorithm* bs = new BubbleSort();
		TestFixture test(bs);
		std::cout << "Bubble sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete bs;
	}
	{
		SortingAlgorithm* hs = new HeapSort();
		TestFixture test(hs);
		std::cout << "Heap sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete hs;
	}
	{
		SortingAlgorithm* is = new InsertionSort();
		TestFixture test(is);
		std::cout << "Insertion sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete is;
	}
	{
		SortingAlgorithm* ms = new MergeSort();
		TestFixture test(ms);
		std::cout << "Merge sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete ms;
	}
	{
		SortingAlgorithm* qs = new QuickSort();
		TestFixture test(qs);
		std::cout << "Quick sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete qs;
	}
	{
		SortingAlgorithm* ss = new SelectionSort();
		TestFixture test(ss);
		std::cout << "Selection sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete ss;
	}
	{
		SortingAlgorithm* cs = new CountingSort();
		TestFixture test(cs);
		std::cout << "Counting sort: " << std::endl;
		TestResult res = test.runRandomizedTests(testsCount * 10, false, start, end, sampleSize);
		totalPassed += res.passed;
		totalFailed += res.failed;
		delete cs;
	}
	std::cout << std::endl << "Total: " << totalPassed << " passed, " << totalFailed << " failed" << std::endl;
}