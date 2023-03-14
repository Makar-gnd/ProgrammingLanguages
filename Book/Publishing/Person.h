#pragma once
#include <iostream>
#include <string>
class Person
{
	private:
		std::string name;
		std::string surname;
		std::string patronymic;
		std::string prefix;
		std::string postfix;
	public:
		Person(std::string name, std::string surname, std::string patronymic = "",
			std::string prefix = "", std::string postfix = "") :name(name), surname(surname), patronymic(patronymic),
			prefix(prefix), postfix(postfix) {};
		~Person();
		friend std::ostream& operator<<(std::ostream& os, const Person& person);
		friend std::istream& operator>>(std::istream& is, const Person& person);
};