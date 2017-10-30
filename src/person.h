#ifndef _PERSON_H
#define _PERSON_H

#include <string>

class Person {
    public:
        Person(std::string, int, std::string);

        void toggle_active();
        std::string name();
        int id();
        std::string phone();
        bool isActive();

    private:
        std::string _name;
        std::string _phone;
        const int _id;
        bool _active = true;
};
#endif
