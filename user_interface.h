#pragma once
#include <iostream>
using std::ostream;

/*
All of these methods can throw exceptions for standard I/O errors.
*/

void print_greeting(ostream &out = std::cout);
//prints information about program

int choose_gen(ostream &out = std::cout);
//prints brief info about generators and asks to choose one of versions
//Returns:
//1 - 10: number of generator["1" - "10" on keyboard]
//0: quit["q","Q","0" on keyboard]

long long input_seed(ostream &out = std::cout);
//gets seed from user

void print_help(ostream &out = std::cout);
//prints list of generators

void print_succes(ostream &out = std::cout);
//prints that app worked without problems

void print_fail(const std::string& reason, ostream &out = std::cout);
//prints that app had problems while working

void print_histogram(double *fr, double from = 0.0, double to = 1.0, double step = 0.1, ostream &out = std::cout);
//outputs a histogram of the distribution of numbers in the interval [from, to] with step
//tested with steps 1 and 0,1
//tested on ranges [0, 1] [-3, 3] [0, 100]
//for other arguments it may not work correctly


