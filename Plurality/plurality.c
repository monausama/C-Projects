#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int x = 0; x < candidate_count; x++)
    {
        if (strcmp(candidates[x].name, name) == 0)
        {
            candidates[x].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int heighst = 0;
    int w1 = 0;
    int w2 = 0;
    int t = 0;
    for (int n = 0; n < candidate_count; n++)
    {
        if (candidates[n].votes == candidates[n + 1].votes)
        {
            t += 1;
        }
        if (candidates[n].votes > heighst)
        {
            heighst = candidates[n].votes;
            w1 = n;
        }
        if (candidates[n].votes == heighst)
        {
            w2 = n;
        }
    }
    if (t == candidate_count - 1)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    else if (w2 != 0 && strcmp(candidates[w1].name, candidates[w2].name) != 0)
    {
        printf("%s\n%s\n", candidates[w1].name, candidates[w2].name);
    }
    else
    {
        printf("%s\n", candidates[w1].name);
    }
    return;
}
