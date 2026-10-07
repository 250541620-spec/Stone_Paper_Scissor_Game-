
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum GameName { Computer = 1, Player1 = 2 };
enum GameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// Function declaration
void StartGame();

short ReadHowManyRound()
{
    int Rounds;

    cout << "How many rounds 1 to 10? \n";
    cin >> Rounds;

    return Rounds;
}

int RandomNumber(int To, int From)
{
    return rand() % (From - To + 1) + To;
}

void ReadPlayerChoice(GameChoice& PlayerChoice)
{
    int Choice;

    cout << "\nYour choice: [1] Stone, [2] Paper, [3] Scissors? ";
    cin >> Choice;

    PlayerChoice = static_cast<GameChoice>(Choice);
}

void ComputerChoicee(GameChoice& ComputerChoice)
{
    ComputerChoice = static_cast<GameChoice>(RandomNumber(1, 3));
}

void ShowRoundResult(
    GameChoice PlayerChoice,
    GameChoice ComputerChoice,
    int& PlayerScore,
    int& ComputerScore,
    int& DrawTimes)
{
    cout << "Player Choice  : " << PlayerChoice << endl;
    cout << "Computer Choice: " << ComputerChoice << endl;

    cout << "Winner         : ";

    if (PlayerChoice == ComputerChoice)
    {
        cout << "[No Winner]" << endl;

        DrawTimes++;

        system("color 6F");
    }
    else if (
        (PlayerChoice == Stone && ComputerChoice == Scissors) ||
        (PlayerChoice == Paper && ComputerChoice == Stone) ||
        (PlayerChoice == Scissors && ComputerChoice == Paper))
    {
        cout << "[Player1]" << endl;

        PlayerScore++;

        system("color 2F");
    }
    else
    {
        cout << "[Computer]" << endl;

        ComputerScore++;

        system("color 4F");
    }

    cout << "-----------------------------------------------------" << endl;
}

void ShowGameOverScreen(
    int PlayerScore,
    int ComputerScore,
    int DrawTimes)
{
    cout << endl;
    cout << "\n\n\t\t\t=====================================================" << endl;
    cout << "\t\t\t\t\t G A M E   O V E R" << endl;
    cout << "\t\t\t=====================================================" << endl;

    cout << "\t\t\t--------------------[Game Result]--------------------" << endl;

    cout << "\t\t\tGame Rounds    : "
         << PlayerScore + ComputerScore + DrawTimes << endl;

    cout << "\t\t\tPlayer Score   : " << PlayerScore << endl;
    cout << "\t\t\tComputer Score : " << ComputerScore << endl;
    cout << "\t\t\tDraw times     : " << DrawTimes << endl;

    if (PlayerScore > ComputerScore)
    {
        cout << "\t\t\tFinal Winner   : [Player]" << endl;

        system("color 2F");
    }
    else if (PlayerScore < ComputerScore)
    {
        cout << "\t\t\tFinal Winner   : [Computer]" << endl;

        system("color 4F");
    }
    else
    {
        cout << "\t\t\tFinal Winner   : [No Winner]" << endl;

        system("color 6F");
    }

    cout << "\t\t\t=====================================================" << endl;
}

void ResetScreen()
{
    string Answer;

    cout << "\n\n\t\t\tDo you want to play again Y/N? ";
    cin >> Answer;

    if (Answer == "Y" || Answer == "y")
    {
        system("cls");
        system("color 0F");

        StartGame();
    }
    else if (Answer == "N" || Answer == "n")
    {
        cout << "Thank you for playing!" << endl;
    }
}

void StartGame()
{
    short Rounds = ReadHowManyRound();

    int PlayerScore = 0;
    int ComputerScore = 0;

    // Draw counter
    int DrawTimes = 0;

    for (int i = 0; i < Rounds; i++)
    {
        cout << endl;

        cout << "Round [" << i + 1 << "] begins" << endl;

        GameChoice PlayerChoice;
        GameChoice ComputerChoice;

        ReadPlayerChoice(PlayerChoice);

        ComputerChoicee(ComputerChoice);

        cout << "--------------------- Round [" << i + 1
             << "] ---------------------" << endl;

        ShowRoundResult(
            PlayerChoice,
            ComputerChoice,
            PlayerScore,
            ComputerScore,
            DrawTimes);
    }

    ShowGameOverScreen(
        PlayerScore,
        ComputerScore,
        DrawTimes);

    ResetScreen();
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    StartGame();

    return 0;
}
