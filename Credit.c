#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long int get_first_digit(long int k);
int get_count_of_card(long int k);
int get_every_second_digit(long int k);
int get_every_one_digit(long int k);
long int get_second_digit(long int k);

int main(void)
{
    long int card = get_long("Enter Card Number ");

    //Get function for counting numbers
    int count_card = get_count_of_card(card);

    //Get function for first digit
    long int firstDigit = get_first_digit(card);

    //Get function for second digit
    long int secondDigit = get_second_digit(card);

    //Get function for every second digit
    int sum_digit_two = get_every_second_digit(card);

    //Get function for every first digit
    int sum_digit_one = get_every_one_digit(card);

    //Get card_sum
    int Card_sum = (sum_digit_two + sum_digit_one) % 10;

    //Begin validation of card
    if ((secondDigit == 37 || secondDigit == 34) & (count_card == 15 & Card_sum == 0))
        printf("AMEX\n");

    else if ((count_card == 16 || count_card == 13) & (firstDigit == 4 & Card_sum == 0))
        printf("VISA\n");

    else if (count_card == 16 & Card_sum == 0 & secondDigit > 50 && secondDigit < 56)
        printf("MASTERCARD\n");

    else
        printf("INVALID\n");
}

//Get first digit
long int get_first_digit(long int k)
{

    long int n = k;
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}

//Get every second digit
long int get_second_digit(long int k)
{

    long int n = k;
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}

//Count numbers in card
int get_count_of_card(long int k)
{
    int count_card = 0;
    long int n = k;
    while (n != 0)

    {
    n /= 10;
    count_card++;
    }

    return count_card;
}

int get_every_second_digit(long int k)
{

    //Get counter for card
    int count_card = 0;
    long int n = k;
    while (n != 0)
    {
        n /= 10;
        count_card++;
    }

    //Define Variables for sum
    long int m = k;
    int sum_first = 0;
    int sum_second = 0;

    //Define array
    long int array_first[count_card];
    long int array_second[count_card];

    //For loop to store card information in array
    for (int i = 0; i < count_card; i++)
    {
        m = m / 10;
        array_first[i] = (m % 10) * 2;
        array_second[i] = (m % 10) * 2;
        m = m / 10;
    }

    //For loop to store last digit in 2 digit number
    for (int j = 0; j < count_card; j++)
    {
        long digit_second = array_first[j] % 10;
        array_first[j] = array_first[j] / 10;

        sum_first += digit_second;
    }

    //For loop to store first digit in 2 digit number
    for (int l = 0; l < count_card; l++)
    {
        array_second[l] = array_second[l] / 10;
        long digit_first = array_second[l] % 10;

        sum_second += digit_first;
    }

    int final_sum = sum_first + sum_second;
    return final_sum;
}

int get_every_one_digit(long int k)
{
    long int n = k;
    int sum_one_digit = 0;

    //while loop to get every first (second) number

    while (n != 0)
    {
        int i = (n % 10);
        n = n / 100;
        sum_one_digit = i + sum_one_digit;
    }
    return sum_one_digit;
}

