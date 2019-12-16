#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp.h"
#define ROTATION 4
#define EXTRANEOUS_ITERATION 1

typedef enum {
    up,
    right,
    down,
    left
} direction;
char *makeString(char *s1, char *s2) {
    char *pointTrack, *sample, *result;
    if (!(result = pointTrack = malloc(strlen(s1) + strlen(s2) + 1)))
        return NULL;
    for (sample = s1; (*pointTrack = *sample) != '\0'; ++pointTrack, ++sample)
        ;
    for (sample = s2; (*pointTrack = *sample) != '\0'; ++pointTrack, ++sample)
        ;
    result[strlen(s1) + strlen(s2)] = '\0';
    return result;
}
char *createFibWord (int n) {
    if (n <= 0) {
        return "";
    }
    if (n == 1) {
        return "1";
    }
    if (n == 2) {
        return "0";
    }
    return makeString(createFibWord(n-1), createFibWord(n-2));
}
int fib( int n, int x, int y, int step , RGB bc , RGB fc , int w, int h,
        RGB* image )
{
    if (image == NULL || n < 3) return 0;
    #define I(i, j) image[(i)*w + (j)]
    char *fibWord = createFibWord(n);
    direction dir = up;
    int digitNum = 1, length = 0;
    for (int i = 0; i < w * h; i++) {
      image[i] = bc;
    }
    while(*fibWord) {
        int increments;
        if (dir == up) {
            for (increments = 0; increments < step; increments++) {
                if (y > (h - 1)) return 0;
                I(x + increments, y) = fc;
            }
            x+= step;
        }
        else if (dir == right) {
            for (increments = 0; increments < step; increments++) {
                if (x > (w - 1)) return 0;
                I(x, y + increments) = fc;
            }
            y+= step;

        }
        else if (dir == down) {
            for (increments = 0; increments < step; increments++) {
                if (y < 0) return 0;
                I(x - increments, y) = fc;
            }
            x-= step;

        }
        else if (dir == left) {
            for (increments = 0; increments < step; increments++) {
                if (x < 0) return 0;
                I(x, y - increments) = fc;
            }
            y-= step;
        }
        length++;
        if (*fibWord == '0') {
            if (digitNum % 2) {
                if (dir == left) dir = up;
                else dir+=1;
            }
            else {
                if (dir == up) dir = left;
                else dir-=1;
            }
        }
        digitNum++;
        fibWord++;
    }
    return length - EXTRANEOUS_ITERATION;
}
