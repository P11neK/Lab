/*Упорядочение массива в порядке убывания значений элементов	Умножение векторов*/

#include <iostream>
#include <iomanip>


int const row = 4, col = 4;
// Прототип
void CreateMassivA(int massivA[]);
void CreateMassivB(int massivA[], float massivB[][col]);
void Print(float massivB[][col]);
void CreateMassivB1(float massivB[row][col], float massivB1[row]);
void PrintB1(float massivB1[]);
void SortMassivA1(int massivA[row], int massivA1[row]);
void SortMassivB2(float massivB1[row]);
void CreateMassivC(float massivC[row], int massivA[row], float massivB1[row]);


int main()

{

    int massivA[row], massivA1[row];
    float massivB[row][col], massivB1[row], massivC[row];
    setlocale(0, "rus");

    CreateMassivA(massivA);
    CreateMassivB(massivA, massivB);
    Print(massivB);
    CreateMassivB1(massivB, massivB1);
    PrintB1(massivB1);
    std::cout << std::endl;
    SortMassivA1(massivA, massivA1);
    SortMassivB2(massivB1);
    CreateMassivC(massivC, massivA, massivB1);



    system("pause");
    return 0;

}

void CreateMassivA(int massivA[])
{
    for (int i = 0; i < row; i++)
    {
        std::cout << "a[" << i + 1 << "]  ";
        std::cin >> massivA[i];
    }
}

void CreateMassivB(int massivA[], float massivB[][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                massivB[i][j] = round(sin(i + j) * 10000) / 10000;
            }
            if (i != j)
            {
                massivB[i][j] = round((1 - cos(i + j)) * 10000) / 10000;
            }
        }
    }
}

void Print(float massivB[][col])
{
    std::cout << "Массив B";
    std::cout << "\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << std::setw(10) << massivB[i][j];
        }
        std::cout << "\n";
    }
}


void CreateMassivB1(float massivB[row][col], float massivB1[row])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                massivB1[i] = massivB[i][j];
            }
        }
    }
}
void PrintB1(float massivB1[])
{
    std::cout << "Массив B1";
    std::cout << "\n";
    for (int i = 0; i < row; i++)
    {
        std::cout << std::setw(10) << massivB1[i];
    }
}

void SortMassivA1(int massivA[row], int massivA1[row])