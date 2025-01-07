#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief ����������� ��� ������������� ������������ �����.
 *
 * @param aRe �������� ����� ������������ �����.
 * @param aIm ������ ����� ������������ �����.
 */
Complex::Complex(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
 * @brief ����������� �����������.
 *
 * @param aRval ����������� ����� ��� �����������.
 */
Complex::Complex(const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief ���������� ��� ������� ������.
 */
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief ������������� �������� �������� � ������ �����.
 *
 * @param aRe �������� �����.
 * @param aIm ������ �����.
 */
void Complex::Set(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
 * @brief �������������� ������� Complex � double (������ ������������ �����).
 *
 * @return ������ ������������ �����.
 */
Complex::operator double()
{
    return abs();
}

/**
 * @brief ���������� ������ ������������ �����.
 *
 * @return ������ ������������ �����.
 */
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief �������� �������� ���� ����������� �����.
 *
 * @param aRval ������ ����������� �����.
 * @return ��������� ��������.
 */
Complex Complex::operator+(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief �������� ��������� ���� ����������� �����.
 *
 * @param aRval ������ ����������� �����.
 * @return ��������� ���������.
 */
Complex Complex::operator-(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief �������� �������� ������������ ����� � ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ��������� ��������.
 */
Complex Complex::operator+(const double& aVal)
{
    Complex Result;
    Result.Re = Re + aVal;
    Result.Im = Im;
    return Result;
}

/**
 * @brief �������� ��������� ����� ���� double �� ������������ �����.
 *
 * @param aVal ����� ���� double.
 * @return ��������� ���������.
 */
Complex Complex::operator-(const double& aVal)
{
    Complex Result(*this);
    Result.Re = Re - aVal;
    return Result;
}

/**
 * @brief �������� ��������� ���� ����������� �����.
 *
 * @param aRval ������ ����������� �����.
 * @return ��������� ���������.
 */
Complex Complex::operator*(const Complex& aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief �������� ��������� ������������ ����� �� ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ��������� ���������.
 */
Complex Complex::operator*(const double& aVal)
{
    Complex Result;
    Result.Re = Re * aVal;
    Result.Im = Im * aVal;
    return Result;
}

/**
 * @brief �������� ������� ������������ ����� �� ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ��������� �������.
 */
Complex Complex::operator/(const double& aVal)
{
    Complex Result;
    Result.Re = Re / aVal;
    Result.Im = Im / aVal;
    return Result;
}

/**
 * @brief �������� ���������� ������� ������������ ����� � ��������.
 *
 * @param aRval ������ ����������� �����.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator+=(const Complex& aRval)
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief �������� ��������� ������� ������������ ����� �� ��������.
 *
 * @param aRval ������ ����������� �����.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator-=(const Complex& aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief �������� ��������� �������� ������� �� ������ ����������� �����.
 *
 * @param aRval ������ ����������� �����.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator*=(const Complex& aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief �������� ���������� ����� ���� double � �������� ������������ �����.
 *
 * @param aVal ����� ���� double.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator+=(const double& aVal)
{
    Re += aVal;
    return *this;
}

/**
 * @brief �������� ��������� ����� ���� double �� �������� ������������ �����.
 *
 * @param aVal ����� ���� double.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator-=(const double& aVal)
{
    Re -= aVal;
    return *this;
}

/**
 * @brief �������� ��������� �������� ������������ ����� �� ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator*=(const double& aVal)
{
    Re *= aVal;
    Im *= aVal;
    return *this;
}

/**
 * @brief �������� ������� �������� ������������ ����� �� ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator/=(const double& aVal)
{
    Re /= aVal;
    Im /= aVal;
    return *this;
}

/**
 * @brief �������� ������������ �������� �� ������� ������������ �����.
 *
 * @param aRval ����������� �����.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator=(const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief �������� ������������ �������� ����� ���� double.
 *
 * @param aVal ����� ���� double.
 * @return ������ �� ������� ������ Complex.
 */
Complex& Complex::operator=(const double& aVal)
{
    Re = aVal;
    Im = 0.0;
    return *this;
}

/**
 * @brief �������� ����� ��� ������������ �����.
 *
 * @param stream ����� �����.
 * @param a ����������� �����.
 * @return ����� �����.
 */
istream& operator>>(istream& stream, Complex& a)
{
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief �������� ������ ��� ������������ �����.
 *
 * @param stream ����� ������.
 * @param a ����������� �����.
 * @return ����� ������.
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
 * @brief �������� �������� ����� ���� double � ������������ �����.
 *
 * @param aLval ����� ���� double.
 * @param aRval ����������� �����.
 * @return ��������� ��������.
 */
Complex operator+(const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/**
 * @brief �������� ��������� ����� ���� double � ������������ �����.
 *
 * @param aLval ����� ���� double.
 * @param aRval ����������� �����.
 * @return ��������� ���������.
 */
Complex operator-(const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/**
 * @brief �������� ��������� ����� ���� double � ������������ �����.
 *
 * @param aLval ����� ���� double.
 * @param a ����������� �����.
 * @return ��������� ���������.
 */
Complex operator*(const double& aLval, const Complex& a)
{
    Complex Result;
    Result.Re = aLval * a.Re;
    Result.Im = aLval * a.Im;
    return Result;
}
