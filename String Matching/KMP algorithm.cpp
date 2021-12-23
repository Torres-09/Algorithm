#include<iostream>
#include<string>
using namespace std;

void FailureFunction(string pattern, int* F)
{
	F[0] = 0;
	int i = 1;
	int j = 0;

	while (i < pattern.size())
	{
		if (pattern[i] == pattern[j])
		{
			F[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = F[j - 1];
		else
		{
			F[j] = 0;
			i++;
		}
	}
}

int KMPmatch(string text, string pattern)
{
	int n = text.size();
	int m = pattern.size();
	int* f = new int[m];
	FailureFunction(pattern, f);

	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (text[i] == pattern[j])
			if (j == m - 1)
				return i - j;
			else
			{
				i++;
				j++;
			}
		else
		{
			if (j > 0)
				j = f[j - 1];
			else
				i++;
		}
	}

	return -1;
}

int main()
{
	string text;
	string pattern;
	cin >> text;
	cin >> pattern;
	cout << KMPmatch(text, pattern) << "\n";
}