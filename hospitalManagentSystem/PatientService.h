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


	void addPatient(string age, string gender, string patientId, string name, string fName, string address, string phoneNumber ,PatientHistory patientHistory ) {
 
		PatientInfo patientInfo(age,gender,patientId,name,fName,address,phoneNumber, patientHistory);

		patientRepostry.save(patientInfo);
	}
	PatientHistory createPatientHistoryObj(string familyDisease, string famDiesMedicine, string majorDiseases [], string medications [], string allergicMedicines[]) {
		PatientHistory patientHistory(familyDisease, famDiesMedicine, majorDiseases, medications, allergicMedicines);
		return patientHistory;
	}
	
	PatientInfo findPatient(string id) {
		return patientRepostry.searchPatient(id);
	}
	PatientHistory* findPatientHistory(string id) {
		return patientRepostry.searchPatientHistory(id);
	}
	void deletePatient(string cnic) {
		patientRepostry.distroy(cnic);
	}
	/*void updatePatient(string age, string cnic ,string gender, string patientId, string name, string fName, string address, string phoneNumber) {
		
		PatientInfo patientObject(age, gender, patientId, name, fName, address, phoneNumber);
		patientRepostry.update(cnic, patientObject);
	}*/

	
};

