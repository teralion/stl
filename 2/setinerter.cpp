#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>

int main() {
  std::set<std::string> s;

  std::istream_iterator<std::string> it {std::cin};
  std::istream_iterator<std::string> end;

  copy(it, end, inserter(s, s.end()));
  std::for_each(s.begin(), s.end(), [](const std::string &str) { std::cout << str << ' '; });
  std::cout << '\n';

  return 0;
}