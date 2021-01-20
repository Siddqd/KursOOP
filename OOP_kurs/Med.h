#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


const int MaxRooms = 25;
const int MaxPatient = 4*MaxRooms;
																							//файл пациентов (1 строка 1 число - текущее количество пациентов, 2 число - номер последнего пациента)
const char* filePatient = "filePatient.txt"; //: IDpat, fio , bday, tel(пациента), tel_res(родственников), #_strahovki
const char* fileDoctor = "fileDoctor.txt"; //файл врачей : IDdoc, fio , bday, tel(а этот внутр), tel_res(например сот), #_strahovki(пусть будет:)
const char* fileHistory = "fileHistory.txt"; //файл историй (основной) : IDpat, status(0-dead,1-на лечении,2-выписан),IDcham(номер палаты) , IDdoc, data priema, data vipiski, string History в текстовом виде
const char* fileChamber = "fileChamber.txt"; //файл палат (1 1 строка - общ кол-во палат (предположим все палаты по 4 места),
											 //перед записью нового пациента тест на оставшееся количество мест в больнице и в палате начиная с  1, IDcham, list IDpat(список ID_пациентов в палате)

struct data {	//для упрощения , 12 месяцев по 30 дней + - ~
	int day;
	int month;
	int year;
};

class Med	{
	protected:
		int total;
		int ID;
	public:
		virtual void AddNewData() = 0;
		virtual void DeleteData() = 0;
		virtual void RewriteData() = 0;
		virtual void ShowData() = 0;
		virtual void PrintData() = 0;
};
