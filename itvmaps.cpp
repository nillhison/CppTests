#include <typeinfo>
#include <iostream>
#include <algorithm>

#include <map>
#include <unordered_map>

template <typename T>
void print(const T& mp) {
    std::cout << "PRINTING DATA IN A " << typeid(mp).name() << " CONTAINER" << std::endl;

    std::cout << "------ Using std::for_each ------" << std::endl;
    std::for_each(mp.begin(), mp.end(), [](std::pair<std::string, std::string> p) {
      std::cout << p.first << ": " << p.second << std::endl;
    } );
    std::cout << "------ Using For loop ------" << std::endl;
    for(auto& [key, value] : mp) {
        std::cout << key << ": " << value << std::endl;
    };
    std::cout << "------ Using tailored routine ------" << std::endl;
    auto it = mp.begin();
    while (it != mp.end()) {
        std::cout << it->first << ": " << it->second << std::endl;
        ++it;
    }
}

int main() {

    const std::map<std::string, std::string> moons_in_map = {
        {"Callisto", "Jupyter"},
        {"Moon", "Earth"},
        {"Miranda", "Uranus"},
        {"Deimos", "Mars"}
    };

    const std::unordered_map<std::string, std::string> moons_in_umap = {
        {"Callisto", "Jupyter"},
        {"Moon", "Earth"},
        {"Miranda", "Uranus"},
        {"Deimos", "Mars"}
    };

    print(moons_in_map);
    print(moons_in_umap);

}