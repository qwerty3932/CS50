#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;
typedef struct{
    string name;
} winner;
// Array of candidates
candidate candidates[MAX];
winner winners[MAX];
// Number of candidates
int candidate_count;
int winner_count;

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
    for (int i = 0; i<candidate_count;i++){
        if(strcmp(candidates[i].name, name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //voto e nome temporario
    int temp;
    string ntemp;
    for(int i = 0; i < candidate_count -1;i++){
        for(int j = 0; j < candidate_count - 1 - i;j++){
            if(candidates[j].votes > candidates[j+1].votes){
                temp = candidates[j].votes;
                ntemp = candidates[j].name;
                candidates[j].votes = candidates[j+1].votes;
                candidates[j].name = candidates[j+1].name;
                candidates[j+1].votes = temp;
                candidates[j+1].name = ntemp;
            }
        }
    }
    int highest_vote = candidates[candidate_count-1].votes;
    // fazer um check pra ver quandos vencedores tem
    int j = 0;
    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].votes == highest_vote){
            winners[j].name = candidates[i].name;
            winner_count++;
            j++;
        }
    }
    if(winner_count>1){
        for(int i = 0;i < winner_count; i++){
            printf("%s\n", winners[i].name);
        }
    }else{
        printf("%s\n", winners[0].name);
    }


    return;
}



