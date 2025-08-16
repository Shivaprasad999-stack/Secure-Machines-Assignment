# Secure-Machines-Assignment
This is related  to internship assignment

# Internship Assignment Project

## 📌 Overview
This repository contains solutions for an assignment with two parts:
1. **RTL Design (Verilog, ModelSim)** – 4-bit counter that increments every 2 seconds using a 100 MHz input clock, simulated in ModelSim.
2. **1024-bit Arithmetic (C)** – custom implementation of large integer operations without external libraries.

---

## 🔧 Part 1: Verilog – 4-bit Counter
- Inputs: `clk` (100 MHz), `reset` (active-high synchronous)
- Output: `led[3:0]`
- RTL module written in Verilog
- Simulated using ModelSim (with reduced divider for faster simulation)
- Demonstrates counter increments on waveform

🔧 Part 2: C – 1024-bit Arithmetic

Custom 1024-bit data type (uint1024_t) using an array of 32x32-bit words

Implemented operation:

Greater-than comparison (a > b)

Helper functions:

Initialize from 64-bit values

Hexadecimal printing

Includes 4 test vectors to demonstrate correctness
