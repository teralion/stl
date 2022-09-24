#include <vector>
#include <iostream>

template <typename T, typename ... Ts>
void insert_all(std::vector<T> &vec, Ts ... ts) {
  (vec.push_back(ts), ...);
}

int main() {
  std::vector<int> v {1, 2, 3, 4};
  insert_all(v, 4, 5, 6);
  for (auto const& n : v)
    std::cout << n << '\n';
  return 0;
}