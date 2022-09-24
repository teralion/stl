#include <string>
#include <functional>
#include <optional>
#include <iostream>

using namespace std;

optional<string> create(bool b) {
  if (b)
    return "Godzilla";
  return {};
}

auto create2(bool b) {
  return b ? optional<string>{"Godzilla"} : nullopt; // ternary is important
}

auto create_ref(bool b) {
  static string value = "Godzilla";
  return b ? optional<reference_wrapper<string>>{value}
    : nullopt;
}

int main() {
  cout << "create(false) returned " << create(false).value_or("empty") << '\n';

  if (auto str = create2(true)) {
    cout << "create2(true) returned " << *str << '\n';
  }

  if (auto str = create_ref(true)) {
    cout << "create_ref(true) returned " << str->get() << '\n';
    str->get() = "Mothra";
    cout << "modifying it changed it to " << str->get() << '\n';
  }

  return 0;
}