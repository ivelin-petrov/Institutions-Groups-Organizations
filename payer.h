#ifndef PAYER_H_
#define PAYER_H_

#include <iostream>
#include <string>
#include <functional>

class Payer
{ 
  private:
    std::function<bool (unsigned int, unsigned int)> payer_member_rule;
    std::string payer_name;

  public:
    Payer(std::function<bool (unsigned int, unsigned int)> _payer_member_rule, const std::string _payer_name = "Unknown");
    Payer(const Payer& other);
    Payer& operator = (const Payer& other);
    ~Payer();

    std::string get_payer_name() const;
    std::function<bool (unsigned int, unsigned int)> get_payer_member_rule();
};

#endif // PAYER_H_