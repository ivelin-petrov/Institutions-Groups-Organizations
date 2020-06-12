#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
  private:
    std::string person_name;
    unsigned int insurance_id;

  public:
    Person(const std::string _person_name = "Unknown", int _insurance_id = 0);
    Person(const Person& other);
    Person& operator = (const Person& other);
    ~Person();

    bool operator == (const Person& other);

    std::string get_person_name() const;
    unsigned int get_insurance_id() const;
};

#endif // PERSON_H_