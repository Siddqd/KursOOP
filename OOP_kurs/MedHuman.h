#pragma once
#include "Med.h";


class MedHuman : public Med
{
protected:
	std::string fio;
	data bday;
	int tel;
	int res_tel;
	int64_t polis;

public:
	std::string getFio();
	void setFio(std::string fioo);
	data getData();
	void setData(data bdayy);
	int getTel();
	void setTel(int tell);
	int getRes_tel();
	void setRes_tel(int res_tell);
	int64_t getPolis();
	void setPolis(int64_t poliss);

};
