//
//Coded by Arsen Stoian
#include <iostream>
#include <time.h>
#include "generators.h"
#include "user_interface.h"

using namespace std;

void* doCallRand(int gen_num, long long seed = 0){

    if(seed == 0)
         seed = time(NULL) % m;
    switch(gen_num){
    case 1:{
        long long *arr = random1();
        double *arr2 = compress(arr);
        double *fr = freq(arr2);
        print_histogram(fr);
        break;}
    case 2:{
        long long *arr = random2();
        double *arr2 = compress(arr);
        double *fr = freq(arr2);
        print_histogram(fr);
        break;}
    case 3:{
        long long *arr = random3(seed);
        double *arr2 = compress(arr);
        double *fr = freq(arr2);
        print_histogram(fr);
        break;}
    case 4:{
        long long *arr = random4(seed);
        double *arr2 = compress(arr, size, p);
        double *fr = freq(arr2);
        print_histogram(fr);
        break;}//lox
    case 5:{
        long long *arr = random3(seed);
        double *arr2 = compress(arr);
        double *fr = freq(arr2);
        print_histogram(fr);
        break;}
    case 6:{
        double *arr = random6(seed);
        double *fr = freq(arr, -3.0, 3.0);
        print_histogram(fr, -3.0, 3.0);
        break;}
    case 7:{
        double *arr = random7(seed);
        double *fr = freq(arr, -3.0, 3.0);
        print_histogram(fr, -3.0, 3.0);
        break;}
     case 8:{
        double *arr = random8(seed);
        double *fr = freq(arr, -3.0, 3.0);
        print_histogram(fr, -3.0, 3.0);
        break;}
    case 9:{
        double *arr = random9(seed);
        double *fr = freq(arr, 0, 100, 1);
        print_histogram(fr, 0, 100, 1);
        break;}
    case 10:{
        double *arr = random10(seed);
        double *fr = freq(arr, 0, 100, 1);
        print_histogram(fr, 0, 100, 1);
        break;}
    }
}

int main()
{
    print_greeting();
    bool stop_app = false;

    int gen_num = choose_gen();
    long long seed = -1;
    if(gen_num == 0)
        stop_app = true;

    if(!stop_app)
        seed = input_seed();

    try{
        if(gen_num >= 1 && gen_num <= 10){
            doCallRand(gen_num, seed);
        }
        print_succes();
    }
    catch(exception &ex)
    {
        print_fail(ex.what());
    }

    return 0;
}
