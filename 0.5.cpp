#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <chrono>
#include <random>
#include "struct.h"
#include "random.hpp"
#include "funkcijos.h"

int main()
{
    int a,b,n=1;
    std::cout<<"Iveskite a ir b, zinant, kad uzduotis bus atlikta su nuo 10^a iki 10^b mokiniu"<<std::endl;
    std::cin>>a>>b;
    for(int i=0; i<a; i++)n*=10;//pradine reiksme n=n^a
    for(int i=a; i<=b; i++)
    {
        std::cout<<std::endl<<"10^"<<i;
        genFile(n, "10^"+std::to_string(i)+".txt");//failu pav bus visi_10^i.txt
        uzduotis(n, "10^"+std::to_string(i));//;cout<<"asd";

        n*=10;
    }
    return 0;
}
