#include <iostream>
#include <map>
#include <string>

void print(const std::map<int, std::string> &m) {
  for (const auto &[placement, driver] : m) {
    std::cout << placement << ": " << driver << '\n';
  }
}

int main() {
  std::map<int, std::string> race_replacement {
    {1, "Luigi"}, {2, "Bowser"}, {3, "Mario"}
  };

  print(race_replacement);
  std::cout << std::endl;
  {
    auto a (race_replacement.extract(1));
    auto b (race_replacement.extract(3));
    std::swap(a.key(), b.key());
    print(race_replacement);
    std::cout << std::endl;
    race_replacement.insert(move(a));
    race_replacement.insert(move(b));
    print(race_replacement);
  }

  return 0;
}