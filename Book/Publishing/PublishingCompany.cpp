#include "PublishingCompany.h"
std::ostream& operator<<(std::ostream& os, const PublishingCompany& publishingCompany)
{
	os << "name: " << publishingCompany.name << std::endl;
}

PublishingCompany::~PublishingCompany()
{
}
