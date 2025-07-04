#pragma once
#include <stdint.h>
#include <Data.hpp>
#include <iostream>

class Serialize {
	public:
		Serialize();
		Serialize(Serialize& other);
		Serialize& operator=(Serialize& other);
		~Serialize();
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};