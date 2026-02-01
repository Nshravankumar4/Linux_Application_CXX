Ah! Got it — you want to **see your Linux project files in a folder locally** (like in Windows Explorer) while working in WSL. Let me explain step by step.

---

### 1️⃣ Access your Linux files from Windows Explorer

Since you are using **WSL**:

1. Open your file explorer in Windows.
2. In the address bar, type:

   ```
   \\wsl$
   ```

   This shows all installed WSL distributions.
3. Navigate to your distro, e.g.:

   ```
   \\wsl$\Ubuntu\home\shravannunsavath\Final
   ```

   Here you can see all your Linux files just like normal Windows files.

> ✅ Tip: You can right-click the folder and “Pin to Quick Access” for easy access.

---

### 2️⃣ Open files in a code editor (VS Code, etc.)

* If you have **VS Code**, you can open the WSL folder directly:

  ```bash
  cd ~/Final
  code .
  ```

  This opens the `Final` folder in VS Code using the **WSL extension**, so you can edit Linux files directly.

---

### 3️⃣ If you want to copy files to Windows folder

You can copy your Linux project to a Windows folder using:

```bash
cp -r ~/Final /mnt/c/Users/<YourWindowsUsername>/Documents/
```

* Here `/mnt/c/` is your Windows `C:` drive.
* Replace `<YourWindowsUsername>` with your Windows username.

---
