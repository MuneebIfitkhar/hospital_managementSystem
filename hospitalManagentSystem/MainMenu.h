#pragma once
#include<iostream>
#include<string>
#include"PatientInfoUI.h"
#include"DoctorInfoUI.h"
using namespace std;

class MainMenu
{
private:
	
	PatientInfoUI patientUI;
	DoctorInfoUI docUI;

public:

	char choice = 'c';
	void MainMenuFunction() {

		int option;
		int select;
			
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
				//outer switch statement

				switch (select)
				{
				case 1:
					option = patientInformenu();
					//first inner switch statement
					switch (option) {
					case 1:
						patientUI.newPatientRigestration();
						break;
					case 2:
						patientUI.searchPatientinfo();
						break;
					case 3:
							patientUI.updatePatientinformation();
						break;
					case 4:
						patientUI.deletepatientInfo();
						break;
					}
				decision();
					break;
				case 2:
					select = patientHistoryMenu();
					//secont inner switch statement
					switch (select) {
					case 1:
						patientUI.searchHistory();
						break;
					case 2:
						patientUI.updatePatienthistory();
						break;
					case 3:
						patientUI.deleteHistory();
						break;
					}
					decision();
					break;
				case 3:
					select = labReportsMenu();
					switch (select) {
					case 1:
						patientUI.searchLabReports();
						break;
					case 2:
						patientUI.updateLabreports();
						break;
					case 3:
						patientUI.delateLabReports();
						break;
					}
					decision();
					break;
				case 4:
					select = doctorMenu();
					switch (select)
					{
					case 1:
						docUI.newDoctorRegisteration();
						break;
					case 2:
						docUI.displayDoctor();
						break;
					case 3:
						docUI.updateDoctore();
						break;
					case 4:
						docUI.deleteDoctor();
						break;
					}
					decision();
					break;
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
		int select;
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

	int patientHistoryMenu() {
		int select;
			cout << "################################################################### \n";
			cout << "##                                                               ## \n";
			cout << "##    Press 1 to SEARCH Patient's History                        ## \n";
			cout << "##    Press 2 to UPDATE Patient's History                        ## \n";
			cout << "##    Press 3 to DELETE Patient's History                        ## \n";
			cout << "##                                                               ## \n";
			cout << "################################################################### \n";
			cin >> select;
			cin.ignore();
			return select;
		}
	int labReportsMenu() {
		int select;
		cout << "################################################################### \n";
		cout << "##                                                               ## \n";
		cout << "##    Press 1 to SEARCH Patient's Lab-Reports                    ## \n";
		cout << "##    Press 2 to UPDATE Patient's Lab-Reports                    ## \n";
		cout << "##    Press 3 to DELETE Patient's Lab-Reports                    ## \n";
		cout << "##                                                               ## \n";
		cout << "################################################################### \n";
		cin >> select;
		cin.ignore();
		return select;

	}
	int doctorMenu() {

		int select;
		cout << "########################################################## \n";
		cout << "##                                                      ## \n";
		cout << "##    Press 1 to STORE  New Doctor's Information        ## \n";
		cout << "##    Press 2 to SEARCH Doctor's Information            ## \n";
		cout << "##    Press 3 to UPDATE Doctor's Information            ## \n";
		cout << "##    Press 4 to DELETE Doctor's Information            ## \n";
		cout << "##                                                      ## \n";
		cout << "########################################################## \n";
		cin >> select;
		cin.ignore();
		return select;
	}

};


