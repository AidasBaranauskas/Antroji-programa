std::random_device rd;
std::mt19937 mt(rd());//zymiai greiciau, kuomet jie globalus
int rrand(int a, int b)
{
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(mt);
}
