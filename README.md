# WatchOS

"What time is it?"
"Time for you to get a watch!"

**WatchOS** is a minimalist operating system that does one thing: display the current time in real-time. Built with C and assembly, WatchOS is a simple yet powerful project for understanding the basics of operating system development. It runs as a bootable ISO and can be tested using an emulator like QEMU.

## Features:
- Displays time from the RTC (Real-Time Clock) of the system.
- Bootable ISO that runs on virtual machines or real hardware.
- Written in C (for the kernel) and assembly (for bootloader support).

## Building and Running WatchOS:

### Requirements:
To build and run WatchOS, you’ll need the following software:
- **Linux/macOS** (or Windows with WSL)
- **QEMU** (for testing the OS)
- **GRUB** (for bootloader support)
- **Build tools**: `gcc`, `nasm`, `make`

### Step-by-Step Installation:

#### 1. Install Dependencies:
On a **Debian-based system** (like Ubuntu), you can install the necessary dependencies using the following command:

```bash
sudo apt-get update
sudo apt-get install qemu-system-x86 grub-pc-bin nasm gcc make
```

For **macOS** (using Homebrew), run:
```bash
brew install qemu nasm gcc make
```

For **Windows**, you can use **WSL** (Windows Subsystem for Linux) and install the above tools using the same commands as Linux.

#### 2. Clone the Repository:
Next, clone the WatchOS repository to your local machine:
```bash
git clone https://github.com/anik-kaushik-kumar/watch-os.git
cd watch-os
```

#### 3. Build the ISO:
To build the WatchOS ISO, run the following command:
```bash
make
```

#### 4. Run WatchOS in QEMU:
After building the ISO, you can test WatchOS in QEMU (a lightweight emulator). Run:
```bash
make run
```
This will boot the OS in QEMU, and you should see the current time displayed on a black screen.

#### 5. Clean Build Artifacts:
To clean up any generated files and reset the build, run:
```bash
make clean
```

### License
Distributed under the MIT License. See the `LICENSE` file for more information.

### Acknowledgments:

- QEMU for providing the virtualization software to test WatchOS.

- GRUB for bootloader support.
