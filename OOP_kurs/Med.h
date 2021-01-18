#pragma once
#include <string>
#include <fstream>

const char* filePatient = "filePatient.txt"; //файл пациентов : IDpat, fio , bday, tel, tel_res, #_strahovki
const char* fileDoctor = "fileDoctor.txt"; //файл доктора : IDdoc, fio , bday, tel(а этот внутренний, tel_res(например сотовый), #_strahovki(пусть будет:)
const char* fileHistory = "fileHistory.txt"; //основной файл : IDpat, status(0-dead,1-лечиться,2-выписан),IDcham(номер палаты) , IDdoc, data priema, data vipiski, string History в текстовом виде
const char* fileChamber = "fileChamber.txt"; //файл палаты (1 строка - общее количество палат (предположим все палаты - по 4 места),
											 //перед записью нового пациента тест на оставшееся количество мест в больнице и в палате начиная с 1, IDcham, list IDpat(список пациентов)

struct data {	//для упрощения все месяцы по 30 дней , или по 2^32 , как пойдет :D
	int Day;
	int Month;
	int Year;
};
class Med	{
	protected:
		int total;
		int ID;
		virtual void AddNewData() = 0;
		virtual void DeleteData() = 0;
		virtual void RewriteData() = 0;
		virtual void ShowData() = 0;
		virtual void PrintData() = 0;
};

