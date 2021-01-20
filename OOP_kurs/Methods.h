#pragma once

void rabbit() {
    system("cls");
    string os2 = "",os1 = "";
    for(int i=1;i<500;i++){
        if(!(i%50)) {
            os1 =" ";
            os2 = os2 + "\n\n\n";
        }
        std::cout<<os2;
        std::cout<<os1<<"(V)\n";
        std::cout<<os1<<"(..)\n";
        std::cout<<os1<<"(\")(\")\n";
        os1 = os1 + "  ";
        system("cls");
    }
}
void mainMenu() {
  std::cout<<" Main menU  "<<'\n';
  std::cout<<" Select menu item (enter its num) : ";

  std::cout<<" 1) Searching patient/med.card by fio and bday >> ";

  std::cout<<" 2) View list of free Med_rooms(chambers) >> ";
                                                    //сначала добавляем пациента, потом мед карту
  std::cout<<" 3) Add new med.card/patient >> ";    //если уже существует, изменяем данные(номер палаты, лечящего врача
                                                    //, дописываем историю болезни)
  std::cout<<" 4) Discharge the patient >> ";       //выписка пациента - освобождение палаты, смена статуса

  std::cout<<" 5) Change doc info >> ";

  std::cout<<" 6) Follow for the white rabbit ... ";
};

void select() {
  cout<<"Enter the num of menu_item >>> "
  char tmp;
  std::cin>>tmp;
  switch(tmp) {
  case '1' :
    MedPatient.look4();
    break;
  case '2' :

    break;
  case '3' :

    break;
  case '4' :

    break;
  case '5' :

    break;
  case '6' :
    rabbit();
    break;
    return;
  default:
    std::cout<<"Oops! Press num baby one more time >> from 1 to 6 >> ";
    system("cls");
    mainMenu();
    select();

}
