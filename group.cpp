#include "group.h"

Group::Group(const std::string _institution_name, Payer* _group_payer, unsigned int _group_id)
        : Institution(_institution_name), group_payer(nullptr), group_id(_group_id)
{
    group_payer = _group_payer;
}

Group::Group(const Group& other) : Institution(other), group_payer(nullptr), group_id(other.group_id)
{
    group_payer = other.group_payer;
}

Group& Group::operator = (const Group& other)
{
    if(this != &other)
    {
        Institution::operator=(other);
        group_payer = other.group_payer;
        group_id = other.group_id;
    }
    return *this;
}

unsigned int Group::get_institution_id() const
{
    return this->institution_id;
}

unsigned int Group::get_group_id() const
{
    return this->group_id;
}

std::string Group::get_group_name() const
{
    return this->institution_name;
}

bool Group::has_member(Person& person)
{
    Payer payer = *group_payer;
    return !(payer.get_payer_member_rule()(person.get_insurance_id(), group_id));
}

Payer* Group::payer() { return this->group_payer; }

bool Group::valid()
{
    return (this->group_payer != nullptr);
}

void Group::print()
{
    std::cout << "Group" << std::endl;
    std::cout << "Name: " << this->institution_name << std::endl;
    std::cout << "ID: " << this->group_id << std::endl;
}