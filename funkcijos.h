
using std::endl;
using std::cout;
using namespace std::chrono;
int rrand(int a,int b)
{
    using Random=effolkronium::random_static;
    return Random::get(a,b);
}
double vid(const mokiniai &mok)//perduodu kaip struktura, nes nenaudoju vektoriaus savybiu
{
    return std::accumulate(mok.Nd.begin(), mok.Nd.end(), 0.0)/mok.Nd.size();
};
double galutinis(const mokiniai &mok)
{
    return 0.4*vid(mok)+0.6 * mok.egz;
}
bool compare(const mokiniai &a, const mokiniai &b)
{
    return(galutinis(a)<galutinis(b));
}
void rykiavimas(std::vector<mokiniai> &mok)
{
    std::sort(mok.begin(),mok.end(),(compare));
}
void rykiavimas2(std::deque<mokiniai> &mok)
{
    std::sort(mok.begin(),mok.end(),(compare));
}
std::string genVard()
{
    std::string vardas{rrand('A','Z')};//vardas arba pavarde prasideda didziaja raide
    do
    {
        vardas+=rrand('a','z');//likosios raides mazosios
    }
    while(rrand(0,4)!=0); //vardo ilgis bus atsitiktinis, 1/5 tikimybe, kad baigs cikla
    return vardas;
}
void genFile(const int n, const std::string pav)
{
    std::ofstream out(pav);//visi_10^i.txt, failo pav sako mokiniu skaiciu jame
    for(int j=0; j<n; j++)
    {
        out<<genVard()<<" "<<genVard()<<" ";//vardas, pavarde
        do
        {
            out<<rrand(1,10)<<" ";
        }
        while(rrand(0,3)!=0); //jei salyga neispildyta, tai baigs generuot Nd pazymius. Bus bent vienas Nd pazymys
        out<<"0 "<<rrand(1,10)<<endl;//0 indikuoja Nd paz pabaiga, po jo Egzamino paz.
    }
    out.close();
}
void genVec(const int n, const std::string pav, auto *mok)
{
    std::ifstream in(pav);
    int a;
    for(int i=0; i<n; i++)
    {
        mokiniai *rmok=new mokiniai;
        in>>rmok->vard>>rmok->pavard;
        in>>a;
        while(a!=0)//Nd ir egzamino pazymiai atskirti '0'
        {
            rmok->Nd.push_back(a);
            in>>a;
        }
        in>>rmok->egz;
        mok->push_back(*rmok);
    }
    in.close();
}
auto splitVec(const int n, const std::string pav, std::vector<mokiniai> &mok)
{
    int z=n/2, puse=z;
    double riba=4.99999999999;//10 val bandziau issiaiskint bet nepavyko
    bool islaike;//true jei islaike pirmas
    do //suzinau, ties kuriuo mok elementu, prasideda blogieji
    {
        puse=puse/2+puse%2;
        islaike=(galutinis(mok[z])>=riba);
        (islaike)? z-=puse: z+=puse;
    }while(puse!=1||!islaike);
    while(galutinis(mok[z])<riba)
        z++;
    std::vector<mokiniai> kietekai(n-z);
    std::move(mok.begin()+z,mok.end(),kietekai.begin());
    mok.erase(mok.begin()+z,mok.end());

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::ofstream out(pav+" vector_lievi.txt");
    for(int i=0; i<mok.size(); i++)
    {
        out<<mok[i].vard<<" "<<mok[i].pavard<<" "<<mok[i].Nd[0]<<" ";
        for(int j=0; j<mok[i].Nd.size(); j++)
            out<<mok[i].Nd[j]<<" ";
        out<<mok[i].egz<<endl;
    }
    out.close();

    std::ofstream out2(pav+" vector_kietekai.txt");
    for(int i=0; i<kietekai.size(); i++)
    {
        out2<<kietekai[i].vard<<" "<<kietekai[i].pavard<<" "<<kietekai[i].Nd[0]<<" ";
        for(int j=0; j<kietekai[i].Nd.size(); j++)
            out2<<kietekai[i].Nd[j]<<" ";
        out2<<kietekai[i].egz<<endl;
    }
    out2.close();
    mok.clear(),kietekai.clear();
    return t1;//grazino laiku uztrukta generuojant failus
}
auto splitList(const int n, const std::string pav, std::list<mokiniai> &mok)
{
    double riba=4.999999999999;//5.0 neveike... Visada buvo taip: double x>int 5 = x>double double 5.0
    std::list<mokiniai>::iterator it=mok.begin(),it2=it;

    advance(it,n/9*5);//5/9 tikimybe islaikyti, del to apie n*5/9 elementas skiria lievus ir kietekus
    //isrykiuota didejimo tvarka. galutinis(it)<galutinis(it++)

    while(galutinis(*it)>=riba)
    {
        it--;
    }
    while(galutinis(*it)<riba)
    {
        it++;
    }
    std::list<mokiniai> kietekai;
    kietekai.splice(kietekai.begin(),mok,it,mok.end());

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::ofstream out(pav+" list_lievi.txt");
    for(it=mok.begin(); it!=mok.end(); it++)
    {
        out<<it->vard<<" "<<it->pavard<<" "<<it->Nd[0]<<" ";
        for(int j=0; j<it->Nd.size(); j++)
            out<<it->Nd[j]<<" ";
        out<<it->egz<<endl;
    }
    out.close();

    std::ofstream out2(pav+" list_kietekai.txt");
    for(it=kietekai.begin(); it!=kietekai.end(); it++)
    {
        out2<<it->vard<<" "<<it->pavard<<" "<<it->Nd[0]<<" ";
        for(int j=0; j<it->Nd.size(); j++)
            out2<<it->Nd[j]<<" ";
        out2<<it->egz<<endl;
    }
    out2.close();
    return t1;
}
auto splitDeque(const int n, const std::string pav, std::deque<mokiniai> &mok)
{//naudosiu vector coda nes nespeju, o deque savybes pritaikyt nemoku
    int z=n/2, puse=z;
    double riba=4.9999999999999;
    bool islaike;//true jei islaike pirmas
    do //suzinau, ties kuriuo mok elementu, prasideda blogieji
    {
        puse=puse/2+puse%2;
        islaike=(galutinis(mok[z])>=riba);
        (islaike)? z-=puse: z+=puse;
    }while(puse!=1||!islaike);
    while(galutinis(mok[z])<riba)
        z++;
    std::deque<mokiniai> kietekai(n-z);
    std::move(mok.begin()+z,mok.end(),kietekai.begin());
    mok.erase(mok.begin()+z,mok.end());

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::ofstream out(pav+" deque_lievi.txt");
    for(int i=0; i<mok.size(); i++)
    {
        out<<mok[i].vard<<" "<<mok[i].pavard<<" "<<mok[i].Nd[0]<<" ";
        for(int j=0; j<mok[i].Nd.size(); j++)
            out<<mok[i].Nd[j]<<" ";
        out<<mok[i].egz<<endl;
    }
    out.close();

    std::ofstream out2(pav+" deque_kietekai.txt");
    for(int i=0; i<kietekai.size(); i++)
    {
        out2<<kietekai[i].vard<<" "<<kietekai[i].pavard<<" "<<kietekai[i].Nd[0]<<" ";
        for(int j=0; j<kietekai[i].Nd.size(); j++)
            out2<<kietekai[i].Nd[j]<<" ";
        out2<<kietekai[i].egz<<endl;
    }
    out2.close();
    mok.clear(),kietekai.clear();
    return t1;//grazino laiku uztrukta generuojant failus
}
void uzduotis(const int n, const std::string pav)
{
    auto t1=high_resolution_clock::now();

    std::vector<mokiniai> mok;
    genVec(n,pav+".txt",&mok);
    rykiavimas(mok);
    cout<<"   vector: "<<duration_cast<microseconds>
        (splitVec(n,pav,mok)-t1).count();


    t1=high_resolution_clock::now();

    std::list<mokiniai> mok2;
    genVec(n,pav+".txt",&mok2);//pavadinimas nera itin universalus...
    mok2.sort(compare);
    cout<<"   list: "<<duration_cast<microseconds>
        (splitList(n,pav,mok2)-t1).count();


    t1=high_resolution_clock::now();

    std::deque<mokiniai> mok3;
    genVec(n,pav+".txt",&mok3);//pavadinimas nera itin universalus...
    rykiavimas2(mok3);
    cout<<"  deque: "<<duration_cast<microseconds>
        (splitDeque(n,pav,mok3)-t1).count();
}

