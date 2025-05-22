#include <iostream>
#include <map>

std::map<std::string, std::map<std::string, int>> students = {
    {"mamaefalei", {{"biologia", 10}, {"quimica", 9}}},
    {"guerreiro de kiev", {{"fisica", 10}, {"quimica", 9}}},
};

int main()
{
    for (auto outer_it = students.begin(); outer_it != students.end(); ++outer_it)
    {
        if (outer_it != students.begin())
        {
            std::cout << std::endl;
        }

        std::cout << "nome: " << outer_it->first << std::endl;

        for (auto inner_it = outer_it->second.begin(); inner_it != outer_it->second.end(); ++inner_it)
        {
            std::cout << "matéria: " << inner_it->first << " = " << inner_it->second << std::endl;
        }
    }
}