#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
    
    static const unsigned int vector_size = 2;
    static const unsigned int lower_bd = 1;
    static const unsigned int upper_bd = vector_size;
    
    unsigned int tmp_number;
    
    std::vector<unsigned int> numbers;
    
    while(numbers.size() < vector_size) {
        do {
           tmp_number = std::rand() % (upper_bd - lower_bd + 1) + lower_bd;
        } while(std::count(numbers.begin(), numbers.end(), tmp_number));
        
        numbers.push_back(tmp_number);
    };

    std::cout << "UNSORTED VECTOR" << std::endl;
    for(auto& elem : numbers) {
        std::cout << elem << std::endl;
    };
    
    std::sort(numbers.begin(), numbers.end());
    
    std::cout << "SORTED VECTOR" << std::endl;
    for(auto& elem : numbers) {
        std::cout << elem << std::endl;
    };

    return 0;
}