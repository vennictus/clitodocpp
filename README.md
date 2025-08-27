# ✅ CLI Todo List Application

A simple **command-line to-do list manager** written in **C++**, designed to help you stay organized directly from your terminal.  
This app lets you add tasks, track their progress, and mark them as completed — all with a clean and minimal interface.

---

## ✨ Features

- ➕ **Add Tasks**: Create new tasks with a unique, sequential ID.  
- ✅ **Mark as Completed**: Finish tasks by marking them as complete using their ID.  
- 📊 **Track Progress**: Update task progress with a percentage (0–100%).  
- 🗑️ **Clear All Tasks**: Wipe the entire list in one go.  
- 📋 **Sorted Display**: Incomplete tasks always appear first, followed by completed ones.  
- ▓ **Progress Bar**: Each task includes a visual progress bar for easy tracking.  

---

## ⚙️ How to Build & Run

You’ll need a **C++ compiler** (like `g++`) installed on your system.

1. **Save the code**  
   Save the source file as `todo.cpp`.

2. **Compile**  
   Open your terminal and run:

   ```bash
   g++ todo.cpp -o todo
   ```

   ⚠️ **Note (Windows-specific):**  
   The code may include `windows.h` (for `Sleep()` and `system("cls")`).  
   - If you're on Linux or macOS, remove those lines and replace them with platform-specific alternatives.

3. **Run**  
   ```bash
   ./todo
   ```

---

## 🖥️ Usage

When you launch the program, you’ll see a menu:

- `[A]dd Item` → Add a new task  
- `[M]ark Item as Completed` → Mark a task as 100% done  
- `[P]rogress Item` → Update a task’s completion percentage  
- `[C]lear Memory` → Delete all tasks  
- `[E]xit` → Quit the application  

---

## 🛠️ Technologies Used

- **C++** → Core language  
- **C++ Standard Library** → Used for I/O and data structures (`<iostream>`, `<string>`, `<list>`)  

---

## 🚀 Example

```
=== Todo List Menu ===
[A]dd Item
[M]ark Item as Completed
[P]rogress Item
[C]lear Memory
[E]xit

Enter choice: A
Enter task: Finish README for project
Task added! (ID: 1)
```

---

## 📌 Future Improvements

- Save/load tasks to a file for persistence  
- Support deadlines and priorities  
- Search/filter tasks  

---

💡 This project is great for practicing **C++ basics**, **OOP**, and **CLI programming**!
