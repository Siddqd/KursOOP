#include "MedPatient.h"


MedPatient::MedPatient() {
	this->id = 0;			//конструктор пациента пустой
	this->fio = "";
	this->bday.day = 0;
	this->bday.month = 0;
	this->bday.year = 0;
	this->tel = 0;
	this->res_tel = 0;
	this->polis = 0;
	this->status = -1;
	this->room_id = 0;
	this->doc_id = 0;
}

MedPatient::MedPatient(int idpp) {
	this->id = idpp;			//конструктор пациента ID
	this->fio = "";
	this->bday.day = 0;
	this->bday.month = 0;
	this->bday.year = 0;
	this->tel = 0;
	this->res_tel = 0;
	this->polis = 0;
	this->status = -1;
	this->room_id = 0;
	this->doc_id = 0;
}

MedPatient::MedPatient(std::string fioo,Data bdayy) {
	this->id = 0;			//конструктор пациента фио и ДР
	this->fio = fioo;
	this->bday = bdayy;
	this->tel = 0;
	this->res_tel = 0;
	this->polis = 0;
	this->status = -1;
	this->room_id = 0;
	this->doc_id = 0;
}

MedPatient::MedPatient(int idpp, std::string fioo, Data bdayy,
				int tell, int res_tell, int64_t poliss, int status, int room_id, int doc_id) {

		this->id = idpp;			//конструктор пациента полный
		this->fio = fioo;
		this->bday = bdayy;
		this->tel = tell;
		this->res_tel = res_tell;
		this->polis = poliss;
		this->status = 1;
		this->room_id = 0;
		this->doc_id = 0;
}

/*MedPatient::MedPatient(int idpp, std::string fioo, data bdayy, int tell, int res_tell, int64_t poliss) {
	try {
	this->idp = idpp;			//конструктор пациента
	this->fio = fioo;
	this->bday = bdayy;
	this->tel = tell;
	this->res_tel = res_tell;
	this->polis = poliss;

	}
}*/

int MedPatient::look4(const char* filePat) { //fio2 поиск по фио и ДР, предварительно создаем объект пациент
    int idpp = -1;							// , куда записываем фио и полис
	int foo32;							   //итоговый результат запись всех найденных данных в объект
	int64_t foo64;			 			  //и сравниваем со значениями в файле пациентов
	Data bdres;
	std::string bar;
	std::string foo;

	std::fstream fPat;
	fPat.open(filePat);

    try {									        					
		if (fPat.is_open()) throw "Error_OpenFile";
		if (fPat.eof()) throw "Error_filePatient_is_EMPTY";
	}	catch (const char* err) { std::cout << err; }//{std::cout<< err; fPat.close(); return -1;}

        
		fPat>>bar;                    // считываем первую строку - общее кол-во пациентов
		fPat>>bar;					 // 2ю строку - номер крайнего пациента
									//просто для пролистывания,хотя можно и вывести
		while (!fPat.eof()) {
			fPat>>bar;							//считываем сигнатуру IDP
			if (bar != "IDP") return -1;		//проверяем сигнатуру IDP //варик ? for(;bar!="IDP";	fPat>>bar)
			fPat >> idpp;						//считали ID текущего пациента
			if (id!=idpp){						//нужный пациент(выполнен поиск по ID) - пропускаем поиск по фио
					fPat>>bar;					//считываем по идее FIO
					if (bar != "FIO") return -1;;
					std::getline(fPat,bar);		//считали фамилию , но с пробелом в начале
					if(" "+fio!=bar) continue; 		//если == , значит фамилия найдена,если != цикл начинаем сначала

					fPat >> bar;											//считываем сигнатуру ДР
					if (bar != "BDAY") return -1;						   //если да, если нет ошибка :[]
					fPat >> bdres.day >> bdres.month >> bdres.year;		  //считываем ДР

					if (bdres.day!=0)	//сравниваем ДР с заданым, если нет идем к след фамилии
						if (bdres.day!=bday.day || bdres.month!=bday.month || bdres.year!=bday.year) continue;
					//если др не задано = 0, то пропускаем сравнение и выводим всех с такой ФИО
										
					//сразу поадаем сюда если bday.day==0 , то есть не задана ДР/ ищет первое совпадение по фио
					//перезаписываем оставшиеся поля класса
			} else {//сюда попадаем если удачно прошел поиск по ID
						fPat >> bar; 
						if (bar == "FIO") { bar = fPat.get(); std::getline(fPat, fio);}
							 	else throw "Oops ... shit happens :|";
						fPat >> bar; 
						if (bar=="BDAY") {fPat>>bday.day; fPat>>bday.month; fPat>>bday.year;}
							 	else throw "Oops ... shit happens :|";
			}		//сюда уходим после совпадения по фио и дате ДР
			id=idpp;
			try {
				fPat >> bar; if (bar=="TEL") fPat>>tel; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "RES_TEL") fPat >> res_tel; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "POLIS") fPat >> polis; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "STATUS") fPat >> status; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "ROOM_ID") fPat >> room_id; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "DOC_ID") fPat >> status; else throw "Oops ... shit happens :|";
				//fPat >> foo32; if (foo=="STATUS") fPat>>status; else throw "Oops ... shit happens :|"
				//возможно вывод данных убрать ? оставить только возврат ID
			} catch (const char* er) { std::cout << er;fPat.close();return -1; }
			
			std::cout<<"		   			  Patient  ID : "<<id<<'\n';
			std::cout<<"						Full name : "<<fio<<'\n';
			std::cout<<"				    Birthday date : "<<bday.day<<' '<<bday.month<<' '<<bday.year<<'\n';
			if (bday.day==0) continue;
			std::cout<<"		     Patient phone number : "<<tel<<'\n';
			std::cout<<"        Phone number of relatives : "<<res_tel<<'\n';
			std::cout<<"						Polis num : "<<polis<<'\n';
			if (status==0) std::cout<<"Sry, patient is game over ..";
			if (status==2) std::cout<<"Patient was discharged out ..";
			if (status==1) std::cout<<"Patient now in chamber num : " <<room_id<<'\n';
			if (bday.day == 0) continue;
				

			fPat.close();
			return id; //возвращаем # id пациента - соответсвует номеру мед карты
		}
			
							fPat.close();
							std::cout << "You push key .. 4 or push key ... patient with entered data is not detected";
							return -1;
	
		
    fPat.close();
	return -1;
}


																										//плюс альтернативный поис по ID
int MedPatient::ShowDataScr(const char* filePat) { //fio2 поиск по фио и ДР, предварительно создаем объект пациент
	int idpp = -1;										// , куда записываем фио и полис
	int foo32;												//итоговый результат запись всех найденных данных в объект
	int64_t foo64;
	Data bdres;
	std::string bar;
	std::string foo;

	std::fstream fPat;
	fPat.open(filePat);

	try {									        					//и сравниваем со значениями в файле пациентов
			
			if (fPat.is_open()) throw "Error_OpenFile";
			if (fPat.eof()) throw "Error_filePatient_is_EMPTY";
	}	catch(const char* er) {std::cout<< er; fPat.close(); return -1;}

	fPat>>bar;                    // считываем первую строку - общее кол-во пациентов
	fPat>>bar;										// 2ю строку - номер крайнего пациента
																		//просто для пролистывания,хотя можно и вывести
	while (!fPat.eof()) {
		fPat>>bar;										//считываем сигнатуру IDP
		if (bar != "IDP") continue;		//проверяем сигнатуру IDP, если нет то сначала //варик ? for(;bar!="IDP";	fPat>>bar)
		fPat>>idpp;										//считали ID текущего пациента
		if (id!=idpp){ //нужный пациент(выполнен поиск по ID) - пропускаем поиск по фио
				fPat>>bar;						//считываем по идее FIO
				if(bar!="FIO") continue;
				std::getline(fPat, bar);							//считали фамилию , но с пробелом в начале
				if(" "+fio!=bar) continue; 		//если == , значит фамилия найдена
				fPat >> bar;										//считываем сигнатуру ДР
				if (bar!="BDAY") return -1;		//если да, если нет ошибка :[]
				fPat >> bdres.day >> bdres.month >> bdres.year;			//считываем ДР

				if (bdres.day!=0)
				if (bdres.day!=bday.day || bdres.month!=bday.month || bdres.year!=bday.year) continue;
					//если др не задано = 0, то пропускаем сравнение и выводим всех с такой ФИО
					//сравниваем ДР с заданым, если нет идем к след фамилии
					//если ок полное совпадение фио и др
					//сразу поадаем сюда если bday.day==0 , то есть не задана ДР/ ищет первое совпадение по фио
					//можно сделать вывод текущих данных с запросом дальнейшего поиска совпадений по фио
					//перезаписываем оставшиеся поля класса
		} else {//сюда попадаем если
						fPat >> bar; if (bar=="TEL") fPat>>tel; else throw "Oops ... shit happens :|";
						fPat >> bar; if (bar=="TEL") fPat>>tel; else throw "Oops ... shit happens :|";
			}
			id=idpp;
			try {
				fPat >> bar; if (bar=="TEL") fPat>>tel; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "RES_TEL") fPat >> res_tel; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "POLIS") fPat >> polis; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "STATUS") fPat >> status; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "ROOM_ID") fPat >> room_id; else throw "Oops ... shit happens :|";
				fPat >> bar; if (bar == "DOC_ID") fPat >> status; else throw "Oops ... shit happens :|";
				//fPat >> foo32; if (foo=="STATUS") fPat>>status; else throw "Oops ... shit happens :|"

			} catch (const char* er) { std::cout << er;fPat.close();return -1; }
			
			if (bday.day==0) std::cout<<"							Patient  ID : "<<id<<'\n';
			std::cout<<"					 			Full name : "<<fio<<'\n';
			std::cout<<"				    Birthday date : " << bday.day << ' ' << bday.month << ' ' << bday.year << '\n';
			if (bday.day==0) continue;
			std::cout<<"		 Patient phone number : "<<tel<<'\n';
			std::cout<<"Phone number of relatives : "<<res_tel<<'\n';
			std::cout<<"								Polis num : "<<polis<<'\n';
			if (status==0) std::cout<<"Sry, patient is game over ..";
			if (status==2) std::cout<<"Patient was discharged out ..";
			if (status==1) std::cout<<"Patient now in chamber num : " <<room_id<<'\n';
			
			fPat.close();
			return id; //возвращаем # id пациента - соответсвует номеру мед карты
	}
			
	fPat.close();
	std::cout << "You push key .. 4 or push key ... \n patient with entered data is not detected";
	return -1; //если поиск прошел не удачно
}

int MedPatient::AddNewData(const char* filePat) {
	std::string bar;
	int idpp = 0, sum_pat = 0;
	
	std::fstream fPat;	
	fPat.open(filePat, std::ios::in | std::ios::out);
	
	try {
		if (fPat.is_open()) throw "Error_OpenFile";	//проверка открытия файла
		
		fPat >> sum_pat;						//считали текущее общее количество пациентов
		if (sum_pat >= MaxPatient) throw "sorrY_Clinic_Overflow"; //если больше равно макс - клиника переполнена
		++sum_pat;   //если не выкинуло, то места есть, прибавляем +1
		fPat >> idpp;					// считали последний занятый ID пациента
		++idpp;			//записываем ID для нового пациента

		fPat.seekg(0, std::ios::beg);//встаем в начало файла
		fPat << sum_pat << idpp;	//пишем новое значения общего числа пациентов и номер нового крайнего
		fPat.close();
	}
	catch (char* er) { std::cout << er;return -1; }
		
	//ввод данных нового пациента
	std::cout<<"Введите ФИО (через пробел) : ";
	std::cin>>fio;
	std::cout<<"Введите день, месяц и год рождения(через пробел) : " ;
	std::cin>>bday.day>>bday.month>>bday.year;
	try {
				if (bday.day<1||bday.day>31||bday.month<1||bday.month>12||bday.year<1910|| bday.year>2021) throw "Error_bday_input";
	} catch (const char* err) {	std::cout << err << '\n';	return -1;	}	
				
	while (tel>89999999999) {
		std::cout<<"Введите номер сотового телефона : " ;
		std::cin>>tel;
	}
	std::cout<<"Введите номер телефона родственника : " ;
	std::cin>>res_tel;
	std::cout<<"Введите номер медицинского полиса : ";
	std::cin>>polis;
	status=1;std::cout<<"Статус нового больного установлен : 1 - В больнице \n";
	std::cout<<"Введите номер палаты : "; //можно выводить список ближайших свободных палат
	std::cin>>room_id;
	std::cout<<"Введите id врача : ";		//можно выводить список врачей
	std::cin>>doc_id;

	
				fPat.open(filePat,std::ios::app|std::ios::in);	//добавляем нового пациента в конец файла
				fPat <<"\nIDP " << id << "\nFIO "<< fio<< "\nBDAY " <<bday.day<<bday.month<<bday.year<<
						 "\nTEL "<<tel<<"\nRES_TEL "<<res_tel<<"\nPOLIS "<<polis<<"'\nSTATUS "<<status<<
						 "\nROOM_ID " <<room_id<<"\nDOC_ID"<<doc_id;
				fPat.close();
				return 0;


}
