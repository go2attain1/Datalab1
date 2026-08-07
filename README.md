# Bit-Level Integer Manipulation

A collection of C implementations for solving common **bit-level manipulation and two's complement arithmetic problems** using restricted operators.

This project focuses on understanding how integers are represented at the binary level and how operations such as shifting, masking, and bitwise logic can be used to implement arithmetic and logical functions without relying on higher-level operators.

## Overview

The project contains implementations of six bit-manipulation functions:

| # | Function          | Description                                                                                 |
| - | ----------------- | ------------------------------------------------------------------------------------------- |
| 1 | `thirdBits`       | Returns an integer with every third bit set to `1`, starting from the least significant bit |
| 2 | `dividePower2`    | Computes `x / 2^n`, rounding toward zero                                                    |
| 3 | `isNonNegative`   | Determines whether an integer is non-negative                                               |
| 4 | `remainderPower2` | Computes `x % 2^n` while preserving the sign of the remainder                               |
| 5 | `replaceByte`     | Replaces a specified byte within a 32-bit integer                                           |
| 6 | `howManyBits`     | Determines the minimum number of bits needed to represent an integer in two's complement    |

## Concepts Demonstrated

The implementations make extensive use of:

* **Bitwise AND (`&`)**
* **Bitwise OR (`|`)**
* **Bitwise XOR (`^`)**
* **Bitwise NOT (`~`)**
* **Left shifts (`<<`)**
* **Arithmetic right shifts (`>>`)**
* **Two's complement representation**
* **Bit masks**
* **Sign extension**
* **Binary search using bit shifts**
* **Integer overflow and bit-level arithmetic**

## Function Details

### `thirdBits`

Creates a 32-bit integer where every third bit, starting from the least significant bit, is set to `1`.

Example pattern:

```text
01001001 00100100 10010010 01001001
```

The implementation builds the pattern from a smaller repeating bit sequence and expands it using left shifts and OR operations.

---

### `dividePower2`

Computes:

```text
x / 2^n
```

while rounding the result toward zero.

Because arithmetic right shifts round negative numbers downward, the implementation uses a **bias** for negative values before performing the shift.

For example:

```text
dividePower2(15, 1)  → 7
dividePower2(-33, 4) → -2
```

---

### `isNonNegative`

Determines whether an integer is greater than or equal to zero using its sign bit.

In two's complement:

* Sign bit `0` → non-negative
* Sign bit `1` → negative

The function extracts the sign bit and flips it to produce the required Boolean result.

---

### `remainderPower2`

Computes:

```text
x % 2^n
```

while preserving the sign of the remainder for negative inputs.

The implementation first extracts the lower `n` bits using a mask. For negative values with a nonzero remainder, it adjusts the result by subtracting `2^n`.

Examples:

```text
remainderPower2(15, 2)  → 3
remainderPower2(-35, 3) → -3
```

---

### `replaceByte`

Replaces byte `n` of a 32-bit integer with a new byte value.

Bytes are numbered from the least significant byte:

```text
Byte 3    Byte 2    Byte 1    Byte 0
[31..24]  [23..16]  [15..8]   [7..0]
```

For example:

```text
replaceByte(0x12345678, 1, 0xAB)
→ 0x1234AB78
```

The implementation clears the target byte using a mask and then inserts the new value using bit shifting.

---

### `howManyBits`

Determines the minimum number of bits required to represent an integer using two's complement.

Examples:

```text
howManyBits(12)          → 5
howManyBits(298)         → 10
howManyBits(-5)          → 4
howManyBits(0)           → 1
howManyBits(-1)          → 1
howManyBits(0x80000000)  → 32
```

The implementation first normalizes negative numbers by flipping their bits, then uses a **binary-search approach** to locate the highest significant bit.

## Restricted Operators

These functions were designed under a restricted operator set:

```text
!  ~  &  ^  |  +  <<  >>
```

This restriction requires the solutions to perform operations that would normally be handled by arithmetic or comparison operators entirely through bit-level manipulation.

## Skills Demonstrated

This project demonstrates experience with:

* C programming
* Low-level integer representation
* Two's complement arithmetic
* Bitwise programming
* Algorithmic problem solving
* Bit masking and shifting
* Working under strict implementation constraints
* Debugging and reasoning about binary data

## Project Structure

```text
.
├── README.md
└── bits.c
```

## Background

These problems are based on the style of exercises found in **Computer Systems / Systems Programming** courses and are intended to develop a deeper understanding of how computers represent and manipulate integer data at the machine level.
