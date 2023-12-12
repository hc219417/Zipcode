/**
 *   @file: zipcode.cc
 * @author: Hannah Culver
 *   @date: September 23, 2021
 *  @brief: homework 3 (zipcode barcode)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

/**
 * getDigitCode - return a barcode for a single digit
 * @param digit single digit of the zipcode
 * @return corresponding barcode value
 */
string getDigitCode (char digit);

/**
 * getCheckDigitValue - return the check digit
 * @param sum sum of the zipcode digits
 * @return a digit that, when added to the total of the zipcode digits, makes the sum divisible by 10
 */
int getCheckDigitValue (int sum);

/**
 * getSum - return the sum of the zipcode digits
 * @param d1 first digit
 * @param d2 second digit
 * @param d3 third digit
 * @param d4 fourth digit
 * @param d5 fifth digit
 * @return sum of all five digits
 */
int getSum (int d1, int d2, int d3, int d4, int d5);

int main(int argc, char const *argv[]) {

    string zipcode; //initialize the zipcode as a string so that it can be checked for length
    char answer;

    do //use a do-while loop so that the user is prompted immediately after running the program
    {
        cout << "Please enter a zip code: ";
        cin >> zipcode;
        int length = zipcode.length();

        if (length != 5)
        {
            cout << "Error: zipcode must be 5 digits" << endl;
            return 0; //quit the program if the zipcode has more or less than 5 digits
        }

        for (int i = 0; i <= 4; i++)
        {
            char digit = zipcode.at(i);
            if (!isdigit(digit)) //check the characters one at a time to see if they are digits
            {
                cout << "Error: Code is invalid" << endl;
                return 0; //quit the program if the zipcode has anything other than digits
            }
        }

        char c1 = zipcode.at(0);
        char c2 = zipcode.at(1);
        char c3 = zipcode.at(2);
        char c4 = zipcode.at(3);
        char c5 = zipcode.at(4);

        //zipcode string is broken up into its individual characters

        int d1 = c1 - '0';
        int d2 = c2 - '0';
        int d3 = c3 - '0';
        int d4 = c4 - '0';
        int d5 = c5 - '0';

        //the characters are then converted to integers
        //subtract the character '0' to avoid getting the ascii value

        int sum = getSum (d1, d2, d3, d4, d5); //using the getSum function
        int check_digit_int = getCheckDigitValue(sum); //using the getCheckDigitValue function
        
        char check_digit_char = check_digit_int + '0';
        
        //convert the check digit from an integer to a character so that it can be used in the getDigitCode function, this time adding the character '0'

        cout << "Code: " << "|" << getDigitCode(c1) << getDigitCode(c2) << getDigitCode(c3) << getDigitCode(c4) << getDigitCode(c5) << getDigitCode(check_digit_char) << "|" << endl;

        //using the getDigitCode function to output our barcode

        cout << "More codes (y/n)?"; //does the user want to enter more zipcodes?
        cin >> answer;

    } while (answer == 'y');    //the loop will continue to run as long as the user keeps typing in 'y'
                                //or until they decide to quit (by entering anything other than a 'y')
    return 0;
} /// main

string getDigitCode (char digit)
{
    string result;
    if (digit == '0')
    {
        result = "||:::";
    }
    else if (digit == '1')
    {
        result = ":::||";
    }
    else if (digit == '2')
    {
        result = "::|:|";
    }
    else if (digit == '3')
    {
        result = "::||:";
    }
    else if (digit == '4')
    {
        result = ":|::|";
    }
    else if (digit == '5')
    {
        result = ":|:|:";
    }
    else if (digit == '6')
    {
        result = ":||::";
    }
    else if (digit == '7')
    {
        result = "|:::|";
    }
    else if (digit == '8')
    {
        result = "|::|:";
    }
    else if (digit == '9')
    {
        result = "|:|::";
    }
    return result;
}

int getCheckDigitValue (int sum)
{
    int result;
    if (sum == 0)
    {
        result = 0;
    }
    else if ((sum % 10) == 0)
    {
        result = 0;
    }
    else
    {
        result = 10 - (sum % 10);
    }
    return result;
}

int getSum (int d1, int d2, int d3, int d4, int d5)
{
    int result = d1 + d2 + d3 + d4 + d5;
    return result;
}