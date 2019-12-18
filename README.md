# Fibonacci-Fractals

In this program, a fibonacci fractal is draw iteratively by applying the Odd-Even drawing rule to a fibonacci word.

When running the program, the user is asked to provide a set of parameters where,

n; the nth fibonacci word fractal to be drawn by the program

x, y; the starting position of the fractal along the x and y axis, respectively

step; the length of each segment in pixels

width, height; the dimensions of the produced image

## Procedure

Before drawing, the program creates the nth fibonacci word as requested by the user. Because fibonacci words are concatenations of their two preceding strings, the nth word can be produced simply by recursively concatenating until the desired word is reached.

Using the Odd-Even drawing rule, an iterative loop runs through the fibonacci word and draws each segment to a length of 'step' pixels. Upon completing the fractal, the drawing is saved to a file with its name provided by the user. In addition the file, the program will return the time taken to run the program.  

## Running the program

To run the program, download all provided files onto your machine. Type "make" to create the 'fib' executable. In order to provide the necessary parameters, adhere to the form:

```
./fib n x y step  width height filename
```
Example:

```
./fib 25 10 10 5 5000 5000 fib25.bmp
```

***Note that fractals of n > 30 may take a significant amount of time to compute, and require intensive processing power to view.***

To clean type "make clean".
