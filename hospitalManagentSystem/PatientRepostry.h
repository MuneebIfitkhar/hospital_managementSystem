#pragma once
#include<iostream>
#include"PatientInfo.h"


class PatientRepostry
{
private:
	PatientInfo patientInfo[100];

public:

	PatientRepostry(){
		cout << "Repository" << endl;
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
	PatientInfo searchPatient(string cnic) {
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == cnic)
			{
				return patientInfo[i];
				break;
			}
		}
	}
	PatientHistory * searchPatientHistory(string id) {
		for (int i = 0; i < 100; i++) {
			if (patientInfo[i].getId() == id)
			{
				return patientInfo[i].getHistory();
			}
		}
	}

	void update(string cnic , PatientInfo obj){
		PatientInfo patientobj =  searchPatient(cnic);
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == patientobj.getId()) {
				patientInfo[i] = obj;
				break;
			}
		}
	}

	void distroy(string cnic) {
		string Age = "404";
		string gender = "404";
		string Id = "404";
		string name = "404";
		string fName = "404";
		string address = "404";
		string contact = "404";
		PatientInfo patientInfoObject = searchPatient(cnic);
		for (int i = 0; i < 100; i++)
		{
			if (patientInfo[i].getId() == patientInfoObject.getId()) {

				patientInfo[i].setVals(Age, gender, Id, name, fName, address, contact);
				break;
			}
		}

	}
};

