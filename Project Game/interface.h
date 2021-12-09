#include <conio.h>
#include "model.h"

using namespace std;

class game_table{
public:
    vector<pair<int, numValue>> journal;
    vector<number> turns;
    void show(){
        vector<pair<int, numValue>>::iterator it;
        cout.width(5);
        cout << "  num of try  bull   cow  miss       number\n";
        int i = 1;
        vector<number>::iterator it2;
        it2 = turns.begin();
        for (it = journal.begin(); it < journal.end(); ++it) {
            cout.width(11);
            cout << i << ' ';
            it->second.print();
            cout.width(8);




            i++;
            it2->print();
            it2++;
        }
        cout << '\n';
    }
    void make_a_move(numValue new_turn, number move){
        journal.push_back(pair<int, numValue> {journal.size(), new_turn});
        turns.push_back(move);
    }
    void clear(){
        journal.clear();
        turns.clear();
    }

};

void start();

void ai();

void multiplayer_mode();

void menu();

void author();

void chosing_mode(){
    cout << "Mode \n 1. vs AI \n 2. vs Player \n 3. Back \n";
    char c;
    c = getch();
    c = getch();
    switch (c) {
        case 49:
            ai();
            break;
        case 50:
            multiplayer_mode();
            break;
        case 51:
            start();
            break;
        default:
            chosing_mode();
    }
}

void rules(){
    system(std::string("start https://metaschool.ru/pub/games/bulls-and-cows/bulls.php").c_str());
    cout << "press any key to go back to menu\n";
    char c;
    c = getch();
    start();
}

void menu() {
    cout << "Welcome to Bulls & Cows Game! \n Press any key to continue\n";
    char c;
    c = getch();
    if (c)
        cout << "Main Menu \n 1.Choose mode \n 2.Rules and tips \n 3.About author\n 4.Clear console \n";
}

void author() {
    system(std::string("start https://github.com/AleksPilot").c_str());
    cout << "press enter to go back to menu\n";
    char c;
    c = getch();
    start();
}



void announce_ai(int n){
    switch (n)
    {
        case 1:
            cout << "Computer is generating a number...Generated (EXIT IS Q) \n Make your first turn\n";
            break;
        case 2:
            cout << "Turn recorded! Showing result...\n";
            break;
        case 3:
            cout << "You won!\n";
            break;
        case 4:
            cout << "Are you really want to leave? The progress of current game won't save! (PRESS Y TO LEAVE OR N TO STAY)\n";
            break;
        case 5:
            cout << "Returning to menu? Y/N\n";
            break;
        default:
            cout << "Leaving to menu....\n";
            break;
    }
}

void announce_multiplayer(int n){
    switch (n)
    {
        case 1:
            cout << "1st player is thinking about the number\n";
            break;
        case 2:
            cout << "Are you sure?(Y/N)\n";
            break;
        case 3:
            cout << "Number recorded!\n\n\n\n\n\n\n\n\n\n\n2nd player may have their first turn\n";
            break;
        case 4:
            cout << "Turn recorded! Showing result...\n";
            break;
        case 5:
            cout << "2nd player won!\n";
            break;
        case 6:
            cout << "Are you really want to leave? The progress of current game won't save! (PRESS Y TO LEAVE OR N TO STAY)\n";
            break;
        case 7:
            cout << "Returning to menu? Y/N\n";
            break;
        case 8:
            cout << "There is only one try!\n";
            break;
        case 9:
            cout << "1st player win. Number of tries is ended\n";
            break;
        default:
            cout << "Leaving to menu....\n";
            break;
    }
}

