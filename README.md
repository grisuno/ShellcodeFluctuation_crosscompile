# 🦠 C ShellcodeFluctuation Port 🦠

<img width="1024" height="1024" alt="image" src="https://github.com/user-attachments/assets/eb611080-73b3-4d4e-8f04-d4cf6e1a9bf4" />
  
A Windows ​​​​🪟 shellcode injection 💉​ and memory evasion tool implementing advanced anti-analysis techniques through API hooking and dynamic memory protection manipulation.  
  
## ​🔬​ Overview  
  
ShellcodeFluctuation demonstrates proof-of-concept techniques for executing shellcode while evading memory-based detection systems. The tool intercepts `Sleep()` API calls to trigger memory protection changes and XOR encryption, making the shellcode invisible to memory scanners during dormant periods. [3](#0-2)   



  
## 🗝️​ Key Features  
  
- **API Hooking**: Intercepts `Sleep()` calls using inline trampolines (`fastTrampoline`)  
- **Memory Fluctuation**: Alternates memory protection between `PAGE_EXECUTE_READ`, `PAGE_READWRITE`, and `PAGE_NOACCESS`  
- **XOR Encryption**: Encrypts shellcode in memory when not executing  
- **Exception-Based Execution**: Uses Vectored Exception Handlers (VEH) for on-demand decryption  
- **Cross-Platform Build**: Compiles from Linux to Windows executables using MinGW [4](#0-3)   
  
## 🔧​ Operational Modes  
  
The tool supports four execution modes:  
  
| Mode | Description | Evasion Technique |  
|------|-------------|-------------------|  
| `-1` | No injection, infinite loop | Testing/placeholder |  
| `0` | Basic injection | No evasion |  
| `1` | RW Fluctuation | XOR encryption + `PAGE_READWRITE` ↔ `PAGE_EXECUTE_READ` |  
| `2` | NA Fluctuation (ORCA666) | XOR encryption + `PAGE_NOACCESS` ↔ `PAGE_EXECUTE_READ` + VEH | [5](#0-4)   
  
## 🔨​ Build Instructions  
  
### 📋​ Prerequisites  
  
- Linux environment (Debian/Ubuntu recommended)  
- MinGW-w64 cross-compiler  
- Python 3.x  
  
### 🗜️​ Compilation  
  
```bash  
# Install MinGW toolchain  [header-1](#header-1)
sudo apt install mingw-w64  
  
# Compile  [header-2](#header-2)
x86_64-w64-mingw32-gcc main.c -lkernel32 -lntdll -s -O2 -o ShellcodeFluctuation.exe
```

## 🪛​ Usage
```bash  
ShellcodeFluctuation.exe <shellcode.raw> <mode>
```

## 💣​ Examples
```bash  
# Basic injection without evasion  [header-3](#header-3)
./ShellcodeFluctuation.exe payload.bin 0  
  
# RW fluctuation with XOR encryption  [header-4](#header-4)
./ShellcodeFluctuation.exe payload.bin 1  
  
# NOACCESS fluctuation with exception handling  [header-5](#header-5)
./ShellcodeFluctuation.exe payload.bin 2
```

## 🔭​ Technical Details
### 🗄️​ Architecture
The tool uses three global structures to manage state:

- **FluctuationMetadata:** Tracks shellcode address, size, encryption state, and XOR key
- **HookedSleep:** Stores original Sleep() function pointer and prologue bytes
- **TypeOfFluctuation:** Enum controlling operational mode main.c:250-261

## 🩻​ How It Works

- **Injection:** Allocates memory with VirtualAlloc(), copies shellcode, sets PAGE_EXECUTE_READ protection
- **Hooking:** Installs inline trampoline on Sleep() API to intercept calls
- **Fluctuation:** On each Sleep() call from shellcode thread:
- **Encrypts shellcode with XOR**
- **Changes memory protection to PAGE_READWRITE or PAGE_NOACCESS**
- **Calls original Sleep()**
- **Decrypts and restores PAGE_EXECUTE_READ**
- **Exception Handling (Mode 2):** VEH catches access violations and decrypts on-demand main.c:93-99

<img width="304" height="912" alt="image" src="https://github.com/user-attachments/assets/ca4682d6-2047-4956-9685-fdd081865f3d" />
<img width="465" height="912" alt="image" src="https://github.com/user-attachments/assets/a84ae43f-9b58-40b4-aaef-54dedb90ff66" />
<img width="330" height="912" alt="image" src="https://github.com/user-attachments/assets/a44f99d0-5d4b-4d65-851d-ebe5e30b5ede" />
<img width="911" height="912" alt="image" src="https://github.com/user-attachments/assets/b1b89c7e-5867-45d5-9600-eb943669e95b" />


## 🖥️​ System Requirements
- **Target:** Windows 7+ (x64)
- **Build:** Linux with MinGW-w64
- **Dependencies:** kernel32.dll, ntdll.dll (standard Windows libraries)

## ⛔​🚫​🚭​ Security Notice
⚠️ For educational and authorized security research only. Unauthorized use of shellcode injection tools is illegal. Use only in controlled environments with proper authorization.

## 📜​ License
GPL v3

## ✒️​ Autor:
**mgeeky**
the original code you can find here:
https://github.com/mgeeky/ShellcodeFluctuation

🖋️ i only ported to C


![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) ![Flask](https://img.shields.io/badge/flask-%23000.svg?style=for-the-badge&logo=flask&logoColor=white) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)


---
### Grisuno Offensive Security Ecosystem
This tool is part of a broader, synergistic RedTeam workflow:
- [LazyOwn](https://github.com/grisuno/LazyOwn): RedTeam/APT framework with AI-powered C&C, rootkits and malleable implants (Windows/Linux/Mac).
- [LazyOwnBT](https://github.com/grisuno/LazyOwnBT): Advanced complementary toolkit for BlueTeam professionals.
- [Lazymapd](https://github.com/grisuno/Lazymapd): Fast, customizable port scanner for firewall evasion.

<!-- readmenator-kb-link -->
## Knowledge Base

This project has been analyzed by [ReadMenator](https://github.com/grisuno/ReadMenator),
a zero-token polyglot static analysis tool. Analysis outputs are available:

- **[KNOWLEDGE_BASE.md](./KNOWLEDGE_BASE.md)** -- Full architecture reference with all
  classes, functions, imports, dependency graphs, UML class diagrams, security
  audit findings, community analysis, and more.
- **[readmenator-agent/](./readmenator-agent/)** -- Agent-friendly, grep-optimized index.
  - `INDEX.md` -- Quick reference: what each file does
  - `API.md` -- Public function contracts
  - `GOTCHAS.md` -- Change warnings
  - `SECURITY.md` -- Findings by severity

AI agents: Read `readmenator-agent/INDEX.md` for fast project context.
Developers: Read `KNOWLEDGE_BASE.md` for full architecture reference.
<!-- /readmenator-kb-link -->

