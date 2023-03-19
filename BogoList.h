#ifndef BOGOSORT_BOGOLIST_H
#define BOGOSORT_BOGOLIST_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 5;

template<typename T>
class BogoList
{
    private:
        int MAX_SIZE;
        std::vector<T> v;
    public:
        BogoList() : MAX_SIZE(MAX) {}

        int getSize()   
        { 
            return v.size(); 
        }

        int maxPossibleSize()
        {
            return MAX_SIZE;
        }

        int& operator[](int index) 
        {
            if (index < 0 || index >= v.size())
                throw std::out_of_range("Index out of range");
            else
                return v[index]; 
        }

        void bogoSort()
        {
            if (alreadySorted()) // lol
                shuffle();
            
            while (! alreadySorted())
                shuffle();
        }

        void add(T val)
        {
            if (v.size() >= MAX_SIZE)
                throw std::out_of_range("BogoList is full. Max Capacity: " + std::to_string(MAX_SIZE));
            else 
                v.push_back(val);
        }

        bool alreadySorted()
        {
            if (v.size() == 0 || v.size() == 1)
                return true;

            for (int i = 1; i < v.size(); i++)
            {
                if (v[i] < v[i-1])
                    return false;
            }

            return true;
        }

        void shuffle()
        {
            std::vector<int> availableIndexes = getAvailableIndexList(v.size());
            std::vector<int> temp = v;

            for (int i = 0; i < v.size(); i++)
                temp[getAndRemoveRandomNumberFromVector(availableIndexes)] = v[i];
            
            v = temp;
        }
    private:
        static std::vector<int> getAvailableIndexList(int size)
        {
            std::vector<int> temp;
            for (int i = 0; i < size; i++)
                temp.push_back(i);
            
            return temp;
        }

        static int getAndRemoveRandomNumberFromVector(std::vector<int>& temp)
        {
            if (temp.empty())
                throw std::out_of_range("Vector is empty. Therefore, a random value from the vector cannot be obtained.");
            
            int randomIndex = randint(0, temp.size() - 1);
            int correspondingValue = temp[randomIndex];
            temp.erase(temp.begin() + randomIndex);

            return correspondingValue;
        }

        static int randint(int min, int max)
        {
            if (min > max)
                throw std::out_of_range("Minimum random value cannot be greater than maximum value.");
            
            srand(time(nullptr));
            return rand() % (max - min + 1) + min;
        }
};

#endif