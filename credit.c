#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long firstTwoDigits(long input); // function prototypes

int main(void)
{
    long creditCardNumber = get_long("Number: ");
    long first_two_digits = firstTwoDigits(creditCardNumber);

    if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55)
    {
        printf("MASTERCARD\n");
    }
    // TODO: implement logic for other card issuers, use && in if statements above and add logic to code to check against luhn alg
}

long firstTwoDigits(long input)
{
    while (input > 99)
    {
        input = input / 10;
    }
    return input;
}


