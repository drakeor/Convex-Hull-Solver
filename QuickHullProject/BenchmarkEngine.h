#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>

class BenchmarkEngine
{
private:
	int startAmount;
	int endAmount;
	int currentAmount;
	int incrementAmount;
	int sampleCount;

	bool isRunning;
	std::queue<std::string> benchmarkResults;

	void RecordResults();
	void RecordSingleResult(std::string result);

public:
	BenchmarkEngine(int startN, int endN, int incrementN, int sampleN);
	~BenchmarkEngine();
	
	bool IsBenchmarkRunning();
	bool StartBenchmark();
	bool StopBenchmark();
	bool StepBenchmark();

	std::string GetCurrentProgress();
};

