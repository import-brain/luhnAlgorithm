#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long firstTwoDigits(long input); // function prototypes
int numDigits(long input);
bool luhnAlg(long input);

int main(void)
{
    long creditCardNumber = get_long("Number: ");
    long first_two_digits = firstTwoDigits(creditCardNumber);
    const long NUMBERDIGITS = numDigits(creditCardNumber);
    bool isValid = NAN;

    if (NUMBERDIGITS != 13 && NUMBERDIGITS != 15 && NUMBERDIGITS != 16)
    {
        isValid = false;
    }

    if (!isValid || luhnAlg(creditCardNumber) == false)
    {
        printf("INVALID\n");
        return 0;
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && luhnAlg(creditCardNumber) == true && isValid)
    {
        printf("AMEX\n");
        return 0;
    }
    else if ((first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55) && isValid && luhnAlg(creditCardNumber) == true)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if (((first_two_digits % 10) == 4) && isValid && luhnAlg(creditCardNumber) == true)
    {
        printf("VISA\n");
        return 0;
    }
    
}

long firstTwoDigits(long input)
{
    while (input >= 100)
    {
        input = input / 10;
    }
    return input;
}

int numDigits(long input)
{
    long nDigits = floor(log10(labs(input))) + 1;
    return ((int) nDigits);
}

bool luhnAlg(long input)
{
    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = input;
    int total = 0;
    int modulo1;
    int modulo2;
    int double_1;
    int double_2;
    do
    {
        // Complicated math stuff
        // Removes last digit and add to sum1
        modulo1 = x % 10;
        x = x / 10;
        sum1 = sum1 + modulo1; // Removes second last digit
        modulo2 = x % 10;
        x = x / 10;        // Doubles second last digit and add digits to sum2
        modulo2 = modulo2 * 2;
        double_1 = modulo2 % 10;
        double_2 = modulo2 / 10;
        sum2 = sum2 + double_1 + double_2;
    }
    while (x > 0);
    total = sum1 + sum2;

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
