#include <iostream>

int main() {
    int intValue = 42;
    size_t sizeTValue = {intValue};
    // size_t sizeTValue = static_cast<size_t>(intValue);

    std::cout << "int value: " << intValue << std::endl;
    std::cout << "size_t value: " << sizeTValue << std::endl;

    return 0;
}