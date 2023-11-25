#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void f()
{
	system("leaks ex01");
}

int main(void)
{
	atexit(f);
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	std::cout << std::endl;

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::string str2;
	std::cout << std::endl;
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	d->getBrain()->setIdea(0, "new idea");
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	*d2 = *d;
	std::cout << "Dog2's first idea is " << d2->getBrain()->getIdea(0) << std::endl;
	d2->getBrain()->setIdea(0, "new idea2");
	str = d->getBrain()->getIdea(0);
	str2 = d2->getBrain()->getIdea(0);
	std::cout << "Dog1's second idea is " << str << std::endl;
	std::cout << "Dog2's second idea is " << str2 << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	return 0;
}