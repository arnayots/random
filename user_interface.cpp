#include <iostream>
#include <string>
#include "user_interface.h"
#include <cmath>
#include <iomanip> //std::setprecision

using namespace std;
//const ostream &standard = std::cout;
const string white_line = "\011\012\013\014\015\040";

void print_greeting(ostream &out)
{
    out << "Welcome to the random number generator!\n"
        << "It was done as a laboratory programming job.\n";
}

string clear_whites(const string &s){
    size_t first = s.find_first_not_of(white_line);

    if(first == string::npos) return "";
    size_t last = s.find_last_not_of(white_line, s.size() );
    return s.substr(first, last - first + 1);
}

int choose_gen(ostream &out)
{
    bool correct_ans = false;
    string ans = "";
    int res = 11;
    size_t ans_len = 0;
    do{
        print_help();
        out << "Select one of the generators by entering its serial number.\n"
            << "Enter H to see help again.\n"
            << "Enter Q to exit the program.\n"
            << "Hint: All other symbols will call help info and ask you to enter the data again.\n" ;
        cin >> ans;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            throw out_of_range("***** FAILED TO GET STRING FROM STD::CIN *****\nWatch size_t choose_gen(ostream &out) to solve the problem\n");
        }
        ans = clear_whites(ans);
        ans_len = ans.length();
        if(ans_len > 0 && ans_len < 3){
            if(ans_len == 2 && ans == "10"){
                res = 10;
                correct_ans = true;
            }
            else if(ans_len == 1){
                    if(ans[0] == 'q' || ans[0] == 'Q' || ans[0] == '0'){
                        res = 0;
                        correct_ans = true;
                    }
                    if(ans[0] >= '0' && ans[0] <= '9'){
                        res = int(ans[0]) - int('0');
                        correct_ans = true;
                    }
                }
        }
    }
    while(!correct_ans);

    return res;
}

long long input_seed(ostream &out)
{
    out << "Please, type generator`s seed.(Use 0 for random seed)\n";
    long long seed;
    cin >> seed;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        throw out_of_range("***** FAILED TO GET STRING FROM STD::CIN *****\nWatch long long input_seed(ostream &out) to solve the problem\n");
    }
    return seed;
}

void print_help(ostream &out)
{
    out << "  1. Linear congruence method.\n"
        << "  2. Quadratic congruence method.\n"
        << "  3. Fibonacci numbers.\n"
        << "  4. Inverted congruent sequence.\n"
        << "  5. The method of integration.\n"
        << "  6. The rule of 3 sigma.\n"
        << "  7. Polar coordinate method.\n"
        << "  8. The method of relations.\n"
        << "  9. Logarithm method for generating indicative distribution.\n"
        << "  10. The Ahrens method for generating a gamma distribution of order a > 1.\n";
}
void print_succes(ostream &out)
{
    out << "Random generator worked without any problems." << endl;
}
void print_fail(const std::string& reason, ostream &out)
{
    out << "Random generator worked with FAIL." << endl;
    out << reason << endl;
}

void print_histogram(double *fr, double from, double to, double step, ostream &out)
{
    int i = 0;
    int len = round((to - from) / step);
    out << fixed;;
    out <<  "[" << setprecision(1) << double(i) * step + from << ", " << setprecision(1) << double(i) * step + step + from << "] : " << setprecision(4) << fr[i] << endl;
    for(i = 1; i < len ; ++i)
        out << "(" << setprecision(1) << double(i) * step + from << ", " << setprecision(1) << double(i) * step + step + from << "] : " << setprecision(4) << fr[i] << endl;
    out << "Sum: " << setprecision(4) << fr[len] << endl;
}
