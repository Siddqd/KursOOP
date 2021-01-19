#include "MedPatient.h"

MedPatient::MedPatient() {
	this->ID = 0;			//конструктор пациента
	this->fio = NULL;
	this->bday = {0,0,0};
	this->tel = tell;
	this->res_tel = res_tell;
	this->polis = poliss;
}
MedPatient::MedPatient(int IDD, std::string fioo, data bdayy, int tell, int res_tell, int64_t poliss) {
	this->ID = IDD;			//конструктор пациента
	this->fio = fioo;
	this->bday = bdayy;
	this->tel = tell;
	this->res_tel = res_tell;
	this->polis = poliss;
}

int MedPatient::look4(MedPatient &mp) { //fio2 поиск по фио и полису, предварительно создаем объект пациент
    int IDD = -1;										// , куда записываем фио и полис, передаем по ссылке
    try {														//и сравниваем со значениями в файле пациентов

        std::fstream fPat;
        fPat.open(filePatient);
        if (fPat.is_open()) throw "Error_OpenFile";
        std::string bar;
        fPat >> bar;                    // считываем первое значение из файла - это общее кол-во пациентов

				while (!fPat.eof()) {
					fPat.getline(bar);
					bar.find(mp.fio)
				}

        fPat.close();
        return IDD;
    }
    catch (char* err) {
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
