#include<iostream>
#include<vector>
using namespace std;
const int n = 1024;
vector<int> graph[n];
bool visit[n];

void DFS(int start)
{
	visit[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visit[graph[start][i]] == false)
			DFS(graph[start][i]);
	}
}