#pragma once
#include "People.h"
class MedPatient :
    protected People
{
private:
    int status;			//0 - умер, 1 - на лечении, 2 - выписан (-1 нет в базе данных)
    int chamber_ID;
    int history_ID;
    int doctor_ID;

public:
    MedPatient();
    look4();
    MedPatient(int IDD, std::string fioo, data bdayy,
                  int tell, int res_tell, int64_t poliss);//нужно вернуть IDpatient, вызов записи из MedHistory
    int AddNewData(MedPatient& pat, const char* filePat);

};
