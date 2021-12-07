#include <conio.h>
#include "model.h"

using namespace std;

class game_table{
public:
    vector<pair<int, numValue>> journal;
    void show(){
        vector<pair<int, numValue>>::iterator it;
        cout.width(11);
        cout << " num of try " << " bull " << " cow " << " miss\n";
        int i = 1;
        for (it = journal.begin(); it < journal.end(); ++it) {
            cout.width(11);
            cout << i << ' ';
            it->second.print();
            i++;
        }
        cout << '\n';
    }
    void make_a_move(numValue new_turn){
        journal.push_back(pair<int, numValue> {journal.size(), new_turn});
    }
    void clear(){
        journal.clear();
    }

};

void start();

void ai();

void player_mode();

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
            player_mode();
            break;
        case 51:
            menu();
            break;
        default:
            ;
    }
}

void rules(){
    system(std::string("start https://metaschool.ru/pub/games/bulls-and-cows/bulls.php").c_str());
    cout << "press enter to go back to menu\n";
    char c;
    c = getch();
    if (c == 32)
        menu();
    c = getch();
}

void menu() {
    cout << "Welcome to Bulls & Cows Game! \n Press any key to continue\n";
    char c;
    c = getch();
    if (c)
        cout << "Main Menu \n 1.Choose mode \n 2.Rules and tips \n 3.About author\n";
}

void author() {
    system(std::string("start https://github.com/AleksPilot").c_str());
    cout << "press enter to go back to menu\n";
    char c;
    c = getch();
    if (c == 32)
        menu();
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


