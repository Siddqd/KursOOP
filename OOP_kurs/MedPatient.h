#pragma once
#include "MedHuman.h"
class MedPatient :
    public People
{
private:
    int status;			//0 - умер, 1 - на лечении, 2 - выписан (-1 нет в базе данных)
    int room_ID;
    //int rec_ID; rec_ID = pat_ID
    int doc_ID;

public:

    MedPatient();
    void look4(const char* filePat);
    MedPatient(int idd, std::string fioo, data bdayy,
                  int64_t tell, int64_t res_tell, int64_t poliss);//нужно вернуть IDpatient, вызов записи из MedHistory
    int AddNewData(const char* filePat);

};
