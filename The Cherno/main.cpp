#include <iostream>
//#include "Log.h"
#include <string>


class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName() {return "Entity";}
    std::string GetClassName() override {return "Entity";}
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}
    std::string GetName() override { return m_Name;}
    std::string GetClassName() override {return "Player";}
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetClassName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}
int main()
{
    std::string n = "hi";
    std::cout << n << std::endl;
    return 0;
}
