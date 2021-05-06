// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

// Install PVS-Studio in "Extensions" or search for it directly in our browser.
// Use the free liscence:
// Extensions -> PVS-Studio -> Options -> Registration
// Name: PVS-Studio Free
// Key: FREE-FREE-FREE-FREE

// If you are using PVS-Studio for Linux/macOS, use the following command:
// pvs - studio - analyzer credentials PVS - Studio Free FREE - FREE - FREE - FREE

struct Entity {};

Entity* LoadEntity()
{
	return nullptr;
}

int main()
{
	const char* string = "Hello";
	char* buffer_s = new char[strlen(string)]; // true: strlen(string) + 1, because there is a '\0' after "Hello"¡¢
	memcpy(buffer_s, string, strlen(string));
	strcpy_s(buffer_s, strlen(string) + 1, string);

	uint32_t width = 800, height = 600;
	uint32_t* buffer = new uint32_t[width * height];
	for (uint32_t y = 0; y < height; y++)
		for (uint32_t x = 0; x < width; y++) // true: x++
			buffer[x + y * width] = 0;

	Entity* entity = LoadEntity(); // entity here is always nullptr
	if (entity)
	{

	}

	// Static Analysis:
	// Extensions -> PVS-Studio -> Check Current File
	// See the message from PVS-Studio
}