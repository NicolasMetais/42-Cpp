#include <Serialize.hpp>

Serialize::Serialize() {};

Serialize::Serialize(Serialize& other) {
	(void)other;
};

Serialize& Serialize::operator=(Serialize& other) {
	(void)other;
	return *this;
};

Serialize::~Serialize() {};

uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}




