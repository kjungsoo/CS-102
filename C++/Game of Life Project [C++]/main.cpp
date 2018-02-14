//Jung Kim
//CS-102 Programming II
//Professor Charles Hamaker
//Project: Game of Life

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

const int world_column = 70, //These constants set the dimensions of the 2 dimensional grid
          world_row = 25;

const char life = '*', //Life is represented by *'s
           death = ' ', //Death is an empty space
           limbo = 'x'; //Limbo is the temporary state of the neighbors during evaluation from life or death

class Generation //Decided to do object-oriented programming for the Game of Life for the sake of convenience
{
public:
    void createWorld(), //create is the same as set, createWorld() sets the 2D space
         createLife(), //sets up the initial configuration of the World
         showLife(), //display function
         startGame(), //begins the game of life
         rules_of_the_game(); //self-explanatory, concerns evaluating neighbors of each cell and shifts from temp world and real world to make the changes

private:
    char world[world_column][world_row], //the world and the neighbors are private
         world_temp[world_column][world_row],
         neighbors[8];
};

void Generation::createWorld() //creates the 2D world, everything starts dead until life is created
{
    for (int row = 0; row < world_row; row++)
        for (int column = 0; column < world_column; column++)
        {
            world[column][row] = death;
            world_temp[column][row] = death;
        }

    for (int row = 0; row < world_row; row ++) //these are borders that never change, could have made them const but opted to not
        {                                      //these borders are both for visual aesthetics and ensuring living cells do not go past the grid
            world[0][row] = '|';
            world[world_column - 1][row] = '|';
        }

    for (int column = 0; column < world_column; column++) //the borders are placed in the 0th and the last index, inputting coordinates during createLife into these points will do nothing.
        {
            world[column][0] = '_';
            world[column][world_row - 1] = '-';
        }
}

void Generation::createLife() //creates life as in the user is given the option to input the starting cells
{
    int birth_row, //coordinates for the cells the user inputs
        birth_column,
        user_input; //the user's answer to prompted questions throughout the setup is stored here

    showLife();
    cout << "*********************************************************" << endl
         << "************** Welcome to the Game of Life **************" << endl
         << "******* To begin, initialize the first generation *******" << endl
         << "*** Initialization will require two coordinate points ***" << endl
         << "*********************************************************" << endl
         << endl; //introduction

    do //this do-while loop allows user to either start the game or continue adding cells
    {
        do //this do-while loop allows user to confirm or change last inputted cell coordinate
        {
            cout << "The current grid is " << world_column << " x " << world_row << " cells.\nPlease keep the coordinates within the boundaries." << endl
                 << "Enter the coordinates of the cell to give it Life: " << endl
                 << "Column: ";
            cin >> birth_column;
            if (birth_column > world_column)
            {
                birth_column = world_column - 2;
                cout << "A coordinate point that exceeded the boundaries of this World was entered." << endl
                     << "The point has been defaulted into " << world_column - 2 << endl;
            }

            cout << "Row: ";
            cin >> birth_row;
            if (birth_row > world_row)
            {
                birth_row = world_row - 2;
                cout << "A coordinate point that exceeded the boundaries of this World was entered." << endl
                     << "The point has been defaulted into " << world_row - 2 << endl;
                Sleep(3000);
            }

            world[birth_column][birth_row] = life;
            system("CLS"); //clears and refreshes the grid to show the cell the user just resurrected
            showLife();

            cout << "The coordinate you entered was (" << birth_column << ", " << birth_row << ")" << " correct?" << endl
                 << "Enter \'1\' to confirm \'Yes\'. Enter any other digit to re-enter the coordinates." << endl
                 << "Do NOT enter anything other than an integer." << endl; //entering a non-integer will result in the program crashing.
            cin >> user_input; //prompts user to confirm or change coordinates

            if (user_input != 1) //if the user changes coordinates the cell is killed and grid is refreshed
            {
                world[birth_column][birth_row] = death;
                system("CLS");
                showLife();
            }
        } while (user_input != 1);

        world[birth_column][birth_row] = life; //might be unnecessary
        system("CLS");
        showLife();

        cout << "Life has been given to the cell located in point (" << birth_column << ", " << birth_row << ") of World." << endl;
        cout << "Would you like to give Life to more cells?" << endl
             << "Enter \'1\' to confirm \'Yes\'. Enter any other digit to start the Game of Life." << endl
             << "Do NOT enter anything other than an integer." << endl;
        cin >> user_input;
    } while (user_input == 1);
}

void Generation::showLife() //simple display function
{
    for (int row = 0; row < world_row; row++)
        for (int column = 0; column < world_column; column++)
            if (column == (world_column - 1)) //if condition to make sure that the console prints on a new line if loop goes past last column of the current row
                cout << world[column][row] << endl;
            else
                cout << world[column][row];
}

void Generation::rules_of_the_game() //4 rules of the game, each concerning neighboring cells
{
    int neighbor_counter = 0; //by counting how many neighbors, rule conditions are fulfilled
    for (int row = 1; row < world_row; row++)
        for (int column = 1; column < world_column; column++) //since the 0th index are borders and are not cells that can live/die the for loops start at 1
        {
            neighbors[0] = world[column][row - 1];

            if (row < (world_row - 1)) //these if statements just ensure that index is not out of bounds
                neighbors[1] = world[column][row + 1];
            else
                neighbors[1] = limbo;

            neighbors[2] = world[column - 1][row]; //the neighbors are cells directly above, below, to the left, right, top left, top right, bottom left and bottom right of the cell

            if (column < (world_column - 1))
                neighbors[3] = world[column + 1][row];
            else
                neighbors[3] = limbo;

            neighbors[4] = world[column - 1][row - 1];

            if (column < (world_column - 1))
                neighbors[5] = world[column + 1][row - 1];
            else
                neighbors[5] = limbo;

            if (row < (world_row - 1))
                neighbors[6] = world[column - 1][row + 1];
            else
                neighbors[6] = limbo;

            if ((row < world_row - 1) && (column < world_column - 1))
                neighbors[7] = world[column + 1][row + 1];
            else
                neighbors[7] = limbo;

            for (int i = 0; i < 8; i ++) //counts all the neighbor cells of the cell under evaluation that are alive
                if (neighbors[i] == life)
                    neighbor_counter++;

            if (world[column][row] == life) //the first 3 rules require the cell under evaluation to be alive
            { //everything is set to a temporary world so that all the changes can be made 'instantaneously' to prevent cells from new generation affecting cells of older generations
                if (neighbor_counter < 2)            //first rule - under population
                    world_temp[column][row] = death;
                else if (neighbor_counter > 3)       //third rule - over-population
                    world_temp[column][row] = death;
                else
                    world_temp[column][row] = world[column][row]; //second rule - survival
            }

            else if (world[column][row] == death) //the last rule require the cell under evaluation to be dead
                if (neighbor_counter == 3)          //fourth rule - birth
                    world_temp[column][row] = life;

            neighbor_counter = 0; //resets the count of alive neighbors back to 0 to prevent the next cell from having incorrect number of living neighbors
            for (int i = 0; i < 8; i ++)
                neighbors[i] = limbo; //also sets all the neighbors to a limbo state for a new evaluation

            for (int row = 0; row < world_row; row ++) //ensures that borders remain as borders
            {
                world_temp[0][row] = '|';
                world_temp[world_column - 1][row] = '|';
            }

            for (int column = 0; column < world_column; column++)
            {
                world_temp[column][0] = '_';
                world_temp[column][world_row - 1] = '-';
            }
        }
    for (int row = 0; row < world_row; row++) //the changes are now made onto the 'real' world so that all the cells are of the same generation
        for (int column = 0; column < world_column; column++)
            world[column][row] = world_temp[column][row];
}

void Generation::startGame() //how the game is run
{
    createWorld();
    createLife();
    for (int i = 0; i < 5000; i++) //set the loop to 5000 times for now
    {
        rules_of_the_game();

        // system("CLS");
        // Sleep(10);
        // showLife();
    }
}

int main()
{
    Generation gameOfLife; //creates the class
    gameOfLife.startGame(); //starts the game
    return 0;
}
