
#include <iostream>
#include "matrix.h"
#include <stdexcept>
using namespace std;
void MainMenu(const Matrix& m)
{
    cout << "Вычислить определитель матрицы - нажмите 1" << endl
        << "Транспонировать матрицу - 2" << endl
        << "Вывести матрицу на экран - 3" << endl
        << "Прибавить ко всем элементам матрицы число - 4" << endl
        << "Вычесть из всех элементов матрицы число - 5" << endl
        << "Умножить матрицу на число - 6" << endl
        << "Сложить матрицы - 7" << endl
        << "Перемножить матрицы - 8" << endl
        << "Вычесть другую матрицу - 9" << endl
        << "Ввести новую матрицу - 10" << endl
        << "Завершение работы - 0" << endl;
    cout << endl << "----------------------------" << endl
        << "Ваша матрица в данный момент: " << endl
        << m << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        size_t rows, cols;
        cout << "Введите размер матрицы" << endl;
        cin >> rows >> cols;
        cout << "Введите элементы матрицы построчно" << endl;
        Matrix m1(rows, cols);
        cin >> m1;
        cout << endl;
        MainMenu(m1);
        int _stateMenu;
        cin >> _stateMenu;
        while (_stateMenu)
        {
            switch (_stateMenu)
            {
            case 1:
            {
                system("cls");
                cout << "Определитель: " << m1.Determinant() << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 2:
            {
                system("cls");
                cout << "Транспонированная матрица: " << endl << !m1 << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 3:
            {
                system("cls");
                cout << m1 << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 4:
            {
                system("cls");
                double digit;
                cout << "Введите число:" << endl;
                cin >> digit;
                cout << endl;
                m1 += digit;
                cout << m1 << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 5:
            {
                system("cls");
                double digit;
                cout << "Введите число:" << endl;
                cin >> digit;
                cout << endl;
                m1 -= digit;
                cout << m1 << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 6:
            {
                system("cls");
                double digit;
                cout << "Введите число:" << endl;
                cin >> digit;
                cout << endl;
                m1 *= digit;
                cout << m1 << endl;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 7:
            {
                system("cls");
                size_t rows_2 = rows, cols_2 = cols;
                cout << endl << "Введите элементы второй матрицы построчно(размер " << rows_2 << "x" << cols_2 << ")" << endl;
                Matrix m2(rows_2, cols_2);
                cin >> m2;
                cout << "Результат: " << endl;
                cout << m1 + m2;

                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 8:
            {
                system("cls");
                cout << "Введите размеры второй матрицы: " << endl;
                size_t rows_2, cols_2;
                cin >> rows_2 >> cols_2;
                cout << endl << "Введите элементы второй матрицы построчно: " << endl;
                Matrix m2(rows_2, cols_2);
                cin >> m2;
                cout << "Результат: " << endl;
                cout << m1 * m2;

                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 9:
            {
                system("cls");
                size_t rows_2 = rows, cols_2 = cols;
                cout << endl << "Введите элементы второй матрицы построчно(размер " << rows_2 << "x" << cols_2 << ")" << endl;
                Matrix m2(rows_2, cols_2);
                cin >> m2;
                cout << "Результат: " << endl;
                cout << m1 - m2;

                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }
            case 10:
            {
                system("cls");
                cout << "Введите размеры новой матрицы: " << endl;
                size_t rows_2, cols_2;
                cin >> rows_2 >> cols_2;
                cout << endl << "Введите элементы новой матрицы построчно: " << endl;
                Matrix m2(rows_2, cols_2);
                cin >> m2;
                m1 = m2;
                system("pause");
                system("cls");
                MainMenu(m1);
                cin >> _stateMenu;
                break;
            }

            }
        }

    }
    catch (const exception& ex)
    {
        cout << "Ошибка! " << ex.what() << endl;
        cout << typeid(ex).name() << endl;
        return 1;
    }
    catch (...)
    {
        cout << "Неизвестная ошибка" << endl;
        return 1;
    }

    Matrix m3;
    Matrix m4;
    // НАПИСАТЬ ЛОГИКУ ТУТ!!
    m4 = 5 + m3;
    m4 = 5 - m3;
}

