#include <map>
#include <string>
#include <stack>
#include <stdexcept>
#include <cassert>
#include <sstream>
#include <iterator>
#include <iostream>
#include <cmath>

template <typename IT>
double evaluate_rpn(IT it, IT end) {
  std::stack<double> val_stack;

  auto pop_stack([&](){
    auto r (val_stack.top());
    val_stack.pop();
    return r;
  });

  std::map<std::string, double (*)(double, double)> ops {
    {"+", [](double a, double b) { return a + b; }},
    {"-", [](double a, double b) { return a - b; }},
    {"*", [](double a, double b) { return a * b; }},
    {"/", [](double a, double b) { return a / b; }},
    {"^", [](double a, double b) { return std::pow(a, b); }},
    {"%", [](double a, double b) { return std::fmod(a, b); }}
  };

  for (; it != end; ++it) {
    std::stringstream ss {*it};

    if (double val; ss >> val) {
      val_stack.push(val);
    } else {
      const auto r {pop_stack()};
      const auto l {pop_stack()};

      try {
        const auto &op (ops.at(*it));
        const double result {op(l, r)};
        val_stack.push(result);
      } catch (const std::out_of_range &) {
        throw std::invalid_argument(*it);
      }
    }
  }

  return val_stack.top();
}

int main() {
  try {
    std::cout << evaluate_rpn(std::istream_iterator<std::string>{std::cin}, {}) << '\n';
  } catch (const std::invalid_argument &e) {
    std::cout << "Invalid operator: " << e.what() << '\n';
  }

  return 0;
}