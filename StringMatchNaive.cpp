// Brute-Froce Algorithm
#include<string>
#include<iostream>
using namespace std;

int BruteForceMatch(string a, string b)
{
	for (int i = 0; i <= a.size() - b.size(); i++)
	{
		int j = 0;
		while (j < b.size() && a[i + j] == b[j])
			j++;

		// match at i
		if (j == b.size())
			return i;
	}

	return -1;
}

int main()
{
	string text;
	string pattern;

	cin >> text;
	cin >> pattern;

	if (BruteForceMatch(text, pattern) == -1)
		cout << "miss match\n";
	else
		cout << "match " << BruteForceMatch(text, pattern) << " index\n";
}