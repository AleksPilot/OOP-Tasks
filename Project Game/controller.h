#include "interface.h"
//#include "model.h"


void ai(){
    int i = 1;
    announce_ai(i);
    int move;

    number created;
    created.generate();
    cin >> move;
    i = 2;
    number converted_move = converted_move.convert(move);
    announce_ai(i);
    game_table journal;
    journal.clear();
    numValue check;
    char c;
    check.checkout(created, converted_move);
    while (!check.wincondition()){
        journal.make_a_move(check);
        journal.show();
        c = getch();
        if (c == 81)
        {
            i = 4;
            announce_ai(i);
            c = getch();
            if (c == 89) {
                i = 5;
                announce_ai(i);
                start();
            }
            else if (c == 78)
                continue;
        }
        cin >> move;
        number converted_move = converted_move.convert(move);
        announce_ai(i);
        check.checkout(created, converted_move);

    }
    i = 3;
    announce_ai(i);
    if (c == 89) {
        i = 5;
        announce_ai(i);
        start();
    }
    else if (c == 78)
        ai();
}

void player_mode(){}



void start(){
    menu();
    char d, c;
    d = getch();
    switch (d) {
        case 49:
            chosing_mode();
            break;
        case 50:
            rules();
            c = getch();
            if (c == 32)
                start();
            break;
        case 51:
            author();
            c = getch();
            if (c == 32)
                start();
            break;
        default:
            c = getch();
    }
}