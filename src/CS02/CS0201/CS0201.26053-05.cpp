#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    vec.push_back(6);
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << vec.size() << "\n";

    vec.pop_back();
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << vec.size() << "\n";

    return 0;
}

