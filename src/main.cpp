#include "sample_project/ipv4.h"
#include <iostream>

auto main() -> int {
    using namespace sample_project;
    std::cout << ipv4::unspecified() << "\n";
    return 0;
}
