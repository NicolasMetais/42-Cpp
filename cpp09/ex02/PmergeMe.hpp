#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>
#include <ctime>

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		const PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void printValues(std::vector<int>& tab);
		void parseValues(char **arv);
		void insertValues(int num);
		void sort();
		template <typename T>
		void FordJohnson(T& tab) {
			if (tab.size() <= 1)
				return ;

			T higher;
			T lower;

			for (size_t i = 0; i + 1 < tab.size(); i+= 2)
			{
				if (tab[i] > tab[i + 1])
				{
					higher.push_back(tab[i]);
					lower.push_back(tab[i + 1]);
				}
				else
				{
					lower.push_back(tab[i]);
					higher.push_back(tab[i + 1]);
				}
			}
			if (tab.size() % 2 != 0) {
				higher.push_back(tab.back());
			}
			FordJohnson(higher);
			for (typename T::iterator it_low = lower.begin(); it_low != lower.end(); ++it_low)
			{
				typename T::iterator it = std::lower_bound(higher.begin(), higher.end(), *it_low);
				higher.insert(it, *it_low);
			}
			tab = higher;
		};
};