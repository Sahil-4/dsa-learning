#include <iostream>

using namespace std;

void p1() {
    // P1 : OOPs Introduction

    // OOPS : Object oriented Programming System

    // It's a method or technique of programming in which,
    // we use classes and objects to make programs

    // OOPs used to make programs close to real world

    // in simple terms Classes are datatypes
    // and Objects are variables

    // Access modifiers : they are some keywords that used to
    // limit the access of properties and methods to a specific level or scope

    // private : properties and methods declared using private keyword can only be accessed inside the same class or by using getters or setters
    // protected : Only same class or sub-classes of the same class have access
    // public : used to provide access of properties and methods inside class and also outside the class

    // getters : function/methods used to access private properties or methods of any class
    // setters : function/methods used to modify private properties or methods of any class

    // When we create a new object
    // a special function constructor gets invoked automatically
    // at the time of creation of objects

    // Types of constructor :
    // Default constructot : even if we dont create a constructor
    // compiler automatic creates a constructor for our class/classes

    // Parameterised constructor : constructor which takes some arguments and use them to create objects

    // Un-Parameterised constructor : constructor that create objects without taking any arguments

    // Copy constructor : constructor which takes an object and use it to create a new object

    // Constructors should always be public
    // a class can also have more than one constructor

    // if we create our own constructor then default constructor will not be created or will die

    // this : this is a pointer points to the current object

    // Shallow copy vs Deep copy
    // Shallow copy : assign the same memory address to the new object
    // Deep copy : creates a new copy of values and then assign the values to new object

    // in case of shallow copy
    // if we change value of main object then value of copied object will also get changed
    // to avoid this we have to create a copy constructor which does deep copy

    // Static : it's a keyword used to make static properties or methods
    // static properties/methods are those which can be shared by all the objects of the class
    // and can be used with/without creating objects
}

// creating a class
class FirstClass {

    // Properties
    public:
        string type;
        int myId;
        string name;
        // to access properties and methods outside this class
        // they should be declared as public

    // private properties
    private:
        string my_class = "FirstClass";
        int my_class_id = 1;
        // my_class and my_class_id properties can only be accessed by this class
        // to access private properties or methods
        // we have to use getters and setters
        // getters used to get value of private properties or call any private method
        // and setters set the value of private properties

    // Static members
    public:
        static int my_num;
        // above is a static property of this class
        // it is shared between all the objects and can be accessed without creating any object

    // Constructor
    public:
        FirstClass() {
            myId = 123;
            type = "Class Object";
            name = "Object";
        }

    // Parameterised Constructor
    public:
        FirstClass(int id) {
            // myId = id;
            this->myId = id;

            // "this" is a pointer to current object
            // "this" indicates the current object
            // "this" used to access/modify current object
        }

    // Copy Constructor (Default)
    // public:
        // FirstClass(FirstClass &obj) {
        //     this->myId = obj.myId;

        //     // we have to give refrence of the object
        //     // else it will first create the copy of old object
        //     // which will lead the program to infinite loop

        //     // this will make a shallow copy
        // }

    // Copy Constructor (Deep copy)
    public:
        FirstClass(FirstClass &obj) {
            // making a deep copy
            this->myId = obj.myId;
        }

    // Methods
    public:
        void callMe() {
            cout << "You called a method of an object of type FirstClass" << endl;
        }

    public:
        string get_myclass() {
            // this is a getter function
            return my_class;
            // this function is used to access private properties 
        }

    public:
        void set_myclass(string val) {
            // this is a getter function
            my_class = val;

            // we can also add some conditions
            // to avoid unwanted changes in private properties
        }

    public:
        void print_details() {
            cout << endl << "{ ";
            cout << "myId : " << this->myId << ", ";
            cout << "name : " << this->name << ", ";
            cout << "type : " << this->type << " }" << endl;
        }

        static void print_class_name() {
            // this is a static method 
            // this method can be called by without creating a new object 
            cout << "This is FirstClass" << endl;
        }

        ~FirstClass() {
            // this is a destructor
            // this will de-allocate/free the memory reserves by the objects of this class 
            cout << "destructor is invoked" << endl;
            // this method will onvoked when an object is going to destroy 
        }
};

void p2() {
    // P2 : Creating first class

    // Create a class names as FirstClass

    // then create an object of FirstClass
    FirstClass my_obj;

    // size allocated by my_obj
    cout << sizeof(my_obj) << endl;

    // accessing properties of my_obj
    cout << my_obj.type << endl;

    // calling method of my_obj
    my_obj.callMe();

    // modifying properties
    my_obj.myId = 213;
    cout << my_obj.myId << endl;

    // calling getters
    cout << "Class of my_obj is " << my_obj.get_myclass() << endl;

    // calling setters
    my_obj.set_myclass("another_class");

    cout << "Class of my_obj is " << my_obj.get_myclass() << endl;
}

void p3() {
    // p3 : Creating objects dynamically

    // we can also create objects dynamically
    FirstClass *my_obj_2 = new FirstClass;

    // accessing properties of *my_obj_2
    cout << (*my_obj_2).type << endl;
    cout << my_obj_2->type << endl;
}

void p4() {
    // p4 : using constructors

    // with un-parameterised constructor
    // FirstClass *my_obj_2 = new FirstClass();
    // cout << "id is " << my_obj_2->myId << endl;

    int id = 512;
    // with parameterised constructor
    FirstClass *my_obj_1 = new FirstClass(id);

    cout << "id of my_obj_1 is " << my_obj_1->myId << endl;
}

void p5() {
    // p5 : using copy constructor

    FirstClass f1(12);
    cout << f1.myId << endl;

    FirstClass f2(f1);
    cout << f2.myId << endl;

    f1.myId = 130;
    cout << f1.myId << endl;
    cout << f2.myId << endl;

    // if we use default copy constructor then 
    // after changing value of one object 
    // value of another object will also be get changed 

    // but if we use the copy constructor made by ourself (which makes a deep copy)
    // then above thing will not happen 
    // change will not be reflect to the second object 
}

void p6() {
    // p6 : Copy assignment operator (=)

    // (=) operator used to copy all the values from one objects to second object
    FirstClass one;
    FirstClass second;

    one.myId = 54;
    one.name = "alpha";
    one.type = "B";

    one.print_details();
    second.print_details();

    second = one;

    one.print_details();
    second.print_details();
}

void p7() {
    // p7 : Destructor

    // Destructor is used to de-allocate memory
    // destructor is get invoked when any object is going out of scope or going to be destroyed
    // compiler creates a default destructor for us
    // but we can also create a destructor
    // destructor has same name as class but it starts with tilde(~) sign

    // creating an object
    FirstClass my_obj;

    // destructor will be get invoked automatically only for the objects that are created statically

    FirstClass *my_obj_2 = new FirstClass;

    // but for dynamically created objects
    // we have to manually call the destructor

    // to call destructor
    // just delete the object with delete keyword
    delete my_obj_2;
}

// initialising value of static property
int FirstClass::my_num = 5;

void p8() {
    // p8 : static keyword

    // static keyword is used to declare independent properties and functions
    // we can access static properties/methods without creating any object

    // accessing value of static property
    cout << FirstClass::my_num << endl;
    // :: scope resolution operator

    // we can also access/modify static properties with objects
    // FirstClass my_obj;

    // cout << my_obj.my_num << endl; // not recommended

    // static functions/methods

    FirstClass::print_class_name();
}

void p9() {
    // p9 : Data alignment and Padding or greedy alignment

    // Data structure alignment is the way data is arranged and accessed 
    // in computer memory. Data alignment and Data structure padding are 
    // two different issues but are related to each other and together 
    // known as Data Structure alignment. 

    // Data alignment: Data alignment means putting the data in memory 
    // at an address equal to some multiple of the word size. 

    // Data Structure Padding: Now, to align the data, it may be necessary 
    // to insert some extra bytes between the end of the last data structure 
    // and the start of the next data structure as the data is placed in memory 
    // as multiples of fixed word size. 
    // This insertion of extra bytes of memory to align the data 
    // is called data structure padding.

    // The compiler try to add padding optimally which is called as greedy alignment
}

void p10() {
    // p10 : constant properties, functions and objects

    // An object declared as const cannot be modified and hence, 
    // can invoke only const member functions as these functions ensure 
    // not to modify the object. 
    // A const object can be created by prefixing the const keyword 
    // to the object declaration.
}

void p11() {
    // p11 : initialisation list

    // Initializer List : used in initializing the data members of a class. 
    // The list of members to be initialized is indicated with constructor 
    // as a comma-separated list followed by a colon. 
}


int main() {
    // Lecture 42 : OOPs comcept

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    // p10();

    // p11();


    // To learn more : 
    // - https://www.geeksforgeeks.org/object-oriented-programming-oops-concept-in-java/
    // - https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/
    // - https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/238489/offering/3210642
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799
    // - https://www.geeksforgeeks.org/copy-constructor-in-cpp/
    // - https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
    // - https://www.geeksforgeeks.org/data-structure-alignment-how-data-is-arranged-and-accessed-in-computer-memory/
    // - https://www.includehelp.com/cpp-tutorial/size-of-a-class-in-cpp-padding-alignment-in-class-size-of-derived-class.aspx
    // - https://www.geeksforgeeks.org/const-member-functions-c/
    // - https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
    // - https://stackoverflow.com/questions/119123/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/119134#119134

    return 0;
}