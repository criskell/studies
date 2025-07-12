#include <print>
#include <vector>
#include <queue>

void bfs(int begin, const std::vector<std::vector<int>> &graph)
{
  int n = graph.size();
  std::vector<bool> visited(n, false);
  std::queue<int> queue_;

  queue_.push(begin);
  visited[begin] = true;

  while (!queue_.empty())
  {
    int current = queue_.front();
    queue_.pop();

    for (int neighbour : graph[current])
    {
      if (!visited[neighbour])
      {
        queue_.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }
}

int main()
{
  std::vector<std::vector<int>> graph = {{1, 2},
                                         {0, 3},
                                         {0},
                                         {1, 4},
                                         {3}};

  std::println("Breadth-First Search");
  bfs(0, graph);
}