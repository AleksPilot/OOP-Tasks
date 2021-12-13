#include "interface.h"
#include <conio.h>
//#include "model.h"


void ai(){
    int i = 1;
    announce_ai(i);
    int move;

    number created;
    created.generate();
    //created.print();
    cin >> move;
    i = 2;
    if (!(cin >> move)){
        throw exception();
    }
    number converted_move = converted_move.convert(move);
    while (converted_move.fwd_conv() != move)
    {
        cin >> move;
        converted_move = converted_move.convert(move);
    }
    announce_ai(i);
    game_table journal;
    journal.clear();
    numValue check;
    check.init();
    char c;
    cout << '\n';
    check = check.checkout(created, converted_move);
    journal.make_a_move(check, converted_move);
    journal.show();
    while (!check.wincondition()){

        check.init();
        cin >> move;
        if (!(cin >> move)){
            throw exception();
        }
        number converted_move = converted_move.convert(move);
        while (converted_move.fwd_conv() != move)
        {
            cin >> move;
            converted_move = converted_move.convert(move);
        }
        announce_ai(i);
        check = check.checkout(created, converted_move);
        journal.make_a_move(check, converted_move);
        journal.show();
    }
    i = 3;
    announce_ai(i);
    i = 5;
    announce_ai(i);
    c = getch();
    if (c == 89) {
        start();
    }
    else if (c == 78)
        ai();
}

void multiplayer_mode(){
    int i = 1;
    announce_multiplayer(i);
    int move;
    int num;
    cin >> num;
    if (!(cin >> move)){
        throw exception();
    }
    i = 2;
    announce_multiplayer(i);
    char e;
    cin >> e;
    if (e == 'N')
    {
        multiplayer_mode();
    }
    number created;
    created = created.convert(num);
    i = 3;
    announce_multiplayer(i);
    //created.print();
    cin >> move;
    if (!(cin >> move)){
        throw exception();
    }
    i = 4;
    number converted_move = converted_move.convert(move);
    while (converted_move.fwd_conv() != move)
    {
        cin >> move;
        converted_move = converted_move.convert(move);
    }
    announce_multiplayer(i);
    game_table journal;
    journal.clear();
    numValue check;
    check.init();
    char c;
    cout << '\n';
    check = check.checkout(created, converted_move);
    journal.make_a_move(check, converted_move);
    journal.show();
    while (!check.wincondition()){

        check.init();
       // c = getch();

        cin >> move;
        number converted_move = converted_move.convert(move);
        while (converted_move.fwd_conv() != move)
        {
            cin >> move;
            converted_move = converted_move.convert(move);
        }
        announce_multiplayer(i);
        check = check.checkout(created, converted_move);
        journal.make_a_move(check, converted_move);
        journal.show();
        if (journal.journal.size() == 8)
        {
            i = 8;
            announce_multiplayer(i);
        }
        if (journal.journal.size() == 9)
        {
            i = 9;
            break;
        }
    }
    if (i != 9)
        i = 5;
    announce_multiplayer(i);
    i = 7;
    announce_multiplayer(i);
    c = getch();
    if (c == 89) {
        start();
    }
    else if (c == 78)
        multiplayer_mode();
}



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
        case 52:
            system("cls");
            start();
        default:
            c = getch();
            start();
    }
}

