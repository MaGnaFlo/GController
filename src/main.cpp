#include <iostream>
#include <vector>
#include "gcontroller.hpp"

int main()
{
    constexpr unsigned short vendor_id {0x0079};
    constexpr unsigned short product_id {0x0006};
    GController gctrl(vendor_id, product_id);
    // GController::enumerate_devices();
    for (;;)
    {
        std::vector<unsigned int> data;
        if (gctrl.read(data))
        {
            for (const auto &val : data)
            {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}