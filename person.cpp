#include "person.h"

Person::Person(const std::string _person_name, int _insurance_id)
        : person_name(_person_name), insurance_id(_insurance_id) {}

Person::Person(const Person& other) : person_name(other.person_name), insurance_id(other.insurance_id) {}

Person& Person::operator = (const Person& other)
{
    if(this != &other)
    {
        person_name = other.person_name;
        insurance_id = other.insurance_id;
    }
    return *this;
}

Person::~Person() {}

bool Person::operator == (const Person& other)
{
    return (person_name == other.person_name && insurance_id == other.insurance_id);
}

std::string Person::get_person_name() const { return this->person_name; }
unsigned int Person::get_insurance_id() const { return this->insurance_id; }