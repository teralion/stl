#include <iostream>
#include <vector>
#include <numeric>

class zip_iterator {
  using it_type = std::vector<double>::iterator;
  it_type it1;
  it_type it2;
public:
  zip_iterator(it_type v1, it_type v2): it1{v1}, it2{v2} {};
  std::pair<double, double> operator*() const { return {*it1, *it2}; }
  zip_iterator& operator++() { ++it1; ++it2; return *this; }
  bool operator!=(const zip_iterator &o) const { return it1 != o.it1 && it2 != o.it2; }
  bool operator==(const zip_iterator &o) const { return !(*this != o); }
};

namespace std {
  template<>
  class iterator_traits<zip_iterator> {
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::pair<double, double>;
    using difference_type = long int;
  };
}

class zipper {
  using vec_type = std::vector<double>;
  vec_type &vec1;
  vec_type &vec2;
public:
  zipper(vec_type &a, vec_type &b): vec1{a}, vec2{b} {};
  zip_iterator begin() const { return {std::begin(vec1), std::begin(vec2)}; };
  zip_iterator end() const { return {std::end(vec1), std::end(vec2)}; };
};

int main() {
  std::vector<double> a {1.0, 2.0, 3.0};
  std::vector<double> b {1.2, 2.2, 3.2};

  zipper zipped{a, b};

  const auto add_product([](double sum, const auto &p) {
    return sum + p.first * p.second;
  });
  const auto dot_product(std::accumulate(std::begin(zipped), std::end(zipped), 0.0, add_product));
  std::cout << dot_product << std::endl;

  return 0;
}