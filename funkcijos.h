using std::endl;
using std::cout;
using std::string;
double vid(mokiniai *mok)//perduodu kaip struktura, nes nenaudoju vektoriaus savybiu
{
    return std::accumulate(mok->Nd.begin(), mok->Nd.end(), 0.0)/mok->Nd.size();
};
double med(mokiniai *mok)
{
    std::sort(mok->Nd.begin(),mok->Nd.end());
    const int z=mok->Nd.size();
    if(z%2==0)//jei lyginis pazymiu skaicius- bus skaiciuojami su dvieju vidurkii
    {
        return float(mok->Nd[z/2-1]+mok->Nd[z/2])/2.;//viduriniu vidurkis
    }
    return mok->Nd[(z-1)/2];//vidurinio reiksme
}
double galutinis(mokiniai *mok, bool Vidur)
{
    double z;
    if(Vidur)
        z=vid(mok);//jei galutinis priklauso nuo vidurkio,
    else
        z=med(mok);
    return 0.4*z+0.6*mok->egz;
}
int fcin(int a,int b)
{//isfiltruoja intervalo neatinkancius sveikuosius cin'us pazymiams.
    int z;
    do{
    std::cin>>z;
    }while(z<a||z>b);//vercia vesti reiksmes kol ives viena is intervalo
    return z;
}
void ivestmok(std::vector<mokiniai> &mok, int &n)
{
    cout<<"Iveskite "<<n+1<<"'ojo mokinio varda ir pavarde"<<endl;
    mok.resize(n+1);
    std::cin>>mok[n].vard>>mok[n].pavard;

    int (*rfun)(int,int),//nuo jo priklauso, bus naudotojo ar tikimybes imputas
    z,
    a=1,b=10;//pazymiu intervalo krastai
    cout<<"Jei norit patys ivesti pazymius- iveskit 0. Ivedus kita skaiciu pazymiu skaicius ir reiksmes bus atsitiktines"<<endl;
    bool Rand;//default reiksme yra false
    std::cin>>z;
    if(z!=0)
        Rand=true;
    if(Rand)//jei random, tai...
    {
        rfun=rrand;
        cout<<"Sugeneruotos reiksmes: ";
    }
    else//jei ne, tai vartotojas ives naudodamas fcin funkcija
    {
        rfun=fcin;
        cout<<"Iveskite Nd pazymius. Ivedus "<<a-1<<" baigsis ivestis: ";
    }
    z=rfun(a,b);
    cout<<z;
    mok[n].Nd.push_back(z);
    while(true)
    {

        z=rfun(a-2,b);//nuo -1 iki 10
        if(z<=0)//jei -1 arba 0, tai baigsis generacija
            break;
        mok[n].Nd.push_back(z);
        if(Rand)cout<<z<<" ";
    }
    (Rand)?
        cout<<"Egzamino pazymys: ":
        cout<<"Iveskite egzamino pazymi: ";
    z=rfun(a,b);
    cout<<z;
    mok[n].egz=z;
    n++;
    cout<<endl;
}
void komandos()
{
    cout<<"Pradeti naujo mokinio info ivedima- 1"<<endl;
    cout<<"Rodyti visu mokiniu vidurkius- 2"<<endl;
    cout<<"Rodyti visu mokiniu medianas- 3"<<endl;
    cout<<"Skaityti mokiniu info is failo- 4"<<endl;
    cout<<"Rodyti mokiniu info- 5"<<endl;
    cout<<"Atlikti 0.5 uzduoti su vector- 6"<<endl;
    cout<<"Baigti darba- 9"<<endl;
    cout<<"Rodyti komandas- 0"<<endl;
}
void skaitMok(std::vector<mokiniai> &mok, int &n)
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
        in>>mok[n].vard>>mok[n].pavard;
        mok[n].Nd.resize(m);
        for(int i=0;i<mok[n].Nd.size();i++)in>>mok[n].Nd[i];
        in>>mok[n].egz;
        n++;
    }
    in.close();
}
bool compare(const mokiniai &a,const mokiniai &b)
{
    if(a.vard==b.vard)return(a.pavard<b.pavard);
    else return (a.vard<b.vard);
}
void rykiavimas(std::vector<mokiniai> &mok)
{
    std::sort(mok.begin(),mok.end(),(compare));
}
void isved(std::vector<mokiniai> &mok, int &n, bool Vidur)
{
    rykiavimas(mok);
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
        cout<<" "<<std::setprecision(3)<<galutinis(&mok[i],Vidur)<<endl;
    }
}
void rodyt(const std::vector<mokiniai> &mok, int n)
{
    if(n!=0)cout<<"Visu mokiniu vardai, pavardes, Nd ir egzaminio pazymiai"<<endl;
    else cout<<"Nera ivesta ar nuskaityta mokiniu"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<mok[i].vard<<" "<<mok[i].pavard<<" ND: ";
        for(int j=0; j<mok[i].Nd.size(); j++)cout<<mok[i].Nd[j]<<" ";
        cout<<"Egz: "<<mok[i].egz<<endl;
    }
}
