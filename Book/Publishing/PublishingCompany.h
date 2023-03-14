#pragma once
#include <string>
#include "City.h"
#include <iostream>
class PublishingCompany
{
		private:
		std::string name;
		City city;
	public:
		PublishingCompany(std::string name) :name(name){};
		~PublishingCompany();
		friend std::ostream& operator<<(std::ostream& os, const PublishingCompany& publishingCompany);
	
};