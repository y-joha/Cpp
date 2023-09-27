
#include <iostream>
#include "rational.hpp" 

int main()
{
	Rational r1(12, 6);

	Rational r2 = Rational(5, 7);

	Rational r3;

	r3 = r1 + r2;

	if (r3.GetNumenetor() != 19)
	{
		std::cout << "Operator+ failed on line " << __LINE__ 
				  << std::endl;
	}

	if (r3.GetDeNumenetor() != 7)
	{
		std::cout << "Operator+ failed on line " << __LINE__ 
				  << std::endl;
	}

	r1 += r2;

	if (r1.GetNumenetor() != 19)
	{
		std::cout << "Operator+= failed on line " << __LINE__ 
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 7)
	{
		std::cout << "Operator+= failed on line " << __LINE__ 
				  << std::endl;
	}

	r1 = r2 * r2;

	if (r1.GetNumenetor() != 25)
	{
		std::cout << "Operator* failed on line " << __LINE__ 
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 49)
	{
		std::cout << "Operator* failed on line " << __LINE__ 
				  << std::endl;
	}

	r3 = r1 / Rational(1, 7);

	if (r3.GetNumenetor() != 25)
	{
		std::cout << "Operator/ failed on line " << __LINE__ 
				  << std::endl;
	}

	if (r3.GetDeNumenetor() != 7)
	{
		std::cout << "Operator/ failed on line " << __LINE__ 
				  << std::endl;
	}

	r1 = Rational(40, 9) - r3;

	if (r1.GetNumenetor() != 55)
	{
		std::cout << "Operator- failed on line " << __LINE__
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 63)
	{
		std::cout << "Operator- failed on line " << __LINE__
				  << std::endl;
	}

	if (!(Rational(2, 4) == Rational(1, 2)))
	{
		std::cout << "Operator== failed on line " << __LINE__
				  << std::endl;
	}

	if (r1 == r3)
	{
		std::cout << "Operator== failed on line " << __LINE__
				  << std::endl;
	}

	if ((Rational(2, 4) != Rational(1, 2)))
	{
		std::cout << "Operator!= failed on line " << __LINE__
				  << std::endl;
	}

	if (!(r1 != r3))
	{
		std::cout << "Operator!= failed on line " << __LINE__
				  << std::endl;
	}

	r1 -= Rational(1);

	if (r1.GetNumenetor() != -8)
	{
		std::cout << "Operator-= failed on line " << __LINE__
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 63)
	{
		std::cout << "Operator-= failed on line " << __LINE__
				  << std::endl;
	}

	r1 *= Rational(9, 8);

	if (r1.GetNumenetor() != -1)
	{
		std::cout << "Operator*= failed on line " << __LINE__
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 7)
	{
		std::cout << "Operator*= failed on line " << __LINE__
				  << std::endl;
	}

	r1 /= Rational(3, 14);

	if (r1.GetNumenetor() != -2)
	{
		std::cout << "Operator/= failed on line " << __LINE__
				  << std::endl;
	}

	if (r1.GetDeNumenetor() != 3)
	{
		std::cout << "Operator/= failed on line " << __LINE__
				  << std::endl;
	}

	/* Rational r5(1, 0); */

	r1 = 7 + Rational(5, 3);

	if (26 != r1.GetNumenetor())
	{
		std::cout << "Operator+ (symmetry) failed on line " << __LINE__
				  << std::endl;
	}

	r1 = 7 / r1;

	if (21 != r1.GetNumenetor())
	{
		std::cout << "Operator/ (symmetry) failed on line " << __LINE__
				  << std::endl;
	}

	return 0;
}
