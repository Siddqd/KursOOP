#pragma once
#include "Med.h";


class MedHuman : public Med
{
protected:
	std::string fio;
	data bday;
	char tel[10];
	char res_tel[10];
	char polis[12];

public:
	std::string getFio();
	void setFio(std::string fioo);
	data getData();
	void setData(data bdayy);
	char* getTel();
	void setTel(char* tell);
	char* getRes_tel();
	void setRes_tel(char* res_tell);
	char* getPolis();
	void setPolis(char* poliss);

};
