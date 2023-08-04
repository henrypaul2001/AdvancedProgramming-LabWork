#pragma once
#include <iostream>

using namespace std;

class Fraction
{
	public:
		Fraction();
		Fraction(int num, int den);

		Fraction operator*(int scalar) const;
		Fraction operator+(Fraction &rhs) const;
		Fraction operator-(Fraction &rhs) const;

		Fraction Add(const Fraction &rhs) const;
		Fraction Subtract(const Fraction &rhs) const;
		Fraction Multiply(int scale) const;
		Fraction Divide(int scale) const;

		int GetNum() const;
		int GetDen() const;

		void SetNum(int num);
		void SetDen(int den);

		void Write(ostream &sout) const;
		void Read(istream &sin);
	
	private:
		int m_num;
		int m_den;
};

istream& operator>>(istream& sin, Fraction& rhs);
ostream& operator<<(ostream &sout, const Fraction &rhs);
Fraction operator*(int scalar, const Fraction& f);
