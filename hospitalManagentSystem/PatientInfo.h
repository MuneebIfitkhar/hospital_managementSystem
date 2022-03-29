#pragma once
#include<iostream>
#include<string.h>
#include"PatientHistory.h"
using namespace std;

class PatientInfo
{
private:
	string  name, fName, homeAddress, phoneNumber, id,age ,gender;
	PatientHistory * patientHistory;

public:

	PatientInfo(){
		age = "404";
		id = "404";
	}

	PatientInfo(string patientAge, string patientGender, string patientId, string patientName, string fathernName,
		string address, string contact ,PatientHistory phistory) {
		 this->patientHistory =  & phistory;
		this->id = patientId;
		this->name = patientName;
		this->fName = fathernName;
		this->homeAddress = address;
		this->phoneNumber = contact;
		this->age = patientAge;
		this->gender = patientGender;
	}

	void setVals(string patientAge, string patientGender, string patientId, string patientName, string fathernName, string address, string contact) {

		id = patientId;
		name = patientName;
		fName = fathernName;
		homeAddress = address;
		phoneNumber = contact;
		age = patientAge;
		gender = patientGender;

	}
	PatientHistory* getHistory() {
		return this->patientHistory;
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
		return gender;
	}
		

	
};

