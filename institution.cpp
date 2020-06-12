#include "institution.h"

int institutions_made = 0;

Institution::Institution(const std::string _institution_name)
    : institution_name(_institution_name)
{
    ++institutions_made;

    institution_id = institutions_made;
}

Institution::Institution(const Institution& other) : institution_name(other.institution_name)
{
    ++institutions_made;

    institution_id = institutions_made;
}

Institution& Institution::operator = (const Institution& other)
{
    if(this != &other)
    {
        ++institutions_made;

        institution_id = institutions_made;
        institution_name = other.institution_name;
    }
    return *this;
}