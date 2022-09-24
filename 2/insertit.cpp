#include <iostream>
#include <map>
#include <string>

template <typename T, typename K>
void show(const std::map<T, K> &m) {
  for (const auto & [key, value] : m) {
    std::cout << "\"" << key << "\": " << value << ", ";
  }
  std::cout << '\n';
}

int main() {
  std::map<std::string, size_t> m {{"b", 1}, {"c", 2}, {"d", 3}};
  auto insert_it(std::end(m));

  for (const auto &s : {"z", "y", "x", "w"}) {
    insert_it = m.insert(insert_it, {s, 1});
  }

  m.insert(std::end(m), {"a", 1});
  show(m);

  return 0;
}