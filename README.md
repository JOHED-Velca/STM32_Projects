# STM32_Projects

This repository contains various STM32 microcontroller projects developed for the ARM Cortex-M platform. Each project demonstrates different aspects of embedded development, from basic GPIO control to sensor interfacing.

## Projects Overview

- **avoidanceSensor/** - Obstacle avoidance sensor implementation
- **Blinky_v2/** - Enhanced LED blinking project with CMake build system
- **nucleo_L476RG_laser/** - Laser control project for Nucleo-L476RG
- **nucleo_L476RG_PhotoInterrupter/** - Photo interrupter sensor interface

## Development Ecosystem & Workflow

This repository follows professional embedded development practices using a comprehensive toolchain that enables productive STM32 development outside of proprietary IDEs.

### Core Development Tools

#### Essential Foundation

- **Git** - Version control, collaboration, and code management
  - Used for: `git clone`, `git commit`, `git diff`, project history
- **Build Essentials** - Fundamental compilation tools
  - Package: `build-essential` (includes gcc, g++, make, etc.)
  - Required even when using ARM-specific compilers

#### ARM Embedded Toolchain

- **gcc-arm-none-eabi** - Cross-compiler for ARM Cortex-M microcontrollers
  - Generates: `.elf`, `.bin`, `.hex` firmware files
  - Essential for producing STM32-compatible binaries
- **arm-none-eabi-gdb** (or `gdb-multiarch`) - ARM debugger
  - Enables: breakpoints, stepping, variable watches, memory inspection

#### Build Systems

Professional projects must build without IDE dependency for CI/CD integration:

- **Make** - Simple, widely supported (common with CubeMX Makefile projects)
- **CMake + Ninja** - Modern, scalable build system (used in Blinky_v2)

### Flashing & Debugging Infrastructure

#### Primary Tools

- **OpenOCD** - Universal debug probe interface
  - Acts as bridge between ST-Link/J-Link probes and GDB
  - Supports flashing, debugging, reset/run operations
- **ST-Link Tools** (`stlink-tools`)
  - Utilities: `st-info`, `st-flash`
  - Quick probe detection and simple flashing operations

#### Official ST Tools

- **STM32CubeProgrammer** - ST's official programming tool
  - Most reliable for flashing/erasing/option bytes
  - Supports DFU and various programming modes
  - Essential when OpenOCD encounters compatibility issues

#### Hardware Interface

- **Udev Rules for ST-Link** - Critical for development workflow
  - Enables user-level access to debug probes without `sudo`
  - Prevents "permission denied" errors during flashing/debugging

### Code Generation & Vendor Support

#### STM32 Ecosystem Tools

- **STM32CubeMX** - Hardware abstraction layer generator
  - Generates initialization code for: clocks, pin configuration, peripheral setup
  - Industry standard for STM32 projects regardless of IDE choice
- **STM32CubeIDE** (optional) - Integrated development environment
  - Comprehensive debugging UI
  - Many professionals use for debugging while building via command line

### Development Quality Tools

#### Code Management

- **Code Editor**: VS Code, CLion, or Vim
  - Features: efficient editing, navigation, autocomplete, Git integration
- **clang-format** - Automated code formatting
  - Maintains consistent code style across team development
  - Essential for professional team collaboration

#### Code Quality (Advanced)

- **Static Analysis**: `cppcheck`, `clang-tidy`
  - Early detection of bugs and anti-patterns
  - Improves code reliability before runtime testing

### Communication & Debugging

#### Serial Communication

- **Terminal Tools**: `minicom`, `picocom`, or `screen`
  - Essential for UART-based debugging and printf output
  - Primary interface for runtime diagnostics

#### Advanced Hardware Debugging

- **Logic Analyzer Software**: `sigrok`/`PulseView`
  - Protocol analysis for I2C, SPI, UART signals
  - Hardware-level debugging when software debugging insufficient

### Minimum Professional Setup

For productive STM32 development, the essential toolchain includes:

1. **Git** - Version control
2. **build-essential** - Basic build tools
3. **gcc-arm-none-eabi** + **arm-none-eabi-gdb** - ARM toolchain
4. **Make** or **CMake+Ninja** - Build system
5. **OpenOCD** - Debug interface
6. **STM32CubeProgrammer** or **stlink-tools** - Flashing
7. **STM32CubeMX** - Code generation
8. **VS Code** + **clang-format** - Development environment
9. **udev rules for ST-Link** - Hardware permissions
10. **Serial terminal** (`minicom`/`picocom`) - Communication

### Project-Specific Configurations

Each project in this repository demonstrates different aspects of this workflow:

- **Blinky_v2** showcases CMake-based build system with proper project structure
- Projects target **Nucleo-L476RG** development boards primarily
- All projects designed for ST-Link debugging interface

### Getting Started

1. Install the essential toolchain for your distribution
2. Clone this repository
3. Navigate to desired project directory
4. Follow project-specific build instructions
5. Use ST-Link for flashing and debugging

This setup enables professional embedded development with full CI/CD compatibility, team collaboration, and industry-standard debugging capabilities.
