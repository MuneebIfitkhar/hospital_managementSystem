#pragma once
#include<string.h>
#include"DoctorInfo.h"
#include"DoctorRepostry.h"
using namespace std;
class DoctorService
{
private:
	DoctorRepostry doctorRepo;
public:
	 
	void saveDoctor(string Id ,string name, string specialized,
		string Gender, string Experience, string contactNumber,
		string email, string hour ,string min) {

		DoctorInfo doctorInfo(Id,name, specialized,
			Gender, Experience, contactNumber, email, hour , min);
		doctorRepo.save(doctorInfo);
	}

	DoctorInfo* searchDoc(string id) {
		return doctorRepo.search(id);
	}
	
	void updateDoctor( string name, string specialized,
		string gender, string experience, string contactNumber,
		string email, string hour, string min, DoctorInfo * docInfo) {

		doctorRepo.update(name, specialized, gender,
			experience, contactNumber, email, hour, min, docInfo);


	}
	
	void deleteDoctor(DoctorInfo* docInfo) {
		doctorRepo.distroy(docInfo);
	}
};

