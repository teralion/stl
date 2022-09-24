#include <iostream>
#include <iterator>

class fibit {
  size_t i{0};
  size_t a{0};
  size_t b{1};
public:
  fibit() = default;
  explicit fibit(size_t _i): i{_i} {};
  size_t operator*() const { return b; };
  fibit& operator++();
  // fibit& operator--();
  bool operator!=(const fibit &other) const { return i != other.i; };
  bool operator==(const fibit &other) const { return !(*this != other); };
};

fibit& fibit::operator++() {
  const size_t old_b {b};
  b += a;
  a = old_b;
  ++i;
  return *this;
}

namespace std {
  template<>
  struct iterator_traits<fibit> {
    using iterator_category = std::reverse_iterator;

    using difference_type = int;

    using value_type = int;
  };
}

class fib_range {
  size_t end_n;
public:
  fib_range(size_t _end_n): end_n{_end_n} {};
  fibit begin() const { return fibit{}; };
  fibit end() const { return fibit{end_n}; };
  // fibit rbegin() const { return fibit{end_n}; };
  // fibit rend() const { return fibit{}; };
};

int main() {
  auto fib = fib_range(10);
  copy(
    std::make_reverse_iterator(fib.begin()),
    std::make_reverse_iterator(fib.end()),
    std::ostream_iterator<int>{std::cout, ", "}
  );
  std::cout << '\n';
  return 0;
}