#include <iostream>

using namespace std;

class Encapsuled_class {
    // all members are private 
    private:
        int n;
        int p;

    public:
        Encapsuled_class(int n, int p) {
            this->n = n;
            this->p = p;
        }

        // using getters to get the member values 
        int getN() {
            return this->n;
        }

        int getP() {
            return this->p;
        }
};

void p1() {
    // p1 : Encapsulation 

    // Encapsulation is the process of wrapping data member
    // and functions together into a single unit/class 
    // it is also known as information or data hiding 

    // Fully encapsulated class : all data members are private 

    // because of this class becomes read only 
    // so to access the members we have to use getters and setters 

    // it increases code re-usablity and readablity 

    Encapsuled_class e1(2, 3);

    // not possible 
    // cout << "value of n is : " << e1.n() << endl;

    // using getters to get the values 
    cout << "value of n is : " << e1.getN() << endl;
    cout << "value of p is : " << e1.getP() << endl;

    // with the help of encapsulation 
    // we have achieve higher lever of security 
}

class Human {
    // This is a parent class 

    public:
        int height;

    private:
        int weight;
        int age;

    public:
        // constructors 
        Human() {}
        Human(int height, int weight, int age) {
            this->height = height;
            this->weight = weight;
            this->age = age;
        }

        // getters 
        int get_height() {
            return this->height;
        }

        int get_weight() {
            return this->weight;
        }

        int get_age() {
            return this->age;
        }

        // setters 
        void inc_age() {
            this->age += 1;
        }

        void set_age(int age) {
            this->age = age;
        }

        void set_height(int height) {
            this->height = height;
        }

        void set_weight(int weight) {
            this->weight = weight;
        }
};

class Man: public Human {
    // This class uses inheritance 
    // it is a child class 
    // it is derived from Human class 
    // and has all the properties which Human class has 

    public:
        string color;

        Man() {}

        Man(string color) {
            this->color = color;
            this->height = 2;

            // not accessible because age is private 
            // this->age = 0;
        }
};

class Woman: public Human {
    // This class also uses inheritance 
    // it is also a child class 
    // it is also derived from Human class 
    // and has all the properties which Human class has 
};

void p2() {
    // p2 : Inheritance 

    // when a class is derived or inherit 
    // all the members and other properties 
    // from another class then it is called as inheritance

    // above Human class is parent class and Man and Woman are child class 
    // Man and Woman are derived from Human class 
    // and has all the properties of Human class (only public properties)
    // to access the private properties 
    // you have to use getters and setters of parent class 

    Human h1(5, 50, 10);

    cout << "height of h1 : " << h1.get_height() << endl;
    cout << "weight of h1 : " << h1.get_weight() << endl;
    cout << "age of h1 : " << h1.get_age() << endl;

    Man m1;
    m1.set_height(5);
    m1.set_weight(35);
    m1.set_age(12);

    // Man m1(7, 70, 16);

    cout << "height of m1 : " << m1.get_height() << endl;
    cout << "weight of m1 : " << m1.get_weight() << endl;
    cout << "age of m1 : " << m1.get_age() << endl;
}

void p3() {
    // p3 : types of inheritance 

    // 1. Single inheritance : a class is allowed to inherit from only one class. 
    // i.e. one subclass is inherited by one base class only.

    // 2. Multilevel inheritance : when a derived class is created from another derived class.
    // i.e. one subclass is derived from another class which is also a subclass of any other class 

    // 3. Multiple inheritance : a class can inherit from more than one class. 
    // i.e one subclass is inherited from more than one base class.

    // 4. Hierarchical inheritance :  more than one subclass is inherited from a single base class. 
    // i.e. more than one derived class is created from a single base class.

    // 5. Hybrid inheritance : Hybrid Inheritance is implemented by combining 
    // more than one type of inheritance. 
    // For example: Combining Hierarchical inheritance and Multiple Inheritance. 

    // Inheritance ambiguity : if a class inherit from two classes 
    // and they both have a function with same name 
    // then compiler will get confuse between both the function 
    // to resolve this issue we use scope resolution operator 
    // Syntax => obj.CLASS_1::fun();
}

void p4() {
    // p4 : Polymorphism 

    // Polymorphism : when a same object has different roles/forms 
    // like a human can be a father and a husband at a same time 

    // Types of polymorphism :
    // 1. Compile time polymorphism
    // 2. Run time polymorphism

    // Compile time polymorphism : achieved by function overloading or operator overloading.
    // it is also called as static polymorphism

    // Run time polymorphism : achieved by Function Overriding
    // in run time polymorphism we modify the function/method of parent/base class 
    // it depends on inheritance 
    // it is also called as dynamic polymorphism

    // Function Overloading : creating functions with same name but different arguments 
    // overloaded functions can also have different return types 
    // to create overloaded functions you must have to change the arguments of the functions 

    // Operator Overloading : changing the working of any operator 
    // there are some restrictions to overload some operators 
    // we cannot overload all the operators 

    /*
    // Syntax to overload + operator => 
    public:
        return_type operator+ (Class obj) {
            // ...
            return value;
        }
    */
}

void p5() {
    // p5 : Abstraction 

    // Abstraction is a process of hiding implementation details 
    // and exposes only the functionality to the user

    // Access modifiers used to achieve abstraction 
}


int main() {
    // Lecture 43 : 4 Pillars of OOPS 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // To learn more 
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382190
    // - https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/
    // - https://www.geeksforgeeks.org/four-main-object-oriented-programming-concepts-of-java/
    // - https://www.geeksforgeeks.org/inheritance-in-c/
    // - https://www.geeksforgeeks.org/cpp-polymorphism/
    // - https://www.geeksforgeeks.org/abstraction-in-cpp/

    return 0;
}