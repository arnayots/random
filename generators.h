#pragma once
const int size = 10000;
const int m = 1234561;
const int p = 5917;
const int inf = 63427;

long long * random1(long long seed = 2, int amount = 0);
//Linear congruence method.
long long * random2(long long seed = 7);
//Quadratic congruence method.
long long * random3(long long seed = 1);
//Fibonacci numbers.
long long * random4(long long seed = 1);
//Inverted congruent sequence.
long long * random5(long long seed = 1);
//The method of integration.
double * random6(long long seed = 1);
//The rule of 3 sigma.
double * random7(long long seed = 1);
//Polar coordinate method.
double * random8(long long seed = 1);
//The method of relations.
double * random9(long long seed = 1);
//Logarithm method for generating indicative distribution.
double * random10(long long seed = 1);
//The Ahrens method for generating a gamma distribution of order a > 1.

double * compress(long long *source, int lenght = size, int m = 0);
//compess array from range [0, m - 1] to [0, 1]

double * freq(double * src, double from = 0.0, double to = 1.0, double step = 0.1);
//outputs an array of numbers between intervals in range [from, to] and step of inner ranges
//returns array of length (to - from) / step + 1, where:
// 0 - (to - from) / step : part of numbers in current area
// (to - from) + 1: sum of all parts in range [from, to]
//tested with steps 1 and 0,1
//tested on ranges [0, 1] [-3, 3] [0, 100]
//for other arguments it may not work correctly
//void print_histogram(double*, double from, double to, double step, ostream&) from "user_interface.h" correctly prints histogram from this data
