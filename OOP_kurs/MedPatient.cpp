#include "MedPatient.h"

MedPatient::MedPatient() {
	this->ID = '';			//конструктор пациента
	this->fio = NULL;
	this->bday = {0,0,0};
	this->tel = 0;
	this->res_tel = 0;
	this->polis = 0;
}
MedPatient::MedPatient(std::string IDD, std::string fioo, data bdayy, int tell, int res_tell, int64_t poliss) {
	try {
	this->ID = IDD;			//конструктор пациента
	this->fio = fioo;
	this->bday = bdayy;
	this->tel = tell;
	this->res_tel = res_tell;
	this->polis = poliss;
	if throw
	}
}

		void MedPatient::look4(const char* filePat) { //fio2 поиск по фио и ДР, предварительно создаем объект пациент
    int iddp = -1;										// , куда записываем фио и полис, передаем по ссылке
		int foo;
    try {									        					//и сравниваем со значениями в файле пациентов

        std::fstream fPat;
        fPat.open(filePat);
        if (fPat.is_open()) throw "Error_OpenFile";
				if (fPat.eof()) throw "Error_filePatient_is_EMPTY";
        std::string bar;
				std::string foo;

				//fPat.getline(bar);                    // считываем первую строку - общее кол-во пациентов и номер крайнего пациента
																						//просто для пролистывания
				//int check=0;										//если находим соотв фамилии в строке, меняем чек

				while (!fPat.eof()) {
					fPat>>bar;
					if(bar=="IDP") {						//проверяем сигнатуру IDP
							fPat>>idpp;							//считали ID текущего пациента
							fPat>>bar;						//считываем по идее FIO

							if(bar=="FIO") {
									bar=getline(fPat);	//считали фамилию , но с пробелом в начале
							if(" "+fio==bar) {					//если == , значит фамилия найдена
								fPat>>bar;					//считываем сигнатуру ДР
								if (bar=="BDAY") {	//если да,
									fpat>>foo;			//считываем число ДР
									if (foo==bday.day) {	//сравниваем с заданым
										fpat>>foo;			//считываем месяц
										if (foo==bday.month) {	//сравниваем с заданым
											fpat>>foo;			//считываем год
												if (foo==bday.year) {	//сравниваем с заданым



													return
									}
								}
								if(bar.find(foo))	{				  //доп проверка по дате рождения, если не 0, значит нашли
										fPat.close();
										return idpp;
									}
								}
			  	}
				}
    }
    catch (char* err) {
        std::cout << err << '\n';
    }
		fPat.close();
		return IDD;
}


int MedPatient::AddNewData() {

				//ввод данных нового пациента

				std::cout<<"Введите ФИО (через пробел) : ";
				std::cin>>fio;
				std::cout<<"Введите день месяц и год рождения(через пробел) : " ;
				std::cin>>bday.day>>bday.month>>bday.year;
try {
				if (bday.day<1||bday.day>31||bday.month<1||bday.month>12||bday.year<1910||>2021) throw "Error_bday_input";
				std::cout<<"Введите номер сотового телефона : " ;
				std::cin>>tel;
				if (tel>89999999999)
				std::cout>>"Введите номер телефона родственника : " ;
				std::cin>>tel_res;
				std::cout<<"Введите номер медицинского полиса : ";
				std::cin>>polis;


	      std::fstream fPat;
        fPat.open(filePat);
        if (fPat.is_open()) throw "Error_OpenFile";
				std::string bar;
				int total_pat=0;
				fPat>>bar;						//считали текущее общее количество пациентов
				if(std::stoi(bar)>=MaxPatient) throw "sorrY_Clinic_Overflow"; //если больше равно макс, ошибка
				fPat>>bar;					// считали последний занятый ID пациента
				int tmp = stoi(bar);
				++tmp;							//сделали ID для нового пациента
				bar=bar.to_string(tmp);
				fPat.close();
				fPat.open(filePat,ios::app);	//добавляем нового пациента в конец файла
				fPat << bar <<" " <<

    }


    catch (const char* err) {
        cout << err << '\n';
        return 1;
    }
}
