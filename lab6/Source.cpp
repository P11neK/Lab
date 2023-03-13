#include <iostream>
#include <iomanip>




int main()


{
    int const row = 4, col = 4;
    int massivA[row], massivA1[row];
    float massivB[row][col], massivB1[row], massivB2[row][col], massivC[row];
    setlocale(0, "rus");
    //Создание массива А
    for (int i = 0; i < row; i++)
    {
        std::cout << "a[" << i + 1 << "]  ";
        std::cin >> massivA[i];
    }
    /*Создание массива Б*/
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

    /*создание массива Б1*/

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


    std::cout << "Массив А1(Массив А, отсортированный методом пузырька)" << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = col - 1; j > i; j--)
        {
            if (massivA[j] > massivA[j - 1])
            {
                int prom = massivA[j];
                massivA[j] = massivA[j - 1];
                massivA[j - 1] = prom;
            }
        }
        massivA1[i] = massivA[i]; /*заполнение массива А1*/
        std::cout << massivA1[i] << std::setw(3); /*вывод массива А1*/
    }
    std::cout << std::endl;


    //Вывод результатов
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

    std::cout << "\n";

    std::cout << "Массив B1 (Массив из главных диагоналей массива В)";
    std::cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << massivB1[i] << std::setw(10);
    }
    std::cout << std::endl;

    std::cout << "Массив B2(Массив B1, отсортированный методом пузырька)" << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = col - 1; j > i; j--)
        {
            if (massivB1[j] > massivB1[j - 1])
            {
                float prom = massivB1[j];
                massivB1[j] = massivB1[j - 1];
                massivB1[j - 1] = prom;
            }
        }
        std::cout << massivB1[i] << std::setw(10); /*вывод массива B1*/
    }
    std::cout << std::endl;

    std::cout << "Массив C(Результирующая матрица от перемножения матриц А1 и В2)" << std::endl;
    for (int i = 0; i < row; i++)
    {
        massivC[i] = massivA[i] * massivB1[i];
        std::cout << massivC[i];

        std::cout << std::endl;
    }


    system("pause");
    return 0;

}