#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BitField.h"
#include "Set.h"
/*int main() {
    Set Set(100);
    for (size_t i = 1; i < 100; ++i) {
        Set.InsElem(i); 
    }
    std::vector<uint64_t> primes = Set.GetPrimary();
    std::cout << "Простые числа в множестве: ";
    for (uint64_t prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}