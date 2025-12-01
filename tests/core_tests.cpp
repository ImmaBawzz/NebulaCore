#include <iostream>
#include <cassert>
#include "../engine/core/Application.h"

void TestApplicationInit() {
    nebula::Application app;
    // Just verifying it compiles and links for now
    std::cout << "TestApplicationInit Passed" << std::endl;
}

int main() {
    TestApplicationInit();
    return 0;
}
