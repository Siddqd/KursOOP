#pragma once
#include "People.h"
class MedPatient :
    protected People
{
private:
    int status;			//0 - ����, 1 - �� �������, 2 - ������� (-1 ��� � ���� ������)
    int chamber_ID;
    int history_ID;
    int doctor_ID;

public:
    MedPatient();
    look4();
    MedPatient(int IDD, std::string fioo, data bdayy, int tell, int res_tell, int64_t poliss);//����� ������� IDpatient, ����� ������ �� MedHistory
    int AddNewData(MedPatient& pat, const char* filePat);
    
};

