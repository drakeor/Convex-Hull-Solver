#include "BenchmarkEngine.h"
#include "../QuickHullLib/PointGenerator.h"
#include "../QuickHullLib/BruteForceSolver.h"
#include "../QuickHullLib/QuickHullSolver.h"

#include <SFML/System.hpp>

void BenchmarkEngine::RecordResults()
{
	std::ofstream csvFile;
	csvFile.open("results.csv", std::ios::app);
	while (benchmarkResults.size() > 0) {
		csvFile << benchmarkResults.front();
		benchmarkResults.pop();
	}
	csvFile.close();
}

void BenchmarkEngine::RecordSingleResult(std::string result)
{
	std::ofstream csvFile;
	csvFile.open("results.csv", std::ios::app);
	csvFile << result;
	csvFile.close();
}

BenchmarkEngine::BenchmarkEngine(int startN, int endN, int incrementN, int sampleN)
{
	startAmount = startN;
	currentAmount = startN;
	endAmount = endN;
	incrementAmount = incrementN;
	sampleCount = sampleN;

	isRunning = false;
	benchmarkResults.empty();
}

BenchmarkEngine::~BenchmarkEngine()
{
}

bool BenchmarkEngine::IsBenchmarkRunning()
{
	return isRunning;
}

bool BenchmarkEngine::StartBenchmark()
{
	if (!isRunning) {
		benchmarkResults.empty();
		currentAmount = startAmount;
		isRunning = true;
		return true;
	}
	return false;
}

bool BenchmarkEngine::StopBenchmark()
{
	if (isRunning) {
		// Set to not running
		RecordResults();
		isRunning = false;
		return true;
	}
	return false;
}

bool BenchmarkEngine::StepBenchmark()
{
	if (isRunning) {

		// Solve x amount of times where x is the sample count
		for (int i = 0; i < sampleCount; i++) {
			auto points = PointGenerator::Generate(currentAmount, 2000, 2000);

			BruteForceSolver bruteForceSolver(points);
			QuickHullSolver quickHullSolver(points);

			const int solverCount = 2;
			ConvexHullSolver* solvers[solverCount] = { &bruteForceSolver, &quickHullSolver };

			for (int i = 0; i < solverCount; i++) {

				// Measure the time of the first solve
				sf::Clock clock;
				clock.restart();
				solvers[i]->Solve();
				sf::Time time = clock.getElapsedTime();
				long timeMs = time.asMilliseconds();

				// Record the results
				std::ostringstream strstr;
				strstr << solvers[i]->GetName()
					<< "," << currentAmount
					<< "," << solvers[i]->GetTotalNumberOfSteps()
					<< "," << timeMs
					<< std::endl;
				std::cout << "Result: " << strstr.str() << std::endl;
				RecordSingleResult(strstr.str());
				//benchmarkResults.push(strstr.str());
			}
			
		}

		// Increment step
		currentAmount += incrementAmount;
		if (currentAmount > endAmount) {
			RecordResults();
			isRunning = false;
			return false;
		}
	}
	return false;
}

std::string BenchmarkEngine::GetCurrentProgress()
{
	std::ostringstream strstr;
	strstr << "Start Amount: " << startAmount
		<< " | Current Amount: " << currentAmount
		<< " | End Amount: " << endAmount
		<< std::endl;
	return strstr.str();
}
