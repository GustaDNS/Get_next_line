# Get Next Line - 42 Project

## 📜 Description

**Get Next Line** is a project from 42 that teaches fundamental skills in file handling and memory management in C. The objective is to implement the function `get_next_line()`, which reads one line at a time from a file descriptor and returns it as a string.

This project focuses on low-level I/O operations, dynamic memory allocation, and efficient buffer management.

### Function Prototype

```c
int get_next_line(int fd, char **line);
```

fd: 
```c
The file descriptor to read from (e.g., 0 for stdin or a file descriptor returned by open()).
```
line:
```c
A pointer to the string where the line read from the file will be stored.
The function should return:
```
1 if a line was successfully read.
0 when the end of the file (EOF) is reached.
-1 if an error occurs.

### 🛠️ Project Features
Read One Line at a Time: Your function must read one line from a file descriptor per call.
Dynamic Memory Management: Allocate and free memory dynamically for each line.
Efficient Buffer Management: Implement a buffer to handle partial lines and optimize the reading process.
Edge Case Handling: Handle various edge cases like files without newline characters, empty lines, and large lines.

### 🧑‍🏫 What You Will Learn
By completing the Get Next Line project, you will gain valuable experience with key concepts in C programming, such as:

File Handling:
```c
Learn how to work with low-level file operations (open(), read(), close()), giving you insight into how files are managed at the system level.
```
Memory Management:
```c
Practice dynamic memory allocation (malloc(), free()) to manage memory efficiently and avoid memory leaks.
```
String Manipulation:
```c
Work with C strings and learn how to manage and manipulate null-terminated strings effectively.
```
Edge Case Management:
```c
Develop your skills in handling edge cases, such as missing newlines, large lines, or files that end unexpectedly.
```
Code Efficiency:
```c
Write optimized, efficient code to minimize memory usage and manage resources effectively.
```
### 📁 Project Structure
The repository contains the following files:

get_next_line.c: The core implementation of the get_next_line() function.
get_next_line.h: Header file containing the function prototype and necessary includes.
Makefile: A script for compiling the project.
tests/: Directory containing sample test cases for verifying the functionality.

### 📝 Conclusion
The Get Next Line project is a rewarding challenge that will significantly improve your understanding of low-level file operations, memory management, and string manipulation in C. Successfully completing this project will provide you with essential skills for working with system-level tasks and prepare you for more advanced programming challenges.

### Key Features of the Formatting:

- **Sections**: Clear sections with titles like "Description," "Project Features," "What You Will Learn," etc., making it easy for readers to navigate.
- **Code Blocks**: Important code snippets and commands are highlighted using Markdown code blocks for clarity.
- **Emojis**: Emojis are used to make the README more engaging and visually appealing.
- **Bullet Points**: Used to list features, learnings, and project components in an organized way.
