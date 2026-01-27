# 4-Day System Design & OOP Mastery Guide

**Complete Tutorial with C++ & Java Examples**  
*From Beginner to Advanced | Including FAQs, Homework & Practical Examples*

---

## **TABLE OF CONTENTS**

### Day 1-2: Foundations
- What is System Design?
- HLD vs LLD
- OOP Recap (Deep Understanding)
- Practical Exercise: Car, Engine, Driver Classes
- Day 1-2 FAQs
- Day 1-2 Homework

### Day 3: Encapsulation & Abstraction
- Encapsulation
- Access Modifiers
- Abstraction
- Bad vs Good Class Design
- Day 3 FAQs
- Day 3 Homework

### Day 4: Inheritance & Polymorphism
- Inheritance
- Polymorphism
- When Inheritance is Bad
- Favor Composition Over Inheritance
- Day 4 FAQs
- Day 4 Homework

### Final Summary
- Key Takeaways
- SOLID Principles
- Golden Rules
- Next Steps

---

# **DAY 1–2: FOUNDATIONS**

---

## **What is System Design?**

### **For Total Beginners:**

Imagine you're planning a birthday party. You need to think about:
- How many guests will come?
- Where will everyone sit?
- How much food to order?
- What if more people show up than expected?

System Design is like planning this party, but for software! It's about planning how different parts of a software application will work together before you actually build it.

**Real-life analogy:** Think of building a house. You don't just start laying bricks randomly. First, an architect creates a blueprint showing where rooms go, how plumbing works, where electricity runs. System Design is creating that blueprint for software.

### **For Those Who Can Code:**

System Design is the process of defining the architecture, components, modules, interfaces, and data flow of a system to satisfy specified requirements. It involves:

- **Scalability:** Can the system handle 100 users? 1 million users?
- **Reliability:** Will it stay up when things go wrong?
- **Performance:** How fast does it respond?
- **Maintainability:** Can other developers understand and modify it?

**Technical example:** Designing a URL shortener (like bit.ly):
- How do you generate unique short codes?
- Where do you store mappings (Database choice?)
- How do you handle millions of redirects per second?
- How do you prevent collisions in short URLs?

---

## **HLD vs LLD (High-Level Design vs Low-Level Design)**

### **For Total Beginners:**

**HLD (High-Level Design):** The Big Picture
- Like looking at a map of a city showing neighborhoods
- Shows major components and how they communicate
- Doesn't worry about tiny details

**LLD (Low-Level Design):** The Details
- Like looking at the blueprint of a single house
- Shows exactly how each component works internally
- Includes specific algorithms, data structures, class designs

**Real-life analogy:**
- **HLD:** "We need a kitchen, bedroom, bathroom, and living room. Water comes from city pipes."
- **LLD:** "The kitchen faucet uses a ceramic disc valve, connects to 1/2 inch copper pipe, requires 40-60 PSI water pressure."

### **For Those Who Can Code:**

| Aspect | HLD | LLD |
|--------|-----|-----|
| **Scope** | System architecture | Component implementation |
| **Focus** | Components & their interactions | Classes, methods, algorithms |
| **Audience** | Architects, stakeholders | Developers |
| **Details** | Abstract, technology choices | Concrete, code-level details |
| **Example** | "Use microservices with REST APIs" | "User class has validateEmail() method using regex" |

**HLD Example for E-commerce:**
```
[Client Browser] 
    ↓
[Load Balancer]
    ↓
[API Gateway]
    ↓ ↓ ↓
[User Service] [Product Service] [Order Service]
    ↓              ↓                 ↓
[User DB]      [Product DB]      [Order DB]
```

**LLD Example for User Service:**
```java
class UserService {
    - UserRepository userRepo
    - EmailValidator validator
    - PasswordHasher hasher
    
    + createUser(email, password)
    + authenticateUser(email, password)
    + updateProfile(userId, profileData)
}
```

---

## **OOP Recap (Deep Understanding)**

### **For Total Beginners:**

OOP (Object-Oriented Programming) is a way of organizing code by thinking of real-world objects.

**The Four Pillars:**

1. **Encapsulation:** Bundling data and methods together (like a capsule)
2. **Abstraction:** Hiding complex details, showing only what's necessary
3. **Inheritance:** Child inheriting features from parent
4. **Polymorphism:** Same thing, different forms

**Real-life analogy:**
Think of a TV remote:
- **Encapsulation:** All the complex circuits are hidden inside; you just see buttons
- **Abstraction:** You press "Volume Up" without knowing how sound increases
- **Inheritance:** A "Smart Remote" is a remote (inherits basic functions) + extra features
- **Polymorphism:** "Power" button works differently for TV vs DVD player, but same button

### **For Those Who Can Code:**

OOP organizes code around objects (data + behavior) rather than functions and logic. Key benefits:

- **Modularity:** Code is organized into self-contained units
- **Reusability:** Write once, use many times
- **Maintainability:** Changes are localized
- **Scalability:** Easy to extend functionality

**Why OOP?**

Procedural approach (messy):
```cpp
string carModel = "Tesla";
int carSpeed = 0;

void accelerate(int& speed) { speed += 10; }
void brake(int& speed) { speed = 0; }
```

OOP approach (organized):
```cpp
class Car {
    string model;
    int speed;
    
    void accelerate() { speed += 10; }
    void brake() { speed = 0; }
};
```

---

## **Practical Exercise: Simple Car, Engine, Driver Classes**

### **For Total Beginners:**

Let's build a simple car system. Think about:
- A **Car** has properties (color, model) and can do things (start, stop)
- An **Engine** has properties (horsepower) and can do things (run)
- A **Driver** can do things (drive the car)

### **C++ Implementation:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Engine class
class Engine {
public:
    int horsepower;
    bool isRunning;
    
    Engine(int hp) {
        horsepower = hp;
        isRunning = false;
    }
    
    void start() {
        isRunning = true;
        cout << "Engine started! Vroom vroom!" << endl;
    }
    
    void stop() {
        isRunning = false;
        cout << "Engine stopped." << endl;
    }
};

// Car class
class Car {
public:
    string model;
    string color;
    Engine engine;
    
    Car(string m, string c, int hp) : model(m), color(c), engine(hp) {
        cout << "New " << color << " " << model << " created!" << endl;
    }
    
    void startCar() {
        cout << "Starting " << model << "..." << endl;
        engine.start();
    }
    
    void stopCar() {
        cout << "Stopping " << model << "..." << endl;
        engine.stop();
    }
    
    void displayInfo() {
        cout << "\n=== Car Info ===" << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Horsepower: " << engine.horsepower << " HP" << endl;
        cout << "Engine Status: " << (engine.isRunning ? "Running" : "Stopped") << endl;
    }
};

// Driver class
class Driver {
public:
    string name;
    int age;
    
    Driver(string n, int a) : name(n), age(a) {
        cout << "Driver " << name << " is ready!" << endl;
    }
    
    void drive(Car& car) {
        cout << "\n" << name << " is driving the " << car.model << endl;
        if (!car.engine.isRunning) {
            car.startCar();
        }
        cout << name << ": Driving..." << endl;
    }
    
    void park(Car& car) {
        cout << "\n" << name << " is parking the " << car.model << endl;
        car.stopCar();
        cout << name << ": Car parked safely!" << endl;
    }
};

int main() {
    // Create a car
    Car myCar("Tesla Model 3", "Red", 283);
    
    // Create a driver
    Driver john("John", 25);
    
    // Display car info
    myCar.displayInfo();
    
    // Driver drives the car
    john.drive(myCar);
    
    // Display updated info
    myCar.displayInfo();
    
    // Driver parks the car
    john.park(myCar);
    
    // Display final info
    myCar.displayInfo();
    
    return 0;
}
```

### **Java Implementation:**

```java
// Engine class
class Engine {
    int horsepower;
    boolean isRunning;
    
    public Engine(int hp) {
        this.horsepower = hp;
        this.isRunning = false;
    }
    
    public void start() {
        isRunning = true;
        System.out.println("Engine started! Vroom vroom!");
    }
    
    public void stop() {
        isRunning = false;
        System.out.println("Engine stopped.");
    }
}

// Car class
class Car {
    String model;
    String color;
    Engine engine;
    
    public Car(String m, String c, int hp) {
        this.model = m;
        this.color = c;
        this.engine = new Engine(hp);
        System.out.println("New " + color + " " + model + " created!");
    }
    
    public void startCar() {
        System.out.println("Starting " + model + "...");
        engine.start();
    }
    
    public void stopCar() {
        System.out.println("Stopping " + model + "...");
        engine.stop();
    }
    
    public void displayInfo() {
        System.out.println("\n=== Car Info ===");
        System.out.println("Model: " + model);
        System.out.println("Color: " + color);
        System.out.println("Horsepower: " + engine.horsepower + " HP");
        System.out.println("Engine Status: " + (engine.isRunning ? "Running" : "Stopped"));
    }
}

// Driver class
class Driver {
    String name;
    int age;
    
    public Driver(String n, int a) {
        this.name = n;
        this.age = a;
        System.out.println("Driver " + name + " is ready!");
    }
    
    public void drive(Car car) {
        System.out.println("\n" + name + " is driving the " + car.model);
        if (!car.engine.isRunning) {
            car.startCar();
        }
        System.out.println(name + ": Driving...");
    }
    
    public void park(Car car) {
        System.out.println("\n" + name + " is parking the " + car.model);
        car.stopCar();
        System.out.println(name + ": Car parked safely!");
    }
}

// Main class
public class CarSystem {
    public static void main(String[] args) {
        // Create a car
        Car myCar = new Car("Tesla Model 3", "Red", 283);
        
        // Create a driver
        Driver john = new Driver("John", 25);
        
        // Display car info
        myCar.displayInfo();
        
        // Driver drives the car
        john.drive(myCar);
        
        // Display updated info
        myCar.displayInfo();
        
        // Driver parks the car
        john.park(myCar);
        
        // Display final info
        myCar.displayInfo();
    }
}
```

### **For Those Who Can Code:**

The above implementation demonstrates basic OOP principles:

**Key Concepts Demonstrated:**

1. **Classes as Blueprints:** `Car`, `Engine`, `Driver` are templates
2. **Objects as Instances:** `myCar`, `john` are concrete instances
3. **Composition:** Car HAS-A Engine (not IS-A)
4. **Encapsulation (basic):** Data and methods bundled together
5. **Methods:** Functions that operate on object data

**Design Decisions Explained:**

- **Why Engine is separate:** Modularity. Engine can be reused, replaced, or upgraded independently
- **Why composition:** A Car contains an Engine. If Car is destroyed, Engine should be too
- **Public members:** For simplicity. In Day 3, we'll make these private and use proper encapsulation

---

## **Day 1-2 FAQs**

**Q1: When should I use HLD vs LLD?**
- Use HLD when planning overall system architecture, choosing technologies, discussing with non-technical stakeholders
- Use LLD when implementing specific features, writing actual code, designing class hierarchies

**Q2: Isn't OOP overkill for simple programs?**
- For 50-line scripts, yes! Use procedural
- For 500+ lines with multiple features, OOP becomes essential for maintenance

**Q3: Why can't the Driver class directly modify the Car's engine?**
- This demonstrates encapsulation. Driver interacts with Car through methods, not by directly accessing Engine. This prevents Driver from accidentally breaking the Car's internal state.

**Q4: What's the difference between a class and an object?**
- **Class:** Blueprint/recipe (e.g., "Car" design)
- **Object:** Actual instance (e.g., "my red Tesla")
- Analogy: Class is like a cookie cutter, objects are the actual cookies

**Q5: Why do we use `this` in Java but not in C++?**
- You CAN use `this->` in C++, but it's optional if there's no ambiguity
- In Java, `this.` is more commonly used to distinguish instance variables from parameters

---

## **Day 1-2 Quick Quiz (Homework)**

### **Beginner Level:**

1. What is the main difference between HLD and LLD?
2. Name the four pillars of OOP
3. In the Car example, what type of relationship exists between Car and Engine? (is-a or has-a?)
4. Why is OOP better than writing all code in one large function?

### **Intermediate Level:**

1. Design HLD for a simple library management system (books, members, borrowing)
2. Modify the Car class to include a `fuel` attribute and `refuel()` method
3. Add a `License` class and ensure Driver must have a valid license to drive
4. What happens if we create an Engine object separately and try to assign it to multiple cars? Is this safe?
5. Write a `TrafficLight` class that a Driver must obey before driving

### **Challenge Problems:**

1. Implement a `CarRental` system with:
   - `RentalAgency` class managing multiple cars
   - `Rental` class tracking which driver rented which car
   - `calculateRentalCost()` based on days and car type

2. Add error handling:
   - Driver can't drive if under 18
   - Car can't start if engine is already running
   - Car can't stop if already stopped

3. Think about edge cases:
   - What if driver is null when calling `drive()`?
   - What if car has no engine?
   - How would you handle these gracefully?

---

# **DAY 3: ENCAPSULATION & ABSTRACTION**

---

## **Encapsulation**

### **For Total Beginners:**

Encapsulation means "putting things in a capsule" (hiding them away). It's like:

**Real-life analogy:**
- **TV Remote:** You press buttons, but don't see the circuit board inside
- **ATM Machine:** You withdraw money, but can't access the vault directly
- **Microwave:** You press "Start" but can't touch the magnetron

**Why is this good?**
- **Safety:** Can't accidentally break internal parts
- **Simplicity:** Don't need to know how it works internally
- **Flexibility:** Internals can change without affecting users

**Example: Bad Design (No Encapsulation)**

```cpp
class BankAccount {
public:
    double balance;  // Anyone can change this!
};

int main() {
    BankAccount myAccount;
    myAccount.balance = 1000;
    
    // OH NO! Anyone can do this:
    myAccount.balance = 999999999;  // Hacked!
}
```

**Example: Good Design (With Encapsulation)**

```cpp
class BankAccount {
private:
    double balance;  // Hidden from outside!
    
public:
    BankAccount() {
        balance = 0;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << endl;
            return true;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
            return false;
        }
    }
    
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount;
    myAccount.deposit(1000);
    myAccount.withdraw(100);
    
    // myAccount.balance = 999999;  // ERROR! Can't access private variable
    
    cout << "Balance: $" << myAccount.getBalance() << endl;  // Safe way
}
```

### **For Those Who Can Code:**

Encapsulation is bundling data (attributes) and methods (functions) together while restricting direct access to internal state. It's implemented using access modifiers.

**Key Benefits:**

1. **Data Hiding:** Prevent unauthorized access
2. **Validation:** Control how data is modified
3. **Flexibility:** Change implementation without breaking client code
4. **Debugging:** Easier to track where data changes

**Best Practices:**

```cpp
class GoodDesign {
private:
    // Data members (always private)
    int sensitiveData;
    vector<int> internalState;
    
    // Private helper methods
    bool validateData(int data) {
        return data >= 0 && data <= 100;
    }
    
public:
    // Constructor
    GoodDesign(int data) {
        if (validateData(data)) {
            sensitiveData = data;
        }
    }
    
    // Getters (read-only access)
    int getSensitiveData() const {
        return sensitiveData;
    }
    
    // Setters (controlled write access with validation)
    void setSensitiveData(int data) {
        if (validateData(data)) {
            sensitiveData = data;
        } else {
            throw invalid_argument("Data must be between 0 and 100");
        }
    }
};
```

---

## **Access Modifiers**

### **For Total Beginners:**

Access modifiers are like security levels:

| Modifier | Who Can Access? | Real-life Analogy |
|----------|----------------|-------------------|
| **public** | Everyone | Public park—anyone can enter |
| **private** | Only this class | Your bedroom—only you can enter |
| **protected** | This class + children | Family room—you and your kids |

**C++ Example:**

```cpp
class House {
public:
    string address;  // Anyone can see
    
    void knockDoor() {
        cout << "Knock knock!" << endl;
        openDoor();
    }
    
private:
    string safeCode;  // Only House can access
    
    void openDoor() {
        cout << "Door opened from inside" << endl;
    }
    
protected:
    int numberOfRooms;  // House and derived classes
};

int main() {
    House myHouse;
    myHouse.address = "123 Main St";  // OK
    myHouse.knockDoor();               // OK
    
    // myHouse.safeCode = "1234";     // ERROR! Private
    // myHouse.openDoor();            // ERROR! Private
    // myHouse.numberOfRooms = 5;     // ERROR! Protected
}
```

**Java Example:**

```java
class House {
    public String address;       // Anyone
    private String safeCode;     // Only House
    protected int numberOfRooms; // House + subclasses
    
    // Default (package-private): same package only
    String ownerName;
    
    public void knockDoor() {
        System.out.println("Knock knock!");
        openDoor();
    }
    
    private void openDoor() {
        System.out.println("Door opened from inside");
    }
}
```

### **For Those Who Can Code:**

**Access Modifier Rules in C++:**

| Context | public | protected | private |
|---------|--------|-----------|---------|
| Same class | ✓ | ✓ | ✓ |
| Derived class | ✓ | ✓ | ✗ |
| Outside class | ✓ | ✗ | ✗ |

**Access Modifier Rules in Java:**

| Context | public | protected | default | private |
|---------|--------|-----------|---------|---------|
| Same class | ✓ | ✓ | ✓ | ✓ |
| Same package | ✓ | ✓ | ✓ | ✗ |
| Subclass (same pkg) | ✓ | ✓ | ✓ | ✗ |
| Subclass (diff pkg) | ✓ | ✓ | ✗ | ✗ |
| Outside | ✓ | ✗ | ✗ | ✗ |

**Design Guidelines:**

1. **Default to private:** Only expose what's necessary
2. **Use protected sparingly:** Breaks encapsulation for subclasses
3. **Minimize public interface:** Easier to maintain

---

## **Abstraction**

### **For Total Beginners:**

Abstraction means hiding complex details and showing only what's necessary. It's like:

**Real-life analogies:**
- **Car:** You know gas pedal = go, brake = stop. Don't need to know about fuel injection, combustion
- **Coffee Machine:** Press button → get coffee. Don't need to know about heating elements, pumps
- **Light Switch:** Flip up = light on. Don't need to know about electrical circuits

**Programming Example:**

```cpp
// WITHOUT Abstraction (Complex, confusing)
class ComplexCar {
public:
    void injectFuel() { /* ... */ }
    void igniteSpark() { /* ... */ }
    void rotateCrankshaft() { /* ... */ }
    void engageTransmission() { /* ... */ }
};

int main() {
    ComplexCar car;
    // User has to know all these details!
    car.injectFuel();
    car.igniteSpark();
    car.rotateCrankshaft();
    car.engageTransmission();
}

// WITH Abstraction (Simple, clear)
class SimpleCar {
private:
    void injectFuel() { /* ... */ }
    void igniteSpark() { /* ... */ }
    void rotateCrankshaft() { /* ... */ }
    void engageTransmission() { /* ... */ }
    
public:
    void startCar() {
        injectFuel();
        igniteSpark();
        rotateCrankshaft();
        engageTransmission();
        cout << "Car started!" << endl;
    }
};

int main() {
    SimpleCar car;
    car.startCar();  // Simple! Don't need to know details
}
```

### **For Those Who Can Code:**

Abstraction is achieved through:

1. **Abstract Classes:** Cannot be instantiated, serve as templates
2. **Interfaces:** Pure abstract classes (Java) or purely virtual classes (C++)

**Abstract Class Example (C++):**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Abstract class (has at least one pure virtual function)
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {}
    
    // Pure virtual function (= 0 makes it abstract)
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    
    // Concrete method (shared by all shapes)
    void displayColor() {
        cout << "Color: " << color << endl;
    }
    
    virtual ~Shape() {}  // Virtual destructor
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}
    
    double getArea() override {
        return width * height;
    }
    
    double getPerimeter() override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    
    double getArea() override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    // Shape shape("Red");  // ERROR! Cannot instantiate abstract class
    
    Rectangle rect("Blue", 5, 3);
    Circle circ("Red", 4);
    
    cout << "Rectangle:" << endl;
    rect.displayColor();
    cout << "Area: " << rect.getArea() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;
    
    cout << "\nCircle:" << endl;
    circ.displayColor();
    cout << "Area: " << circ.getArea() << endl;
    cout << "Perimeter: " << circ.getPerimeter() << endl;
    
    // Polymorphism with abstraction
    Shape* shapes[] = {&rect, &circ};
    cout << "\nPolymorphic access:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Area: " << shapes[i]->getArea() << endl;
    }
    
    return 0;
}
```

**Interface Example (Java):**

```java
// Interface (pure abstraction in Java)
interface Drawable {
    void draw();  // Automatically public and abstract
    void resize(double factor);
}

interface Colorable {
    void setColor(String color);
    String getColor();
}

// Class implementing multiple interfaces
class Rectangle implements Drawable, Colorable {
    private double width, height;
    private String color;
    
    public Rectangle(double w, double h, String c) {
        this.width = w;
        this.height = h;
        this.color = c;
    }
    
    @Override
    public void draw() {
        System.out.println("Drawing " + color + " rectangle");
    }
    
    @Override
    public void resize(double factor) {
        width *= factor;
        height *= factor;
    }
    
    @Override
    public void setColor(String color) {
        this.color = color;
    }
    
    @Override
    public String getColor() {
        return color;
    }
}

public class InterfaceDemo {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(5, 3, "Blue");
        rect.draw();
        rect.resize(2);
        rect.setColor("Red");
        rect.draw();
    }
}
```

---

## **Bad vs Good Class Design**

### **For Total Beginners:**

**Bad Design Example: Everything Public, No Validation**

```cpp
class BadBankAccount {
public:
    string accountNumber;
    string ownerName;
    double balance;
    string password;  // Password is public!
};

int main() {
    BadBankAccount account;
    account.balance = -1000;  // Negative balance? No validation!
    account.password = "abc";  // Anyone can see/change password!
}
```

**Problems:**
- No data validation
- Anyone can modify anything
- Easy to introduce bugs
- No security

**Good Design Example: Private Data, Validation, Encapsulation**

```cpp
class GoodBankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    string passwordHash;  // Hashed, not plaintext
    
    bool isValidAmount(double amount) {
        return amount > 0;
    }
    
    bool isValidPassword(string pwd) {
        return pwd.length() >= 8;  // Simple validation
    }
    
public:
    GoodBankAccount(string accNum, string owner, string pwd) {
        accountNumber = accNum;
        ownerName = owner;
        balance = 0;
        
        if (isValidPassword(pwd)) {
            passwordHash = pwd;  // In real app, hash this!
        } else {
            cout << "Password must be at least 8 characters!" << endl;
        }
    }
    
    bool deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
            return true;
        }
        return false;
    }
    
    bool withdraw(double amount, string pwd) {
        if (pwd != passwordHash) {
            cout << "Wrong password!" << endl;
            return false;
        }
        
        if (isValidAmount(amount) && amount <= balance) {
            balance -= amount;
            return true;
        }
        
        cout << "Insufficient funds or invalid amount!" << endl;
        return false;
    }
    
    double getBalance(string pwd) {
        if (pwd == passwordHash) {
            return balance;
        }
        cout << "Wrong password!" << endl;
        return -1;
    }
};
```

### **For Those Who Can Code:**

**Design Principles Comparison:**

| Aspect | Bad Design | Good Design |
|--------|-----------|-------------|
| Data Members | Public | Private |
| Validation | None | In setters |
| Dependencies | Tightly coupled | Loosely coupled |
| Single Responsibility | Many responsibilities | One clear purpose |
| Naming | Unclear (`x`, `temp`) | Clear (`accountBalance`) |

**Bad Design: God Class (Does Everything)**

```cpp
class BadUserManager {
public:
    // User management
    void createUser(string name) { /* ... */ }
    void deleteUser(int id) { /* ... */ }
    
    // Database operations
    void connectToDatabase() { /* ... */ }
    void executeQuery(string sql) { /* ... */ }
    
    // Email operations
    void sendEmail(string to, string subject) { /* ... */ }
    void validateEmail(string email) { /* ... */ }
    
    // Payment operations
    void processPayment(double amount) { /* ... */ }
    void refund(int transactionId) { /* ... */ }
    
    // Logging
    void logError(string msg) { /* ... */ }
    void logInfo(string msg) { /* ... */ }
};
```

**Good Design: Single Responsibility Principle**

```cpp
// Each class has ONE clear responsibility

class DatabaseConnection {
private:
    string connectionString;
    
public:
    void connect() { /* ... */ }
    void disconnect() { /* ... */ }
    void executeQuery(string sql) { /* ... */ }
};

class EmailService {
private:
    string smtpServer;
    
public:
    bool isValidEmail(string email) { /* ... */ }
    void sendEmail(string to, string subject, string body) { /* ... */ }
};

class PaymentProcessor {
private:
    string apiKey;
    
public:
    bool processPayment(double amount, string cardNumber) { /* ... */ }
    bool refund(string transactionId) { /* ... */ }
};

class Logger {
private:
    string logFile;
    
public:
    void logInfo(string message) { /* ... */ }
    void logError(string message) { /* ... */ }
    void logWarning(string message) { /* ... */ }
};

class UserManager {
private:
    DatabaseConnection db;
    EmailService emailService;
    Logger logger;
    
public:
    void createUser(string name, string email) {
        // Validate email
        if (!emailService.isValidEmail(email)) {
            logger.logError("Invalid email: " + email);
            return;
        }
        
        // Save to database
        db.executeQuery("INSERT INTO users ...");
        
        // Send welcome email
        emailService.sendEmail(email, "Welcome!", "Thanks for joining!");
        
        logger.logInfo("User created: " + name);
    }
};
```

**Benefits of Good Design:**
- **Testable:** Each class can be tested independently
- **Maintainable:** Changes to email don't affect payments
- **Reusable:** EmailService can be used in other projects
- **Clear:** Each class has one job

---

## **Day 3 FAQs**

**Q1: Why make everything private? Isn't that restrictive?**
- Encapsulation protects against bugs. If balance is public, anyone can set it to negative. If private with methods, you can validate.
- You can always relax restrictions, but you can't tighten them without breaking code.

**Q2: What's the difference between encapsulation and abstraction?**
- **Encapsulation:** HOW you hide (using access modifiers)
- **Abstraction:** WHAT you hide (hiding complexity, showing essentials)
- Example: ATM abstracts "withdraw money" (what), encapsulates vault access (how)

**Q3: When should I use an abstract class vs an interface?**
- **Abstract class (C++):** When you have shared code/data among subclasses
- **Interface (Java):** When you want to define a contract with no implementation
- **Java Note:** Use interfaces for "can-do" relationships (Flyable, Drawable), abstract classes for "is-a" with shared behavior

**Q4: Can a class have both abstract and concrete methods?**
- **Yes!** That's the point of abstract classes
- Abstract methods = subclasses must implement
- Concrete methods = shared behavior

**Q5: Why use getters/setters instead of public variables?**
```cpp
// Without getter/setter
class Bad {
public:
    int age;  // Anyone can set age = -5!
};

// With getter/setter
class Good {
private:
    int age;
public:
    void setAge(int a) {
        if (a >= 0 && a <= 120) {
            age = a;
        }
    }
    int getAge() { return age; }
};
```

---

## **Day 3 Quick Quiz (Homework)**

### **Beginner Level:**

1. What does encapsulation mean?
2. List three access modifiers in C++
3. Fix this code:
```cpp
class Student {
public:
    int marks;
};
// Make marks private and add a setter that validates (0-100)
```

4. What's wrong with this design?
```cpp
class BankAccount {
public:
    double balance;
    string password;
};
```

5. Create a `Calculator` class with private methods for add, subtract, multiply, divide. Expose a public `calculate(double a, double b, char op)` method.

### **Intermediate Level:**

1. Design a `SmartLight` class with:
   - Private: `brightness` (0-100), `isOn` (bool)
   - Public: `turnOn()`, `turnOff()`, `setBrightness(int)`, `getBrightness()`
   - Validation: Can't set brightness when off

2. Create an abstract `Animal` class with:
   - Abstract methods: `makeSound()`, `move()`
   - Concrete method: `eat()` (prints "Eating...")
   - Derive `Dog` and `Bird` classes

3. Redesign this God class into separate classes:
```cpp
class MessyClass {
public:
    void readFile() { /* ... */ }
    void writeFile() { /* ... */ }
    void sendEmail() { /* ... */ }
    void calculateTax() { /* ... */ }
};
```

### **Challenge Problems:**

1. Create a `SecurePassword` class that:
   - Stores password as a hash (not plaintext)
   - Validates password strength (min 8 chars, 1 number, 1 special char)
   - Has `checkPassword(string)` that returns bool
   - Never exposes the actual password

2. Design a `ShoppingCart` system:
   - `Product` class (name, price)
   - `Cart` class (private vector of products)
   - Methods: `addProduct()`, `removeProduct()`, `getTotal()`
   - Validation: Can't add same product twice, price > 0

---

# **DAY 4: INHERITANCE & POLYMORPHISM**

---

## **Inheritance**

### **For Total Beginners:**

Inheritance is when a child class gets features from a parent class. It's like:

**Real-life analogies:**
- **You inherit traits from parents:** Eye color, height, personality traits
- **Dog inherits from Animal:** All animals eat, sleep; dogs specifically bark
- **Electric Car inherits from Car:** All cars have wheels, engine; electric cars specifically have batteries

**Simple Example:**

```cpp
// Parent class (Base class)
class Animal {
public:
    string name;
    
    void eat() {
        cout << name << " is eating." << endl;
    }
    
    void sleep() {
        cout << name << " is sleeping." << endl;
    }
};

// Child class (Derived class)
class Dog : public Animal {  // Dog inherits from Animal
public:
    void bark() {
        cout << name << " says: Woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.name = "Buddy";
    
    // Dog can use Animal methods (inherited)
    myDog.eat();    // Inherited from Animal
    myDog.sleep();  // Inherited from Animal
    myDog.bark();   // Dog's own method
}
```

**Key Terms:**
- **Base/Parent/Super class:** The class being inherited from (Animal)
- **Derived/Child/Sub class:** The class that inherits (Dog)
- **IS-A relationship:** Dog IS-A Animal

### **For Those Who Can Code:**

**Types of Inheritance:**

1. **Single Inheritance:** Child inherits from one parent
2. **Multiple Inheritance:** Child inherits from multiple parents (C++ only, not Java)
3. **Multilevel Inheritance:** Chain of inheritance (A → B → C)
4. **Hierarchical Inheritance:** Multiple children from one parent
5. **Hybrid Inheritance:** Combination of above

---

## **Polymorphism**

### **For Total Beginners:**

Polymorphism means "many forms." Same thing behaves differently in different situations.

**Real-life analogies:**
- **"Go":** For car = start engine, for person = start walking, for website = load page
- **Mobile phone button:** Volume up = increase call volume (during call), increase music volume (during music)
- **Payment:** Can pay with cash, card, or mobile app—same action, different implementations

**Simple Example:**

```cpp
class Shape {
public:
    virtual void draw() {  // Virtual = can be overridden
        cout << "Drawing a generic shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {  // Override parent method
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    
    shape1->draw();  // Calls Circle's draw()
    shape2->draw();  // Calls Square's draw()
    
    // This is polymorphism! Same method name, different behavior
    
    delete shape1;
    delete shape2;
}
```

### **For Those Who Can Code:**

**Types of Polymorphism:**

1. **Compile-Time (Static) Polymorphism:**
   - Function Overloading
   - Operator Overloading

2. **Runtime (Dynamic) Polymorphism:**
   - Virtual Functions (C++)
   - Method Overriding

---

## **When Inheritance is Bad**

### **For Total Beginners:**

Inheritance can be bad when it creates confusing or wrong relationships.

**Example 1: Square inherits from Rectangle?**

```cpp
class Rectangle {
public:
    int width, height;
    
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    
    int getArea() { return width * height; }
};

class Square : public Rectangle {
    // Problem: Square has width and height, but they should always be equal!
    // This violates the "Square is always equal sides" rule
};

int main() {
    Square sq;
    sq.setWidth(5);
    sq.setHeight(10);  // Wait... now it's not a square!
}
```

**Why it's bad:**
- Square violates the definition of Rectangle (width can be different from height)
- Breaks the "IS-A" test: A square IS-A rectangle mathematically, but not in code behavior

### **For Those Who Can Code:**

**Problems with Inheritance:**

1. **Tight Coupling:** Child depends heavily on parent
2. **Fragile Base Class:** Changes to parent break children
3. **Deep Hierarchies:** Hard to understand and maintain
4. **Inappropriate IS-A:** Logical relationship doesn't match code behavior

---

## **Favor Composition Over Inheritance**

### **For Total Beginners:**

Instead of saying "Square IS-A Rectangle," say "Square HAS-A SideLengthProperty."
Instead of saying "Employee IS-A Person," say "Employee HAS-A Person."

**Real-life analogy:**
- **Inheritance:** "Electric Car IS-A Car"
- **Composition:** "Car HAS-A Engine, HAS-A Wheels, HAS-A Battery"

**Why Composition is Better:**
- More flexible
- Easier to change
- Can "have" multiple things
- Can change behavior at runtime

**Example: Bad Inheritance**

```cpp
class Person {
public:
    string name;
    int age;
};

class Employee : public Person {
    int employeeID;
    double salary;
};
```

**Example: Good Composition**

```cpp
class Person {
public:
    string name;
    int age;
    
    Person(string n, int a) : name(n), age(a) {}
};

class Employee {
private:
    Person person;  // HAS-A Person (composition)
    int employeeID;
    double salary;
    
public:
    Employee(Person p, int id, double sal) 
        : person(p), employeeID(id), salary(sal) {}
    
    string getName() { return person.name; }
    int getAge() { return person.age; }
};
```

**Benefits:**
- Person can be reused elsewhere (in Student, Customer, etc.)
- Employee doesn't depend on Person's implementation
- Can easily add multiple "roles" (someone can be Employee AND Student)

---

## **Day 4 FAQs**

**Q1: When should I use inheritance vs composition?**
- **Inheritance:** When there's a clear, unchanging IS-A relationship (Dog IS-A Animal)
- **Composition:** When you need flexibility, multiple behaviors, or runtime changes (ShoppingCart HAS-A PaymentMethod)
- **Rule of thumb:** Prefer composition. Only use inheritance when composition doesn't make sense

**Q2: What's the diamond problem in multiple inheritance?**

```cpp
class A { public: void foo() {} };
class B : public A {};
class C : public A {};
class D : public B, public C {};  // D has two copies of A!

int main() {
    D obj;
    obj.foo();  // Error! Ambiguous - which A::foo()?
}
```

**Solution:** Virtual inheritance or use composition

**Q3: What's the difference between overloading and overriding?**

| Aspect | Overloading | Overriding |
|--------|------------|-----------|
| Type | Compile-time | Runtime |
| Same class? | Yes | No (parent/child) |
| Signature | Different | Same |
| Keyword | None | `override` (C++), `@Override` (Java) |

**Q4: Why do we need virtual destructors?**

```cpp
class Base {
public:
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
    int* data;
public:
    Derived() { data = new int[100]; }
    ~Derived() {
        delete[] data;
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Only calls Base destructor! Memory leak!
}
```

**Solution:**
```cpp
class Base {
public:
    virtual ~Base() { cout << "Base destructor" << endl; }
};
// Now delete ptr calls both destructors correctly
```

---

## **Day 4 Quick Quiz (Homework)**

### **Beginner Level:**

1. What does inheritance represent in real-world terms?
2. What's the difference between IS-A and HAS-A relationships?
3. What's polymorphism? Give a real-life example.
4. Why is Square inheriting from Rectangle a bad design?

### **Intermediate Level:**

1. Create a `Shape` hierarchy:
   - Abstract `Shape` base class with `getArea()` and `getPerimeter()`
   - `Circle`, `Rectangle`, `Triangle` derived classes
   - Demonstrate polymorphism with a vector of Shape pointers

2. Redesign this using composition:
```cpp
class Employee : public Person {
    // ...
};
class Manager : public Employee {
    // ...
};
```

3. Create a `Logger` interface with different implementations:
   - `ConsoleLogger` (prints to console)
   - `FileLogger` (writes to file)
   - `DatabaseLogger` (saves to database)
   - Use composition in an `Application` class

### **Challenge Problems:**

1. **Complex Polymorphism:**
   Create a `NotificationSystem`:
   - `Notification` base class
   - `EmailNotification`, `SMSNotification`, `PushNotification`
   - `NotificationSender` class that can send any notification type
   - Add `priority` levels and `retry` mechanisms

2. **Composition Design:**
   Design a game character system:
   - `Character` class with composition
   - `AttackBehavior` interface (`MeleeAttack`, `RangedAttack`, `MagicAttack`)
   - `DefenseBehavior` interface (`ShieldDefense`, `DodgeDefense`, `ArmorDefense`)
   - Character can change behaviors at runtime (equip/unequip)

---

# **FINAL SUMMARY & BEST PRACTICES**

---

## **Key Takeaways:**

1. **System Design:** Plan before you code (HLD → LLD)
2. **Encapsulation:** Hide data, expose behavior through methods
3. **Abstraction:** Show only what's necessary, hide complexity
4. **Inheritance:** IS-A relationships, be careful not to overuse
5. **Polymorphism:** Same interface, different implementations
6. **Composition > Inheritance:** More flexible, easier to maintain

---

## **Design Principles (SOLID):**

1. **S**ingle Responsibility: One class, one job
2. **O**pen/Closed: Open for extension, closed for modification
3. **L**iskov Substitution: Subclasses should be replaceable
4. **I**nterface Segregation: Many small interfaces > one large interface
5. **D**ependency Inversion: Depend on abstractions, not concretions

---

## **Golden Rules:**

- **Make data private by default**
- **Favor composition over inheritance**
- **Program to interfaces, not implementations**
- **Keep hierarchies shallow (max 2-3 levels)**
- **Use polymorphism for behavior variation**
- **Encapsulate what varies**
- **Design for testability**

---

## **Additional Resources**

### **Recommended Reading:**
- "Design Patterns: Elements of Reusable Object-Oriented Software" (Gang of Four)
- "Head First Object-Oriented Analysis and Design"
- "Clean Code" by Robert C. Martin
- "Effective C++" by Scott Meyers (C++ specific)
- "Effective Java" by Joshua Bloch (Java specific)

### **Practice Platforms:**
- LeetCode (OOP problems)
- HackerRank (OOP challenges)
- Codewars (Design patterns katas)

### **Next Steps:**
1. Practice implementing design patterns (Factory, Strategy, Observer, etc.)
2. Study SOLID principles in depth
3. Learn UML diagrams for system design
4. Build a real project applying all concepts
5. Study common interview questions on OOP

---

**Remember:** OOP is not about making code longer—it's about making code **clearer, more maintainable, and more flexible**. Always ask: "Will this design make sense to someone reading it 6 months from now?"

**Good luck with your learning journey! 🚀**

---

*End of Guide*
