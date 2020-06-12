#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "organization.h"

TEST_CASE("Creating and testing Groups and Organizations")
{
    Payer payer1([](unsigned int group_id, unsigned int insurance_id)->bool{ return group_id % insurance_id == 0; }, "Coco");
    Payer payer2([](unsigned int group_id, unsigned int insurance_id)->bool{ return group_id % insurance_id != 0; }, "Momo");

    Group group1("laws", &payer1, 567);
    Institution* inst = new Group("h", &payer2, 10);

    Group group2 = group1;
    CHECK(group1.get_group_id() == 567);
    CHECK(group2.get_group_id() == 567);

    Group group3(group2);
    CHECK(group3.get_group_id() == 567);
    CHECK(group3.get_group_name() == "laws");

    Group g1("name1", nullptr, 125);
    Group g2("name2", &payer1, 120);

    Group g3("name3", nullptr, 555);
    Group g4("name4", &payer2, 80);

    std::vector<Institution*> groups_for_o1 = {&g2, &g3};
    Organization o1("organization A", groups_for_o1, "unknown");
    Organization o2("organization B", {}, "unknown");

    Person p1 = {"John Smith", 40};
    Person p2 = {"Jane Smith", 30};
    Person p3 = {"Erica Smith", 20};

    CHECK((payer1.get_payer_member_rule()(g2.get_group_id(), p1.get_insurance_id())) == 1);
    CHECK((payer1.get_payer_member_rule()(g2.get_group_id(), p2.get_insurance_id())) == 1);
    CHECK((payer1.get_payer_member_rule()(g2.get_group_id(), p3.get_insurance_id())) == 1);

    CHECK((payer2.get_payer_member_rule()(g4.get_group_id(), p1.get_insurance_id())) == 0);
    CHECK((payer2.get_payer_member_rule()(g4.get_group_id(), p2.get_insurance_id())) == 1);
    CHECK((payer2.get_payer_member_rule()(g4.get_group_id(), p3.get_insurance_id())) == 0);

    // g2 обхваща p1, p2, p3;
    // g1 няма застраховател -> тя няма потребители. Същото важи и за g3;
    // g4 обхваща p2;

    std::cout << g2.has_member(p1) << std::endl; // yes
    std::cout << std::endl;

    std::cout << g4.has_member(p1) << std::endl; // no
    std::cout << std::endl;

    Institution* i = find_most_popular_institution({&g4, &g2}, {p1, p2, p3});
    i->print();
    std::cout << std::endl;

    std::vector<Institution*> i_list = clear_institutions({&o1, &o2, &g2, &g4});
    
    // [o1, g2, g4]

    for(Institution* _i: i_list)
    {
        _i->print();
        std::cout << std::endl;
    }
}

int main()
{
    // g++ main.cpp person.cpp payer.cpp institution.cpp group.cpp organization.cpp -o main.exe

    // пускане на тестовете
    doctest::Context().run();



    return 0;
}