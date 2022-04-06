#include<string>
#include"DoctorInfo.h"
using namespace std;
#pragma once

class DoctorRepostry
{
private:
	DoctorInfo doctorInfo[100];
public:

	void save(DoctorInfo docInfo) {
		for (int i = 0; i < 100; i++) {
			if (doctorInfo[i].getId() == "404") {
				doctorInfo[i] = docInfo;
				break;
			}
		}
	}

	void update( string name, string specialized,
		string gender, string experience, string contactNumber,
		string email, string hours,string min , DoctorInfo * docInfo) {

		if (name != "") {
			docInfo->setName(name);
		}
		if (specialized != "") {
			docInfo->setSpecialization(specialized);
		}
		if (gender != "") {
			docInfo->setGender(gender);
		}
		if (experience !=""){
			docInfo->setExperience(experience);
		}
		if (contactNumber != "") {
			docInfo->setPhoneNumber(contactNumber);
		}
		if (email != "") {
			docInfo->setEmail(email);
		}
		if (hours!="") {
			docInfo->setHour(hours);
		}
		if (min != "") {
			docInfo->setMints(min);
		}

	}

	void distroy(DoctorInfo* docInfo) {

		docInfo->setId("404");
		docInfo->setName("404");
		docInfo->setPhoneNumber("404");
		docInfo->setSpecialization("404");
		docInfo->setGender("404");
		docInfo->setEmail("404");
		docInfo->setHour("404");
		docInfo->setMints("404");
		docInfo->setExperience("404");
		
	}

	DoctorInfo * search(string id) {
		DoctorInfo * emptyObject = new DoctorInfo();
		for (int i = 0; i < 100; i++) {
			if (doctorInfo[i].getId() == id) {
				
				return &doctorInfo[i];
			}
		}
		return emptyObject;

	}
	
	
};

