#pragma once
#include "Med.h"
class MedRec : public virtual Med
{
private:
	int idc;
	data data_in;
	data data_out;
	int stat;
	std::string recs;

};
