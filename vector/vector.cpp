#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z) {}

	Vertex(const Vertex& vertex) // copy operation overload
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)
{

}

int main()
{
	std::vector<Vertex> vertices;
	// add vertice
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });
	// iterate all vertices
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;
	// or easier way like:
	for (Vertex& v : vertices) // add '&' to avoid copying
		std::cout << v << std::endl;
	// erase elememt
	vertices.erase(vertices.begin() + 1);
	std::cout << std::endl;
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;
	// when we need to use a vector in a function
	// remember to pass by reference to avoid copy
	Function(vertices);
	// clear
	vertices.clear();
	std::cout << std::endl;

	// when we push_back elements and the vector array is full,
	// the vector will find a enough space for the vector on the memory,
	// and copy all of these things to the memory, which is a slow operation.
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
	std::cout << std::endl;
	vertices.clear();
	// we can see that we copied the vertices for 6 times.
	// run step by step to see the various capacity of vertices.
	// it is definitily a waste of performance

	// so, why not just tell the compiler: hey, I need 3 blocks of memory,
	// and let it allocate for us directly.
	vertices.reserve(3);
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
	vertices.clear();
	std::cout << std::endl;
	// this time, we can see that we only copied the vertices for 3 times

	// however, that is not enough
	// the vertices are copied for 3 times because they are constructed in the main function
	// and copied to the vector
	// so, why not construct these vertices just in vector.
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	vertices.clear();
	// this time, we can see there is not a single copy at all.

}