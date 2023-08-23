#include <unordered_map>

class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int last_fruit = -1;
        int current_fruit = -1;
        int current_homogenous_size = 1; // How many of the same fruit have there been in a row?
        int start = 0;
        int end = 0;
        int num_fruits = 0;
        int max_num_fruits = 0;
        std::unordered_map<int, bool> hashmap;
        for(int i = 0; i < fruits.size(); i++)
        {
            current_fruit = fruits[i];
            if(hashmap.size() < 2)
            {
                hashmap[current_fruit] = true;
            }
            else if(hashmap[current_fruit] == false)
            {
                num_fruits = end - start;
                if(num_fruits > max_num_fruits)
                {
                    max_num_fruits = num_fruits;
                }
                start = end - current_homogenous_size;
                current_homogenous_size = 1;
                hashmap.clear();
                hashmap[last_fruit] = true;
                hashmap[current_fruit] = true;

            }
            else if(current_fruit == last_fruit)
            {
                current_homogenous_size++;
            }
            else
            {
                current_homogenous_size = 1;
            }
            last_fruit = current_fruit;
            end = i+1;
        }
        num_fruits = end - start;
        if(num_fruits > max_num_fruits)
        {
            max_num_fruits = num_fruits;
        }
        return max_num_fruits;
    }
};
