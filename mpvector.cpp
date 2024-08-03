#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
void parsed_function(T* pointer_to_T) {
    auto it = std::find(entity.begin(), entity.end(), pointer_to_T);
    std::cout << "Element " << std::distance(entity.begin(), it) + 1 << " from the vector:" << std::endl;
    for (const auto& [key, value] : *pointer_to_T)
    {
        std::cout << key << ": " << value << std::endl;
    };
    std::cout << "---------------------" << std::endl;
}

template<typename T>
class VCPort
{
    public:
        void add(T* value) {
            entity.push_back(value);
        }
        void print_with_lambda_funtion() {
            std::for_each(entity.begin(), entity.end(), [&](T* pointer_to_T) {
                auto it = std::find(entity.begin(), entity.end(), pointer_to_T);
                std::cout << "Element " << std::distance(entity.begin(), it) + 1 << " from the vector:" << std::endl;
                for (const auto& [key, value] : *pointer_to_T)
                {
                    std::cout << key << ": " << value << std::endl;
                };
                std::cout << "---------------------" << std::endl;
            });
        }
        void print_with_parsed_function() {
            std::for_each(entity.begin(), entity.end(), parsed_function);
        }
        void print_with_inner_function() {
            std::for_each(entity.begin(), entity.end(), parsed_function);
        }
    private:
        std::vector<T*> entity;

};

int main()
{
    
    std::cout << "---------------------" << std::endl;

    std::vector<std::map<std::string, std::string>> vector_of_maps = {
        {{"CPU", "Hardware"}},
        {{"Keyboard", "Hardware"}},
        {{"EFI", "Software"}},
        {{"RAM", "Hardware"}},
        {{"Grub", "Software"}}
    };

    VCPort<std::map<std::string, std::string>> vector_of_pointers_to_map;
    
    for(auto& map : vector_of_maps)
    {
        vector_of_pointers_to_map.add(&map);
    };
    
    vector_of_pointers_to_map.print_with_lambda_funtion();
    
    std::map<std::string, std::string> new_maps { {"Server", "Software"}, {"Server", "Hardware"}, {"Server", "Mainframe"} };
    
    vector_of_maps.push_back(new_maps);
    
    vector_of_pointers_to_map.add(&(vector_of_maps.back()));
    
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
    
    vector_of_pointers_to_map.print_with_lambda_funtion();
    
    
    return 0;
}