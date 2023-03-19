#include "BogoList.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

BogoList<int> fillBogo(int size, int min, int max);

void printBogo(BogoList<int>& temp);

int main()
{
    BogoList<int> B = fillBogo(4, 1, 99);

    printBogo(B);

    B.bogoSort();

    printBogo(B);


    return 0;
}

BogoList<int> fillBogo(int size, int min, int max)
{
    srand(time(nullptr));

    BogoList<int> temp;

    if (size > temp.maxPossibleSize())
        size = temp.maxPossibleSize();
    
    if (min > max)
        min = max;

    for (int i = 0; i < size; i++)
        temp.add(rand() % (max - min + 1) + min);
    
    return temp;
}

void printBogo(BogoList<int>& temp)
{
    for (int i = 0; i < temp.getSize(); i++)
        std::cout << temp[i] << " ";
    
    std::cout << std::endl;
}