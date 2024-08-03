#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
std::vector<T>** merge_vectors(std::vector<T> first_vector, std::vector<T> second_vector)
{
	static std::vector<T>* merged = new std::vector<T>;

	merged->assign(first_vector.begin(), first_vector.end());

	for(auto& elem : second_vector)
	{
		auto it = std::find(merged->begin(), merged->end(), elem);

		if(it == merged->end())
		{
			merged->push_back(elem);
		} else continue;
	}
	
	return &merged;

}

int main()
{

	const std::vector<int> v1 = {0, 1, 5, 9, 11, 18, 23};
	const std::vector<int> v2 = {2, 5, 6, 14, 23};
	
	std::vector<int>** vm = merge_vectors(v1, v2);
	
	std::sort((*vm)->begin(), (*vm)->end());

	for(auto& elem : **vm)
	{
		std::cout << elem << std::endl;
	}
    
	delete *vm;

}