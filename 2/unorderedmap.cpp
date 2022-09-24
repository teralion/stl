#include <iostream>
#include <unordered_map>

struct record {
  int x;
  int y;
};
bool operator==(const record &l, const record &r) {
  return l.x == r.x && l.y == r.y;
}

namespace std {
  template<>
  struct hash<record>
  {
    std::size_t operator()(const record &c) const {
      return static_cast<std::size_t>(c.x + c.y);
    }
  };
}

int main() {
  std::unordered_map<record, int> m {{{0, 0}, 1}, {{9, 3}, 3}, {{3, 4}, 2}};
  for (const auto &[key, value] : m) {
    std::cout << "{(" << key.x << ", " << key.y
      << "): " << value << "} ";
  }
  std::cout << '\n';
  return 0;
}