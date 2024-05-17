#include <iostream>
#include <wchar.h>
#include <hidapi.h>
#include <vector>

class GController
{
public:
    GController() = default;
    GController(unsigned short vendor_id, unsigned short product_id);
    ~GController();

    /**
     * @brief Buffer size as defined per the USB standard, which is 63+1 bytes.
     * @return Buffer size.
     */
    size_t buffer_size() const { return _buffer_size; }

    /**
     * @brief Set the vendor id.
     * @param vendor_id
     */
    void set_vendor_id(unsigned short vendor_id) { _vendor_id = vendor_id; }

    /**
     * @brief Set the product id.
     * @param product_id
     */
    void set_product_id(unsigned short product_id) { _product_id = product_id; }

    /**
     * @brief Prints the device info.
     * @param info The device info.
     */
    static void print_device_info(hid_device_info *info) const;

    /**
     * @brief Prints all devices. Useful to identify the controller.
     */
    static void enumerate_devices() const;

    /**
     * @brief Reads the device input buffer and stores the data as a vector of unsigned integers.
     * @param data The resulting data gathered from the buffer reading.
     * @return The reading status. False if failed.
     */
    bool read(std::vector<unsigned int> &data) const;

private:
    //!< vendor ID. Can be found using enumerate_devices.
    int _vendor_id;
    //!< Product ID. Can be found using enumerate_devices.
    int _product_id;
    //!< USB buffer size (number of bytes).
    static constexpr int _buffer_size = 65;
};