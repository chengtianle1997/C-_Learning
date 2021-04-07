#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName()
{
	return "Tommy";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	int a = 5;
	auto b = a;
	auto c = 5L;
	auto d = 5.5f;
	auto e = "Tommy";
	std::cin.get();  // Set a break point here, and see the actual type of b, c, d, e

	auto name = GetName();
	std::cout << name << std::endl;

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	// instead of writing 'std::vector<std::string>::iterator' type, we can use 'auto'
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	DeviceManager dm;
	// we can simplify the code by 'using'
	using DeviceMap_using = std::unordered_map<std::string, std::vector<Device*>>;
	const DeviceMap_using& devices_using = dm.GetDevices();
	// we can simplify the code by 'typedef'
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap_typedef;
	const DeviceMap_typedef& devices_typedef = dm.GetDevices();
	// however, by using 'auto'
	const auto& devices_auto = dm.GetDevices();
	// remember to use reference '&' here, because we do not want to copy the variable

}