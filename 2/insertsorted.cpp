#include <iostream>
#include <type_traits>
#include <set>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

template <typename C, typename T>
void insert_sorted(C &v, const T &item) {
  if constexpr (std::is_same<C, std::set<T>>::value) {
    std::cout << "constexpr" << '\n';
    const auto insert_pos(v.lower_bound(item));
    v.insert(insert_pos, item);
  } else {
    std::cout << "else" << '\n';
    const auto insert_pos(std::lower_bound(v.begin(), v.end(), item));
    v.insert(insert_pos, item);
  }
}

int main() {
  std::vector<std::string> v {"some", "random", "words",
    "without", "order", "aaa", "yyy"};
  std::sort(v.begin(), v.end());
  insert_sorted<std::vector<std::string>, std::string>(v, "some");
  insert_sorted<std::vector<std::string>, std::string>(v, "zzz");

  for (const auto &w : v)
    std::cout << w << ' ';
  std::cout << '\n';

  return 0;
}