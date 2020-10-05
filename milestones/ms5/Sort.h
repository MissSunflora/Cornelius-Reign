#ifndef SICT_SORT_H
#define SICT_SORT_H

#include <iostream>
#include <cstring>

namespace sict
{
	template<typename T>
	void sort(T* data, int n)
	{
		int i, j;
		T temp;

		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (*data[j] > *data[j + 1]) {
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
}

#endif // !SICT_SORT_H


