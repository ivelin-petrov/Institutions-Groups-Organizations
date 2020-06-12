#ifndef GROUP_H_
#define GROUP_H_

#include "institution.h"

class Group : public Institution
{
  private:
    Payer* group_payer;
    unsigned int group_id;

  public:
    Group(const std::string _institution_name, Payer* _group_payer = nullptr, unsigned int _group_id = 0);
    Group(const Group& other);
    Group& operator = (const Group& other);
    //~Group();

    unsigned int get_institution_id() const;
    unsigned int get_group_id() const;

    std::string get_group_name() const;

    bool has_member(Person& person);
    Payer* payer();
    bool valid();

    void print();
};

#endif // GROUP_H_