#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum e_type
{
	CLASS_A,
	CLASS_B,
	CLASS_C
};

Base *generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
	case CLASS_A:
		return new A();
		break;
	case CLASS_B:
		return new B();
		break;
	case CLASS_C:
		return new C();
		break;
	default:
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
}