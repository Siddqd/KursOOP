#pragma once
#include "Med.h"
class MedRec : public Med
{
private:

	int patient_ID;
	Data data_in;
	Data data_out;
	Data data_story;
	std::string story;

};
