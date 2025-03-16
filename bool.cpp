#include <vector>
#include <iostream>

int main() {
    std::vector<char> boolVector;
    
    // Adding elements to the vector
    boolVector.push_back(true);
    boolVector.push_back(false);
    boolVector.push_back(true);
    boolVector.push_back(false);

    // Printing the elements of the vector
    for (size_t i = 0; i < boolVector.size(); ++i) {
        std::cout << "Element at index " << i << " is " << (bool)boolVector[i] << std::endl;
    }

    return 0;
}