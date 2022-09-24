#include <iostream>
#include <queue>
#include <string>
#include <tuple>

int main() {
  using item_type = std::pair<int, std::string>;
  std::priority_queue<item_type> q;
  std::initializer_list<item_type> il {
    {0, "Play games"},
    {1, "Wash dishes"},
    {0, "Read book"},
    {2, "Do homework"}
  };

  for (const auto &p : il) {
    q.push(p);
  }

  while (!q.empty()) {
    std::cout << q.top().first << ": " << q.top().second << '\n';
    q.pop();
  }

  return 0;
}