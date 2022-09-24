#include <iostream>
#include <vector>
#include <string>

struct employee {
  unsigned id;
  std::string name;
  std::string role;
  unsigned salary;
};

int main() {
  std::vector<employee> employees {
    { 1, "Ivan", "CEO", 25000 },
    { 2, "Yuri", "developer", 13000 },
    { 3, "Oleg", "lawyer", 20000 }
  };

  for (const auto &[id, name, role, salary] : employees)
    std::cout << "Name: " << name
      << "; Role: " << role
      << "; Salary: " << salary << '\n';

  return 0;
}