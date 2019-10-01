//
#define PI 3.14159265358979323846
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <algorithm> //gcd

#include "generators.h"
using namespace std;

long long * random1(long long seed, int amount)
{
    static long long res[size]{};
    res[0] = 3;

    int a = seed;
    const int c = 4;

    if(m <= 0)
        throw out_of_range("in long long * random1( ) m <= 0");
    if(a < 0 || a >= m)
        throw out_of_range("in long long * random1( ) a is out of range [0, m)");
    if(c < 0 || c >= m)
        throw out_of_range("in long long * random1( ) c is out of range [0, m)");
    if(amount == 0)
        amount = size;

    for(int i = 1; i < amount; ++i)
        res[i] = (a * res[i-1] + c) % m;

    return res;
}

bool isprime(int N);

long long * random2(long long seed)
{
    static long long res [size];
    res[0] = 3;
    int a = seed;
    const int d = 4;
    const int c = 8;

    if(__gcd(c, m) != 1)
        throw out_of_range("in long long * random2( ) c and m is not relatively simple.");

    if(isprime(p) && p != 2){
        if(d % p != 0)
            throw out_of_range("in long long * random2( ) d is not multiply of p.");

        if((a - 1) % p != 0)
            throw out_of_range("in long long * random2( ) a - 1 is not multiply of p.");
    }

    if(m % 4 == 0){
        if(d % 2 != 0)
            throw out_of_range("in long long * random2( ) d is not even number, when m % 4 == 0.");

        if(d % 4 != (a - 1) % 4)
            throw out_of_range("in long long * random2( ) no condition is met (d % 4 != (a - 1) % 4) if m % 4 == 0.");
    }

    if(m % 3 == 0 && d % 27 == 0)
        throw out_of_range("in long long * random2( ) d is not multiple of 3c % 9 if m % 3 == 0.");

    for(int i = 1; i < size; ++i)
        res[i] = (d * res[i-1] * res[i-1] + a * res[i-1] + c) % m;

    return res;
}

long long * random3(long long seed)
{
    static long long res [size];
    res[0] = res[1] = seed;
    for(int i = 2; i < size; ++i)
        res[i] = (res[i - 1] + res[i - 2]) % m;

    return res;
}

long long invert(long long src){
    long long res = 0;
    bool succes = false;
    while(res < p && !succes)
    {
        if((src * res) % p == 1)
            succes = true;
        else
            ++res;
    }

    if(res == 0)
        res = inf;
    return res;
}

long long * random4(long long seed)
{
    static long long res [size];
    res[0] = 1;
    const int a = 13;
    const int c = 140;
    const int p = 5927;

    if(!isprime(p) || p == 2)
        throw out_of_range("in long long * random4( ) p is not prime.");

    for(int i = 1; i < size; ++i)
        res[i] = (a * invert(res[i - 1]) + c) % p;

    return res;
}

long long * random5(long long seed)
{
    static long long res [size];
    long long *x = random1(seed);
    long long *y = random2(seed);

    for(int i = 0; i < size; ++i)
        res[i] = (abs(x[i] - y[i])) % m;
    return res;
}

double * random6(long long seed)
{
    long long *array12 = random1(seed, 12);
    double *array12compr = compress(array12);
    double sum = 0;
    static double res [size];
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < 12; ++j)
            sum += array12compr[j];
        res[i] = sum - 6.0;
        sum = 0;
        array12 = random1(array12[11], 12);
        array12compr = compress(array12);
    }


    return res;
}

double * random7(long long seed)
{
    size_t u_len = round(size * 7);
    long long *u_long = random1(seed, u_len);
    double *u = compress(u_long, u_len);

    size_t j = 0;
    double v[2] = {};
    double s;
    static double res [size] = {};

    for(int i = 0; i < size; i += 2){
        do{
            v[0] = 2 * u[j] - 1;
            v[1] = 2 * u[j + 1] - 1;
            s = v[0]*v[0] + v[1]*v[1];
            j += 2;
            if(j >= u_len)
                throw length_error("In function double * random7(long long): there is lack of random numbers in array u.");
        }
        while(s >= 1);

        res[i] = v[0] * sqrt((-2.0 * log(s)) / s);
        if(res[i] >= m)
            res[i] = m - 1;
        if(i != size)
        {
            res[i + 1] = v[1] * sqrt(-2.0 * log(s) / s);
            if(res[i + 1] >= m)
                res[i + 1] = m - 1;
        }
        if(j >= u_len)
                throw length_error("In function double * random7(long long): there is too much numbers in array res.");

    }
    return res;
}

double * random8(long long seed)
{
    static double res [size];

    size_t u_len = round(size * 7);
    long long *u_long = random1(seed, u_len);
    double *u_compr = compress(u_long, u_len);
    size_t j = 0;

    bool again = true;
    double v,u,X = 0;

    for(int i = 0; i < size; ++i)
    {
        again = true;
        while(again)
        {
            ++j;
            v = u_compr[j];
            u = u_compr[j + 1];
            if(u == 0)
                again = true;
            else {
                X = sqrt(8.0 / exp(1)) * (v - 0.5) / u;

                if(X*X <= 5 - 4 * exp(0.25) * u)
                    again = false;
                else
                {
                    if(X*X >= 4 * exp(-1.35) / u + 1.4)
                        again = true;
                    else
                    {
                        if(X*X <= -4*log(u))
                            again = false;
                    }
                }
            }
        }
        res[i] = X;
    }
    return res;
}

double * random9 (long long seed)
{
    static double res [size];
    long long *src_long = random1(seed);
    double *src = compress(src_long);
    const double mu = 18;

    for(int i = 0; i < size; ++i)
        res[i] = - mu * log(src[i]);

    return res;
}

double * random10 (long long seed)
{
    const double a = 2;
    static double res [size];

    size_t u_len = round(size * 4);
    long long *u_long = random1(seed, u_len);
    double *u = compress(u_long, u_len);
    int j = 0;

    double x, y, v;

    for(int i = 0; i < size; ++i)
    {
        do{
            do{
                if(j >= u_len)
                    throw length_error("In function double * random10(long long): there is lack of random numbers in array u.");
                y = tan(PI * u[j]);
                ++j;
                x = sqrt(2 * a - 1) * y + a - 1;
            }
            while(x <= 0);

            if(j >= u_len)
                throw length_error("In function double * random10(long long): there is lack of random numbers in array u.");
            v = u[j];
            ++j;
            if(a == 1)
                throw runtime_error("In function double * random10(long long): a == 1, division by zero.");
        }
        while(v > (1 + y * y) * exp( (a - 1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y ) );
        res[i] = x;
    }
    return res;
}

double * compress(long long *src, int lenght, int n){
    double *res = new double[lenght] {};

    if(n == 0)
        n = m;

    for(int i = 0; i < lenght; ++i){
        res[i] = double(src[i]) / (n - 1);
    }

    return res;
}

int what_freq(double num, double from, double to, double step){
    if(num > to || num < from){
        cout << "Ignore this message, if you chose method #6 - 10:\nNumber [" << num << "] is not in range [ " << from << " ; " << to << " ].\nSee what_freq, if you interpret it like an error." <<endl;
        return -1;
    }
    num = (num - from) / step;

    return floor(num);
}

double * freq(double * src, double from, double to, double step)
{
    int arrsize = round((to - from) / step) + 1;
    double *range = new double[arrsize]{};
    int interval = 0;

    for(int i = 0; i < size; ++i)
    {
        interval = what_freq(src[i], from, to, step);
        if(interval != -1)
            range[interval]++;
    }

    for(int i = 0; i < arrsize - 1; ++i){
        range[i] /= size;
        range[arrsize - 1] += range[i];
    }

    return range;
}

bool isprime(int N){
// source: https://stackoverflow.com/questions/10896915/built-in-prime-checking-function
    if(N<2 || (!(N&1) && N!=2))
        return false;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return false;
    }
    return true;
}

