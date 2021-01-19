#pragma once
#include "Med.h"
class MedRoom : public Med
{
private:
	int taked_cham;	//количество занятых мест в палате
	int* list_patient_id; //список id пациентов в палате (можно и не писать, искать инфу в MedHistory)
public:
	MedRoom();

	~MedRoom();
};
