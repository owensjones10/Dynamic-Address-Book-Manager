
# Dynamic Address Book Manager

A C++ application designed to manage contact information dynamically using linked lists. The program allows you to store, search, sort, and delete contact entries with an efficient and user-friendly interface.

---

## Features

- **Dynamic Data Management**:
  Utilizes linked lists to handle an unlimited number of entries.

- **CRUD Operations**:
  - Add new contacts.
  - Delete existing contacts.
  - Update and search for specific entries.

- **File Handling**:
  - Load and save contact information to/from files for persistent storage.

- **Sorting and Filtering**:
  - Sort contacts dynamically by name.
  - Filter contacts by status, birthday month, or name ranges.

- **Object-Oriented Design**:
  - Encapsulation and inheritance for modularity.
  - Custom classes (`personType`, `extPersonType`, etc.) to represent data.

---

## Installation

### Prerequisites

- A C++ compiler (e.g., GCC, MSVC).
- [Git](https://git-scm.com/) installed on your machine.

### Clone the Repository

```bash
git clone https://github.com/owensjones10/Dynamic-Address-Book-Manager.git
cd Dynamic-Address-Book-Manager
```

---

## Usage

### Build the Project

1. Open a terminal and navigate to the `Dynamic Address Book Manager` folder.
2. Run the following command to compile the project:
   ```bash
   g++ -I include -o main src/*.cpp
   ```

### Run the Program

```bash
./main
```

### Sample Workflow

1. **Load Address Book**: Enter the name of the file (e.g., `data.txt`) to load contacts.
2. **Interact with the Menu**:
   - Add, search, delete, or display contact entries.
3. **Save Changes**: Save your modifications to a file for future use.

---

## File Structure

```
Dynamic Address Book Manager/
│
├── include/
│   ├── addressBookType.h
│   ├── addressType.h
│   ├── dateType.h
│   ├── extPersonType.h
│   └── personType.h
│
├── src/
│   ├── addressBookType.cpp
│   ├── addressType.cpp
│   ├── dateType.cpp
│   ├── extPersonType.cpp
│   └── main.cpp
│
├── data/
│   ├── data.txt
│   └── out.txt
│
└── README.md
```

---

## Example Input File (`data.txt`)

```plaintext
John Doe 1 15 1990
123 Main St
Anytown
FL
12345 555-5555 Friend
Jane Smith 2 20 1985
456 Elm St
Othertown
NY
67890 444-4444 Business
```

---

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Author

Developed by **Owen Jones** ([owensjones10](https://github.com/owensjones10)).
