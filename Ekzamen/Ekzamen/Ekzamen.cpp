#include <iostream>
#include <windows.h>

using namespace std;

int stopGl = 10;

enum SeaFight
{
    Человек = 1, Компьютер, Выйти
};

void full(int arr[][12], int size);
void print2(int arr[][12], int size); 
void ComputerPlaceStart(int pole2[][12], int size);
void HumanPlaceStart(int pole1[][12], int size); 
void compPlay(int pole2[][12], int& x1, int& y1, int& x, int& y, int i, int spot, int shot, int kill);
void compPlay2(int& x, int& y);
void Play(int pole[][12], int poleIg[][12], int pole2[][12], int size, int detect);
bool check(int pole[][12], int size);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int restart; 
    do
    {
        system("cls");
        cout << "Добро пожаловать в игру Морской бой" << endl;
        cout << "Выберете режим игры: \nЧеловек - Компьютер - 1\nКомпьютер - Компьютер - 2\nВыйти - 3" << endl;
        int mode;
        int const size = 12;
        int pole1[size][size];
        int pole2[size][size];
        int poleIg[size][size];
        full(pole1, size);
        full(pole2, size);
        full(poleIg, size);
        do
        {
            cin >> mode;
            switch (mode)
            {
            case Человек:
            {
                cout << "Кто заполнит поле для игры?\nЧеловек - 1\nКомпьютер - 2\nВыход - 3" << endl;
                int made;
                cin >> made;
                do
                {
                    switch (made)
                    {
                    case Человек:
                    {
                        HumanPlaceStart(pole1, size);
                        ComputerPlaceStart(pole2, size);
                        system("pause");
                        break;
                    }
                    case Компьютер:
                    {
                        cout << "Ваше ";
                        ComputerPlaceStart(pole1, size);
                        print2(pole1, size);
                        system("pause");
                        cout << "Компьютера ";
                        ComputerPlaceStart(pole2, size);
                        print2(pole2, size);
                        system("pause");
                        break; 
                    }
                    case Выйти:
                    {
                        cout << "Выход";
                        mode = 3;
                        break;
                    }
                    default:
                    {
                        cout << "Неверно";
                        break;
                    }
                    }

                } while (made != 3 && made != 1 && made != 2);
                break;
            }
            case Компьютер:
            {
                ComputerPlaceStart(pole1, size);
                print2(pole1, size);
                system("pause");
                ComputerPlaceStart(pole2, size);
                print2(pole2, size); 
                system("pause");  
                break;
            }
            case Выйти:
            {
                return 0;
                break;
            }
            default:
            {
                break;
            }
            }
        } while (mode != 3 && mode != 1 && mode != 2);
        system("cls");
        int start;
        if (mode == 1)
        {
            do
            {

            
            system("cls");
            cout << "Игра началась \n";
            cout << "Какой режим хотите?\n1 - случайные выстрелы\n2 - интеллектуальный компьютер\n";
            cin >> start;
            switch (start)
            {
            case 1:
            {
                do
                {
                    Play(pole1, poleIg, pole2, size, 1);
                    if (check(pole1, size) == true)
                    {
                        Play(pole2, poleIg, pole1, size, 2);
                    }
                } while (check(pole1, size) == true && check(pole2, size) == true);

                if (check(pole2, size) == false)
                {
                    cout << "Игрок победил";
                }
                else
                    cout << "Компьтер победил"; 
                break;
            }
            case 2:
            {
                do
                {
                    Play(pole1, poleIg, pole2, size, 1);
                    if (check(pole1, size) == true)
                    {
                        Play(pole2, poleIg, pole1, size, 4);
                    }
                } while (check(pole1, size) == true && check(pole2, size) == true);

                if (check(pole2, size) == false)
                {
                    cout << "Игрок победил";
                }
                else
                    cout << "Компьтер победил";
                break;
            }
            default:
                break;
            }
            } while (start != 1 || start != 2);
        }
        else
        {
            do
            {
                system("cls");
                Play(pole1, poleIg, pole2, size, 2);
                cout << "Поле 1: \n";
                print2(pole2, size);
                if (check(pole1, size) == true) 
                {
                    cout << "Поле 2: \n";
                    Play(pole2, poleIg, pole1, size, 2); 
                    print2(pole1, size);
                }
                system("pause");
            } while (check(pole1, size) == true && check(pole2, size) == true); 
            if (check(pole2, size) == false) 
            {
                cout << "Компьютер 1 победил";
            }
            else  
                cout << "Компьтер 2 победил";
        }
        cout << "\nЗаново?\n1-Да\n2 - нет\n";
        cin >> restart;
        switch (restart)
        {
        case 1:
        {
            cout << "Перезапуск\n";
            system("pause");
            break;
        }
        case 2:
        {
            cout << "Спасибо за игру!!!";
            return 0;
        }
        default:
        {
            cout << "Ошибка";
            break;
        }
        }
    }while (restart != 2);
    return 0;
}

void full(int arr[][12], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            arr[i][j] = 0;
        }
    }
}
int PlacePr(int pole[][12],  int size, int ShipSize, int detect = 1)
{
    int napr = 1, x, y;
    stopGl--;
    if (stopGl <= 1) 
    {
        return 1;
    }
    if (detect == 1)
    {
        if (ShipSize != 1)
        {
            do
            {
                cout << "Введите направление\n1 - горизонталь\n2 - вертикаль\n";
                cin >> napr;
            } while (napr != 1 && napr != 2);
        }
        cout << "Введите x: ";
        cin >> x;
        cout << "Введите y: ";
        cin >> y;
    }
    else
    {
        if (ShipSize != 1)
        {
            napr = 1 + rand() % 2; 
        }
        x = 1 + rand() % 10;
        y = 1 + rand() % 10;
        if (detect == 3)
        {
            napr = 1;
            x = 8;
            y = 5;
        }
    }
    if ((napr == 1 && x + ShipSize - 1  <= 10) || (napr == 2 && y + ShipSize - 1 <= 10) ) 
    {
        if (napr == 1)
        {
            if (pole[y][x - 1] != 1 && pole[y + 1][x - 1] != 1 && pole[y - 1][x - 1] != 1 && pole[y][x + ShipSize] != 1 && pole[y - 1][x + ShipSize] != 1 && pole[y + 1][x + ShipSize] != 1) 
            {
                for (int i = x; i < x + ShipSize; i++) 
                {
                    if (pole[y + 1][i] != 1 && pole[y - 1][i] != 1 && pole[y][i] != 1)
                    {
                        pole[y][i] = 1;
                    }
                    else
                    {
                        for (int j = x; j < i; j++)  
                        {
                            pole[y][j] = 0; 
                        }
                        i = x + ShipSize;  
                        if (detect == 1)
                        {
                            cout << "Выбрана неверная координата" << endl;
                        }
                        PlacePr(pole, size, ShipSize, detect);
                    }
                }
            }
            else
            {
                if (detect == 1)
                {
                    cout << "Выбрана неверная координата" << endl;
                }
                PlacePr(pole, size, ShipSize, detect);
            }
        }
        else if(napr == 2)
        {
            if (pole[y - 1][x] != 1 && pole[y - 1][x + 1] != 1 && pole[y - 1][x - 1] != 1 && pole[y + ShipSize][x] != 1 && (x != 9 ? pole[y + ShipSize ][x + 1] != 1 : 0) && pole[y + ShipSize][x - 1] != 1)
            {
                for (int i = y; i < y + ShipSize; i++) 
                {
                    if (pole[i][x - 1] != 1 && pole[i][x + 1] != 1 && pole[i][x] != 1)
                    {
                        pole[i][x] = 1; 
                    }
                    else
                    {
                        for (int j = y; j < i; j++)
                        {
                            pole[j][x] = 0;
                        }
                        i = y + ShipSize; 
                        if (detect == 1)
                        {
                            cout << "Выбрана неверная координата" << endl;
                        }
                        PlacePr(pole, size, ShipSize, detect);
                    }
                }
            }
            else
            {
                if (detect == 1)
                {
                    cout << "Выбрана неверная координата" << endl;
                }
                PlacePr(pole, size, ShipSize, detect);
            }
        }
        
    }
    else
    {
        if (detect == 1)
        {
            cout << "Выбрана неверная координата" << endl;
        }
        PlacePr(pole, size, ShipSize, detect);
    }
    
    if (stopGl <= 1)
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}
void ComputerPlaceStart(int pole2[][12], int size)
{
    int stop;
    for (int i = 4; i > 0; i--)
    {
        do
        {
            stop = PlacePr(pole2, size, 1, 0);
            stopGl = 10;
        } while (stop == 1);  
        if (i <= 3)
        {
            do
            {
               stop = PlacePr(pole2,  size, 2, 0);
               stopGl = 10;
            } while (stop == 1);
        }
        if (i <= 2)
        {
            do
            {
                stop = PlacePr(pole2,  size, 3, 0);
                stopGl = 10;
            } while (stop == 1); 
        }
        if (i == 1)
        {
            do
            {
                stop = PlacePr(pole2, size, 4, 0);
                stopGl = 10;
            } while (stop == 1); 
        }
    }
    cout << "поле готово\n";
}
void HumanPlaceStart(int pole1[][12], int size)
{
    int stop;
    int paluba1 = 4, paluba2 = 3, paluba3 = 2, paluba4 = 1, choice;
    do
    {
        system("cls");
        cout << "Ваше поле:\n";
        print2(pole1, size);  
        cout << "Какой корабль хотите расположить?" << endl;
        cout << "У вас есть: \n";
        cout << "1 - Однопалубный корабль - " << paluba1 << " Штуки" << endl;
        cout << "2 - Двухпалубный корабль - " << paluba2 << " Штуки" << endl;
        cout << "3 - Трехпалубный корабль - " << paluba3 << " Штуки" << endl;
        cout << "4 - Четырех палубный корабль - " << paluba4 << " Штука" << endl; 
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (paluba1 == 0)
            {
                cout << "У вас нет таких кораблей\n";
                system("pause");
                break;
            }
            else
            {
                do
                {
                stop = PlacePr(pole1, size, 1); 
                paluba1--;
                stopGl = 10;
                break;
                } while (stop == 1);
                break;
            }
        }
        case 2:
        {
            if (paluba2 == 0)
            {
                cout << "У вас нет таких кораблей\n";
                system("pause");
                break;
            }
            else
            {
                do
                {
                    stop = PlacePr(pole1, size, 2); 
                    paluba2--;
                    stopGl = 10;
                    break;
                } while (stop == 1);
                break;
            }
        }
        case 3:
        {
            if (paluba3 == 0)
            {
                cout << "У вас нет таких кораблей\n";
                system("pause");
                break;
            }
            else
            {
                do
                {
                    stop = PlacePr(pole1, size, 3); 
                    paluba3--;
                    stopGl = 10;
                    break;
                } while (stop == 1);
                break;
            }
        }
        case 4:
        {
            if (paluba4 == 0)
            {
                cout << "У вас нет таких кораблей\n";
                system("pause");
                break;
            }
            else
            { 
                do
                {
                    stop = PlacePr(pole1, size, 4);
                    paluba4--;
                    stopGl = 10;
                    break;
                } while (stop == 1);
                break;
            }
        }
        default:
        {
            cout << "Ошибка";
            break;
        }
        }
    } while (paluba1 > 0 || paluba2 > 0 || paluba3 > 0 || paluba4 > 0);
}
bool check(int pole[][12],int size)
{
        for (int i = 1; i < size - 1; i++)
        {
            for (int j = 1; j < size - 1; j++)
            {
                if (pole[i][j] == 1)
                {
                    return true;
                }
            }
            cout << endl;
        }
    return false;
}
void Play(int pole[][12], int poleIg[][12], int pole2[][12], int size, int detect = 1)
{
    int shot = 1, temp = 1, trigger = 1,trY, trX; 
    static int x, y, x1, y1, kill = 1, spot = 1, i = 0; 
    do
    { 
        if (check(pole2, size) == false) 
        {
            break;
        } 
        trigger = 1;  
        temp = 1; 
        if (detect == 1)
        {
            cout << "\n3 - мимо\n4 - Попал";
            cout << "Ваше поле: \n";
            print2(pole, size);
            cout << "Поле для игры: \n";
            print2(poleIg, size);
            cout << "Поле компа: \n";
            print2(pole2, size);
            cout << "Куда вы хотите выстрелить?";
            cout << "Введите x: ";
            cin >> x;
            cout << "Введите y: ";
            cin >> y;
        }
        else if (detect == 3)
        {
            compPlay(pole2, x1, y1, x, y, i, spot, shot, kill);     
        }
        else if (detect == 4)
        {
            compPlay2(x, y);
        }
        else
        {
            x = 1 + rand() % 10;
            y = 1 + rand() % 10;
        }
        if (x <= 10 && x >= 1 && y <= 10 && y >= 1 && pole2[y][x] != 3 && pole2[y][x] != 4)
        {
            if (pole2[y][x] == 1)
            {
                trX = x;
                while (pole2[y][trX + 1] != 0 && pole2[y][trX + 1] != 3)
                {
                    if (pole2[y][trX + 1] == 1)
                    {
                        trigger++;
                    }
                    trX++;
                }
                trX = x;
                while (pole2[y][trX - 1] != 0 && pole2[y][trX - 1] != 3)
                {
                    if (pole2[y][trX - 1] == 1)
                    {
                        trigger++;
                    }
                    trX--;
                }
                trY = y;
                while (pole2[trY + 1][x] != 0 && pole2[trY + 1][x] != 3)
                {
                    if (pole2[trY + 1][x] == 1)
                    {
                        temp++;
                    }
                    trY++;
                }
                trY = y;
                while (pole2[trY - 1][x] != 0 && pole2[trY - 1][x] != 3)
                {
                    if (pole2[trY - 1][x] == 1)
                    {
                        temp++;
                    }
                    trY--;
                }
                if (trigger == 1)
                {
                    trigger = -1;
                }
                else if (temp == 1)
                {
                    temp = -1;
                }
                shot = 1;
                pole2[y][x] = 4;
                temp--;
                trigger--;
                if (detect == 1)
                {
                    poleIg[y][x] = 4;
                    if (temp > 0 || trigger > 0)
                    {
                        cout << "Ранил\n";
                        system("pause");
                    }
                    else if (temp == 0 || trigger == 0)
                    {
                        cout << "Убил\n"; 
                        system("pause"); 
                    }
                }
                else if (detect == 3)
                {
                    if (temp > 0 || trigger > 0)
                    {
                        kill = 0;                                   //ранил
                        if (i == 0)
                        {
                            i++; 
                            x1 = x;
                            y1 = y;
                        }
                    }
                    else if (temp == 0 || trigger == 0)
                    {
                        kill = 1;               //убил
                        i = 0; 
                        spot = 0;
                    }
                }
            }
            else
            {
                shot = 0;
                pole2[y][x] = 3;
                if (detect == 1)
                {
                    poleIg[y][x] = 3;
                    cout << "Мимо\n"; 
                    system("pause"); 
                }
                else if (detect == 3)
                {
                    if (kill == 0)
                    {
                        spot++;             //мимо
                    }
                }
            }
        }
        if (check(pole2, size) == false)
        {
            break;
        }


    } while (shot == 1);
}
void compPlay(int pole2[][12], int& x1, int& y1, int& x, int& y, int i, int spot, int shot, int kill)                       // Добивает корабли, не успел доделать:(
{
    int static trX = 0, trY;
    if (kill == 1)
    {
        x = 1 + rand() % 10;
        y = 1 + rand() % 10;
    }
    if (kill == 0)
    {
        if (i == 1)
        {
            trX = x1;
            trY = y1;
        }
        if (spot == 0 || spot == 1 || spot == 2)
        {
            if (shot == 1 && spot == 1 && x + 1 <= 10)
            {
                x = x + 1;
            }
            else
            {
                x = x - 1;
            }
        }
        else
        {
            if (shot == 1 && y + 1 <= 10)
            {
                y = y + 1;
            }
            else
            {
                y = y1 - 1;
            }
        }
    }
}           
void compPlay2(int& x, int& y)
{
    int static x1 = -1, y1 = 1, i = 0;
    if (x1+2 <= 10 && y1 <= 10) 
    {
        x = x1 + 2;
        x1 += 2; 
        y = y1;
    }
    else if(x1 + 2 == 11 && y1 <= 10) 
    {
        y1++;  
        x1 = 0; 
        compPlay2(x, y);
    }
    else if(x1 + 2 == 12 && y1 <= 10) 
    {
        y1++;
        x1 = -1;
        compPlay2(x,y); 
    }
    if (y1 > 10 && i == 0)
    {
        i++;
        y1 = 1;
        x1 = 0;
        compPlay2(x, y);
    }

}
void print2(int arr[][12], int size)

{
    cout << "  X 1 2 3 4 5 6 7 8 9 10\n Y\n";

    for (int i = 1; i < size - 1; i++)
    {
        if (i != 10) 
        {
           cout << " " << i << "  "; 
        }
        else
            cout << i << "  ";
        for (int j = 1; j < size - 1; j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}

