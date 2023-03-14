#pragma once
#include <set>
#include <string>
#include "Person.h"
#include "PublishingCompany.h"
class Book
{
	public:
		
    private:
		std::set < Person > Authors;
		std::string Title;
		std::size_t ImprintDate;
		PublishingCompany publishingCompany;
};
