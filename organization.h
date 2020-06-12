#ifndef ORGANIZATION_H_
#define ORGANIZATION_H_

#include "group.h"

class Organization : public Institution
{
  private:
    std::vector<Institution*> institution_list;
    std::string organization_address;

  public:
    Organization(const std::string _institution_name, const std::vector<Institution*> _institution_list = {}, 
                 const std::string _organization_address = "Unknown");
    Organization(const Organization& other);
    Organization& operator = (const Organization& other);
    ~Organization();

    bool has_member(Person& person);
    Payer* most_common_payer(const std::vector<Payer*>& _payers);
    Payer* payer();
    bool valid();
    bool compatible(Organization& other);

    void add_institution(Institution*& other);
    void add_institution(Institution*& other, bool add);

    void print();
};

Institution* find_most_popular_institution(std::vector<Institution*> list, std::vector<Person> people);
std::vector<Institution*> clear_institutions(std::vector<Institution*> list);

#endif // ORGANIZATION_H_