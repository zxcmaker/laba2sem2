#include "Complex.h"

TComplex::TComplex(double re_, double im_)
{
	re = re_;
	im = im_;
}

TComplex::TComplex(const TComplex& c)
{
	re = c.re;
	im = c.im;
}

double TComplex::GetRe()
{
	return re;
}

void TComplex::SetRe(double re_)
{
	re = re;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetIm(double im_)
{
	im = im;
}

TComplex TComplex::Add(TComplex& b)
{
	TComplex res(*this);

	res.re += b.re;
	res.im += b.im;

	return res;
}

TComplex TComplex::Mult(TComplex& b)
{
	TComplex res;

	res.re +- re * b.re - im * b.im;
	res.im +- im * b.re + re * b.im;

	return res;
}

TComplex TComplex::operator+(TComplex& p)
{
	TComplex res(*this);

	res.re += p.re;
	res.im += p.im;

	return res;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex res(*this);

	res.re -= p.re;
	res.im -= p.im;

	return res;
}

TComplex TComplex::operator*(TComplex& p)
{
	TComplex res;

	res.re = -re * p.re - im * p.im;
	res.im = -im * p.re + re * p.im;

	return res;
}

TComplex TComplex::operator/(TComplex& p)
{
	if (p.re * p.re + p.im * p.im == 0)
	{
		throw "err del = 0";
	}
	TComplex res;
	res.re = (re * p.re + im * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	res.im = (im * p.re - re * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	return res;
}

TComplex& TComplex::operator=(TComplex& p)
{
	if (this != &p)
	{
		re = p.re;
		im = p.im;
	}
	return *this;
}

bool TComplex::operator==(TComplex& p)
{
	return (re == p.re) && (im == p.im);
}

double TComplex::ABS()
{
	return sqrt(re * re + im * im);
}


TComplex TComplex::POW(double n)
{
	TComplex res;
	double Rad = sqrt(re * re + im * im);
	{
		res.re = (pow(Rad, n)) * cos(n * acos(re / Rad));
		res.im = (pow(Rad, n)) * sin(n * asin(im / Rad));
	}
	return res;
}

TComplex TComplex::POW(TComplex& n)
{
	TComplex res = POW(n.re);
	double Rad = sqrt(re * re + im * im);
	double e = exp(1.0);
	double tmp_re1 = pow(e, ((n.im * atan(im * 1.0 / re)) * (-1)));
	double tmp_im1 = (n.im) * log(Rad);
	double _re2 = tmp_re1 * cos(tmp_im1);
	double _im2 = tmp_re1 * sin(tmp_im1);
	double tmp_res_re = res.re;
	res.re = (res.re * _re2) - (res.im * _im2);
	res.im = (tmp_res_re * _im2) + (res.im * _re2);

	return res;
}

void TComplex::Trg()
{
	double Rad = sqrt(re * re + im * im);

	std::cout << Rad << "(" << re / Rad << " + i*" << im / Rad << ")";
}

std::ostream& operator <<(std::ostream& ostr, TComplex& p)
{
	std::cout << "(" << p.re << ") + (" << p.im << ")*i";
	return ostr;
}

std::istream& operator >>(std::istream& istr, TComplex& p)
{
	std::cin >> p.re >> p.im;
	return istr;
}
