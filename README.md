Circular Buffer Implementation in C

Course: Embedded Systems (CE-ESY26)
Assignment: Assignment 1

---

📌 Overview

This project presents a complete implementation of a Circular Buffer (Ring Buffer) using the C programming language.
The circular buffer is a fixed-size data structure widely used in embedded systems for efficient data handling under memory constraints.

Unlike a linear buffer, the circular buffer reuses memory by wrapping around when reaching the end of the array, making it highly efficient for continuous data streams.

---

🎯 Objectives

- Implement a circular buffer manually without using built-in data structures.
- Understand FIFO (First-In, First-Out) data handling.
- Handle critical edge cases:
  - Buffer Overflow (write to full buffer)
  - Buffer Underflow (read from empty buffer)
- Apply modular arithmetic to achieve circular behavior.

---

🧠 System Design

Data Structure

The buffer is implemented using a "struct":

- "data[MAX]" → stores the elements (characters)
- "front" → points to the next element to be read
- "rear" → points to the next position to write
- "used" → keeps track of the number of stored elements

This design ensures clear separation between read and write operations.

---

⚙️ Core Functionalities

1. Initialization ("setup")

Resets all indices and prepares the buffer for operation.

2. State Checking

- "isEmpty()" → checks if buffer is empty
- "isFull()" → checks if buffer is full

3. Write Operation ("push")

- Inserts a new element into the buffer.
- Updates the "rear" pointer using circular logic.
- Prevents overflow and notifies the user.

4. Read Operation ("pop")

- Retrieves and removes the oldest element.
- Updates the "front" pointer.
- Prevents underflow and ensures safe access.

---

🔁 Circular Mechanism

The circular behavior is achieved using modulo arithmetic:

rear = (rear + 1) % MAX;
front = (front + 1) % MAX;

This ensures that the buffer reuses space efficiently without exceeding array bounds.

---

🚀 Program Workflow

1. Initialize the buffer.
2. Prompt the user to input a name.
3. Append the string ""CE-ESY"" to the input.
4. Insert each character into the buffer using the "push" function.
5. If the buffer reaches its capacity, an overflow message is displayed.
6. Read all stored characters using the "pop" function.
7. Print the result sequentially.
8. Verify that the buffer is empty after all operations.

---

⚠️ Edge Case Handling

- Overflow: Prevents writing when the buffer is full.
- Underflow: Prevents reading when the buffer is empty.
- Buffer size is intentionally limited ("MAX = 5") to demonstrate overflow behavior clearly.

---

▶️ Example Execution

Input:

yousif

Processed Input:

yousifCE-ESY

Output:

Output: yousi
Overflow!
Buffer empty now

---

📁 Project Structure

- "prog.c" → contains the full implementation of the circular buffer

---

💡 Key Takeaways

- Circular buffers are essential in embedded systems for managing limited memory.
- Proper handling of edge cases is critical for system stability.
- Modular arithmetic enables efficient reuse of memory space.

---

✅ Conclusion

This implementation demonstrates a robust and efficient circular buffer system in C.
It highlights fundamental concepts in embedded programming such as memory management, data flow control, and low-level system design.

---
