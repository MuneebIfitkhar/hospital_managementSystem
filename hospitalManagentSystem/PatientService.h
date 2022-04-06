#pragma once
#include<string.h>
#include<iostream>
#include"PatientRepostry.h"
#include"PatientInfo.h"

using namespace std;

class PatientService
{
	PatientRepostry patientRepostry;

public:


	void addPatient(string age, string gender, string patientId,
		string name, string fName, string address,
		string phoneNumber ,
		PatientHistory patientHistory, LabReports reports) 
	{
 
		PatientInfo patientInfo(age,gender,patientId,name,
			fName,address,phoneNumber, patientHistory , reports);

		patientRepostry.save(patientInfo);

	}

	PatientHistory createPatientHistoryObj(string familyDisease, string childhoodDisease[],
		string chdMedies [],string allergicMedicines[])
	{
		PatientHistory patientHistory(familyDisease, childhoodDisease,
			chdMedies,allergicMedicines);

		return patientHistory;
	}

	LabReports createLabReports(string oldTest, string newTest, string results) {
		LabReports labreports(oldTest, newTest, results);
		return labreports;
	}
	
	PatientInfo findPatient(string id) {
		return patientRepostry.searchPatient(id);
	}
	
	

	PatientInfo * findPatientReference(string id) {
		return patientRepostry.searchPatientReference(id);
	}

	PatientHistory* findPatientHistoryRefrence(string cnic) {
		return patientRepostry.searchPatientHistoryRefrence(cnic);
	}
	LabReports* findLabReports(string cnic) {
		return patientRepostry.searchLabReports(cnic);
	}
	void deletePatient(PatientInfo * patientInfo) {
		patientRepostry.distroyPatientInfo(patientInfo);
	}

	void deletePatientHistory(PatientHistory *patientHistory) {
		patientRepostry.distroyHistory(patientHistory);
	}

	void deletePatientLabReports(LabReports * labReports) {
		patientRepostry.distroyLabreports(labReports);
	}

	void updatePatient(string age,string patientId , string gender, string name, string fName,
		string address, string phoneNumber,PatientInfo * patientInfo) 
	{
		//PatientInfo* info = &patientInfo;
		patientRepostry.updatePatientInfo(age, patientId ,gender, name, fName,
			address, phoneNumber, patientInfo);

	}


	void updatePatientHistory(string familyDisease, string childhoodDisease[],
		string chdMedies[], string allergicMedicines[], PatientHistory * patientHistory) {

		patientRepostry.updatePatientHistory(familyDisease, childhoodDisease, chdMedies, allergicMedicines, patientHistory);

	}

	void updateLAbReports(string previousTest,string newTest , string results,LabReports* reports) {
		patientRepostry.updateLabReports(previousTest, newTest, results, reports);
	}
	
};

