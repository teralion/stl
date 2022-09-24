#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

template <typename Itr>
static void print(Itr it, size_t chars) {
  copy_n(it, chars, ostream_iterator<char>{cout});
  cout << '\n';
}

int main() {
  const string long_string {
    "Lorem ipsum dolor sit amet, consetetur"
    " sadipscining elitr, sed diam nonumy eirmod"
  };
  const string needle {"elitr"};

  {
    auto match (search(begin(long_string), end(long_string), default_searcher(begin(needle), end(needle))));
    print(match, 5);
  }

  return 0;
}