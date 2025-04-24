# example-unicode

Demonstrates the use of an external library to handle Unicode characters in C. Moreover, it shows how to configure the CMake build system.

Uses the [sheredom/utf8.h](https://github.com/sheredom/utf8.h) library.

The program shows the difference in sorting between UTF-8 and ASCII. It reads a file containing Unicode characters, sorts the lines according UTF-8 and ASCII, and prints the results.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/main tests/data/w3-utf-8-test.txt
```
