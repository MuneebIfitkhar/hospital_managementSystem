#pragma once
#include<iostream>
#include<string.h>
#include"PatientHistory.h"
#include"LabReports.h"
using namespace std;

class PatientInfo
{
private:
	string  name, fName, homeAddress, phoneNumber, id,age ,patientGender;
	PatientHistory  patientHistory;
	LabReports labReports;

public:

	PatientInfo(){
		age = "404";
		id = "404";
	}

	PatientInfo(string patientAge, string gender, string patientId, string patientName, string fathernName,
		string address, string contact ,PatientHistory phistory , LabReports reports) {
		
		labReports = reports;
		patientHistory =  phistory;
		id = patientId;
		name = patientName;
	    fName = fathernName;
	    homeAddress = address;
		phoneNumber = contact;
		age = patientAge;
		patientGender = gender;
	}

	
	//set methods
	void setId(string cnic) {
		id = cnic;
	}
	void setAge(string patientAge){
		age = patientAge;
	}
	void setName(string patientName) {
		name = patientName;
	}
	void setfName(string fatherName) {
		fName = fatherName;
	}
	void setAddress(string address){
		homeAddress = address;
	}
	void setPhoneNumbr (string contact){
		phoneNumber = contact;
	}
	void setGender(string gender) {
		patientGender = gender;
	}


	//get methods
	

	PatientHistory* getHistory() {
		return &patientHistory;
	}
	LabReports* getLabReports() {
		return &labReports;
	}

	string getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getAddress() {
		return homeAddress;
		}
	string getLastName() {
		return fName;
		}
	string getPhoneNumber() {
		return phoneNumber;
		}
	string getAge() {
		return age;
	}
	string getGender() {
		return patientGender;
	}
		

	
};

