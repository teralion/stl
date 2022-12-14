#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct person
{
  string name;
  size_t age;
  person(string n, size_t a)
    : name{move(n)}, age{a}
  { cout << "CTOR " << name << '\n'; }
  ~person() { cout << "DTOR " << name << '\n'; }
};

int main()
{
  shared_ptr<string> shared_name;
  shared_ptr<size_t> shared_age;

  {
    auto spreson (make_shared<person>("John Doe", 30));
    shared_name = shared_ptr<string>(spreson, &spreson->name);
    shared_age = shared_ptr<size_t>(spreson, &spreson->age);
  }

  cout << "name: " << *shared_name
    << "\nage: " << *shared_age << '\n';
}
