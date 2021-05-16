#include <iostream>
#include <array>

template<typename T, size_t S>
class Array {
public:
	Array()
	{
		// m_Data = (int*)alloca(size * sizeof(int));
	}
	// The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.
	constexpr int size() const
	{
		return S;
	}
	// index operator: use reference here for assignment like: array[i] = 2;
	T& operator[](size_t index)
	{
		if (!(index < S))
			__debugbreak();
		return m_Data[index];
	}
	// const index operator
	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}
	
	T* data()
	{
		return m_Data;
	}
	const T* data() const
	{
		return m_Data;
	}

private:
	// int* m_Data;
	T m_Data[S];
};

int main()
{
	std::array<int, 10> collection;

	Array<int, 10> data;
	std::cout << data.size() << std::endl;
	// static_assert(data.size() < 10, "Size is too large!");
	static_assert(data.size() < 100, "Size is too large!");
	const auto& data_const = data;
	// iterate index
	for (int i = 0; i < data.size(); i++)
	{
		// data_const[i] = i; // this will cause an error.
		data[i] = i;
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	// data[20] = 4;  // debugbreak

	// without data() function, we do like:
	memset(&data[0], 0, data.size() * sizeof(int));
	// with data() function:
	memset(data.data(), 0, data.size() * sizeof(int));

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

}