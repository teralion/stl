#include <vector>
#include <string>
#include <list>
#include <map>
#include <iostream>

class Billionaire {
  std::string name;
  double dollars;
  std::string country;
public:
  Billionaire(const std::string &n, double d, const std::string &c): name(n), dollars(d), country(c) { std::cout << n << " created!" << '\n'; };
  Billionaire(const Billionaire &);
  ~Billionaire() { std::cout << name << " destroyed!" << '\n'; };
  Billionaire& operator=(const Billionaire &);
  const std::string& getCountry() const { return country; };
  friend std::ostream& operator<<(std::ostream &, const Billionaire &);
};

Billionaire::Billionaire(const Billionaire &b) {
  std::cout << b.name << " copy constructor called" << '\n';
  name = b.name;
  dollars = b.dollars;
  country = b.country;
}

Billionaire& Billionaire::operator=(const Billionaire &b) {
  std::cout << "assign constructor called" << '\n';
  if (&b == this) {
    return *this;
  }

  name = b.name;
  dollars = b.dollars;
  country = b.country;

  return *this;
}

std::ostream& operator<<(std::ostream& out, const Billionaire &b) {
  out << b.name << " has " << b.dollars
    << " B$\n" << " and lives in " << b.country;

  return out;
}

int main() {
  std::list<Billionaire> billionaires {
    Billionaire({"Bill Gates", 86.0, "USA"}),
    Billionaire({"Warren Buffet", 75.6, "USA"})
    // Billionaire({"Jeff Bezos", 72.8, "USA"}),
    // Billionaire({"Amancio Ortega", 71.3, "Spain"}),
    // Billionaire({"Mark Zuckerberg", 56.0, "USA"}),
    // Billionaire({"Carlos Slim", 54.6, "Mexico"}),
    // Billionaire({"Bernard Arnault", 41.5, "France"}),
    // Billionaire({"Liliane Bettencourt", 39.5, "France"})
  };

  std::map<std::string, std::pair<const Billionaire, size_t>> m;
  for (const auto &b : billionaires) {
    auto [iterator, success] = m.try_emplace(b.getCountry(), b, 1);
    if (!success) {
      iterator->second.second += 1;
    }
  }

  for (const auto & [key, value] : m) {
    const auto & [b, count] = value;
    std::cout << b << '\n';
  }

  return 0;
}