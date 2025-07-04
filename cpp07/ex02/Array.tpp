#pragma once

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= len)
		throw std::out_of_range("OOB");
	return tab[i];
};

template <typename T>
unsigned int Array<T>::size() {
	return len;
};