#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX] = {"yle","julia","mae"};

pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void mergeSort(int arr[], int l, int r);
void lock_pairs(void);
void print_winner(void);
void merge(int arr[], int l, int m, int r);

int main(int argc, string argv[])
{
	return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,candidates[i]) == 0)
        {
            ranks[i] = rank;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                preferences[i][j] = 0;
                pair_count++;
            }

            else if (i < j)
            {
                preferences[ranks[i]][j]++; //O numero de preferencia dos candidatos e igual a ordem menos o numero de candidados
                pair_count++;
            }
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[i].winner = i;
                    pairs[j].loser = j;
                }

                else if(preferences[i][j] > preferences[j][i])
                {
                    pairs[i].winner = j;
                    pairs[j].loser = i;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int temp[2];

    for (int i = 0; i < pair_count -1 ; i++)
    {
        if (preferences[pairs[i].winner][pairs[i].loser] < (preferences[pairs[i+1].winner][pairs[i+1].loser]))
        {
            temp[0] = pairs[i+1].winner;
            temp[1] = pairs[i+1].loser;

            pairs[i+1].winner = pairs[i].winner;
            pairs[i+1].loser = pairs[i].loser;

            pairs[i].winner = temp[0];
            pairs[i].loser = temp[1];
        }
    }
}


void lock_pairs(void)
{

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {

            locked[i][j] = false;

        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] =  true;
    }

}

// Print the winner of the election
void print_winner(void)
{

    int test = 0;

     for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                test++;
            }

            if (test == candidate_count -1)
            {
                printf("%s\n",candidates[i]);
                return;
            }


        }

        test = 0;
    }

    return;
}
