#pragma once
#include <string>
#include <fstream>

const char* filePatient = "filePatient.txt"; //���� ��������� : IDpat, fio , bday, tel, tel_res, #_strahovki
const char* fileDoctor = "fileDoctor.txt"; //���� ������� : IDdoc, fio , bday, tel(� ���� ����������, tel_res(�������� �������), #_strahovki(����� �����:)
const char* fileHistory = "fileHistory.txt"; //�������� ���� : IDpat, status(0-dead,1-��������,2-�������),IDcham(����� ������) , IDdoc, data priema, data vipiski, string History � ��������� ����
const char* fileChamber = "fileChamber.txt"; //���� ������ (1 ������ - ����� ���������� ����� (����������� ��� ������ - �� 4 �����),
											 //����� ������� ������ �������� ���� �� ���������� ���������� ���� � �������� � � ������ ������� � 1, IDcham, list IDpat(������ ���������)

struct data {	//��� ��������� ��� ������ �� 30 ���� , ��� �� 2^32 , ��� ������ :D
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

