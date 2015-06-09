#pragma once
#include <string>

using namespace std;
struct Sportsman
{
	string name;
	unsigned height;
	unsigned weight;
};

template <typename T, typename Comp = std::less<T>>
bool FindMaxEx(std::vector<T> const& arr, T &maxValue, Comp const& comp = std::less<T>())
{
	if (arr.empty())
	{
		return false;
	}

	size_t max = 0;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (comp(arr[max], arr[i]))
		{
			max = i;
		}
	}
	maxValue = arr[max];
	return true;
}