#include <iostream>
#include <type_traits>
#include <algorithm>
#include <vector>

template <typename T>
void show(const std::vector<T>& v) {
  for (auto const& val : v)
    std::cout << val;
  std::cout << '\n';
}

int main() {
  std::vector<char> delitemer(10, '-');
  std::vector<int> v {1, 2, 3, 2, 4, 2, 6, 2, 4, 8};
  auto v2(v);
  const auto odd([](int i) { return i % 2 != 0; });
  show(v);
  const auto new_end (std::remove(std::begin(v), std::end(v), 2));
  show(delitemer);
  show(v);
  v.erase(new_end, std::end(v));
  show(delitemer);
  show(v);

  std::cout << "V capacity: " << v.capacity() << '\n';
  std::for_each(new_end, new_end + 4, ([](int i) { std::cout << i; })); // though erase, still in memory
  std::cout << '\n';

  v.shrink_to_fit();

  show(delitemer);
  show(v);
  std::cout << "V capacity: " << v.capacity() << '\n';

  show(delitemer);
  show(v2);
  v2.erase(std::remove_if(std::begin(v2), std::end(v2), odd));
  v2.shrink_to_fit();
  show(delitemer);
  show(v2);

  return 0;
}