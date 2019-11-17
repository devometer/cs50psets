#include <cs50.h>
#include <stdio.h>

int check_digit(long number);
void check_validity(long number);

int main(void)
{
    long number = get_long("Number: ");
    check_validity(number);
}

void check_validity(long number)
{
    // get c num digits
    int digit = -1;
    digit = check_digit(number);
    
    long tempnum = number;
    int total = 0;
    
    // Luhn's Algorithm
    for(int i = 0; i < digit; i++)
    {
        int index = (int) (tempnum % 10);
        tempnum /= 10;
//         printf("tempnum: %20li, popped number: %i\n", tempnum, index);
        
        if ((i + 1) % 2 == 0) // second-to-last evens
        {
//             printf("EVEN!\t");
            if(index * 2 >= 10)
            {
                index *= 2;
                total += index / 10;
                total += index % 10;
//                 printf("(%i) (%i) \n", index/10, index%10);
            }
            else
            {
//                 printf("%i \n", index);
                total += (index * 2);
            }
        }
        else
        {
//             printf("ODD!\tindex: %i\n", index);
            total += index;
        }
    }
    
//     printf("\ntotal: %i, total %% 10: %i, digits: %i\n", total, total % 10, digit);
    
    // number validity check
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return;
    }
    
    // card type
    if (digit == 15)
    {
        long divisor = 10000000000000;
        if (number / divisor == 34 || number / divisor == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
//             printf("digit: %i, first 2 letters: %i\n", digit, (int) (number / divisor));
        }
    }
    else if (digit == 16)
    {
        long divisor = 100000000000000;
        if(number / divisor > 50 && number / divisor < 56)
        {
            printf("MASTERCARD\n");
        }
        else if(number / (divisor * 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
//             printf("digit: %i\tfirst 2 letters: %i", digit, (int)(number / divisor));
        }
    }
    else if(digit == 13)
    {
        long divisor = 100000000000;
        if(number / divisor == 4)
        {
            printf("VISA\n");
//             printf("digit: %i\tfirst 2 letters: %i", digit, (int)(number / divisor));
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
//     printf("number digit: %i\tnumber: %li\n", digit, number);
}

int check_digit(long number)
{
    int digit = 1;
    while (number / 10 > 0){
        number /= 10;
        digit++;
    }
    return digit;
}
