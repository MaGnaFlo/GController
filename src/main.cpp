#include <iostream>
#include <vector>
#include "gcontroller.hpp"

int main()
{
    constexpr unsigned short vendorID {0x0079};
	constexpr unsigned short productID {0x0006};
    GController gctrl(vendorID, productID);
    GController::enumerate_devices();
    for (;;) {
        std::vector<unsigned int> data;
        if (gctrl.read(data)) {
            for (const auto& val : data) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}