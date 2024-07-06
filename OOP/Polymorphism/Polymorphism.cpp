#include <iostream>
#include <iterator>
#include <vector>
#include <memory>
using namespace std;


//Polymorphism
// Polymorphism means having many forms. An operation may exhibit different behaviors in different instances.
// Compile Time: Operator Overloading and Function Overloading (same function, different types/amounts of parameters)
// Run Time: Virtual Functions & Function Overriding (Subclass has same function as superclass and overrides it)

// Compile Time: Function Overloading
class FuncOverloading {
private:
    int var1 = 1;
    int var2 = 1;

public:
    int add_vars(int loc_var1, int loc_var2) {
        int loc_storage = loc_var1 + loc_var2 + var1 + var2;
        return loc_storage;
    }

    double add_vars(double loc_var1, double loc_var2) {  // This method is now overloaded
        double loc_storage = loc_var1 + loc_var2;
        return loc_storage;
    }

    int add_vars(int loc_var1, int loc_var2, int loc_var3) {
        int loc_storage = loc_var1 + loc_var2 + loc_var3 + var1 + var2;
        return loc_storage;
    }

};

//................................................................................

// Compile Time: Operator Overloading - Inside Class
//    A member function is used instead of a friend function when overloading operators that
//    are typically member functions, like +=, -=, or the assignment operator =
//    This is often the case for methods that modify the state of the object or rely heavily on the context of the object.
//    For example:
//    Accumulator acc1(10);
//    Accumulator acc2(5);
//    acc1 += acc2;
//    acc1's state gets modified, hence it's a member function
//    When overloading +, c3 = c2 + c1, neither c2, nor c1 get modified
class OperatorOverloading {
private:
    int arg1 = 0;
    int arg2;

public:
    OperatorOverloading(int a1 = 0, int a2 = 0) {
        arg1 = a1;
        arg2 = a2;
    }

    OperatorOverloading operator+(OperatorOverloading const& para) const {  // "const& para" Object is passed by reference and cannot be modified within the function
        return OperatorOverloading(arg1 + para.arg1, arg2 + para.arg2);  // The const above indicates that member function does not modify the state of the object it is called on
    }

    void getArg1() {
        cout << arg1 << endl;
    }

    void getArg2() {
        cout << arg2 << endl;
    }

};

//    Example to utilise this:
//    int main() {
//        OperatorOverloading obj1(1, 2);
//        OperatorOverloading obj2(3, 4);
//        OperatorOverloading obj3 = obj1 + obj2;
//        obj3.display();  // Should output: arg1: 4, arg2: 6
//        return 0;
//    }


//................................................................................
/*
// Compile Time: Operator Overloading - Implementation Outside the Class with Friend Function
// The global operator function is made friend of class so that it can access private members
// Useful when overloading binary operators (like +, -, etc.) where you want both operands to be treated symmetrically
// The operation does not inherently prioritize one operand over the other; they are treated as equals.
// Complex c3 = c1 + c2

//Almost all operators can be overloaded except a few:
//  sizeof
//  typeid
//  Scope resolution(::)
//  Class member access operators(.(dot), .* (pointer to member operator))
//  Ternary or conditional(? : )

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void print() { cout << real << " + i" << imag << endl; }

    friend Complex operator+(Complex const& c1, Complex const& c2);

};
Complex operator+(Complex const& c1, Complex const& c2)  // No const at the end because not a member function, no "this" object whose state it could modify
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
*/
//................................................................................
// Runtime Polymorphism - Function Overriding:
// Occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
class Parent {
public:
    void func1() {
        cout << "this is the parent class" << endl;
    }
};

class Child : public Parent {
public:
    void func1() {
        cout << "this is the child class" << endl;
    }
};

//................................................................................
// Object Slicing: When an object of a subclass is assigned to an object of a base class
// During this assignment, the derived class part of the object is "sliced off," and only the base class part is retained
// As a result, any data members or methods specific to the derived class are lost in the process
class AnimalColour {
public:
    string colour = "Black";
};

class DogColour : public AnimalColour {
public:
    string colour = "Gray";
};

//int main() {
// Object Slicing:
//    Animal d = Dog();
//    cout << d.colour;  // Prints out Animal's attribute, "Black"
//}

// ................................................................................

// Virtual Functions: A member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class
// Virtual functions are Dynamic in nature. They are called during Runtime.
// They allow you to call derived class methods through a base class pointer or reference
class BaseVC {
public:
    // Virtual function
    virtual void display() {
        cout << "Called virtual Base Class function\n\n";
    }

    void print() {
        cout << "Called Base print function\n\n";
    }

    // Virtual destructor for proper cleanup
    virtual ~BaseVC() = default;  // To ensure derived class' destructor is called when deleting a base class pointer to a derived class object
};

class ChildVC : public BaseVC {
public:
    void display() override { // To ensure function is overriden. Helps catch errors at compile-time if Base's display method signature changes
        cout << "Called Child Display Function\n\n";
    }

    void print() {
        cout << "Called Child print Function\n\n";
    }
};


// Creating more virtual functions and creating a method that universally prints the method of the object passed

class Animal {
public:

    //  const indicates that the function does not modify the state of
    //  the object on which it is called and will not change any member
    //  variables and will not call any non-const member functions of the object
    //  How to define a const object: const Circle cc - this could only call const member functions, compiler will generate an error;

    virtual void makeSound() const {
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() = default;
};
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Bark" << endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow" << endl;
    }
};

void playSound(Animal* animal) {
    animal->makeSound();  // Calls the appropriate makeSound() method based on the actual object type
}


// Using virtual functions for Dynamic Binding
class BaseDB {
public:
    void display() {
        print();
    }

    virtual void print() {
        cout << "This is from BaseDB class" << endl;
    }
};

class ChildDB : public BaseDB {
public:
    void print() {
        cout << "This is from the ChildDB class" << endl;
    }
};



int main() {

    // Compile Time:
    // For Function Overloading
    FuncOverloading func_obj1;
    cout << func_obj1.add_vars(1.345, 1.435) << endl;
    cout << func_obj1.add_vars(1, 1, 1) << endl;
    cout << func_obj1.add_vars(1, 1) << endl;

    //................................................................................
    // For Operator Overloading - Inside Class with Member Function
    OperatorOverloading opera_obj1(1, 1), opera_obj2(1, 1);
    OperatorOverloading opera_obj3 = opera_obj1 + opera_obj2;
    opera_obj3.getArg1();
    opera_obj3.getArg2();

    //................................................................................
    // For Operator Overloading - Outside Class with Friend Function
        // Commented out due to overloading duplicated
        //Complex comp_obj1(1, 1), comp_obj2(1, 1);
        //Complex comp_obj3 = comp_obj1 + comp_obj2;
        //comp_obj3.print();


    //................................................................................

    // Runtime - Overriding Output:
    Child child1;
    child1.func1();

    //................................................................................
    // Object Slicing:
    AnimalColour d = DogColour();
    cout << d.colour << endl;  // Prints out "Black" of Animal base class

    //................................................................................
    // Virtual Functions: If a pointer is used from Base to Derived,
    BaseVC* base = new ChildVC();
    base->display(); // Called Child display()
    base->print(); // Called Base print ()
    delete base;  // Clean up to avoid memory leak

    // Calling function that prints method of passed in object
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    playSound(dog);  // Outputs Dog's makeSound() "Bark"
    playSound(cat);  // Outputs Cat's makeSound() "Meow"
    // Clean up
    delete dog;
    delete cat;

    // Pointer to object of subclass by reference
    Animal* an1;
    Dog dog2;
    an1 = &dog2;
    an1->makeSound();

    // The following isn't using pointers and references. The "virtual" prefix for the print() method in the base class
    // allows the usage of function overriding without actually overriding the method in the child class. It allows
    // me to call BaseDB's display() method and get called ChildDB's print() method.
    BaseDB baseDB;
    ChildDB childDB;
    baseDB.display();
    childDB.display();

    // ................................................................................
    // Putting the objects of the subclasses of Animal into a vector and iterating through them
    vector<unique_ptr<Animal>> objects;
    objects.push_back(make_unique<Dog>());
    objects.push_back(make_unique<Cat>());
    for (const auto& obj : objects) {
        obj->makeSound();
    }
    // ................................................................................
    return 0;
}