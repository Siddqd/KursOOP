#pragma once
#include "Med.h"
class MedChamber : protected Med
{
private:
	int taked_cham;	//���������� ������� � ������
	int* list_patient_id; //������ id ��������� � ������

public:
	MedChamber();
	~MedChamber();
};

