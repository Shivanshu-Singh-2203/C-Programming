/* Frequency Calculator */

#include <stdio.h>
#define RESPONSE_SIZE 10
#define FREQUENCY_SIZE 6

void frequency(int response[], int freq[])
{
    // reset frequency array
    for (int i = 0; i < FREQUENCY_SIZE; i++)
        freq[i] = 0;

    // count responses
    for (int answer = 0; answer < RESPONSE_SIZE; answer++)
    {
        int value = response[answer];
        if (value >= 0 && value < FREQUENCY_SIZE) {
            ++freq[value];
        }
    }
}

int main()
{
    int responses1[RESPONSE_SIZE] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int responses2[RESPONSE_SIZE] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int responses3[RESPONSE_SIZE] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3};

    int freq1[FREQUENCY_SIZE];
    int freq2[FREQUENCY_SIZE];
    int freq3[FREQUENCY_SIZE];

    frequency(responses1, freq1);
    frequency(responses2, freq2);
    frequency(responses3, freq3);

    printf("Frequencies for responses1:\n");
    for (int i = 0; i < FREQUENCY_SIZE; i++)
        printf("%d ", freq1[i]);
    printf("\n");

    printf("Frequencies for responses2:\n");
    for (int i = 0; i < FREQUENCY_SIZE; i++)
        printf("%d ", freq2[i]);
    printf("\n");

    printf("Frequencies for responses3:\n");
    for (int i = 0; i < FREQUENCY_SIZE; i++)
        printf("%d ", freq3[i]);
    printf("\n");

    return 0;
}

