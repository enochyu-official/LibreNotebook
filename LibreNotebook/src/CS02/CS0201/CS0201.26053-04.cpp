#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    for (int element : vec) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}

