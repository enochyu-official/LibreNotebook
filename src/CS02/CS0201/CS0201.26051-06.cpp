#include <iostream>

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << "Banana " << i+1 << " and "
                      << "Apple " << j+1 << std::endl;
        }
    }

    return 0;
}

