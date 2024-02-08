#include <iostream>             //Подключаемая библиотека
//using namespace std;

int main()                  //Определение функции Main
{
    char sym = 'E';
    char sym1{ 'g' };
    char sym3 = 'o';
    char sym4 = 'r';

    int letter1 = sym;
    int letter2 = sym1;
    int letter3 = sym3;
    int letter4 = sym4;
    std::cout << letter1 << " " << letter2 << " " << " " << letter3 << " " << letter4;
}
