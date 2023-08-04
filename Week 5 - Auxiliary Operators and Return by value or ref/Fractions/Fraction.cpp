#include "Fraction.h"
#include <iostream>
#include <cassert>

using namespace std;


Fraction::Fraction() {
	SetNum(0); SetDen(1);
}

Fraction::Fraction(int num, int den) {
	SetNum(num); SetDen(den);
}

int Fraction::GetNum() const {
	return m_num;
}

int Fraction::GetDen() const {
	return m_den;
}

void Fraction::SetNum(int num) {
	m_num = num;
}

void Fraction::SetDen(int den) {
	assert(den);
	m_den = den;
}

Fraction Fraction::Add(const Fraction& rhs) const {
	int den = GetDen();
	int num = GetNum();
	int otherDen = rhs.GetDen();
	int otherNum = rhs.GetNum();

	if (den != otherDen) {
		// Find common denominator
		int newDen = otherDen * den;
		int newNum = otherDen * num;

		int otherNewDen = den * otherDen;
		int otherNewNum = den * otherNum;

		newNum = newNum + otherNewNum;
		Fraction newFraction(newNum, newDen);
		return newFraction;
	}
	else {
		// Already has common denominator
		int newNum = num + otherNum;
		Fraction newFraction(newNum, den);
		return newFraction;
	}
}

Fraction Fraction::Subtract(const Fraction& rhs) const {
	int den = GetDen();
	int num = GetNum();
	int otherDen = rhs.GetDen();
	int otherNum = rhs.GetNum();

	if (den != otherDen) {
		// Find common denominator
		int newDen = otherDen * den;
		int newNum = otherDen * num;

		int otherNewDen = den * otherDen;
		int otherNewNum = den * otherNum;

		newNum = newNum - otherNewNum;
		Fraction newFraction(newNum, newDen);
		return newFraction;
	}
	else {
		// Already has common denominator
		int newNum = num - otherNum;
		Fraction newFraction(newNum, den);
		return newFraction;
	}
}

Fraction Fraction::Multiply(int scale) const {
	int den = GetDen();
	int num = GetNum();

	num = num * scale;

	Fraction newFraction(num, den);
	return newFraction;
}

Fraction Fraction::Divide(int scale) const {
	int den = GetDen();
	int num = GetNum();

	den = den * scale;

	Fraction newFraction(num, den);
	return newFraction;
}

void Fraction::Write(ostream& sout) const {
	sout << GetNum() << "/" << GetDen();
}

void Fraction::Read(istream& sin) {
	int num;
	int den;
	sin >> num;
	sin >> den;

	SetNum(num);
	SetDen(den);
}

Fraction Fraction::operator*(int scalar) const {
	return Multiply(scalar);
}

Fraction Fraction::operator+(Fraction &rhs) const {
	return Add(rhs);
}

Fraction Fraction::operator-(Fraction &rhs) const {
	return Subtract(rhs);
}


Fraction operator*(int scalar, const Fraction& f) {
	return f * scalar;
}

ostream& operator<<(ostream &sout, const Fraction &rhs) {
	rhs.Write(sout);
	return sout;
}

istream& operator>>(istream& sin, Fraction& rhs) {
	 rhs.Read(sin);
	 return sin;
}