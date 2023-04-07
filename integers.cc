/**
 *   @file: integers.cc
 * @author: Tyler Pohlman
 *   @date: 10/03/2021
 *  @brief: This program has four different functions: it can find the number of digits in a given integer,
 *          find the integer at a given position with a bigger number, find the sum of individual numbers
 *          within a larger integer, and determine whether a given number is palindrome or not. The program
 *          continues with these same options until option 5, exit, is selected.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

///function prototypes
/**
*  Finds the number of digits in the given number
*  @param number a positive integer
*  @return the number of digits as an integer
*/
int getNumDigits(int number);
/**
*  Return the digit number specified by n. Right most digit is digit one.
*  @param number a positive integer
*  @param n a positive integer
*  @return the number at nth position, as an integer
*/
int getNthDigit(int number, int n);
/**
*  Return the total value of all the digits.
*  @param number a positive integer
*  @return the sum of each individual number
*/
int getSumDigits(int number);
/**
*  returns true if the number is a palindrome. False otherwise.
*  @param number a positive integer
*  @return true if palindrome, false otherside. As a bool.
*/
bool isPalindrome(int number);
/**
*  Loops through cin until a positive integer is inputted. It returns said positive intger.
*  @return a positive integer
*/
int getInteger();
/**
*  Checks if input number is 1 thru. 5.
*  @param number any valid integer
*  @return True if number is 1 thru. 5. False if otherwise.
*/
bool isValidChoice(int number);

int main(int argc, char const *argv[]) {
    //variable used to select choices 1-5
    int choice;

    //prompt shown first time user starts program
    cout << "1. Find the number of digits in an integer." << endl;
    cout << "2. Find the nth digit in an integer." << endl;
    cout << "3. Find the sum of all digits of an integer." << endl;
    cout << "4. Is the integer a palindrome?" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    cout << endl;

    while(choice != 5)//checks for choice number 5, if true then loop is exited
    {
        if (isValidChoice(choice) )//determines if input is 1-5
        {
            //asks for the input integer
            cout << "Enter an integer number: ";
            int number = getInteger();//ensures input integer is positive
            cout << endl;

            switch (choice)
            {
            case 1://number of digits in a number
                cout << number << " has " << getNumDigits(number) << " digits." << endl;
                cout << endl;
                break;
            case 2://digit at given position within input integer
                int position;
                cout << "Enter a position: ";
                cin >> position;
                cout << endl;
                if (position > 0 && position <= getNumDigits(number) )//checks if position is within range of integer
                {
                    cout << "Digit number " << position << " is " <<  getNthDigit(number, position) << endl;
                    cout << endl;
                }
                else 
                {
                    cout << "Invalid position" << endl;
                }
                break;
            case 3://adds the individual digits within the input integer together
                cout << "The sum of all digits in " << number << " is " << getSumDigits(number) << endl;
                break;
            case 4://checks whether or not the input integer is a palindrome
                cout << "The number " << number;
                if (isPalindrome(number) )
                {
                    cout << " is a palindrome" << endl;
                }
                else
                {
                    cout << " isn't a palindrome" << endl;
                }
                break;
            case 5://exits the program
                break;
            default:
                break;
            }
        }

        //prompt and input before next occurrence of loop
        cout << "1. Find the number of digits in an integer." << endl;
        cout << "2. Find the nth digit in an integer." << endl;
        cout << "3. Find the sum of all digits of an integer." << endl;
        cout << "4. Is the integer a palindrome?" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        cout << endl;
    }
    
    return 0;//exit program successfully 
}/// main

//created functions
int getNumDigits(int number)
{
    int digits = 0;
    while (number > 0)
    {
        digits++;
        number /= 10;
    }
    return digits;
}

int getNthDigit(int number, int n)
{   
    int enumerations = 1;
    for ( int i = 0; i < n; i++)
    {
        enumerations *= 10;
    }

    int divisions = 1;
    for ( int i = 0; i < n - 1; i++)
    {
        divisions *= 10;
    }

    number %= enumerations;
    number = number / divisions;

    return number;
}

int getSumDigits(int number)
{
    int sum = 0;

    for (int i = 1; i <= getNumDigits(number); i++)
    {
        sum += getNthDigit(number, i);
    }
    
    return sum;
}
bool isPalindrome(int number)
{
    for (int i = 1; i <= getNumDigits(number) / 2; i++)
    {
        int higherLimit = getNumDigits(number) + 1 - i;
        if (getNthDigit(number, i) != getNthDigit(number, higherLimit) )
        {
            return false;
        }
    }
    return true;
}

int getInteger()
{
    int input;
    cin >> input;
    while(input < 0)
    {
        cout << endl;
        cout << "Enter a positive integer: ";
        cin >> input;
    }
    return input;
}
bool isValidChoice(int number)
{
    switch (number)
    {
    case 1:
        return true;
        break;
    case 2:
        return true;
        break;
    case 3:
        return true;
        break;
    case 4:
        return true;
        break;
    case 5:
        return true;
        break;
    default:
        return false;
        break;
    }
}