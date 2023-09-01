#include <iostream>
using namespace std;

int playerChoice() {
    int playerChoose;
    cout << "1. Rock\n2. Paper\n3. Scissor\nEnter your choice as a number: ";
    cin >> playerChoose;
    return playerChoose;
}
int npcChoice() {
    srand(time(NULL));
    return (rand() % 3) + 1;
}

bool checkDraw(int player1, int NPC) {
    return player1 == NPC;
}
bool playerWin(int player1, int NPC) {
    return (player1 == 3 && NPC == 1) || (player1 + 1 == NPC);
}

string npcChoice_as_Str(int RPC_as_Num) {
    switch(RPC_as_Num) {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissor";
        default:
            cerr << "Wrong case at -> chooseRPC_as_Str()" << endl;
            return "";
    }
}

void mainGame() {
    int NPC = npcChoice();
    int playerChoose = playerChoice();

    cout << "NPC choose: " << npcChoice_as_Str(NPC) << endl;

    if (checkDraw(playerChoose, NPC)) {
        cout << "Result: Draw";
    } else if (playerWin(playerChoose, NPC)) {
        cout << "Result: Player Win";
    } else {
        cout << "Result: NPC Win";
    }
}

int main() {
    mainGame();
    return 0;
}
