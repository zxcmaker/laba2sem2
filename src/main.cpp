#include<iostream>
#include"Complex.h"

int main()
{
	TComplex a, b, c;
	std::cout << " enter Complex a: ";
	std::cin >> a;
	std::cout << "a = " << a << std::endl;
	a.Trg(); std::cout << std::endl;
	std::cout << "|a| = " << a.ABS() << std::endl;

	std::cout << " enter Complex b: ";
	std::cin >> b;
	std::cout << "b = " << b << std::endl;
	b.Trg(); std::cout << std::endl;
	std::cout << "|b| = " << b.ABS() << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	try 
	{
		std::cout << "a / b = ";
		std::cout << a / b << std::endl;
	}
	catch (const char* massage)
	{
		std::cerr << std::endl << massage << std::endl;
	}
	std::cout << "a ^ 5 = " << a.POW(5) << std::endl;
	std::cout << "a ^ -2 = " << a.POW(-2) << std::endl;
	std::cout << "a ^ 0.25 = " << a.POW(0.25) << std::endl;;
	std::cout << "a * b = " << a.POW(b) << std::endl;

	return 0;
}