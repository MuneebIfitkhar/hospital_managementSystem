#pragma once
#include<iostream>
#include<string>
using namespace  std;

class PatientHistory
{
private:
	string familyDisease;
	string childHoodDisease[10];
	string  childHoodMedicines[10];
	string  allergicMedicines[10];
public:
	

	PatientHistory() {

		familyDisease = "404";
		
		for (int i = 0; i < 10; i++) {
		
			childHoodDisease[i] = "404";
			childHoodMedicines[i] = "404";
			allergicMedicines[i] = "404";
		}
	}
		
	
	PatientHistory(string famDisease , string  chDisease[],string chdMedies[] ,string alrgMedicine[]) {
		familyDisease = famDisease;
		
		for (int i = 0; i < 10; i++) {

			childHoodDisease[i] = chDisease[i];
			childHoodMedicines[i] = chdMedies[i];
			allergicMedicines[i] = alrgMedicine[i];
		}
	}

	//setter methods 

	void setFamDiseas(string famDisease) {
		familyDisease = famDisease;
	}
	void setChildHoodMedicine(string chDisease[]) {
		for (int i = 0; i < 10; i++) {
			childHoodMedicines[i] = chDisease[i];
		}
		
	}
	void setChildhoodDisease(string childHD[]) {
		for (int i = 0; i < 10; i++) {
			childHoodDisease[i] = childHD[i];
		}
	}
	
		void setAllergicMedicines(string alergic[]) {
			for (int i = 0; i < 10; i++)
			{
				allergicMedicines[i] = alergic[i];
			}
		}
	
		//Getter Methods 
	string getFamDisease() {
		return familyDisease;
	}
	
	string* getChildHoodDisease() {
		return childHoodDisease;
	}
	string* getChildHoodMedies() {
		return childHoodMedicines;
	}
	string* getAlrgicMedies() {
		return allergicMedicines;
	}
};

