#include<string.h>
#include<string>
#include<iostream>
#include"DoctorService.h"
using namespace std;

#pragma once
class DoctorInfoUI
{
private:
	DoctorService docService;
public:
	string inputCnic() {
		string id;
		cout << "Enter Doctor's CNIC/license Number: \t";
		getline(cin, id);
		return id;
	}

	void newDoctorRegisteration() {
		string Id, name, specialization, gender;
		string experience, contactNumber;
		string email, hours, mins;

		cout << "Enter Doctor's CNIC/License Number: \t";
		getline(cin, Id);
		cout << "Enter Doctor's Name: \t";
		getline(cin, name);
		cout << "Enter Doctor's Gender: \t";
		getline(cin, gender);
		cout << "Enter Doctore's Contact Number: \t";
		getline(cin, contactNumber);
		cout << "Enter Doctore's Email Address: \t";
		getline(cin, email);
		cout << "Enter Doctor's Specialization Area: \t";
		getline(cin, specialization);
		cout << "Enter Doctore's Working Experienc: \t";
		getline(cin, experience);
		cout << "Enter Doctore's Available Timing(hh/mm): \t";
		getline(cin, hours); cout << "/"; getline(cin, mins);

		docService.saveDoctor(Id, name, specialization, gender, experience, contactNumber, email, hours,mins);
		cout << endl;
		cout << "***********************************************\n";
		cout << "**                                           **\n";
		cout << "**  DOCTOR'S RECORD IS SAVED SUCCESSFULLY    **\n";
		cout << "**                                           **\n";
		cout << "***********************************************\n";
	}

	void displayDoctor() {

		DoctorInfo *docInfo = docService.searchDoc(inputCnic());
		if (docInfo->getId() == "404") {
			cout << "RECORD NOT FOUND" << endl;
		} 
		else {
			cout << "Doctor's CNIC/License Number: " << docInfo->getId() << endl;
			cout<<"Doctor's Name: "<< docInfo->getName() << endl;
			cout<<"Doctore's Gender: "<<docInfo->getGender() << endl;
			cout<<"Doctor's Contact Number: "<<docInfo->getPhoneNumber() << endl;
			cout<<"Doctor's Email Address: "<<docInfo->getEmail() << endl;
			cout<<"Doctor's Specializationn Area: "<<docInfo->getSpecializeArea() << endl;
			cout<<"Doctor's Working Experience: "<<docInfo->getExperience() << endl;
			cout << "Doctor's Available Timings: " << docInfo->getHours() << ":"<<docInfo->getMins() << endl;
		}
	}


	void updateDoctore() {
		string Id, name, specialization, gender;
		string experience, contactNumber;
		string email, hours,min;

		DoctorInfo* docInfo = docService.searchDoc(inputCnic());
		if (docInfo->getId() == "404") {
			cout << "RECORD NOT FOUND" << endl;
		}
		else {
			cout << "NOTE: Only enter Info that you want to update otherwise Press Enter to skip: \n";

			
			cout << "Update Doctor's Name: \t";
			getline(cin, name);
			cout << "Update Doctor's Gender: \t";
			getline(cin, gender);
			cout << "Update Doctore's Contact Number: \t";
			getline(cin, contactNumber);
			cout << "Update Doctore's Email Address: \t";
			getline(cin, email);
			cout << "Update Doctor's Specialization Area: \t";
			getline(cin, specialization);
			cout << "Update Doctore's Working Eperienc: \t";
			getline(cin, experience);
			cout << "Update Doctore's Available Timing(HH/MM): \t";
			getline(cin, hours); cout << "/"; getline(cin, min);

			docService.updateDoctor(name, specialization, gender, experience, contactNumber, email, hours,min,docInfo);
			cout << endl;
			cout << "*************************************************\n";
			cout << "**                                             **\n";
			cout << "**  DOCTOR'S RECORD IS UPDATED SUCCESSFULLY    **\n";
			cout << "**                                             **\n";
			cout << "*************************************************\n";
		}
		
	}

	void deleteDoctor() {
		DoctorInfo* docInfo = docService.searchDoc(inputCnic());
		if (docInfo->getId() == "404") {
			cout << "RECORD NOT FOUND" << endl;
		}
		else {
			docService.deleteDoctor(docInfo);
			cout << endl;
			cout << "*************************************************\n";
			cout << "**                                             **\n";
			cout << "**  DOCTOR'S RECORD IS DELETED SUCCESSFULLY    **\n";
			cout << "**                                             **\n";
			cout << "*************************************************\n";
		}
	}
};

