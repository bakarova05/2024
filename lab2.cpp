#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "lab2.h"

int main()
{   setlocale(LC_ALL, "");
    std::vector<std::vector<int>> adres;
    std::string s;
    std::ifstream file("ip_filter.tsv");
    while(std::getline(file, s)){
        auto razbivka = razbienie(s.substr(0, s.find('\t')), '.');
        std::vector<int> oct = {stoi(razbivka[0]), stoi(razbivka[1]), stoi(razbivka[2]), stoi(razbivka[3])};
        adres.push_back(oct);}
    sort(adres.begin(), adres.end(), LexiSort);
    std::cout << "Полный список адресов после сортировки" << std::endl;
    print(adres);
    std::cout << "Сразу после списка печатается список адресов, первый байт которых равен 1" << std::endl;
    print1(adres);
    std::cout << "Сразу продолжается список адресов, первый байт которых равен 46, а второй 70" << std::endl;
    print4670(adres);
    std::cout << "Сразу печатается список адресов, любой байт которых равен 46" << std::endl;
    print46(adres);
}