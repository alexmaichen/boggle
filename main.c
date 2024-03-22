// include headers
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// init constants
#define MAXWORDLENGTH 16
#define MAXWORDS 100000
#define GRIDSIZE 4
char words[MAXWORDS][MAXWORDLENGTH];
int wordNB;

bool isValid(int row, int col, bool visited[GRIDSIZE][GRIDSIZE]);
char* findWords(int row, int col, char grid[GRIDSIZE][GRIDSIZE], bool visited[GRIDSIZE][GRIDSIZE], char* builtWord);

void main(int argc, char* argv[]){
    // cmd args let the user input the grid
    if(argc != 5){
        printf("invalid amount of extra cmd-line args (%d), expected 4 \n", argc -1);
        exit(EXIT_FAILURE);
    }
    
    // words.txt file is a dictionary to choose words from
    FILE* file = fopen("words.txt", "r");
    if (!file){
        printf("file not found!\n");
        exit(EXIT_FAILURE);
    }

    // copy words from file to table
    //TODO make this into hash-table to speed up the process (for example filter by first letter)
    char word[MAXWORDLENGTH];
    for(wordNB = 0; fscanf(file, "%s", word); wordNB++){
        strcpy(words[wordNB], word);
    }

    fclose(file);

    // init grids
    char grid[GRIDSIZE][GRIDSIZE] = {
        {'\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0'}
        };

    bool visited[GRIDSIZE][GRIDSIZE] = {
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false}
        };

    /*
    read cmd line args.
    each individual arg represents a row of the grid.
    each position within the arg represents a column (referred to by variables named "col").
    usage example: ./main cats rate tape sets
    */
    for(int i = 1; i < 5; i++){
        if(strlen(argv[i]) != 4){
            printf("invalid arg-length (%d), expected 4 \n", strlen(argv[i]));
            exit(EXIT_FAILURE);
        }

        for(int j = 0; j < 4; j++){
            grid[i - 2][j] = argv[i][j];
        }
    }

    // find words
    printf("Words found in the grid:\n");

    //TODO
}

// Function to check if the given position is valid on the grid
bool isValid(int row, int col, bool visited[GRIDSIZE][GRIDSIZE]){
    return (row >= 0 && row < 4 && col >= 0 && col < 4 && !visited[row][col]);
}

char* findWords(int row, int col, char grid[GRIDSIZE][GRIDSIZE], bool visited[GRIDSIZE][GRIDSIZE], char* builtWord){

    if(!isValid(row, col, visited)){
        return "";
    }
    visited[row][col] = true;
    return ""; //TODO go through the grid recursively, updating the VISITED board each time. only non-visited array indexes may be visited at each recursion.
}

