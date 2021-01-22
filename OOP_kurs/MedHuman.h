#pragma once
#include "Med.h";


class MedHuman : public Med
{
protected:
	std::string fio;
	data bday;
	int64_t tel;
	int64_t res_tel;
	int64_t polis;

public:
	std::string getFio();
	void setFio(std::string fioo);
	data getData();
	void setData(data bdayy);
	int64_t getTel();
	void setTel(int64_t tell);
	int64_t getRes_tel();
	void setRes_tel(int64_t res_tell);
	int64_t getPolis();
	void setPolis(int64_t poliss);

};
