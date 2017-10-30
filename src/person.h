#ifndef _PERSON_H
#define _PERSON_H

#include <string>

class Person {
    public:
        Person(std::string, int, std::string) {}
        void toggle_active();

    private:
        std::string _name;
        int _id;
        std::string _phone;
        bool _active = true;
}