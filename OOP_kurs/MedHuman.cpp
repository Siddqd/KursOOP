#include "MedHuman.h"

std::string MedHuman::getFio() {
    return fio;
}
void string MedHuman::setFio(std::string fio2) {
    fio=fio2;
}

data MedHuman::getBday() {
  return  bday;
}

void MedHuman::setBday(data bdayy) {
  bday=bdayy;
}

int MedHuman::getTel() {
  return tel;
}
void MedHuman::setTel(int tell) {
  tel=tell;
}

int MedHuman::getRes_tel() {
  return res_tel;
}
void MedHuman::setRes_tel(int res_tell) {
  res_tel=res_tell;
}

int64_t MedHuman::getPolis() {
  return polis;
}
void MedHuman::setPolis(int64_t poliss) {
  polis=poliss;
}
