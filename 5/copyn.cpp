#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
#include <iterator>

namespace std {
  std::ostream& operator<<(std::ostream &os, const std::pair<int, std::string> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
  }
}

int main() {
  std::vector<std::pair<int, std::string>> v {
    {1, "one"}, {2, "two"}, {3, "three"},
    {4, "four"}, {5, "five"}
  };
  std::map<int, std::string> m;

  std::copy_n(std::begin(v), 3, std::inserter(m, std::begin(m)));
  auto shell_it(std::ostream_iterator<std::pair<int, std::string>>{std::cout, ", "});
  std::copy(std::begin(m), std::end(m), shell_it);
  std::cout << '\n';

  m.clear();
  std::move(std::begin(v), std::end(v), std::inserter(m, std::begin(m)));
  std::copy(std::begin(m), std::end(m), shell_it);
  std::cout << '\n';
  std::copy(std::begin(v), std::end(v), shell_it);
  std::cout << '\n';

  return 0;
}