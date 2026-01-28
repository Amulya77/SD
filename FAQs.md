### DAY -1 
---
    1.What is the main difference between HLD and LLD?

    2.Name the four pillars of OOP

    3.In the Car example, what type of relationship exists between Car and Engine? (is-a or has-a?)

    4.Why is OOP better than writing all code in one large function?

It sounds like you're diving into system design and software architecture! These are the fundamental building blocks that separate "coding" from "engineering."

Here is the breakdown of your questions:

---

## 1. HLD vs. LLD: The Bird’s Eye vs. The Microscope

The main difference lies in the **scope and audience**.

* **High-Level Design (HLD):** Focuses on the **overall architecture**. It describes "what" the system does and how data flows between major components like databases, servers, and external APIs. It’s the "big picture" used by stakeholders and architects.
* **Low-Level Design (LLD):** Focuses on the **implementation details**. It describes "how" specific features work at the code level, including class diagrams, method signatures, and design patterns. It’s the "blueprint" used by developers to write the actual code.

---

## 2. The Four Pillars of OOP

Object-Oriented Programming (OOP) is built on these four concepts:

1. **Encapsulation:** Bundling data (properties) and methods (actions) into a single unit (a class) and restricting direct access to some components to keep data safe.
2. **Abstraction:** Hiding complex implementation details and showing only the necessary features of an object.
3. **Inheritance:** Allowing a new class (subclass) to take on the properties and methods of an existing class (superclass).
4. **Polymorphism:** The ability of different objects to respond to the same function call in their own specific way (e.g., a `Shape` class has a `draw()` method, but `Circle` and `Square` draw differently).

---

## 3. The Car and Engine Relationship

In the Car example, the relationship is a **"has-a"** relationship.

* **Has-a (Composition/Aggregation):** A Car **has an** Engine. The engine is a component *within* the car.
* **Is-a (Inheritance):** This would be something like "A Sedan **is a** Car."

---

## 4. Why OOP beats the "One Giant Function" approach

Writing everything in one massive function (often called "Spaghetti Code") is a recipe for a headache. OOP is superior because:

* **Maintainability:** If there’s a bug in how "Wheels" work, you just look at the `Wheel` class, not 5,000 lines of unrelated code.
* **Reusability:** You can use the `Engine` class in a `Truck` or a `Boat` without rewriting it.
* **Scalability:** It’s much easier for a team of 10 people to work on 10 different classes simultaneously than to fight over one giant file.
* **Readability:** Code structured around real-world objects is more intuitive for humans to understand.

---