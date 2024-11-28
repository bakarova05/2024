#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

/**
 * @brief Функция для лексикографической сортировки от меньшего к большему.
 * 
 */
auto LexiSort = [](auto a, auto b)
{
    if (a == b) return false;
    for (auto i = 0; i < 4; i++)
    {
        if (a[i] > b[i])
        {
            return false;
        }
        else if (a[i] < b[i])
        {
            return true;
        }
    }
    return false;
}; //сортируем без символов

auto print = [](std::vector<std::vector<int>> adres)
{
    for (size_t i = 0; i < adres.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            std::cout << adres[i][j];
            if (j < 3) 
            std::cout << ".";
        } 
        std::cout << std::endl;
    }
};

auto print1 = [](std::vector<std::vector<int>> adres)
{
    for (size_t i = 0; i < adres.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (adres[i][0] == 1)
            {
                std::cout << adres[i][j];
                if (j < 3) 
                std::cout << ".";
                else if (j == 3) 
                std::cout << std::endl;
                else break;
            }

        } 
    }
};

auto print4670 = [](std::vector<std::vector<int>> adres)
{
    for (size_t i = 0; i < adres.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (adres[i][0] == 46 && adres[i][1] == 70)
            {
                std::cout << adres[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};

auto print46 = [](std::vector<std::vector<int>> adres)
{
    for (size_t i = 0; i < adres.size(); i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if ( std::find(adres[i].begin(), adres[i].end(), 46) != adres[i].end() )
            {
                std::cout << adres[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};

std::vector<std::string> razbienie(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}