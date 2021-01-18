#include "MedPatient.h"

MedPatient::MedPatient() {}
MedPatient::MedPatient(int IDD, std::string fioo, data bdayy, int tell, int res_tell, int64_t poliss) {
	this->ID = IDD;
	this->fio = fioo;
	this->bday = bdayy;
	this->tel = tell;
	this->res_tel = res_tell;
	this->polis = poliss;
}

int MedPatient::look4() {
    int IDD = -1;
    try {

        std::fstream fPat;
        fPat.open(filePatient);
        if (fPat.is_open()) throw "Error_OpenFile";
        std::string bar;
        fPat >> bar;                    // считываем первое значение из файла - это общее количество пациентов
        

        fPat.close();
        return IDD;
    }
    catch (const char* err[20]) {
        std::count << err << '\n';
    }
}

int MedPatient::AddNewData(MedPatient& pat, const char* filePat) {
    pat.look4();
    try {
        
        std::fstream fPat;
        fPat.open(filePat);
        if (fPat.is_open()) throw "ErrorE";
        std::string bar;
        fPat>>bar;
        

        fPat.close();
    }


    catch (const char* err) {
        cout << err << '\n';
        return 1;
    }
}