#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::string;
using std::cin;
struct mokiniai
{
    string vard,pavard;
    std::vector<int> Nd;
    int m,//kiek namu darbu
        egz;
};
std::vector<mokiniai> mok;
int n=0;//kelintas mokinys, n+1=kiek mokiniu
void komandos();
void ivestmok();
double vid(int i);
double med(int i);
double galutinis(int i, bool Vidur);//kai vidur=true, skaiciuoja galutini naudojant vidurki
void isved(bool Vidur=true);//kai false, tada su mediena
int fcin(bool Pirmas);//vartotojas iveda mokiniu pazymius
int frand(bool Pirmas);//Nd skaicius, pazymiai ir egz rezultatas sugeneruojamas
void skaitMok();
void rodyt();
void rykiavimas();
bool compare(const mokiniai &a,const mokiniai &b);
int main()
{
    komandos();//isvedamos komandu reiksmes i ekrana
    int z;//komandos intas naudojant meniu
    while(true)//norejau loop, bet nenorejau inversijos
    {
        cout<<endl<<"iveskite komanda: ";
        cin>>z;
        cout<<endl;
        switch(z)
        {
        case 0:
        {
            komandos();
            break;
        }
        case 1:
        {
            ivestmok();
            break;
        }
        case 2:
        {
            isved();    //default reiksme yra true, todel vidurkis
            break;
        }
        case 3:
        {
            isved(false);    //jei false, tai bus mediana
            break;
        }
        case 4:
        {
            skaitMok();//skaito is failo
            break;
        }
        case 5:
        {
            rodyt();//rodo visu mokiniu info
            break;
        }
        default : break;
        }
    }
    return 0;
}
int fcin(bool Pirmas)//jei pirmas Nd arba egzamino pazymys, tai Pirmas=true.
{
    //Tada ivedus/ sugeneravus maziau nei 1, funkcija reikalaus, kad vel ivestumet/ generuos nauja
    int z;
    do
    {
        cin>>z;//ivedamas namu darbo arba egzamino pazymys
    }
    while(Pirmas&&z<=0);//apsauga, kad neuzbaigtu Nd ivedimo ciklo neivedus ne vieno namu darbo
    return z;
}
int frand(bool Pirmas)
{
    //generuoja skaicius nuo -1 iki 10, isridenus -1 ar 0 baigiasi ciklas
    int z;
    do
    {
        //nuo -1 iki 12.
        z=rand()%12-1;//Kai nera pirmas namu darbas, reiksmes bus generuojamos kol sugeneruos -1 arba 0. 2/12 tikimybe, kad baigsis ciklas
    }
    while(Pirmas&&z<=0);//neuzbaigs Nd generavimo ciklo usridenus 0 arba -1, kuomet dar nera kitu namu darbu pazymiu
    if(z>0)
        cout<<z<<" ";//taip pat grazins tinkama reiksme egzaminui, nes negalima gaut 0 arba -1
    return z;
}
void ivestmok()
{
    cout<<"Iveskite "<<n+1<<"'ojo mokinio varda ir pavarde"<<endl;
    mok.resize(n+1);
    cin>>mok[n].vard>>mok[n].pavard;

    int (*rfun)(bool),z;//nuo jo priklauso, bus naudotojo ar tikimybes imputas
    bool Rand=true;
    cout<<"Jei norit patys ivesti pazymius- iveskit 0. Ivedus kita skaiciu pazymiu skaicius ir reiksmes bus atsitiktines"<<endl;
    cin>>z;
    if(z==0)
        Rand=false;
    if(Rand)//jei random, tai...
    {
        rfun=frand;
        cout<<"Sugeneruotos reiksmes: ";
    }
    else//jei ne, tai vartotojas ives naudodamas fcin funkcija
    {
        rfun=fcin;
        cout<<"Iveskite Nd pazymius. Ivedus maziau nei 1 baigsis ivestis: ";
    }
    while(true)
    {
        if(mok[n].m==0)
            z=rfun(true);
        else
            z=rfun(false);
        if(z<=0)
            break;
        mok[n].Nd.push_back(z);
        mok[n].m++;
    }
    if(Rand)
    {
        cout<<endl<<"Egzamino pazymys: ";
        z=frand(true);
    }
    else
    {
        cout<<endl<<"Iveskite egzamino pazymi: ";
        z=fcin(true);
    }
    mok[n].egz=z;
    n++;
}
void skaitMok()
{
    std::ifstream in("kursiokai.txt");
    string z;
    bool bol=true;
    int m=-3;
    while(bol)
    {//cin pav,m=-2; cin var,m=-1, cin ND1,m=0... cin ND5;m=4, cin Egz;m=5
        in>>z;
        m++;
        if(z[0]=='E')bol=false;//jei egzaminas
    }
    while(!in.eof())
    {
        mok.resize(n+1);
        in>>mok[n].vard>>mok[n].pavard;//cout<<mok[n].vard<<" ";
        mok[n].m=m;
        mok[n].Nd.resize(m);
        for(int i=0;i<m;i++){in>>mok[n].Nd[i];}
        in>>mok[n].egz;
     //   cout<<n<<" ";
        n++;
    }
    in.close();
}
void komandos()
{
    cout<<"Pradeti naujo mokinio info ivedima- 1"<<endl;
    cout<<"Rodyti visu mokiniu vidurkius- 2"<<endl;
    cout<<"Rodyti visu mokiniu medianas- 3"<<endl;
    cout<<"Skaityti mokiniu info is failo- 4"<<endl;
    cout<<"Rodyti mokiniu info- 5"<<endl;
    cout<<"Rodyti komandas- 0"<<endl;
}
double vid(int i)
{
    int z=0;
    for(int j=0; j<mok[i].m; j++)
        z+=mok[i].Nd[j];
    //    cout<<z/mok[i].m<<endl;
    return z/mok[i].m;
}
double med(int i)
{
    std::sort(mok[i].Nd.begin(),mok[i].Nd.end());
    if(mok[i].m%2==0)//jei lyginis pazymiu skaicius, tai jie skaiciuojami paimant ju vidurki
    {
        return float(mok[i].Nd[mok[i].m/2-1]+mok[i].Nd[mok[i].m/2])/2.;//randa viduriniu vidurki
    }
    return mok[i].Nd[(mok[i].m-1)/2];//randa vidurini
}
double galutinis(int i, bool Vidur)
{
    int z;
    if(Vidur)
        z=vid(i);//jei galutinis priklauso nuo vidurkio,
    else
        z=med(i);
    return 0.4*z+0.6*mok[i].egz;
}
void isved(bool Vidur)
{
    rykiavimas();
    srand(time(NULL));//norejau ji det i frand, bet tada visi pazymiai vienodi. Jei ivestmok- visi mokiniai vienodi
    string S[3]= {"Pavarde","Vardas","Galutinis"};
    if(Vidur)//jei skaiciuos naudojant vidurki...
        S[2]+="(Vid.)";
    else
        S[2]+="(Med.)";
    int varilg=S[0].length(),pavilg=S[1].length();
    for(int i=0; i<n; i++)
    {
        if(mok[i].vard.length()>varilg)
            varilg=mok[i].vard.length();
        if(mok[i].pavard.length()>pavilg)
            pavilg=mok[i].pavard.length();
    }
    const string tarpas(varilg-S[0].length(),' '),tarpas2(pavilg-S[1].length(),' ');
    S[0]+=tarpas+' ';
    S[1]+=tarpas2+' ';
    const string SS=S[0]+S[1]+S[2];
    cout<<endl<<SS<<endl;
    for(int i=0; i<SS.length()+5; i++)
        cout<<'-';
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<mok[i].vard<<std::setw(S[0].length()-mok[i].vard.length()+mok[i].pavard.length());
        cout<<mok[i].pavard<<std::setw(S[1].length()-mok[i].pavard.length());
        cout<<" "<<std::setprecision(3)<<galutinis(i,Vidur)<<endl;
        //cia visur viena eilute
    }
}
//kambariokas padejo debuginant.
void rodyt()
{
    if(n!=0)cout<<"Visu mokiniu vardai, pavardes, Nd ir egzaminio pazymiai"<<endl;
    else cout<<"Nera ivesta ar nuskaityta mokiniu"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<mok[i].vard<<" "<<mok[i].pavard<<" ND: ";
        for(int j=0; j<mok[i].m; j++)cout<<mok[i].Nd[j]<<" ";
        cout<<"Egz: "<<mok[i].egz<<endl;
    }
}
bool compare(const mokiniai &a,const mokiniai &b)
{
  //  if(a==b)
  if(a.vard==b.vard)return(a.pavard<b.pavard);
    return (a.vard<b.vard);
}
void rykiavimas()
{
    std::sort(mok.begin(),mok.end(),(compare));
}
