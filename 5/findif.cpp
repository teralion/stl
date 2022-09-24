#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct city {
  string name;
  unsigned population;
};

bool operator==(const city &a, const city &b) {
  return a.name == b.name && a.population == b.population;
}

ostream& operator<<(ostream &os, const city &a) {
  return os << "{" << a.name << ", " << a.population << "}";
}

template <typename C>
static auto opt_print(const C &container) {
  return [end_it (end(container))](const auto &item) {
    if (item != end_it) {
      cout << *item << '\n';
    } else {
      cout << "<end>\n";
    }
  };
}

int main() {
  const vector<city> c {
    {"Aachen", 2250},
    {"Braunschweig", 160000},
    {"Berlin", 3500000},
    {"Cologne", 400000}
  };

  auto print_city(opt_print(c));
  print_city(find(begin(c), end(c), {"Cologne", 400000}));

  return 0;
}