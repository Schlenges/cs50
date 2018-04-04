#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input

    long long cardnum = get_long_long("Please enter your credit card number: ");

    // Determine the amount of digits for initializing an array of the right size

    long long num = cardnum;
    int digits = 0;

    while (num > 0)
    {
        num /= 10;
        digits++;
    }

    int numArray[digits];

    // Get the individual digits and store them in the array

    int i;
    num = cardnum;

    for (i = digits - 1; i >= 0; i--)
    {
        numArray[i] = num % 10;
        num /= 10;
    }

    // Validation via Luhn’s Algorithm

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together

    int sum1 = 0,
        product = 0;

    for (i = digits - 2; i >= 0; i -= 2)
    {
        product = 2 * numArray[i];

        if (product > 9)
        {
            sum1 += (product / 10) + (product % 10);
        }
        else
        {
            sum1 += product;
        }
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2

    int sum2 = 0;

    for (i = digits - 1; i >= 0; i -= 2)
    {
        sum2 += numArray[i];
    }

    int sum = sum1 + sum2;

    // Check if the total’s last digit is 0

    if (sum % 10 == 0)
    {
        // Check the credit card company

        if (digits == 15 && numArray[0] == 3 && (numArray[1] == 4 || numArray[1] == 7))
        {
            printf("AMEX\n");
        }
        else if (digits == 16 && numArray[0] == 5 && (numArray[1] > 0 && numArray[1] < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((digits == 13 || digits == 16) && numArray[0] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}