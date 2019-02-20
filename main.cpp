#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Jusu vardas ir pavarde?" << endl;
    string vardas, pavarde;
    cin>>vardas>>pavarde;
    int n;
    cout << "Kiek namu darbu turejote?" << endl;
    cin>>n;
    int nd[n],
    galutinis,//egzamino balas
    S=0;//suma ND pazymiu
    cout << "Visu namu darbu gauti pazymiai?" << endl;
    for(int i=0;i<n;i++){cin>>nd[i]; S+=nd[i];}
    cout << "Koks egzamino pazymys?: " << endl;
    cin>>galutinis;
    double ats=S/n*0.4+galutinis*0.6;
    cout << "Jusu semestro pazymys yra: " << ats;
    return 0;
}
