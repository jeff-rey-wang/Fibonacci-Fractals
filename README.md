# Fibonacci-Fractals

In this program, a fibonacci fractal is draw iteratively by applying the Odd-Even drawing rule to a fibonacci word.

When running the program, the user is asked to provide a set of parameters where,

n; the nth fibonacci word fractal to be drawn by the program
x,y; the starting position of the fractal along the x and y axis, respectively
step; the length of each segment in pixels
width, height; the dimensions of the produced image

Before drawing, the program creates the nth fibonacci word as requested by the user. Because fibonacci words are concatenations of their two preceding words, the nth word can be produced simply by recursively concatenating until the desired word is reached.
