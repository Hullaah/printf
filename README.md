# 🔧 `printf` Clone in C — From Scratch Using Only `write(2)`

This project is a full-featured reimplementation of the standard C `printf` function — **built entirely from scratch** using only the low-level `write` system call.

It includes its own **buffering system**, **format specifier parser**, and **modular handlers** for each format type — without depending on the standard library's `printf`, `sprintf`, or related routines.

---

## 📌 Motivation

The standard C library's `printf` is deceptively complex, involving variadic arguments, formatting rules, padding logic, and internal buffering.

This project was created to:
- Deepen understanding of **low-level I/O**, **format parsing**, and **variadic functions**
- Gain practical experience building reusable, modular code under constraints
---

## ✨ Key Features

### ✅ Format Specifiers Supported:
| Specifier | Meaning                      |
|-----------|------------------------------|
| `%c`      | Character                    |
| `%s`      | String                       |
| `%d`/`%i` | Signed decimal integer       |
| `%u`      | Unsigned decimal integer     |
| `%x`      | Lowercase hexadecimal        |
| `%X`      | Uppercase hexadecimal        |
| `%o`      | Octal                        |
| `%%`      | Literal `%` character        |

---

### 🧾 Supported Flags:
| Flag  | Meaning                                  |
|-------|------------------------------------------|
| `-`   | Left-align within the field width        |
| `+`   | Always print the sign (`+` or `-`)       |
| (space) | Print space if no sign is used        |
| `0`   | Pad with zeros instead of spaces         |
| `#`   | Use alternate form (`0x`, `0X`, `0` etc) |

---

### 📏 Width & Precision:
- Field width supported (e.g. `%10d`)
- Precision supported for strings and numbers (e.g. `%.5s`, `%.4d`)
- Combined width & precision supported (e.g. `%08.4d`)

---

### 🧱 Length Modifiers:
| Modifier | Meaning                     |
|----------|-----------------------------|
| `hh`     | `char` or `unsigned char`   |
| `h`      | `short` or `unsigned short` |
| `l`      | `long` or `unsigned long`   |
| `ll`     | `long long` or `unsigned long long` |

---

### ⚙️ Core Architecture

- ✅ Manual parsing of format strings
- ✅ Variadic argument handling with `stdarg.h`
- ✅ Internal output buffer with flushing control
- ✅ Edge-case handling:
  - `LLONG_MIN` signed overflow
  - Mixed flags (`+`, ` `, `0`, `-`)
  - Zero precision with zero value (`%.0d`)
  - Buffer overflow protection

---

## 🛠️ Building the Project

### 🔧 Requirements
- GCC or Clang
- `make`
- Unix-like OS (Linux, macOS, WSL, etc.)

### 🧪 Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/Hullaah/printf.git
cd printf
```
2. Build the **static** and **shared** libraries:
```bash
make
```
This produces:
- `libprintf.a` → static library
- `libprintf.so` → shared (dynamic) library
3. Optionally, run the included test program
```bash
make test
./printf
```

## 🧠 What I Learned
- How printf actually works under the hood
- Designing and implementing format parsers
- Manual buffer management and flushing logic
- Respecting field width, precision, flags, and length modifiers
- Debugging tricky issues like signed integer overflow (LLONG_MIN)
- Writing clean, maintainable low-level C code

## 👨‍💻 Author
**Umar Adelowo**

Intermediate systems programmer focused on OS, networking, and low-level development.
Aiming to contribute to the Linux Kernel and become a security and systems expert.

[📧 Contact me](umaradelo1.247@gmail.com)

🌐 GitHub: [@Hullaah](https://github.com/Hullaah)
