#pragma once
#include<iostream>
#include<string>
using namespace  std;

class PatientHistory
{
private:
	string familyDisease;
	string famDieseasMedicine;
	string  childHoodDiseases[10];
	string  medications[10];
	string  allergicMedicines[10];
public:
	

	PatientHistory() {

		familyDisease = "404";
		famDieseasMedicine = "404";
		for (int i = 0; i < 10; i++) {
		
			childHoodDiseases[i] = "404";
			medications[i] = "404";
			allergicMedicines[i] = "404";
		}
	}
		
	
	PatientHistory(string famDisease ,string fdMedicine, string  chDisease[], string medicine[] , string alrgMedicine[]) {
		familyDisease = famDisease;
		famDieseasMedicine = fdMedicine;
		for (int i = 0; i < 10; i++) {
			if (childHoodDiseases[i] == "404" || medications[i]=="404" || allergicMedicines[i]=="404") {

				childHoodDiseases[i] = chDisease[i];
				medications[i] = medicine[i];
				allergicMedicines[i] = alrgMedicine[i];
			}
			
		}
	}

	

	string getFamDisease() {
		return familyDisease;
	}
	string getFammDiesMedicine() {

		return famDieseasMedicine;
	}
	string* getChildHoodDisease() {
		return childHoodDiseases;
	}
	string* getMedies() {
		return medications;
	}
	string* getAlrgicMedies() {
		return allergicMedicines;
	}
};

