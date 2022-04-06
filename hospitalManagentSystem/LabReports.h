#include<string.>
using namespace std;
#pragma once

class LabReports
{
private:
	string previousTests;
	string furtherTests;
	string labResults;
public:
	LabReports() {
		labResults = "404";
	}
	LabReports(string oldTest, string newTest, string results) {
		previousTests = oldTest;
		furtherTests = newTest;
		labResults = results;
	}

	void setPreviousTest(string oldTest) {
		previousTests = oldTest;
	}
	void setfurtherTest(string newTest) {
		furtherTests = newTest;
	}
	void setLabReults(string results) {
		labResults = results;
	}

	string getPreviousTest() {
		return previousTests;
	}
	string getFurtherTest() {
		return furtherTests;
	}
	string getLabReults() {
		return  labResults;
	}
};