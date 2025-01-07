#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор для инициализации комплексного числа.
 *
 * @param aRe Реальная часть комплексного числа.
 * @param aIm Мнимая часть комплексного числа.
 */
Complex::Complex(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования.
 *
 * @param aRval Комплексное число для копирования.
 */
Complex::Complex(const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор для очистки данных.
 */
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает значения реальной и мнимой части.
 *
 * @param aRe Реальная часть.
 * @param aIm Мнимая часть.
 */
void Complex::Set(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование объекта Complex в double (модуль комплексного числа).
 *
 * @return Модуль комплексного числа.
 */
Complex::operator double()
{
    return abs();
}

/**
 * @brief Вычисление модуля комплексного числа.
 *
 * @return Модуль комплексного числа.
 */
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Операция сложения двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат сложения.
 */
Complex Complex::operator+(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Операция вычитания двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Операция сложения комплексного числа и числа типа double.
 *
 * @param aVal Число типа double.
 * @return Результат сложения.
 */
Complex Complex::operator+(const double& aVal)
{
    Complex Result;
    Result.Re = Re + aVal;
    Result.Im = Im;
    return Result;
}

/**
 * @brief Операция вычитания числа типа double из комплексного числа.
 *
 * @param aVal Число типа double.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const double& aVal)
{
    Complex Result(*this);
    Result.Re = Re - aVal;
    return Result;
}

/**
 * @brief Операция умножения двух комплексных чисел.
 *
 * @param aRval Второе комплексное число.
 * @return Результат умножения.
 */
Complex Complex::operator*(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Операция умножения комплексного числа на число типа double.
 *
 * @param aVal Число типа double.
 * @return Результат умножения.
 */
Complex Complex::operator*(const double& aVal)
{
    Complex Result;
    Result.Re = Re * aVal;
    Result.Im = Im * aVal;
    return Result;
}

/**
 * @brief Операция деления комплексного числа на число типа double.
 *
 * @param aVal Число типа double.
 * @return Результат деления.
 */
Complex Complex::operator/(const double& aVal)
{
    Complex Result;
    Result.Re = Re / aVal;
    Result.Im = Im / aVal;
    return Result;
}

/**
 * @brief Операция добавления второго комплексного числа к текущему.
 *
 * @param aRval Второе комплексное число.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator+=(const Complex& aRval)
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief Операция вычитания второго комплексного числа из текущего.
 *
 * @param aRval Второе комплексное число.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator-=(const Complex& aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief Операция умножения текущего объекта на второе комплексное число.
 *
 * @param aRval Второе комплексное число.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator*=(const Complex& aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief Операция добавления числа типа double к текущему комплексному числу.
 *
 * @param aVal Число типа double.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator+=(const double& aVal)
{
    Re += aVal;
    return *this;
}

/**
 * @brief Операция вычитания числа типа double из текущего комплексного числа.
 *
 * @param aVal Число типа double.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator-=(const double& aVal)
{
    Re -= aVal;
    return *this;
}

/**
 * @brief Операция умножения текущего комплексного числа на число типа double.
 *
 * @param aVal Число типа double.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator*=(const double& aVal)
{
    Re *= aVal;
    Im *= aVal;
    return *this;
}

/**
 * @brief Операция деления текущего комплексного числа на число типа double.
 *
 * @param aVal Число типа double.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator/=(const double& aVal)
{
    Re /= aVal;
    Im /= aVal;
    return *this;
}

/**
 * @brief Операция присваивания значений из другого комплексного числа.
 *
 * @param aRval Комплексное число.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator=(const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief Операция присваивания значения числа типа double.
 *
 * @param aVal Число типа double.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator=(const double& aVal)
{
    Re = aVal;
    Im = 0.0;
    return *this;
}

/**
 * @brief Оператор ввода для комплексного числа.
 *
 * @param stream Поток ввода.
 * @param a Комплексное число.
 * @return Поток ввода.
 */
istream& operator>>(istream& stream, Complex& a)
{
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief Оператор вывода для комплексного числа.
 *
 * @param stream Поток вывода.
 * @param a Комплексное число.
 * @return Поток вывода.
 */
ostream& operator<<(ostream& stream, Complex& a)
{
    stream << a.Re;
    if (!(a.Im < 0))
        stream << '+';
    stream << a.Im << 'i';
    return stream;
}

/**
 * @brief Операция сложения числа типа double и комплексного числа.
 *
 * @param aLval Число типа double.
 * @param aRval Комплексное число.
 * @return Результат сложения.
 */
Complex operator+(const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/**
 * @brief Операция вычитания числа типа double и комплексного числа.
 *
 * @param aLval Число типа double.
 * @param aRval Комплексное число.
 * @return Результат вычитания.
 */
Complex operator-(const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/**
 * @brief Операция умножения числа типа double и комплексного числа.
 *
 * @param aLval Число типа double.
 * @param a Комплексное число.
 * @return Результат умножения.
 */
Complex operator*(const double& aLval, const Complex& a)
{
    Complex Result;
    Result.Re = aLval * a.Re;
    Result.Im = aLval * a.Im;
    return Result;
}
