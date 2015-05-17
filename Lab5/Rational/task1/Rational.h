#pragma once

/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	//////////////////////////////////////////////////////////////////////////
	// TODO: 1. Реализовать метод ToDouble() согласно заданию
	// Возвращает отношение числителя и знаменателя в виде числа double
	// Пример использования:
	//	CRational r(3, 5)
	//	cout << r.ToDouble(); // Должно вывести 0.6
	double ToDouble() const;
	//////////////////////////////////////////////////////////////////////////

	CRational const operator +() const;
	CRational const operator -() const;
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// TODO: 5. Реализовать оператор +=
	// Выполняет увеличение рационального числа на величину второго рационального,
	//	либо целого числа:
	//	(1/2) += (1/6)  → (2/3)
	//	(1/2) += 1      → (3/2)
	CRational& operator +=(CRational const& rational);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// TODO: 6. Реализовать оператор -=
	// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
	// (1/2) -= (1/6)  → (1/3)
	// (1/2) -= 1      → (-1/2)
	CRational& operator -=(CRational const& rational);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// TODO: 9. Реализовать оператор *=
	// Умножает значение первого рационального числа на другое рациональное, 
	//	либо целое:
	//	(1/2) *= (2/3) → (1/3)
	//	(1/2) *= 3     → (3/2)
	CRational& operator *=(CRational const& other);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// TODO: 10. Реализовать оператор /=
	// Делит первое рациональное число на другое рациональное, 
	//	либо целое:
	//	(1/2) /= (2/3) → (3/4)
	//	(1/2) /= 3     → (1/6)
	CRational& CRational::operator /=(CRational const &other);
	//////////////////////////////////////////////////////////////////////////

private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);
unsigned LCM(unsigned a, unsigned b);

const CRational operator *(const CRational &num1, const CRational &num2);
const CRational operator / (const CRational &num1, const CRational &num2);

const CRational operator + (const CRational &num1, const CRational &num2);
const CRational operator - (const CRational &num1, const CRational &num2);

const bool operator == (const CRational &num1, const CRational &num2);
const bool operator != (const CRational &num1, const CRational &num2);
const bool operator < (const CRational &other1, const CRational &other2);
const bool operator > (const CRational &other1, const CRational &other2);
const bool operator >= (const CRational &other1, const CRational &other2);
const bool operator <= (const CRational &other1, const CRational &other2);

std::ostream& operator << (std::ostream &stream, const CRational &num);
std::istream & operator >>(std::istream & stream, CRational & rational);
