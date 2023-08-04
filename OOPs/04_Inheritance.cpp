#include <iostream>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age >= 18) Age = age;
    }
    int getAge(){
        return Age;
    }
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
    void AskForPromotion(){
        if(Age > 30){
            cout << Name << " got promoted!" << endl;
        }
        else cout << Name << ", Sorry! No Promotion for you!" << endl;
    }
};

class Developer:public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {   
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug(){
        cout << Name << " fixed a bug using " << FavProgrammingLanguage << endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
};

int main() {
    Developer d = Developer("Pratyaksh", "Google", 20, "C++");
    Teacher t = Teacher("Jack", "Cool School", 35, "Mathematics");
    t.PrepareLesson();
    t.AskForPromotion();
    return 0;
}