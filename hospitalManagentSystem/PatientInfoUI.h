#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include "PatientService.h"
using namespace std;

class PatientInfoUI
{
	//objects 
	PatientService patientService;
public:

	string getCnic() {

		string patientCNIC;
		cout << "Enter Patient CNIC Number: \t";
		getline(cin, patientCNIC);
		return patientCNIC;
	}

	void newPatientRigestration() {

		string name, fName, address, phoneNumber, id, age, gender;
		string familyDisease;
		string chilhoodMedication[10];
		string childHoodDisease[10];
		string allergicMedicines[10];
		string oldTest, newTest, results;
		char choice;
		int size;

		cout << "Enter Patient CNIC Number: \t";
		getline(cin, id);
		cout << "Enter Patient's Name: \t";
		getline(cin, name);
		cout << "Enter Patient's Father/Gardians name: \t";
		getline(cin, fName);
		cout << "Enter Patietn's Gender (MAle/Female):\t";
		getline(cin, gender);
		cout << "Enter Patient's Age: \t";
		getline(cin, age);
		cout << "Enter Patient's Resedential Address: \t";
		getline(cin, address);
		cout << "Enter Patient's Contact Number: \t (+92)";
		getline(cin, phoneNumber);

		//Getting Patient's History information

		cout << "Does Patient have any childhood  disease ? (press 'Y' for yes and 'N' for No) \t";
		cin >> choice;
		if (choice == 'y')
		{
			cout << "Is patient have multiple disease (press 'Y' for yes and 'N' for No): \t";
			cin >> choice;
			cin.ignore();
			if (choice == 'y') {
				cout << "Enter the Number of disease: \t";
				cin >> size;
				cin.ignore();
				for (int i = 0; i < size; i++) {
					cout << "Enter the Disease  " << i + 1 << "\t" << endl;
					cin >> childHoodDisease[i];
					cin.ignore();

				}
			}
			else {
				for (int i = 0; i < 1; i++) {
					cout << "Enter the Disease \t";
					cin >> childHoodDisease[i];
					cin.ignore();
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				childHoodDisease[i] = "Nill";
			}
		}


		cout << "Is patient taking any medicine for childhood disease ? (press 'Y' for yes and 'N' for No): \t";
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			cout << "Is patient taking multiple medication? (press 'Y' for yes and 'N' for No): \t";
			cin >> choice;
			cin.ignore();
			if (choice == 'y')
			{
				cout << "Enter Number of medicine: \t";
				cin >> size;
				cin.ignore();
				for (int i = 0; i < size; i++)
				{
					cout << "Enter medicine No." << i + 1 << endl;
					cin >> chilhoodMedication[i];
					cin.ignore();
				}
			}
			else
			{
				for (size_t i = 0; i < 1; i++)
				{
					cout << "Enter the medicine: \t";
					cin >> chilhoodMedication[i];
					cin.ignore();

				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				chilhoodMedication[i] = "NILL";
			}
		}

	


		cout << "Does patient have any family disease? (press 'Y' for yes and 'N' for No) \t";
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			cout << "Enter Patient's Family Disease : \t";
			getline(cin, familyDisease);
			cin.ignore();
			
		}
		else {
			familyDisease = "NILL";
			
		}

		cout << "Is Patietn Allergic to any medicine(s)? (press 'Y' for yes and 'N' for No): \t";
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			cout << "Is there multiplle medicin? (press 'Y' for yes and 'N' for No):\t";
			cin >> choice;
			cin.ignore();
			if (choice == 'y') {
				cout << "Enter the Number of medicines: \t";
				cin >> size;
				cin.ignore();
				for (int i = 0; i < size; i++)
				{
					cout << "Enter Medicine No." << i + 1 << endl;
					cin >> allergicMedicines[i];
					cin.ignore();
				}
			}
			else {
				for (int i = 0; i < 1; i++)
				{
					cout << "Enter the Medicine \t";
					cin >> allergicMedicines[i];
					cin.ignore();
				}
			}

		}
		else {
			for (int i = 0; i < 10; i++)
			{
				allergicMedicines[i] = "Nill";
			}
		}
		
		cout << endl;
		cout << "Patient have Any previous Lab Reports or results? (press 'Y' for Yes and 'N' for NO) \t ";
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			cout << "Please specify the Test \t ";
			getline(cin, oldTest);
			cout << "Enter the result: \t ";
			getline(cin, results);
			
		}
		else {
			oldTest = "Nill";
			results = "Nill";
			newTest = "Nill";
		}
		
		PatientHistory patientHistory= patientService.createPatientHistoryObj(familyDisease,
			childHoodDisease ,chilhoodMedication, allergicMedicines);

		LabReports reports = patientService.createLabReports(oldTest, newTest, results);

		patientService.addPatient(age,gender,id ,name,fName,address,
			phoneNumber,patientHistory,reports);

		cout << endl;
		cout << "PATIENT'S INFORMATION IS RECORDED SUCCESSFULLY \n";
		
	}


		void searchPatientinfo() {

			PatientInfo patientInfo = patientService.findPatient(getCnic());
			if (patientInfo.getId() == "404") {
			
				cout << " RECORD NOT FOUND " << endl;
			}
			else {
				cout << "Patient's CNIC Number: " << patientInfo.getId() << endl;
				cout << "Patient's Name: " << patientInfo.getName() << endl;
				cout << "Patietn's Father/Garidan Name: " << patientInfo.getLastName() << endl;
				cout << "Patient's Contact Number: " << patientInfo.getPhoneNumber() << endl;
				cout << "Patient's Age: " << patientInfo.getAge() << " Year(s)" << endl;
				cout << "Patient's Gender: " << patientInfo.getGender() << endl;
				cout << "Patient's Residential Address: " << patientInfo.getAddress() << endl;
			}
		}

		void searchHistory() {
			PatientHistory * patientHistory = patientService.findPatientHistoryRefrence(getCnic());
			if (patientHistory->getFamDisease() == "404") {
				
				cout << "RECORD NOT FOUND \n";

			}
			else {
				string* childHoodDisease = patientHistory->getChildHoodDisease();
				string* chldHoodMedicines = patientHistory->getChildHoodMedies();
				string* allergicMedicines = patientHistory->getAlrgicMedies();

				cout << "Patient's Family Disease :" << patientHistory->getFamDisease() << endl;
				for (int i = 0; i < 10; i++)
				{
					

					if ((*childHoodDisease) == "" ) {
						break;
					}
					else
					{
						cout << "Patient's Childhood Disease(s): " << *childHoodDisease << endl;
						cout << "Patients's Medications for Childhood Disease(s):  " << *chldHoodMedicines << endl;
						cout << "Medicines patient allergic to : " << *allergicMedicines << endl;

					}
					cout << endl;
					childHoodDisease++;
					chldHoodMedicines++;
					allergicMedicines++;

				}
			}
		}

		void searchLabReports() {
			LabReports* labReports = patientService.findLabReports(getCnic());
			if (labReports->getLabReults()=="404")
			{
				cout << "RECORD NOT FOUND " << endl;
			}
			else {
				cout << "Previously Done Reports: " << labReports->getPreviousTest() << endl;
				cout << "Previously Done Reports results: " << labReports->getLabReults() << endl;
				cout << "further Test recomendations: " << labReports->getFurtherTest() << endl;
			}
		}

		void deletepatientInfo() {
			PatientInfo * obj = patientService.findPatientReference(getCnic());
			if (obj->getId() != "404") {

				patientService.deletePatient(obj);
				cout << "RECORD DELETED SUCCESSFULLY \n";
			}
			else {
				cout << "RECORD NOT FOUND \n";
			}
			
			
		}

		void delateLabReports() {
			LabReports* reports = patientService.findLabReports(getCnic());
			if (reports->getLabReults() == "404") {
				cout << "RECORD NOT FOUND" << endl;
			}
			else {
				patientService.deletePatientLabReports(reports);
			}
		}

		void deleteHistory() {
			PatientHistory* patientHistory = patientService.findPatientHistoryRefrence(getCnic());

			if (patientHistory->getFamDisease() == "404") {
				cout << "RECORD NOT FOUND" << endl;
			}
			else {
				patientService.deletePatientHistory(patientHistory);
				cout << "RECORD DELETED SUCCESSFULLLY" << endl;
			}
		}

		void updatePatientinformation() {
			string name, fName, address, phoneNumber, id, age, gender;
			PatientInfo * patientinfo = patientService.findPatientReference(getCnic());
			if (patientinfo->getId() == "404") {
				cout << "RECORD NOT FOUND" << endl;
			}
			else {
				cout << "NOTE: Only Enter Information you want to update, otherwise press Enter to skip\n";
				cout << "Update Patient CNIC Number: \t";
				getline(cin, id);
				cout << "Update Patient's Name: \t";
				getline(cin, name);
				cout << "Update Patient's Father/Gardians name: \t";
				getline(cin, fName);
				cout << "Update Patietn's Gender (Male/Female):\t";
				getline(cin, gender);
				cout << "Update Patient's Age: \t";
				getline(cin, age);
				cout << "Update Patient's Resedential Address: \t";
				getline(cin, address);
				cout << "Update Patient's Contact Number: \t";
				getline(cin, phoneNumber);
				patientService.updatePatient(age, id, gender, name, fName, address, phoneNumber,patientinfo);
			}
		}

		void updatePatienthistory() {
			string chilhoodMedication[10];
			string childHoodDisease[10];
			string famDisease;
			string allergicMedicines[10];
			char choice;
			int size;

			PatientHistory* patientHistory = patientService.findPatientHistoryRefrence(getCnic());

			if (patientHistory->getFamDisease() == "404")
			{
				cout << "RECORD NOT FOUND!" << endl;
			}
			else {
				cout << "UPDATE PATIENT HISTORY" << endl;

				cout << "Do you wnat to Update childhood  disease ? (press 'Y' for yes and 'N' for No) \t";
				cin >> choice;
				cin.ignore();
				if (choice == 'y')
				{
					cout << "Is patient have multiple disease (press 'Y' for yes and 'N' for No): \t";
					cin >> choice;
					cin.ignore();
					if (choice == 'y') {
						cout << "Enter the Number of disease: \t";
						cin >> size;
						cin.ignore();
						for (int i = 0; i < size; i++) {
							cout << "Update the Disease No." << i + 1 << "\t" << endl;
							cin >> childHoodDisease[i];
							cin.ignore();

						}
					}
					else {
						for (int i = 0; i < 1; i++) {
							cout << "Enter the Disease \t";
							cin >> childHoodDisease[i];
							cin.ignore();
						}
					}
				}
				else {
					for (int i = 0; i < 10; i++) {
						childHoodDisease[i] = "";
					}
				}
				cout << "Do you Want to Update Childehood medication Record? (press 'Y' for yes and 'N' for No) \t";
				cin >> choice;
				cin.ignore();
				if(choice=='y'){
					cout << "Is patient taking any medicine for childhood disease ? (press 'Y' for yes and 'N' for No): \t";
					cin >> choice;
					cin.ignore();
					if (choice == 'y') {
						cout << "Is patient taking multiple medication? (press 'Y' for yes and 'N' for No): \t";
						cin >> choice;
						cin.ignore();
						if (choice == 'y')
						{
							cout << "Enter Number of medicine: \t";
							cin >> size;
							cin.ignore();
							for (int i = 0; i < size; i++)
							{
								cout << "Update medicine No." << i + 1 << endl;
								cin >> chilhoodMedication[i];
								cin.ignore();
							}
						}
						else
						{
							for (size_t i = 0; i < 1; i++)
							{
								cout << "update the medicine: \t";
								cin >> chilhoodMedication[i];
								cin.ignore();

							}
						}
					}

				}
				else {
					for (int i = 0; i < 10; i++) {
						chilhoodMedication[i] = "";
					}
				}
				cout << "Do you Want to Update Patient's Family Disease record? (press 'Y' for yes and 'N' for No) \t";
				cin >> choice;
				cin.ignore();
				if (choice == 'y') {
					cout << "Does patient have any family disease? (press 'Y' for yes and 'N' for No) \t";
					cin >> choice;
					cin.ignore();
					if (choice == 'y') {
						cout << "Enter Patient's Family Disease : \t";
						getline(cin,famDisease);
						cin.ignore();
					}
					else {
						famDisease = "";

					}
				}
				cout << "Do you want to update Allegic medicines record ? (press 'Y' for yes and 'N' for No) \t";
				cin >> choice;
				cin.ignore();
				if (choice == 'y') {
					cout << "Is Patietn Allergic to any medicine(s)? (press 'Y' for yes and 'N' for No): \t";
					cin >> choice;
					cin.ignore();
					if (choice == 'y') {
						cout << "Is there multiplle medicin? (press 'Y' for yes and 'N' for No):\t";
						cin >> choice;
						cin.ignore();
						if (choice == 'y') {
							cout << "Enter the Number of medicines: \t";
							cin >> size;
							cin.ignore();
							for (int i = 0; i < size; i++)
							{
								cout << "Update Medicine No." << i + 1 << endl;
								cin >> allergicMedicines[i];
								cin.ignore();
							}
						}
						else {
							for (int i = 0; i < 1; i++)
							{
								cout << "Update the Medicine \t";
								cin >> allergicMedicines[i];
								cin.ignore();
							}
						}
					}
				}
				else {
					for (int i = 0; i <10 ; i++)
					{
						allergicMedicines[i] = "";
					}
				}
				PatientHistory* patientHistory = patientService.findPatientHistoryRefrence(getCnic());
				patientService.updatePatientHistory(famDisease, childHoodDisease, chilhoodMedication, allergicMedicines, patientHistory);

				cout << endl;
				cout << "PATIENT'S HISTORy RECORDED IS UPDATED SUCCESSFULLY \n";


			}
		}

		void updateLabreports() {
			char choice;
			string oldTest, newTest, results;
			LabReports* reports = patientService.findLabReports(getCnic());
			if (reports->getLabReults() == "404") {
				cout << "RECORD NOT FOUND" << endl;
			}
			else {
				cout << "Do you want to Update Previously Done Lab-Reports? (press 'Y' for yes and 'N' for no): \t";
				cin >> choice;
				cin.ignore();
				if (choice == 'y') {
					cout << "Please Specify Previously done lab-Reports: \t";
					getline(cin, oldTest);
					cin.ignore();
					cout << "Please Update the Results :\t ";
					getline(cin, results);
				}
				else {
					oldTest = "";
					results = "";
				}
				cout << "Do you want to update/recomend Further Lab Reports? (press 'Y' for yes and 'N' for no):\t";
				cin >> choice;
				cin.ignore();
				if (choice == 'y')
				{
					cout << "Please Update/recomend Furthet Lab reports: \t";
					getline(cin, newTest);
					cin.ignore();
				}
				else {
					newTest = "";
				}


			}

			patientService.updateLAbReports(oldTest, newTest, results, reports);

			cout << endl;
			cout << "Lab-Reports Update Successfully" << endl;

		}
		
};