#include "People.h"
try {
    ofstream MF1;
    //MF1.open("test_text.txt");
    if (!MF1.is_open()) throw "ErrorE";
    MF1 << "Test store #1 ";
    MF1 << "Test store #1+\n";
    MF1 << "Test store #2 \n";
    MF1.close();
}


catch (const char* err) {
    cout << err << '\n';
    return 1;
}




string line;
ifstream MF2("test_text.txt");
while (getline(MF2, line)) {
    cout << line << '\n';
}
MF2.close();