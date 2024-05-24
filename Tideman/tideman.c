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
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool make_cycle(int w, int l);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int x, y;
    for (int i = 0; i < candidate_count; i++)
    {
        x = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            y = ranks[j];
            preferences[x][y] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int n1, n2, x, y, a, b;
    int strongest = 0;
    for (int i = 0; i < pair_count; i++)
    {
        n1 = pairs[i].winner;
        n2 = pairs[i].loser;
        for (int j = i + 1; j < pair_count; j++)
        {
            x = pairs[j].winner;
            y = pairs[j].loser;
            if (preferences[n1][n2] < preferences[x][y])
            {
                strongest = j;
            }
        }
        if (strongest != 0)
        {
            a = pairs[strongest].winner;
            b = pairs[strongest].loser;
            pairs[i].winner = a;
            pairs[i].loser = b;
            pairs[strongest].winner = n1;
            pairs[strongest].loser = n2;
            strongest = 0;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int n1, n2;
    for (int i = 0; i < pair_count; i++)
    {
        n1 = pairs[i].winner;
        n2 = pairs[i].loser;
        if (make_cycle(n1, n2) == false)
        {
            locked[n1][n2] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int score = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                score += 1;
            }
        }
        if (score == candidate_count)
        {
            printf("%s\n", candidates[i]);
            return;
        }
        else
        {
            score = 0;
        }
    }
}

bool make_cycle(int w, int l)
{
    // base case
    if (w == l)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[l][i] == true)
        {
            if (make_cycle(w, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}
