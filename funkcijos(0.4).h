std::string genVard()
{
    std::string vardas{rrand('A','Z')};//vardas arba pavarde prasideda didziaja raide
    do{
    vardas+=rrand('a','z');//likosios raides mazosios
    }while(rrand(0,4)!=0);//vardo ilgis bus atsitiktinis, 1/5 tikimybe, kad baigs cikla
    return vardas;
}
void genFile(std::vector<mokiniai> &mok, int i,std::string pav)
{
    string z(i+1,'0');//nuliai reikalingi failu pavadinimams
    std::ofstream out("studentai"+pav+".1"+z+".txt");
    //studentai+Visi/Ger/Blo+.1+0/00/.../00000+.txt
    //pvz: studentaiVisi.10.txt
    for(int j=0; j<mok.size(); j++)
    {
        out<<mok[j].vard<<" "<<mok[j].pavard<<" ";//vard, pavard
        for(int l=0; l<mok[j].Nd.size(); l++)//Nd pazymiai
            out<<mok[j].Nd[l]<<" ";
        out<<mok[j].egz<<std::endl;//egzamino pazymys
    }
    out.close();
}
void genMok(mokiniai *m)
{
    m->vard=genVard();//duoda varda
    m->pavard=genVard();//duoda pavarde

        m->Nd.push_back(rrand(1,10));//bent 1 Nd ivertinimas
        int z;
        while(true)
        {
            z=rrand(-1,10);
            if(z<=0)//2/12 tikimybe, kad baigs generuot Nd
                break;
            m->Nd.push_back(z);
        }
    m->egz=rrand(1,10);
}
void uzduotis()//sito failo funkcijos naudoja nauja mok reiksme
{
    using namespace std::chrono;
    const int fileNum=5;//jei =1, bus 10 mok, jei 6, tai 6 failai, paskutinis su 1 mil mok
    for(int i=0; i<fileNum; i++)//i=0 -> mok[10], i=1 -> mok[100]...i=x -> mok[10^(x+1)]
    {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int n=10;//pradinis studentu skaicius
    for(int j=0; j<i; j++)n*=10;//kiek studentu 10-10 000

    std::vector<mokiniai> mok(n);

    for(int j=0; j<n; j++)//ciklas suksis 10^fileNum kartu nes tiek bus mokiniu
    genMok(&mok[j]);

    high_resolution_clock::time_point exclud = high_resolution_clock::now();
    genFile(mok,i,"Visi");
    high_resolution_clock::time_point exclud2 = high_resolution_clock::now();
    std::vector<mokiniai> mokblo,mokger;

    int n2,n3;//kiek mokblo ir mokger tures nariu
    for(int j=n-1; j>=0; j--)
    {
        if(galutinis(&mok[j],true)>5.0)mokger.push_back(mok[j]);
        else mokblo.push_back(mok[j]);
        mok.resize(j);
    }
    rykiavimas(mokger);
    rykiavimas(mokblo);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2-t1+exclud-exclud2).count();
    std::cout<<std::endl<<duration;//nesuprantau kodel, pirmos 2-3 reiksmes laiko = 0. Naudojimas nanoseconds nepadejo

    genFile(mokger,i,"Ger");
    genFile(mokblo,i,"Blo");
  //  cout<<mokger.size()<<endl;
    }
}
