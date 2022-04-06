#include<string.h>
#include<iostream>
using namespace std;
#pragma once

class DoctorInfo
{ 
private:

	string id;
	string name, speciallizeArea, gender, experience;
	string phoneNumber, emailAddress, hours , min;

public:
	DoctorInfo() {
		id = "404";
		
	}
	
	DoctorInfo(string docId,string docName, string specialized,
		string docGender, string docExperience, string contactNumber,
		string email, string hrs , string mins) {
		id = docId;
		name = docName;
		speciallizeArea = specialized;
		gender = docGender;
		experience = docExperience;
		phoneNumber = contactNumber;
		emailAddress = email;
		hours = hrs;
		min = mins;
		
	}
	
	void setId(string doctId) {
		id = doctId;
	}
	
	void setName(string docName) {
		name = docName;
	}
	
	void setSpecialization(string specialized) {
		speciallizeArea = specialized;
	}
	
	void setGender(string docGender) {
		gender = docGender;
	}
	
	void setExperience(string docExperience) {
		experience = docExperience;
	}
	
	void setPhoneNumber(string contact) {
		phoneNumber = contact;
	}
	
	void setEmail(string email) {
		emailAddress = email;
	}
	
	void setHour(string hrs) {
		
		hours = hrs;
	}

	void setMints(string mins) {
		min = mins;
	}

	string getId() {
		return id;
	}
	
	string getName() {
		return name;
	}
	
	string getSpecializeArea() {
		return speciallizeArea;
	}
	
	string getGender() {
		return gender;
	}
	
	string getExperience() {
		return experience;
	}
	
	string getPhoneNumber() {
		return phoneNumber;
	}
	
	string getEmail() {
		return emailAddress;
	}
	
	string getHours() {
		return hours;
	}
	string getMins() {
		return min;
	}
};

