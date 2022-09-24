#include <type_traits>
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
class addable {
private:
  T val;
public:
  addable(T v): val{v} {}
  template <typename U>
  T add(U x) const {
    if constexpr (std::is_same_v<T, std::vector<U>>) {
      auto copy (val);
      for (auto &n : copy)
        n += x;
      return copy;
    } else {
      return val + x;
    }
  }
};

int main() {
  std::cout << addable<int>{1}.add(2) << '\n';
  std::cout << addable<float>{1.0}.add(2) << '\n';

  std::vector<std::string> sv {"a", "b", "c"};
  sv = addable<std::vector<std::string>>{sv}.add(std::string{"z"});
  for (auto const& str : sv)
    std::cout << str << '\n';

  return 0;
}
