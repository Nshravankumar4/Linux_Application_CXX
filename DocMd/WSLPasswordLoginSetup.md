# WSL Password Login Setup - Complete Documentation

## Overview
This document explains how WSL login authentication was configured to require a password when starting WSL, similar to a traditional Linux system.

---

## What Was Done

### Configuration Summary
- **Default User:** Changed from `shravannunsavath` to `root`
- **Login Method:** Automatic login prompt via `.bashrc`
- **Authentication:** Password required for user `shravannunsavath`

---

## Files Modified

### 1. `/etc/wsl.conf` - WSL Configuration
**Purpose:** Configure WSL default user and system settings

**Location:** `/etc/wsl.conf`

**Content:**
```ini
[boot]
systemd=true

[user]
default=root

[interop]
enabled=true
appendWindowsPath=true

[network]
generateHosts=true
generateResolvConf=true
```

**What Each Section Does:**
- `[boot] systemd=true` - Enables systemd init system
- `[user] default=root` - WSL starts as root user (then prompts for login)
- `[interop] enabled=true` - Allows running Windows executables from WSL
- `[interop] appendWindowsPath=true` - Access Windows PATH from WSL
- `[network] generateHosts=true` - Auto-generate /etc/hosts
- `[network] generateResolvConf=true` - Auto-generate DNS configuration

---

### 2. `/root/.bashrc` - Root User Bash Configuration
**Purpose:** Trigger login prompt when WSL starts

**Location:** `/root/.bashrc`

**Key Addition (Lines 5-9):**
```bash
# Auto login prompt - MUST BE BEFORE THE PS1 CHECK
if [[ $- == *i* ]] && [ -z "$WSL_LOGIN_DONE" ]; then
    export WSL_LOGIN_DONE=1
    exec login
fi
```

**How It Works:**
1. `[[ $- == *i* ]]` - Checks if shell is interactive
2. `[ -z "$WSL_LOGIN_DONE" ]` - Checks if login hasn't run yet (prevents loop)
3. `export WSL_LOGIN_DONE=1` - Sets flag to prevent re-running
4. `exec login` - Replaces current shell with login prompt

---

## Login Flow Diagram

```
┌─────────────────────────────────────┐
│  User types: wsl                    │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  WSL starts with default user: root │
│  (configured in /etc/wsl.conf)      │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  Root's .bashrc executes             │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  Login code in .bashrc checks:      │
│  - Is interactive? ✓                │
│  - Already logged in? ✗             │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  Executes: exec login               │
│  Shows: "DESKTOP-9ASPK4E login: "   │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  User enters: shravannunsavath      │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  System prompts: "Password: "       │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  User enters password                │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│  Authentication successful!          │
│  User logged in as: shravannunsavath│
└─────────────────────────────────────┘
```

---

## Step-by-Step Setup Instructions

### Step 1: Set User Password
```bash
# Start WSL
wsl

# Set password for user
sudo passwd shravannunsavath
```

**Enter:**
- Current sudo password (if prompted)
- New password
- Confirm new password

**Output:** `passwd: password updated successfully`

---

### Step 2: Configure WSL Default User

```bash
# Edit WSL configuration
sudo nano /etc/wsl.conf
```

**Add/Modify:**
```ini
[boot]
systemd=true

[user]
default=root

[interop]
enabled=true
appendWindowsPath=true

[network]
generateHosts=true
generateResolvConf=true
```

**Save:** `Ctrl+O`, `Enter`, `Ctrl+X`

---

### Step 3: Configure Root's .bashrc

```bash
# Edit root's bash configuration
sudo nano /root/.bashrc
```

**Add at the TOP (after initial comments, before `[ -z "$PS1" ] && return`):**
```bash
# Auto login prompt - MUST BE BEFORE THE PS1 CHECK
if [[ $- == *i* ]] && [ -z "$WSL_LOGIN_DONE" ]; then
    export WSL_LOGIN_DONE=1
    exec login
fi
```

**Save:** `Ctrl+O`, `Enter`, `Ctrl+X`

---

### Step 4: Apply Changes

```bash
# Exit WSL
exit
```

**From Windows CMD/PowerShell:**
```cmd
# Shutdown WSL completely
wsl --shutdown

# Wait 5-8 seconds

# Start WSL
wsl
```

---

### Step 5: Test Login

**You should see:**
```
DESKTOP-9ASPK4E login: _
```

**Enter:** `shravannunsavath`

**You should see:**
```
Password: _
```

**Enter:** Your password (won't display on screen)

**Success:** You're now logged in!

---

## User Management Commands

### Create New User
```bash
# Create user
sudo adduser newusername

# Add to sudo group
sudo usermod -aG sudo newusername
```

### Set/Change User Password
```bash
# Change your own password
passwd

# Change another user's password (as root/sudo)
sudo passwd username
```

### Delete User
```bash
# Delete user (keep home directory)
sudo deluser username

# Delete user and home directory
sudo deluser --remove-home username
```

### List All Users
```bash
# View all users
cat /etc/passwd

# View only usernames
cut -d: -f1 /etc/passwd
```

### Check Current User
```bash
# Show current username
whoami

# Show user details
id
```

---

## Password Management

### Password File Locations
- **User passwords:** `/etc/shadow` (encrypted, root only)
- **User info:** `/etc/passwd`
- **Group info:** `/etc/group`

### Password Security Commands

```bash
# Lock user account
sudo passwd -l username

# Unlock user account
sudo passwd -u username

# Check password status
sudo passwd -S username

# Force password change on next login
sudo passwd -e username

# Set password expiry (days)
sudo chage -M 90 username

# View password expiry info
sudo chage -l username
```

---

## Troubleshooting

### Issue: No password prompt appears

**Solution 1:** Verify `/root/.bashrc`
```bash
wsl
head -15 /root/.bashrc
```

Should show the login code at lines 5-9.

**Solution 2:** Check `/etc/wsl.conf`
```bash
cat /etc/wsl.conf
```

Should show `default=root`.

**Solution 3:** Completely restart WSL
```cmd
wsl --shutdown
# Wait 10 seconds
wsl
```

---

### Issue: "Permission denied" or login fails

**Solution:** Reset password
```bash
# From Windows, login as root
wsl -u root

# Reset password
passwd shravannunsavath

# Exit and try again
exit
wsl --shutdown
wsl
```

---

### Issue: Want to disable password login

**Method 1:** Change default user back
```bash
# Edit wsl.conf
sudo nano /etc/wsl.conf
```

Change:
```ini
[user]
default=shravannunsavath
```

**Method 2:** Remove login code from .bashrc
```bash
sudo nano /root/.bashrc
```

Delete lines 5-9 (the login code).

**Then:**
```bash
exit
wsl --shutdown
wsl
```

---

## Security Notes

### Authentication Levels

1. **Windows Level:** WSL inherits Windows user session (no password)
2. **WSL Level (configured):** Password required via `login` command
3. **Sudo Level:** Password required for administrative tasks

### Best Practices

- ✅ Use strong passwords (12+ characters, mixed case, numbers, symbols)
- ✅ Different password than Windows account
- ✅ Enable `sudo` password requirement (already default)
- ✅ Regular password updates
- ❌ Don't disable `sudo` password
- ❌ Don't use `NOPASSWD` in sudoers

### Password Requirements

Check/set password policies:
```bash
# Install password quality checker
sudo apt install libpam-pwquality

# Edit password policy
sudo nano /etc/security/pwquality.conf
```

Example settings:
```
minlen = 12          # Minimum length
dcredit = -1         # Require at least 1 digit
ucredit = -1         # Require at least 1 uppercase
lcredit = -1         # Require at least 1 lowercase
ocredit = -1         # Require at least 1 special char
```

---

## Advanced Configuration

### Auto-logout After Idle Time

Add to `~/.bashrc`:
```bash
# Auto-logout after 10 minutes of inactivity
export TMOUT=600
```

### Login Banner

Create custom login message:
```bash
# Edit message of the day
sudo nano /etc/motd
```

### Disable System Info on Login

```bash
# Create hushlogin file for user
touch ~/.hushlogin

# Or for root
sudo touch /root/.hushlogin
```

---

## Summary

| Component | Purpose | Location |
|-----------|---------|----------|
| `/etc/wsl.conf` | Set default user to root | System-wide |
| `/root/.bashrc` | Trigger login prompt | Root user |
| `/etc/passwd` | User account info | System-wide |
| `/etc/shadow` | Encrypted passwords | System-wide (root only) |
| `passwd` command | Set/change passwords | Command line |

**Key Concept:** WSL starts as `root` → `.bashrc` runs → `exec login` prompts for username/password → User logs in → Regular shell starts

---

## Quick Reference Commands

```bash
# User Management
sudo adduser username              # Create user
sudo passwd username               # Set password
sudo deluser username              # Delete user
whoami                             # Current user
id                                 # User details

# WSL Control (from Windows)
wsl                                # Start WSL
wsl --shutdown                     # Stop WSL
wsl --list --running               # Show running instances
wsl -u root                        # Login as root
wsl -d Ubuntu -u username          # Login as specific user

# Password Management
passwd                             # Change own password
sudo passwd username               # Change user password
sudo passwd -l username            # Lock account
sudo passwd -u username            # Unlock account
sudo passwd -S username            # Check status
```

---

## Files Reference

### Complete /root/.bashrc (First 20 lines)
```bash
# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# Auto login prompt - MUST BE BEFORE THE PS1 CHECK
if [[ $- == *i* ]] && [ -z "$WSL_LOGIN_DONE" ]; then
    export WSL_LOGIN_DONE=1
    exec login
fi

# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# don't put duplicate lines in the history. See bash(1) for more options
# ... or force ignoredups and ignorespace
HISTCONTROL=ignoredups:ignorespace

# append to the history file, don't overwrite it
shopt -s histappend
```

### Complete /etc/wsl.conf
```ini
[boot]
systemd=true

[user]
default=root

[interop]
enabled=true
appendWindowsPath=true

[network]
generateHosts=true
generateResolvConf=true
```

---

**End of Documentation**

---

*Created: January 26, 2026*  
*System: WSL Ubuntu 24.04.3 LTS on Windows 11*  
*User: shravannunsavath*
