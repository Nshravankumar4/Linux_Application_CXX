# **Vehicle Inheritance System** 🚗🚲

## **📌 Project Overview**
A professional C++ inheritance demonstration implementing a vehicle hierarchy with parent-child class relationships, showcasing object-oriented programming principles with comprehensive unit testing.

## **🎯 Project Description**
This project demonstrates **inheritance in C++** through a real-world vehicle management system. It features a base `Vehicle` class with specialized child classes `Car` and `Bike`, each extending functionality while maintaining code reusability and clean architecture.

### **Core Features**
- ✅ **Class Hierarchy**: Clear parent-child relationships (Vehicle → Car/Bike)
- ✅ **Code Reusability**: Common properties/methods in base class
- ✅ **Polymorphism Ready**: Extensible design for future vehicle types
- ✅ **Professional Testing**: Google Test integration for reliability
- ✅ **Clean Architecture**: Separation of headers, implementation, and tests

## **🏗️ Architecture Diagram**
```
        Vehicle (Base Class)
           │
           ├─ speed: int
           └─ setSpeed(int): void
           │
    ┌──────┴──────┐
    │             │
    ▼             ▼
   Car           Bike
   │             │
   ├─ showSpeed() ├─ speedLevel()
   └─ (Displays)  └─ AlertFunction()
                    (Speed alerts)
```

## **📁 Project Structure**
```
Linux-Application_CXX/
├── include/                         # Header files
│   └── InheritanceVehicleCar.h     # Class declarations
├── src/                            # Implementation
│   └── InheritanceVehicleCar.cpp   # Method definitions
├── tests/                          # Unit tests
│   └── InheritanceVehicleCar_Test.cpp  # Google Test suite
├── CMakeLists.txt                  # Build configuration
└── README.md                       # This documentation
```

## **🔧 Technical Implementation**

### **1. Base Class: Vehicle**
```cpp
class Vehicle {
protected:
    int speed;  // Common property for all vehicles
public:
    Vehicle();              // Constructor
    void setSpeed(int s);   // Speed setter
};
```

### **2. Derived Class: Car**
```cpp
class Car : public Vehicle {  // Inherits from Vehicle
public:
    void showSpeed();  // Displays current speed
};
```

### **3. Derived Class: Bike**
```cpp
class Bike : public Vehicle {  // Inherits from Vehicle
public:
    string speedLevel();     // Returns speed status
    string AlertFunction();  // Calculates alert level
};
```

## **🚀 Speed Alert Logic (Bike Class)**
| Speed Range | Status | Description |
|------------|--------|-------------|
| 0 | "NA" | Not moving |
| 1-60 | "Normal" | Safe operating speed |
| 61-100 | "Orange" | Caution advised |
| 101-120 | "OverspeedReached" | Above recommended limit |
| 121-180 | "Red" | Critical speed warning |
| >180 | "OutOffRange" | Exceeds maximum range |

## **🧪 Testing Strategy**
```cpp
// Example test case
TEST(Bike, SpeedAlert) {
    Bike b;
    b.setSpeed(0);
    EXPECT_EQ(b.AlertFunction(), "NA");
    
    b.setSpeed(70);
    EXPECT_EQ(b.AlertFunction(), "Orange");
}
```
**Test Coverage:** 14 comprehensive tests ensuring:
- ✅ Car speed display functionality
- ✅ Bike alert logic across all ranges
- ✅ Inheritance integrity
- ✅ Boundary condition handling

## **⚡ Quick Start**

### **Prerequisites**
- C++11 or higher
- CMake 3.10+
- Google Test (included via CMake)

### **Build & Run**
```bash
# Clone and setup
git clone <repository-url>
cd Linux-Application_CXX

# Configure build
mkdir build && cd build
cmake ..

# Compile
make

# Run tests
./InheritanceVehicleCar_Tests

# Run demo
./InheritanceVehicleCar
```

### **Sample Output**
```
Car Speed is: 60
Bike is: Orange
[  PASSED  ] 14 tests.
```

## **📚 Key Concepts Demonstrated**

### **1. Inheritance Principles**
- **Code Reuse**: Common `speed` property in base class
- **Extensibility**: Easy to add new vehicle types
- **Hierarchy**: Clear parent-child relationships

### **2. Access Specifiers**
- `protected`: Allows child class access while maintaining encapsulation
- `public`: Interface exposed to users
- Inheritance type: `public Vehicle` maintains access levels

### **3. Software Engineering Best Practices**
- **Separation of Concerns**: Headers vs implementation
- **Test-Driven Development**: Comprehensive unit tests
- **Clean Code**: Descriptive naming, single responsibility

## **🔍 Code Quality Features**
- **Compilation Warnings**: Zero warnings with strict flags
- **Memory Safety**: Proper constructors/destructors
- **Error Handling**: Boundary checks in speed calculations
- **Maintainability**: Well-structured, commented code

## **🔄 Inheritance Flow Visualization**
```
Vehicle (Base)
    ├── int speed            ───┐
    └── void setSpeed(int)   ───┤
                                 │ Inheritance
Car (Derived)                   │
    ├── [Inherited: speed]  ←───┘
    ├── [Inherited: setSpeed] ←──┘
    └── void showSpeed()      ←── Unique to Car
```

## **🎯 Use Cases**
1. **Educational Tool**: Learn inheritance concepts
2. **Code Template**: Starting point for vehicle systems
3. **Testing Example**: Google Test integration reference
4. **Architecture Demo**: Professional project structure

## **📈 Performance & Scalability**
- **Lightweight**: Minimal overhead from inheritance
- **Extensible**: Add trucks, motorcycles, etc., easily
- **Testable**: Isolated components for unit testing
- **Maintainable**: Clear separation reduces complexity

## **🤝 Contributing**
1. Fork the repository
2. Create a feature branch
3. Add tests for new functionality
4. Ensure all tests pass
5. Submit a pull request

## **📄 License**
This project is open-source and available for educational and professional use.

## **👨‍💻 Author**
**Shravan Nunsavath**  
*Software Developer | C++ Enthusiast*

## **🌟 Features Summary**
| Aspect | Implementation |
|--------|---------------|
| Inheritance Type | Single, Public |
| Testing Framework | Google Test |
| Build System | CMake |
| Code Quality | Zero Warnings |
| Architecture | Header/Source Separation |
| Documentation | Comprehensive README |

---

**✅ Professional, production-ready demonstration of C++ inheritance with complete testing and documentation.**














# **🎯 Inheritance - Complete Interview Guide**

## **📚 Inheritance Fundamentals**

### **1. What is Inheritance?**
**Answer:** Inheritance is an OOP concept where a **child class** (derived) acquires properties and behaviors from a **parent class** (base). It establishes an **"is-a"** relationship.

```cpp
// Base class
class Animal {
    void eat() { /* ... */ }
};

// Derived class
class Dog : public Animal {  // Dog "is-a" Animal
    void bark() { /* ... */ }
};
```

### **2. Why Use Inheritance?**
**Answer:**
- **Code Reusability**: Avoid duplicate code
- **Extensibility**: Easy to add new features
- **Polymorphism**: Base pointer can point to derived objects
- **Organization**: Logical class hierarchy
- **Maintainability**: Change in base affects all derived classes

### **3. Types of Inheritance**
```cpp
// 1. Single Inheritance
class A {};
class B : public A {};

// 2. Multiple Inheritance
class A {};
class B {};
class C : public A, public B {};

// 3. Multilevel Inheritance  
class A {};
class B : public A {};
class C : public B {};

// 4. Hierarchical Inheritance
class A {};
class B : public A {};
class C : public A {};

// 5. Hybrid Inheritance (Diamond Problem)
class A {};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
```

## **🔍 Interview Questions & Answers**

### **Q1: Difference between `public`, `protected`, `private` inheritance?**
**Answer:**
```cpp
class Base {
public:     int x;
protected:  int y;  
private:    int z;
};

// Public Inheritance (Most Common)
class PubDerived : public Base {
    // x: public, y: protected, z: not accessible
};

// Protected Inheritance
class ProDerived : protected Base {
    // x: protected, y: protected, z: not accessible  
};

// Private Inheritance
class PriDerived : private Base {
    // x: private, y: private, z: not accessible
};
```

### **Q2: What is the Diamond Problem? How to solve it?**
**Answer:** Diamond problem occurs in multiple inheritance when a class inherits from two classes that both inherit from the same base class.

```cpp
// PROBLEM: D gets two copies of A
class A { int data; };
class B : public A {};
class C : public A {};
class D : public B, public C {};  // Gets data twice!

// SOLUTION: Virtual Inheritance
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};  // Gets data only once
```

### **Q3: Constructor/Destructor calling order?**
**Answer:**
**Construction:** Base → Derived  
**Destruction:** Derived → Base

```cpp
class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

// Output:
// Base Constructor
// Derived Constructor  
// Derived Destructor
// Base Destructor
```

### **Q4: Can we inherit constructors?**
**Answer:** In C++11 and later, **YES** using inheriting constructors:

```cpp
class Base {
public:
    Base(int x) { cout << "Base: " << x; }
};

class Derived : public Base {
public:
    using Base::Base;  // Inherits Base(int)
    
    // Can add more constructors
    Derived(int x, int y) : Base(x) { /* ... */ }
};
```

### **Q5: What is slicing problem?**
**Answer:** When a derived object is assigned to a base object, extra derived parts get "sliced" off.

```cpp
class Base { int x; };
class Derived : public Base { int y; };

Derived d;
Base b = d;  // SLICING! Only 'x' copied, 'y' lost

// Solution: Use pointers/references
Base* ptr = &d;  // No slicing
Base& ref = d;   // No slicing
```

### **Q6: Can we make a class non-inheritable?**
**Answer:** Yes, using final keyword (C++11):

```cpp
class FinalClass final {  // Cannot be inherited
    // ...
};

class TryDerive : public FinalClass {  // ERROR!
    // ...
};
```

## **💡 Advanced Concepts**

### **1. Virtual Base Class**
```cpp
class A { protected: int x; };

// Without virtual: Each gets own copy of A
class B : public A {};
class C : public A {};

// With virtual: Share single copy
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
```

### **2. Abstract Base Classes**
```cpp
// Pure virtual function = abstract class
class Shape {
public:
    virtual double area() = 0;  // Pure virtual
    virtual ~Shape() {}         // Virtual destructor
};

class Circle : public Shape {
    double radius;
public:
    double area() override { return 3.14 * radius * radius; }
};
```

### **3. Override vs Overload**
```cpp
class Base {
public:
    virtual void func(int x) { }  // Base version
};

class Derived : public Base {
public:
    void func(int x) override { }  // Override - SAME signature
    
    void func(double x) { }  // Overload - DIFFERENT signature
};
```

## **🎯 Common Interview Tasks**

### **Task 1: Design Vehicle Hierarchy**
```cpp
class Vehicle {
protected:
    string brand;
    int speed;
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int doors;
public:
    void start() override { cout << "Car starting\n"; }
    void stop() override { cout << "Car stopping\n"; }
};

class Bike : public Vehicle {
    bool hasCarrier;
public:
    void start() override { cout << "Bike starting\n"; }
    void stop() override { cout << "Bike stopping\n"; }
};
```

### **Task 2: Implement Employee System**
```cpp
class Employee {
protected:
    string name;
    double salary;
public:
    virtual double calculateBonus() = 0;
};

class Manager : public Employee {
    int teamSize;
public:
    double calculateBonus() override {
        return salary * 0.20 + teamSize * 1000;
    }
};

class Developer : public Employee {
    string language;
public:
    double calculateBonus() override {
        return salary * 0.15;
    }
};
```

## **🚫 Common Mistakes to Avoid**

### **1. Forgetting Virtual Destructor**
```cpp
class Base {
public:
    // ~Base() {}  // WRONG - causes memory leak
    virtual ~Base() {}  // CORRECT
};

class Derived : public Base {
    int* data;
public:
    Derived() { data = new int[100]; }
    ~Derived() { delete[] data; }
};

Base* ptr = new Derived();
delete ptr;  // Calls correct destructor only if virtual
```

### **2. Not Using `override` Keyword**
```cpp
class Base {
public:
    virtual void func(int x) { }
};

class Derived : public Base {
public:
    void func(int x) override { }  // Good - compiler checks
    
    // void func(double x) override { }  // ERROR caught early
};
```

### **3. Accessing Base Private Members**
```cpp
class Base {
private:
    int secret;  // Derived cannot access
protected:
    int shared;  // Derived can access
};

class Derived : public Base {
public:
    void show() {
        // cout << secret;  // ERROR: private
        cout << shared;    // OK: protected
    }
};
```

## **📊 Comparison Table**

| Aspect | Public Inheritance | Private Inheritance |
|--------|-------------------|-------------------|
| Relationship | Is-a | Implemented-in-terms-of |
| Base Public | Public in Derived | Private in Derived |
| Base Protected | Protected in Derived | Private in Derived |
| Usage | Most common | Rare, composition preferred |

## **🎖️ Best Practices**

1. **Use public inheritance** for "is-a" relationships
2. **Make destructors virtual** in base classes
3. **Use `override` keyword** for clarity and safety
4. **Prefer composition over private inheritance**
5. **Use virtual base classes** to solve diamond problem
6. **Keep inheritance hierarchies shallow** (2-3 levels max)
7. **Abstract base classes** for interfaces
8. **Avoid multiple inheritance** unless necessary

## **🧠 Quick Memory Tips**

- **"Is-a"** = Public Inheritance
- **"Has-a"** = Composition (not inheritance)
- **Virtual destructor** = MUST for polymorphic classes
- **`override`** = Safety net for function overriding
- **`final`** = Prevents further inheritance
- **Constructor order** = Base → Derived
- **Destructor order** = Derived → Base

## **💼 Real-World Use Cases**

1. **GUI Frameworks**: Window → Button, TextBox
2. **Game Development**: GameObject → Player, Enemy
3. **Database Systems**: Connection → MySQLConnection, PostgreSQLConnection
4. **Payment Systems**: Payment → CreditCardPayment, PayPalPayment
5. **Notification Systems**: Notifier → EmailNotifier, SMSNotifier

---

## **✅ Interview Checklist**

Before your interview, ensure you can:
- [ ] Explain all 5 types of inheritance
- [ ] Solve diamond problem example
- [ ] Write virtual destructor example
- [ ] Differentiate override vs overload
- [ ] Explain slicing problem and solution
- [ ] Design a simple class hierarchy
- [ ] List advantages/disadvantages of inheritance
- [ ] Compare inheritance vs composition

**Remember:** Inheritance is about **relationships** and **code reuse**, not just syntax!

---
**📌 Pro Tip:** In interviews, always explain WHY you're using inheritance, not just HOW. Show understanding of design decisions!
