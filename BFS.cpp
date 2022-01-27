#include<queue>
#include<vector>
using namespace std;
const int n = 1024;
queue<int> q;
vector<int> graph[n];
bool visit[n];

void BFS(int start)
{
	visit[start] = true;
	q.push(start);

	while (!q.empty())
	{
		start = q.front();
		q.pop();

		for (int i = 0; i < graph[start].size(); i++)
		{
			if (visit[graph[start][i]] == false)
			{
				visit[graph[start][i]] = true;
				q.push(graph[start][i]);
			}
		}
	}
}