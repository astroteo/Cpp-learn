#include <iostream>
#include <string>

class TextInput
{
public:
    void add(char c) { }

    std::string getValue() { return NULL; }
};

class NumericInput : public TextInput { };

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif
