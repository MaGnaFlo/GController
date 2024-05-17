#include "gcontroller.hpp"

GController::GController(unsigned short vendor_id, unsigned short product_id)
    : _vendor_id(vendor_id), _product_id(product_id)
{
    hid_init();
}

GController::~GController()
{
    hid_exit();
}

void GController::print_device_info(hid_device_info *info) const
{
    // maybe just exclude USB interface -1
    if (info->interface_number)
        return;
    std::wcout << "##############################################"
               << "\nDevice Vendor ID: " << info->vendor_id
               << "\nDevice Product ID: " << info->product_id
               << "\nDevice Version Number: " << info->serial_number
               << "\nrelease_number: " << info->release_number
               << "\nManufacturer String: " << info->manufacturer_string
               << "\nProduct string: " << info->product_string
               << "\nUsage Page: " << info->usage_page
               << "\nUsage for this Device/Interface: " << info->usage
               << "\nThe USB interface which this logical device represents: " << info->interface_number
               << "\nUnderlying bus type: " << info->bus_type
               << "\n##############################################\n";
}

void GController::enumerate_devices() const
{
    hid_device_info *device = hid_enumerate(0, 0);
    hid_device_info *device_it = device;
    while (device_it)
    {
        print_device_info(device_it);
        device_it = device_it->next;
    }
    hid_free_enumeration(device);
}

bool GController::read(std::vector<unsigned int> &data) const
{
    unsigned char buffer[_buffer_size];
    hid_device *handle = hid_open(_vendorID, _productID, nullptr);
    if (!handle)
    {
        std::cerr << "Unable to open device\n";
        return false;
    }
    hid_read(handle, buffer, _buffer_size);
    for (int i = 0; i < _buffer_size; ++i)
    {
        data.push_back(buffer[i]);
    }
    hid_close(handle);
    return true;
}