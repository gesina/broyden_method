# Implementation of Broyden's method

This project was an excercise for the lecture 
*Numerical Mathematics* for Bachelor students by
[Prof. Dr. Blank](http://www.mathematik.uni-regensburg.de/Mat8/Blank/)
at the University of Regensburg in 2014. It implements
[Broyden's method](https://en.wikipedia.org/wiki/Broyden%27s_method) 
for approximating roots of functions in *k* variables.

## Compilation
For compilation you need **gcc** and **make**. Then call
```bash
make
```

## Functionality
The programm `broyden_method` will offer a couple of example functions
to choose from (see `broyden_functions.h` for documentation).
You can then enter start values
(start point and your guess for the derivation at that point)
and other parameters.
I recommend taking the default.

It will print the steps into `OUTPUT_FILE` (see `broyden_file.h`; 
currently `broyden_method_output.txt`).
If possible, an approximation result for a root ist printed to the
console.

## Structure of the Files
Mind the comments in the source files that try to
describe the functionality.

- Broyden's method: `broyden_method.*`
- Matrix operations (addition, multiplication, memory allociation): `matrix_operations.*`
- Solution of linear equation systems (with LU decomposition; see also
  [here](https://github.com/gesina/lu_decomposition)): `solve_equation.*`
- Example functions to choose from: `broyden_functions.*` 
  (see also `FUNCTION_OPTIONS*` in `broyden_input.h`)
- Main function: `broyden_main.*`
- File-/Terminal-IO: `broyden_file.*`, `broyden_input.*`, `broyden_output.*`
- Build helper: `Makefile`, `broyden.deps`
