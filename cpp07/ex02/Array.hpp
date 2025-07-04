#pragma once
#include <iostream>

template <typename T> class Array {
	private:
		T* tab;
		unsigned int len;
	public:
		Array() : tab(NULL), len(0) {};
		Array(unsigned int len) : tab(NULL), len(len) {
			if (len > 0)
				tab = new T[len];
		};
		Array(const Array& other) {
			tab = new T[other.len];
			len = other.len;
			for (unsigned int i = 0; i < other.len; i++)
				tab[i] = other.tab[i];
		};
		Array& operator=(const Array& other) {
			if (this != &other)
			{
				if (other.len != len)
				{
					delete[] tab;
					tab = new T[other.len];
				}
				len = other.len;
				for (unsigned int i = 0; i < len; i++)
					tab[i] = other.tab[i];
			}
			return *this;
		};
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		~Array() { 
			delete[] tab; 
		};
		unsigned int size();
};

#include "Array.tpp"