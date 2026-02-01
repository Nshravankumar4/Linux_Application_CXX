✅ The correct way (NO cd build needed)

From project root (~), run:

cmake -S . -B build

What this means:

-S . → source directory (current directory)

-B build → build directory

CMake will generate everything inside build/, even though you never entered it.

✅ Build without changing directory

Still from project root:

cmake --build build

✅ Run the executable (still without cd)
./build/app

🔥 Full workflow (ZERO directory changes)
nano src/Hello.cpp
cmake -S . -B build
cmake --build build
./build/app


No cd.
No jumping back and forth.
Clean. Professional. Fast.

Perfect 👍
Here’s your **FINAL, SHORT & POWERFUL Ubuntu + Nano + CMake cheat sheet** — fast, practical, no noise.

---

# 🚀 UBUNTU QUICK CHEAT SHEET (FINAL)

## 📁 DIRECTORY & FILE COMMANDS

```
ls            → list files
pwd           → current path
cd dir        → go to dir
cd ..         → back
cd ~          → home
mkdir build   → create dir
rm file       → delete file
rm -r build   → delete folder
cp a b        → copy file
mv a b        → move / rename
clear         → clear terminal
```

---

## ✏️ NANO EDITOR (FASTEST SHORTCUTS)

### 🔹 Select / Copy / Paste

```
ALT + A     → start selection
Arrow keys → expand selection
ALT + 6     → copy
CTRL + K   → cut
CTRL + U   → paste
```

### 🔹 Select ALL (FAST)

```
ALT + A
ALT + /
ALT + 6
```

### 🔹 Navigation

```
ALT + /     → end of file
ALT + \     → start of file
CTRL + _   → go to line
CTRL + W   → search
```

### 🔹 Save & Exit

```
CTRL + O   → save
ENTER
CTRL + X   → exit
```

---

## 💻 TERMINAL COPY / PASTE

```
CTRL + SHIFT + C   → copy
CTRL + SHIFT + V   → paste
```

---

## 🛠️ CMAKE (NO cd BUILD — PROFESSIONAL WAY)

### ✅ Configure (from project root)

```
cmake -S . -B build
```

### ✅ Build

```
cmake --build build
```

### ✅ Clean build

```
rm -r build
cmake -S . -B build
cmake --build build
```

### ✅ Run executable

```
./build/app
```

---

## ⚡ CMAKE SHORTCUT (ALIAS – OPTIONAL BUT 🔥)

Add shortcut:

```
nano ~/.bashrc
```

Add at bottom:

```
alias cb='cmake -S . -B build'
alias bb='cmake --build build'
alias run='./build/app'
```

Reload:

```
source ~/.bashrc
```

Now just type:

```
cb
bb
run
```

🚀 **Ultra fast**

---

## 🔥 FULL ZERO-CD WORKFLOW

```
nano src/Hello.cpp
cb
bb
run
```

---

## 🧠 MOST IMPORTANT (REMEMBER THIS)

```
ALT + A   → select
ALT + /   → end of file
ALT + 6   → copy
CTRL+ K   → cut
CTRL+ U   → paste

cb        → cmake configure
bb        → build
run       → execute
```

---

This is **exactly how professionals work on Ubuntu + CMake**
If you want **one-page PDF**, **Vim version**, or **CMake debug tips**, tell me 🔥
