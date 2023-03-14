#include "Person.h"

miit::Person::Person::Person()
{
}


std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << "name: " << person.name << std::endl;
	os << "surname: " << person.surname << std::endl;
	if (person.patronymic != "")
	{
		os << "patronymic: " << person.patronymic << std::endl;
	}
	if (person.prefix != "")
	{
		os << "prefix: " << person.prefix << std::endl;
	}
	if (person.postfix != "")
	{
		os << "postfix: " << person.postfix << std::endl;
	}
	
}

/*std::istream& operator>>(std::istream& is, const Person& person)
{
	is >>  person.name >> std::endl;
	std::cout << "surname: " << person.surname << std::endl;
	if (person.patronymic != nullptr)
	{
		std::cout << "patronymic: " << person.patronymic << std::endl;
	}
	if (person.prefix != nullptr)
	{
		std::cout << "prefix: " << person.prefix << std::endl;
	}
	if (person.postfix != nullptr)
	{
		std::cout << "postfix: " << person.postfix << std::endl;
	}
}*/
