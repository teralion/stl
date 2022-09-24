#include <iostream>

template <typename ... Ts>
auto sum(Ts ... ts) {
  return (ts + ...);
}

int main() {
  using namespace std;

  std::string hello {"Hello, "};
  std::string world {"world"};
  cout << sum(hello, world) << endl;

  return 0;
}