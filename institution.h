#ifndef INSTITUTION_H_
#define INSTITUTION_H_

#include <vector>

#include "person.h"
#include "payer.h"

class Institution
{
  protected:
    unsigned int institution_id;
    std::string institution_name;

  public:
    Institution(const std::string _institution_name = "Unknown");
    Institution(const Institution& other);
    Institution& operator = (const Institution& other);
    ~Institution() {}

    virtual bool has_member(Person& person) = 0;
    virtual Payer* payer() = 0;
    virtual bool valid() = 0;

    virtual void print() = 0;
};

#endif // INSTITUTION_H_