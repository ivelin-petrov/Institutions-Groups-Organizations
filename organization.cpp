#include "organization.h"

Organization::Organization(const std::string _institution_name, const std::vector<Institution*> _institution_list, 
                           const std::string _organization_address)
                            : Institution(_institution_name), institution_list(_institution_list), 
                              organization_address(_organization_address) {}

Organization::Organization(const Organization& other) : Institution(other.institution_name),
                institution_list(other.institution_list), organization_address(other.organization_address) {}

Organization& Organization::operator = (const Organization& other)
{
    if(this != &other)
    {
        Institution::operator=(other);
        institution_list = other.institution_list; 
        organization_address = other.organization_address;
    }
    return *this;
}

Organization::~Organization() {}

bool Organization::has_member(Person& person)
{
    // bool found = false;

    for(int i = 0; i < institution_list.size(); ++i)
    {
        if(this->institution_list[i]->has_member(person) == 1)
        {
            return true;
        }
    }

    return false;
}

Payer* Organization::most_common_payer(const std::vector<Payer*>& _payers)
{
    int max_count = 0;
    int current_count = 0;
    int save_position = 0;

    for(int i = 0; i < _payers.size(); ++i)
    {
        for(int j = 0; j < _payers.size(); ++j)
        {
            if(_payers[i] == _payers[j])
            {
                ++current_count;
            }
        }
        if(max_count < current_count)
        {
            max_count = current_count;
            save_position = i;
        }
    }
    return _payers[save_position];
}

Payer* Organization::payer()
{
    std::vector<Payer*> all_payers;

    for(int i = 0; i < institution_list.size(); ++i)
    {
        all_payers.push_back(this->institution_list[i]->payer());
    }

    return most_common_payer(all_payers);
}

bool Organization::valid()
{
    bool valid = false;

    for(int i = 0; i < institution_list.size(); ++i)
    {
        if(this->institution_list[i]->valid() == 1)
        {
            return true;
        }
    }

    return false;
}

bool Organization::compatible(Organization& other)
{
    return (this->payer() == other.payer());
}

void Organization::add_institution(Institution*& other)
{
    if(this->payer() == other->payer() && other->valid() == 1)
    {
        this->institution_list.push_back(other);
    }
    else if(other->valid() == 1)
    {
        this->institution_list.push_back(other);
    }
}

void Organization::add_institution(Institution*& other, bool add)
{
    if(add == 1)
    {
        this->institution_list.push_back(other);
    }
}

Institution* find_most_popular_institution(std::vector<Institution*> list, std::vector<Person> people)
{
    int most_popular = 0;
    int current_counter = 0;
    int save_index = 0;
    for(int i = 0; i < list.size(); ++i)
    {
        for(int j = 0; j < people.size(); ++j)
        {
            if(list[i]->has_member(people[j]) == 1)
            {
                ++current_counter;
            }
        }
        if(most_popular < current_counter)
        {
            most_popular = current_counter;
            save_index = i;
        }
    }
    return list[save_index];
}

std::vector<Institution*> clear_institutions(std::vector<Institution*> list)
{
    std::vector<Institution*> result;

    for(int i = 0; i < list.size(); ++i)
    {
        if(list[i]->valid() == 1)
        {
            result.push_back(list[i]);
        }
    }

    return result;
}

void Organization::print()
{
    std::cout << "Organization" << std::endl;
    std::cout << "Name: " << this->institution_name << std::endl;
    std::cout << "Address: " << this->organization_address << std::endl;
}