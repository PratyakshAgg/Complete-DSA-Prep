#include <iostream>
using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    void introduceYourself() {
        cout << "Name- " << Name << endl;
        cout << "Company- " << Company << endl;
        cout << "Age- " << Age << endl;
    }
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

int main() {
    Employee employee1 = Employee("Pratyaksh", "Google", 20);
    employee1.introduceYourself();

    Employee employee2 = Employee("Aditya", "Amazon", 21);
    employee2.introduceYourself();

    return 0;
}