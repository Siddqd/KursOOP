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

  std::cout<<" 1) View info patient using fio & bday >> \n";

  std::cout<<" 2) View info med.card using Med_Card_ID \n>> ";

  std::cout<<" 3) View list of free Med_rooms(chambers) \n>> ";
                                                    //сначала добавляем пациента, потом мед карту
  std::cout<<" 4) Add new med.card/patient \n>> ";    //если уже существует, изменяем данные(номер палаты, лечящего врача
                                                    //, дописываем историю болезни)
  std::cout<<" 5) Change the patient info(status or add new recs) \n>> ";       //выписка пациента - освобождение палаты, смена статуса

  std::cout<<" 6) Change Doc info >> \n";

  std::cout<<" 0) Follow for the white rabbit ... \n";
};

void selectItem() {
  cout<<"Enter the num of menu_item >>> "
  char tmp;
  while (tmp!='0'){
    std::cin>>tmp;
    switch(tmp) {
      case '1' :
        system("cls");
        MedPatient medP;
        medP.ShowDataScr(filePatient);
        break;

      case '2' :
        system("cls");
        break;

      case '3' :

        break;

      case '4' :

        break;

      case '5' :

        break;

      case '5' :

        break;

      case '0' :
        rabbit();
        break;
        return;
      default:
        std::cout<<"Oops! Press num baby one more time >> from 1 to 6 or 0 >> ";
        system("cls");
        mainMenu();
        select();
  }
  return;
}
