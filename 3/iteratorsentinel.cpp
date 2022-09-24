#include <iostream>

class cstring_iterator_sentinel {};

class cstring_iterator {
  const char *s {nullptr};
public:
  explicit cstring_iterator(const char *_s): s{_s} {};
  char operator*() const { return *s; };
  cstring_iterator& operator++() { ++s; return *this; };
  bool operator!=(const cstring_iterator_sentinel) const { return *s != '\0' && s != nullptr; };
};

class cstring_range {
  const char *s {nullptr};
public:
  cstring_range(const char *_s): s{_s} {};
  cstring_iterator begin() const { return cstring_iterator{s}; };
  cstring_iterator_sentinel end() const { return {}; }
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Please, provide one parameter\n";
    return 1;
  }

  for (char c : cstring_range(argv[1])) {
    std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}