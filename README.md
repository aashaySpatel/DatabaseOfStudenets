# DatabaseOfStudenets
# Student Database — CS 211, Spring 2023

A command-line student records management system written in C. The program maintains a linked-list-based database of students and automatically organizes them into multiple sorted views for quick lookup.

---

## Features

- Load students from a CSV file or start with an empty database
- Add, view, and delete student records interactively
- Automatically categorizes each student into relevant lists on insert:
  - **Honor Roll** — GPA ≥ 3.5 (sorted by GPA descending)
  - **Academic Probation** — GPA < 2.0 (sorted by GPA ascending)
  - **Freshman** — 0–29 credit hours (sorted by name)
  - **Sophomore** — 30–59 credit hours (sorted by name)
  - **Junior** — 60–89 credit hours (sorted by name)
  - **Senior** — 90+ credit hours (sorted by name)
  - **Master ID List** — all students, sorted by ID

---

## Data Structures

Each `Student` holds:
- `name` (string)
- `id` (string, must be unique)
- `gpa` (double)
- `creditHours` (int)

The `Database` struct holds seven separate singly-linked lists (`StudentNode*`), each pointing to the same underlying `Student` objects — so a student exists in memory once but is referenced from multiple lists.

---

## Getting Started

### Compile

```bash
gcc -o student_db starter_code.c
```

### Run

```bash
./student_db
```

---

## Usage

On startup, choose how to initialize the database:

```
Enter E to start with an empty database,
or F to start with a database that has information on students from a file.
Your choice --> F
Enter the name of the file you would like to use: students.csv
```

### CSV Format

The file must have a header row followed by one student per line:

```
name,id,gpa,creditHours
Alice Smith,A12345678,3.8,95
Bob Jones,B98765432,1.7,45
```

### Main Menu (CRDX)

Once the database is loaded, the program loops on:

| Command | Action |
|---------|--------|
| `C` | Create — add a new student manually |
| `R` | Read — display students from one of the sorted lists |
| `D` | Delete — remove a student by ID |
| `X` | Exit — free all memory and quit |

### Read Options

```
1) Display the head (first 10 rows) of the database
2) Display students on the honor roll, in order of their GPA
3) Display students on academic probation, in order of their GPA
4) Display freshmen students, in order of their name
5) Display sophomore students, in order of their name
6) Display junior students, in order of their name
7) Display senior students, in order of their name
8) Display the information of a particular student
```

---

## Key Functions

| Function | Description |
|----------|-------------|
| `addToDB` | Validates and inserts a student into all applicable lists |
| `deleteStudentfromDB` | Removes a student from every list and frees memory |
| `getFile` | Parses a CSV file and bulk-loads students into the database |
| `getNewStudent` | Prompts the user for student data and adds them manually |
| `clearDB` | Frees all nodes and student data (called on exit) |
| `printList` | Prints up to N students from a given linked list |
| `displayStudentInfo` | Looks up and prints a single student by ID |

---

## Notes

- Duplicate IDs are rejected at insert time.
- All memory is dynamically allocated (`malloc`) and freed on deletion or exit.
- Input is read with `fgets` throughout to avoid buffer overflows.
