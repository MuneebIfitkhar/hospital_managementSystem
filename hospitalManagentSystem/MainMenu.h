#pragma once
#include<iostream>
#include<string>
#include"PatientInfoUI.h"
using namespace std;

class MainMenu
{
private:
	
	PatientInfoUI UIobject;

public:

	int option;
	int select;
	char choice = 'c';

	void MainMenuFunction() {
		
		
		while (choice == 'c') {

			cout << "\t\t\t\t\t\t\t   Welcome to \n \t\t\t\t\t\t\t  ABC hospital \n";
			cout << endl; cout << endl;
			cout << "**********************************************************\n";
			cout << "**     Please Follow the Below menu                     **\n";
			cout << "**                                                      **\n";
			cout << "**   Press 1 For Patient's Information                  **\n";
			cout << "**   Press 2 For patient History                        **\n";
			cout << "**   Press 3 For Pathological History and Lab reports   **\n";
			cout << "**   Press 4 For Doctor's Information                   **\n";
			cout << "**   Press 5 For Appointments from Doctor               **\n";
			cout << "**   Press 6 for statistics  of Patients                **\n";
			cout << "**   Press 0 to Exit the Program                        **\n";
			cout << "**                                                      **\n";
			cout << "**********************************************************\n";
			cin >> select;
			if (select == 0) {
				exit(0);
			}
			else {
				cin.ignore();
				switch (select)
				{
				case 1:
					option = patientInformenu();
					switch (option) {
					case 1:
						UIobject.newPatientRigestration();
						break;
					case 2:
						UIobject.searchPatientinfo();
						break;
					case 3:
					/*	UIobject.updateRecord();*/
						break;
					case 4:
						UIobject.deletepatientInfo();
						break;
					}
					decision();
					break;
				case 2:
					UIobject.searchHistory();
					decision();
				}
			}
		}
		
}
	char decision() {
		
		cout << "Press 'Q' to Exit and 'C' to contienu \t";
		cin >> choice;
		return choice;
	}
	int patientInformenu() {
		cout << "######################################################### \n";
		cout << "##                                                     ## \n";
		cout << "##    Press 1 to STORE  New Patient Information        ## \n";
		cout << "##    Press 2 to SEARCH Patient Information            ## \n";
		cout << "##    Press 3 to UPDATE Patient Information            ## \n";
		cout << "##    Press 4 to DELETE Patient Information            ## \n";
		cout << "##                                                     ## \n";
		cout << "######################################################### \n";
		cin >> select;
		cin.ignore();
		return select;
	}

};

