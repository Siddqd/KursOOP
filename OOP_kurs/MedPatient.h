#pragma once
#include "MedHuman.h"
class MedPatient :
    public People
{
private:
    int status;			//0 - умер, 1 - на лечении, 2 - выписан (-1 нет в базе данных)
    int room_ID;
    int rec_ID;
    int doc_ID;

public:

    MedPatient();
    std::string look4(const char* filePat);
    MedPatient(int IDD, std::string fioo, data bdayy,
                  int tell, int res_tell, int64_t poliss);//нужно вернуть IDpatient, вызов записи из MedHistory
    int AddNewData(const char* filePat);

};
