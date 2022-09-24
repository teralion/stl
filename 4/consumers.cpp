#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <functional>

static void print(const auto &c) {
  for (auto i : c) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

static auto consumer(auto &container) {
  return [&](auto value){
    container.push_back(value);
  };
}

int main() {
  std::vector<int> v;
  std::deque<int> d;
  std::list<int> l;

  const std::vector<std::function<void(int)>> consumers
    {consumer(d), consumer(l), consumer(v)};

  for (size_t i{0}; i < 10; ++i) {
    for (auto &&consume : consumers) {
      consume(i);
    }
  }

  print(v);
  print(d);
  print(l);

  return 0;
}