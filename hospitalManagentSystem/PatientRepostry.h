#pragma once
#include<iostream>
#include"PatientInfo.h"


class PatientRepostry
{
private:
	PatientInfo patientInfo[100];

public:

	PatientRepostry(){
		
	}

	void save(PatientInfo obj) {
		for (int i = 0; i <100; i++)
		{
			if (patientInfo[i].getId() == "404") {
				patientInfo[i] = obj;
				
				break;
			}
			
		}
	}

	PatientInfo * searchPatientReference(string cnic) {
		PatientInfo* emptyObj = new PatientInfo();
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == cnic)
			{
				return &patientInfo[i];
				
			} 
		}
		return  emptyObj;
	}

	PatientInfo searchPatient(string cnic) {
		PatientInfo emptyObj;
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == cnic)
			{
				return patientInfo[i];
				break;
			}
		}
		return  emptyObj;
	}

	
	PatientHistory * searchPatientHistoryRefrence(string cnic) {
		
		PatientHistory* emptyobject = new PatientHistory();
	
		
		for (int i = 0; i < 100; i++) {
			if (patientInfo[i].getId() ==cnic)
			{
				return patientInfo[i].getHistory();
			}
		}
		return emptyobject;
	}

	LabReports* searchLabReports(string cnic) {
		LabReports emptyObject;
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == cnic) {
				return patientInfo[i].getLabReports();
			}
		}
		return &emptyObject;
	}
	
	void updatePatientInfo(string age, string patientId, 
		string gender, string name, string fName,
		string address,
		string phoneNumber,
		PatientInfo * patientInfo){
		

				if (patientId != "") {
					 patientInfo->setId(patientId);
				}
				if (name != "") {
					patientInfo->setName(name);
				}
				if(fName != "") {
					patientInfo->setfName(fName);
				}
				if (age != "") {
					patientInfo->setAge(age);
				}
				if (gender != "") {
					patientInfo->setGender(gender);
				}
				if (phoneNumber != "") {
					patientInfo->setPhoneNumbr(phoneNumber);
				}
				
	}
	
	void updatePatientHistory(
		string familyDisease, 
		string chldHoodDiseas[],
		string chldHoodMedications[],
		string allergicMedicines[],
		PatientHistory * patientHistory)
	{
		
		
		if (familyDisease!="")
		{
			patientHistory->setFamDiseas(familyDisease);
		}
		for (int i = 0; i <10 ; i++)
		{
			if (allergicMedicines[i] != "") {
				patientHistory->setAllergicMedicines(allergicMedicines);
			}
			if (chldHoodDiseas[i]!="")
			{
				patientHistory->setChildhoodDisease(chldHoodDiseas);
			}
			if (chldHoodMedications[i]!= "")
			{
				patientHistory->setChildHoodMedicine(chldHoodMedications);
			}
		}
		

	}

	void updateLabReports(string oldTest, string newTest, string results,LabReports * reports) {
		
		if (oldTest != "") {
			reports->setPreviousTest(oldTest);
		}
		if (newTest != "") {
			reports->setfurtherTest(newTest);
		}
		if (results != "") {
			reports->setLabReults(results);
		}

	}

	void distroyPatientInfo(PatientInfo* info) {
	
		
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == info->getId()) {
				
				patientInfo[i].setId("404");
				patientInfo[i].setName("404");
				patientInfo[i].setfName("404");
				patientInfo[i].setAge("404");
				patientInfo[i].setPhoneNumbr("404");
				patientInfo[i].setGender("404");
				patientInfo[i].setAddress("404");
				PatientHistory *history = patientInfo[i].getHistory();
				LabReports* reports = patientInfo[i].getLabReports();
				distroyHistory(history);
				distroyLabreports(reports);
				break;
			}
		}

	}

	void distroyHistory(PatientHistory *patientHistory){
		string chldHdDiseas[10], chldHdMed[10], alrgMed[10];
		for (int i = 0; i < 10; i++) {
			chldHdDiseas[i] = "404";
			chldHdMed[i] = "404";
			alrgMed[i] = "404";
		}
		patientHistory->setFamDiseas("404");
		patientHistory->setChildhoodDisease(chldHdDiseas);
		patientHistory->setAllergicMedicines(alrgMed);
		patientHistory->setChildHoodMedicine(chldHdMed);

	}

	void distroyLabreports(LabReports* reports) {
		reports->setfurtherTest("404");
		reports->setLabReults("404");
		reports->setPreviousTest("404");
	}
};

