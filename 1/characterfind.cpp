#include <utility>
#include <algorithm>
#include <iostream>
#include <map>

void show(const std::pair<char, int>& v) {
  std::cout << v.first << ": " << v.second << '\n';
}

int main() {
  std::map<char, int> character_map{{'c', 1}, {'a', 2}, {'b', 10}};

  if (auto itr(character_map.find('e')); itr != character_map.end()) {
    for_each(itr, character_map.end(), show);
  } else {
    std::cout << "No char found!" << '\n';
  }

  return 0;
}
