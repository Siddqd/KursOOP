#pragma once
#include "MedHuman.h"
class MedPatient :
    public MedHuman
{
private:
    int status;			//0 - умер, 1 - на лечении, 2 - выписан (-1 нет в базе данных)
    int room_id;
    //int rec_ID; rec_ID = pat_ID
    int doc_id;

public:

    MedPatient();
    MedPatient(int);
    MedPatient(std::string, Data);
    MedPatient(int idpp, std::string fioo, Data bdayy,
        int tell, int res_tell, int64_t poliss, int status, int room_id, int doc_id);
    int getStatus();
    void setStatus(int statuss);

    int64_t getRoom_id();
    void setRoom_id(int64_t room_idd);

    int64_t getDoc_id();
    void setDoc_id(int doc_idd);

    MedPatient();
    int look4(const char* filePat);

    int ShowDataScr(const char* filePat);

    MedPatient(int idd, std::string fioo, Data bdayy,
                  int64_t tell, int64_t res_tell, int64_t poliss);//нужно вернуть IDpatient, вызов записи из MedHistory

    int AddNewData(const char* filePat); //возвращает -1 при fail

};
