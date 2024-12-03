// main.cpp

#include "FixedBlockMemoryResource.h"
#include "PmrList.h"
#include <iostream>
#include <string>

struct ComplexType
{
    int id;
    std::string name;

    ComplexType(int id, std::string name) : id(id), name(std::move(name)) {}

    friend std::ostream &operator<<(std::ostream &os, const ComplexType &obj)
    {
        os << "ID: " << obj.id << ", Name: " << obj.name;
        return os;
    }
};

int main()
{
    FixedBlockMemoryResource memory_resource(1024, 10240);

    PmrList<int> int_list(&memory_resource);
    int_list.push_back(10);
    int_list.push_back(20);
    int_list.push_back(30);

    std::cout << "Container with ints:\n";
    for (const auto &val : int_list)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    PmrList<ComplexType> complex_list(&memory_resource);
    complex_list.push_back(ComplexType(1, "Alice"));
    complex_list.push_back(ComplexType(2, "Bob"));
    complex_list.push_back(ComplexType(3, "Charlie"));

    std::cout << "Container with complex types:\n";
    for (const auto &val : complex_list)
    {
        std::cout << val << "\n";
    }

    return 0;
}
