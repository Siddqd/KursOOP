#pragma once
#include "Med.h"
class MedChamber : protected Med
{
private:
	int taked_cham;	//количество занятых в палате
	int* list_patient_id; //список id пациентов в палате

public:
	MedChamber();
	~MedChamber();
};

