#include <iostream>
#include <string>
#include <map>

template <typename T>
void print(const T &m) {
  std::cout << "Racers:\n";
  for (const auto &[placement, driver] : m) {
    std::cout << placement << ": " << driver << '\n';
  }
}

int main() {
  std::map<int, std::string> racers {
    {1, "Mario"}, {2, "Luigi"}, {3, "Bower"},
    {4, "Peach"}, {5, "Yoshi"}, {6, "Hoopa"}
  };
  print(racers);

  {
    auto a(racers.extract(2));
    auto b(racers.extract(5));

    std::cout << "a.key: " << a.key() << ", a.mapped: " << a.mapped() << '\n';
    std::cout << "b.key: " << b.key() << ", b.mapped: " << b.mapped() << '\n';

    std::swap(a.key(), b.key());
    racers.insert(move(a));
    racers.insert(move(b));
  }

  print(racers);

  return 0;
}