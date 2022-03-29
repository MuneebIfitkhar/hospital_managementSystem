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
		
public :
	
	string getCnic() {

		string patientCNIC;
		cout << "Enter Patient CNIC Number: \t";
		getline(cin, patientCNIC);
		return patientCNIC;
		}

		void newPatientRigestration() {
			
			string name, fName, address, phoneNumber, id, age, gender;
			string familyDisease;
			string famDiesMedicine;
			string childHoodDisease[10];
			string medications[10];
			string allergicMedicines[10];
			char choice;
			int size;

		cout << "Enter Patient CNIC Number: \t";
		getline(cin,id);
		cout << "Enter Patient's Name: \t";
		getline(cin, name);
		cout << "Enter Patient's Father/Gardians name: \t";
		getline(cin, fName);
		cout << "Enter Patietn's Gender (MAle/Female):\t";
		getline(cin, gender);
		cout << "Enter Patient's Age: \t";
		getline(cin,age);
		cout << "Enter Patient's Resedential Address: \t";
		getline(cin, address);
		cout << "Enter Patient's Contact Number: \t";
		getline(cin, phoneNumber);

		//Getting Patient's History information

		cout << "Does Patient have any child hood  disease ? (press 'Y' for yes and 'N' for No) \t";
		cin >> choice;
		if (choice == 'y')
		{
			cout << "Is patient have multiple disease (press 'Y' for yes and 'N' for No): \t";
			cin >> choice;
			if (choice == 'y') {
				cout << "Enter the Number of disease: \t";
				cin >> size;
				for (int i = 0; i < size; i++) {
					cout << "Enter the Disease  " << i + 1 << "\t" << endl;
					cin >> childHoodDisease[i];
				}
			}
			else {
				for (int i = 0; i < 1; i++) {
					cout << "Enter the Disease \t";
					cin >> childHoodDisease[i];
				}
			}

		}

		cout << "Does patient have any family disease? (press 'Y' for yes and 'N' for No) \t";
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			cout << "Enter Patient's Family Disease : \t";
			getline(cin, familyDisease);
			cout << "Enter the medication taken by Patient: \t";
			getline(cin, famDiesMedicine);
		}
		else {
			familyDisease = 'NILL';
			famDiesMedicine = 'NILL';
		}
		cout << "Is Patietn Allergic to any medicine(s)? (press 'Y' for yes and 'N' for No): \t";
		cin >> choice;
		if (choice == 'y') {
			cout << "Is there multiplle medicin? (press 'Y' for yes and 'N' for No):\t";
			cin >> choice;
			if (choice == 'y') {
				cout << "Enter the Number of medicines: \t";
				cin >> size;
				for (int i = 0; i < size; i++)
				{
					cout << "Enter Medicine No." << i + 1 << endl;
					cin >> allergicMedicines[i];
				}
			}
			else {
				for (int i = 0; i < 1; i++)
				{
					cout << "Enter the Medicine \t";
					cin >> allergicMedicines[i];
				}
			}

		}
		

		PatientHistory patientHistory= patientService.createPatientHistoryObj(familyDisease, famDiesMedicine, childHoodDisease, medications, allergicMedicines);

		patientService.addPatient(age,gender,id ,name,fName,address,phoneNumber,patientHistory);

		
	}


		void searchPatientinfo() {
			PatientInfo patientInfo = patientService.findPatient(getCnic());
			cout << patientInfo.getId()<<endl;
			cout << patientInfo.getName() << endl;
			cout << patientInfo.getLastName() << endl;
			cout << patientInfo.getPhoneNumber() << endl;
			cout << patientInfo.getAge()<< endl;
			cout << patientInfo.getGender() << endl;
			cout << patientInfo.getAddress()<< endl;
		}
		void searchHistory() {

			string CNIC = getCnic();
			PatientHistory* ptr = patientService.findPatientHistory(CNIC);
			string* majorDisease = ptr->getChildHoodDisease();
			string* medicines = ptr->getMedies();
			string* allergicMedicines = ptr->getAlrgicMedies();

			/*cout << ptr->getFamDisease()<<endl;
			cout << ptr->getFammDiesMedicine() << endl;
			*/
			for (int i = 0; i <10 ; i++)
			{
				if ((* majorDisease) == "404") {
					break;
				}
				else
				{
					cout << * majorDisease << endl;
				}
				majorDisease++;
			}

			/*cout << ptr->getFammDiesMedicine() << endl;
			cout << ptr->getAlrgicMedies() << endl;*/
		}

		void deletepatientInfo() {
			patientService.deletePatient(getCnic());

		}

		/*void updateRecord() {
			string CNIC = getCnic();
			cout << "Update Patient CNIC Number: \t";
			getline(cin, id);
			cout << "Update Patient's Name: \t";
			getline(cin, name);
			cout << "Update Patient's Father/Gardians name: \t";
			getline(cin, fName);
			cout << "Update Patietn's Gender (type M for male and F in case of Female):\t";
			getline(cin, gender);
			cout << "Update Patient's Age: \t";
			getline(cin,age);
			cout << "Update Patient's Resedential Address: \t";
			getline(cin, address);
			cout << "Update Patient's Contact Number: \t";
			getline(cin, phoneNumber);

			patientService.updatePatient(age, CNIC, gender, id, name, fName, address, phoneNumber);
			
		}*/

};