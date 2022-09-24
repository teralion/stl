#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>

static void print(const std::vector<int> &v) {
  std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << '\n';
}

int main() {
  std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_device rd;
  std::mt19937 g {rd()};

  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';

  std::shuffle(std::begin(v), std::end(v), g);
  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';
  print(v);

  std::sort(std::begin(v), std::end(v));
  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';
  print(v);

  std::shuffle(std::begin(v), std::end(v), g);
  std::partition(std::begin(v), std::end(v), [](int i) { return i < 5; });
  print(v);

  std::shuffle(std::begin(v), std::end(v), g);
  auto middle (std::next(std::begin(v), int(v.size() / 2)));
  std::partial_sort(std::begin(v), middle, std::end(v));
  print(v);

  struct mystruct {
    int a;
    int b;
  };
  std::vector<mystruct> mv {{5, 100}, {1, 50}, {-123, 1000}, {3, 70}};
  std::sort(std::begin(mv), std::end(mv), 
    [](const mystruct &lhs, const mystruct &rhs) {
      return lhs.b < rhs.b;
    });
  for (const auto &[a, b] : mv) {
    std::cout << "{" << a << ", " << b << "} ";
  }
  std::cout << '\n';

  return 0;
}