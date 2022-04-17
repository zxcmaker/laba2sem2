#pragma once
#include<iostream>
#include<math.h>

class TComplex
{
public:
	TComplex(double re_ = 0, double im_ = 0);
	TComplex(const TComplex& c);

	double GetRe();
	void SetRe(double re_);

	double GetIm();
	void SetIm(double im_);

	void Trg();

	TComplex Add(TComplex& b);
	TComplex Mult(TComplex& b);
	double ABS();
	TComplex POW(double n);
	TComplex POW(TComplex& n);


	TComplex operator + (TComplex& p);
	TComplex operator - (TComplex& p);
	TComplex operator * (TComplex& p);
	TComplex operator / (TComplex& p);

	TComplex& operator = (TComplex& p);

	bool operator == (TComplex& p);

	friend std::ostream& operator <<(std::ostream& ostr, TComplex& p);
	friend std::istream& operator >>(std::istream& istr, TComplex& p);

private:
	double re;
	double im;

};
