#include <iostream>
#include <string>

template <typename T>
class Destructive {
  T* value;
public:
  Destructive(const T&);
  ~Destructive();
  bool istrue() const { return false; };
  template <typename U>
  friend std::ostream &operator<<(std::ostream &, const Destructive<U> &);
};

template <typename T>
Destructive<T>::Destructive(const T& val) {
  std::cout << "Destructive constructed" << '\n';
  value = new T(val);
}

template <typename T>
Destructive<T>::~Destructive()
{
  std::cout << "Destructive destroyed" << '\n';
  delete value;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const Destructive<U> &d) {
  os << d.value << ' ';
  return os;
}

int main() {
  const std::string str("Destruction is not construction");
  if (Destructive<std::string> obj(str); obj.istrue()) {
    std::cout << obj << "is true" << '\n';
  } else {
    std::cout << "not true" << '\n';
  }

  std::cout << "finish" << '\n';

  return 0;
}
