#include <iterator>
#include <iostream>
#include <string>
#include <set>

int main() {
  std::set<std::string> s;
  std::istream_iterator<std::string> it {std::cin};
  std::istream_iterator<std::string> end;

  std::copy(it, end, std::inserter(s, s.end()));
  for (const auto &word : s) {
    std::cout << word << ", ";
  }
  std::cout << '\n';
  return 0;
}