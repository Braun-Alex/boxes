# S-box and P-box algorithms

Practise task № 3 for Distributed Lab Course "Cryptography in decentralized systems" 2023.

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

## 💬 Description

### S-box

| Input data size | Output data size | Data fragmentation  | Cryptosystem | 
| :-------------- | :--------------- | :------------------ | :----------- |
| `8 bits`        | `8 bits`         | `4 bits` + `4 bits` | Serpent      |

### P-box

| Input data size | Output data size | Data fragmentation | Cryptosystem | 
| :-------------- | :--------------- | :----------------- | :----------- |
| `8 bits`        | `8 bits`         | No                 | Serpent      |

## 🛠 Running tests

Clone the project

```bash
git clone https://github.com/Braun-Alex/boxes.git
```

Go to the project directory

```bash
cd boxes
```

Build the project with CMake

```bash
mkdir build
cd build
cmake ..
make
```

Run the tests

```bash
./boxes
```

> **Notice.** To run the tests you need a compatible operating system (e.g. Linux, macOS, Windows); a compatible C++ compiler that supports
> at least C++ 14; CMake and a compatible build tool for building the project; GoogleTest.
