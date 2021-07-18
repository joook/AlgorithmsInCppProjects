#include <iostream>
#include <cstdint>
#include <string>

#include "stack.h"
#include "stack_itr.h"

int main(int argc, char* argv[])
{
    Stack<std::string> s;
    s.push("ab");
    s.push("cd");
    s.push("ef");
    s.push("gh");
    std::cout << "The size of the stack is " << s.size() << std::endl;
    std::cout << "It has: ";
    for (auto item : s)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    Stack<std::int16_t> s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    std::cout << "The size of the stack is " << s2.size() << std::endl;
    std::cout << "It has: ";
    while (!s2.isEmpty())
    {
        auto item = s2.pop();
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}

