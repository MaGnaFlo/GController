#include <iostream>
#include <wchar.h>
#include <hidapi.h>
#include <vector>

class GController
{
public:
    GController() = default;
	GController(unsigned short vendorID, unsigned short productID);
    ~GController();

    /**
     * @brief Prints the device info.
     * @param info The device info.
    */
	static void print_device_info(hid_device_info* info);
	/**
	 * @brief Prints all devices. Useful to identify the controller.
	*/
	static void enumerate_devices();
    /**
     * @brief Reads the device input buffer and stores the data as a vector of unsigned integers.
     * @param data The resulting data gathered from the buffer reading.
     * @return The reading status. False if failed.
    */
	bool read(std::vector<unsigned int>& data);
    /**
     * @brief Buffer size as defined per the USB standard, which is 63+1 bytes.
     * @return Buffer size.
    */
    size_t buffer_size() const {return _buffer_size;}

private:
    //!< vendor ID. Can be found using enumerate_devices.
	int _vendorID;
    //!< Product ID. Can be found using enumerate_devices.
	int _productID;
    //!< USB buffer size (number of bytes).
	static constexpr int _buffer_size = 65;
};