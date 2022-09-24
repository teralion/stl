#include <iostream>
#include <list>
#include <iterator>

int main() {
  std::list<int> l {1, 2, 3, 4, 5};
  copy(l.rbegin(), l.rend(), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << std::endl;
  return 0;
}