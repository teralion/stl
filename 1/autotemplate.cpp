#include <iostream>
#include <type_traits>

template <typename T>
struct sum {
  T value;

  template <typename ... Ts>
  sum(Ts&& ... values) : value{(values + ...)} {}
};

template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;

int main() {
  sum s {1u, 2.0, 3, 4.0f};
  std::cout << s.value << '\n';

  return 0;
}
