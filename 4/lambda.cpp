#include <iostream>
#include <string>

int main() {
  const auto plus ([](auto l, auto r){ return l + r; });
  std::cout << plus(std::string{"abc"}, "cde") << ' ' << plus(1, 15) << '\n';

  auto counter (
    [count = 0]() mutable { return ++count; }
  );
  for (size_t i{0}; i < 5; ++i) {
    std::cout << counter() << ", ";
  }
  std::cout << std::endl;

  int a {0};
  auto incrementer ([&a]{ ++a; });
  incrementer();
  incrementer();
  incrementer();
  std::cout << a << std::endl;

  auto plus_ten ([=](int x){ return plus(10, x); });
  std::cout << plus_ten(5) << '\n';

  return 0;
}