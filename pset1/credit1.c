#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input

    long long num = get_long_long("Please enter your credit card number: ");

    // Validation via Luhn’s Algorithm

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    long long i;
    int sum1,
        product;

    for (i = num / 10, sum1 = 0; i > 0; i /= 100)
    {
        product = 2 * (i % 10);

        if (product > 9)
        {
            sum1 += (product / 10) + (product % 10);
        }
        else
        {
            sum1 += product;
        }
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    long long j;
    int sum2;

    for (j = num, sum2 = 0; j > 0; j /= 100)
    {
        sum2 += j % 10;
    }

    int sum = sum1 + sum2;

    // Check if the total’s last digit is 0

    if (sum % 10 == 0)
    {
        // Check the credit institute

        // Determine how many digits in number
        long long k = num;
        int digits = 0;

        while (k > 0)
        {
            k = k / 10;
            digits++;
        }

        int number[digits];

        for (int l = digits - 1; l >= 0; l--)
        {
            number[l] = num % 10;
            num = num / 10;
        }

        // check first digits
        if (digits == 15 && number[0] == 3 && (number[1] == 4 || number[1] == 7))
        {
            printf("AMEX\n");
        }
        else if (digits == 16 && number[0] == 5 && (number[1] > 0 && number[1] < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((digits == 13 || digits == 16) && number[0] == 4)
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