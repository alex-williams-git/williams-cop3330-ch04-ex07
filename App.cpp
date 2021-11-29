/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Alexander Williams
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

// creating a vector that contains the string representations of single-digit numbers
vector<string> numbers;
void identifyNumbers(){
    numbers.push_back("zero");
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");
}

// function to get the input
// tries digit first, if not digit tries string
double getInput()
{
    const double notWord = numbers.size();
    double value = notWord;

    // if the input is in digit form, return the digit
    if(cin >> value)
        return value;

    cin.clear();

    string input;
    cin >> input;

    // if the input string is a single digit word in the vector, we return that value
    for(int i = 0; i < numbers.size(); ++i){
        if(numbers[i] == input)
            value = i;
    }

    return value;
}

// function to do computation
double doOperation(char operand[], double input1, double input2){
    // checking operation and returning the inputs after operation has been complete
    if(strcmp(operand, "+") == 0){
        return input1 + input2;
    }
    else if(strcmp(operand, "-") == 0){
        return input1 - input2;
    }
    else if(strcmp(operand, "*") == 0){
        return input1 * input2;
    }
    else if(strcmp(operand, "/") == 0){
        return input1 / input2;
    }

    return 0;
}

// getting the operation type for the output statement
char * getOperation(char operand[]){
    if(strcmp(operand, "+") == 0){
        return "sum";
    }
    else if(strcmp(operand, "-") == 0){
        return "difference";
    }
    else if(strcmp(operand, "*") == 0){
        return "product";
    }
    else if(strcmp(operand, "/") == 0){
        return "quotient";
    }

    return "n/a";
}

int main(){
    identifyNumbers();

    double value1 = getInput();
    double value2 = getInput();
    char op[1];

    scanf("%s", op);

    char * opWord = getOperation(op);
    double result = doOperation(op, value1, value2);

    printf("The %s of %lf and %lf is %lf", opWord, value1, value2, result);

    return 0;
}