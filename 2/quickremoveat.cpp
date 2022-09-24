#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it) {
  if (it != std::end(v)) {
    *it = std::move(v.back());
    v.pop_back();
    v.shrink_to_fit();
  }
}

int main() {
  std::vector<int> v {213, 456, 681, 984, 300};
  std::cout << v.capacity() << ' ' << v.size() << '\n';
  quick_remove_at(v, v.begin() + 2);
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';
  std::cout << v.capacity() << ' ' << v.size() << '\n';
  return 0;
}