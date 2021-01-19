#pragma once
#include "Med.h"
class MedRec : public Med
{
private:
	char* IDP;
	char* IDD;
	data data_in;
	data data_out;
	char stat;
	std::string recs;

};
