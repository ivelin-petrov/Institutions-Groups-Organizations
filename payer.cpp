#include "payer.h"

Payer::Payer(std::function<bool (unsigned int, unsigned int)> _payer_member_rule, const std::string _payer_name)
    : payer_member_rule(_payer_member_rule), payer_name(_payer_name) {}

Payer::Payer(const Payer& other) : payer_member_rule(other.payer_member_rule), payer_name(other.payer_name) {}

Payer& Payer::operator = (const Payer& other)
{
    if(this != &other)
    {
        payer_member_rule = other.payer_member_rule;
        payer_name = other.payer_name;
    }
    return *this;
}

Payer::~Payer() {}

std::string Payer::get_payer_name() const { return this->payer_name; }

std::function<bool (unsigned int, unsigned int)> Payer::get_payer_member_rule() { return this->payer_member_rule; }