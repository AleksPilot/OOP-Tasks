#include "interface.h"
#include <conio.h>
//#include "model.h"

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

void complexed_ai_mode(){
    int i = 1;
    announce_comp(i);
    int move;
    int num;
    cin >> num;
    /*if (!(cin >> move)){
        throw exception();
    }*/
    i = 2;
    announce_comp(i);
    char e;
    cin >> e;
    if (e == 'N')
    {
        complexed_ai_mode();
    }
    number created;
    created = created.convert(num);
    i = 3;
    announce_comp(i);
    number comp_created;
    comp_created.generate();
    comp_created.print();
    created.print();
    //created.print();
    cin >> move;
    if (!(cin >> move)){
        throw exception();
    }
    i = 4;
    number converted_move = converted_move.convert(move);
    ai_guessing guess;
    guess.init();
    number comp_move = guess.make_a_random_move();
    while (converted_move.fwd_conv() != move)
    {
        cin >> move;
        converted_move = converted_move.convert(move);
    }
    announce_comp(i);
    game_table player_journal;
    game_table ai_journal;
    player_journal.clear();
    ai_journal.clear();
    numValue player_check;
    numValue ai_check;
    ai_check.init();
    player_check.init();
    char c;
    cout << '\n';
    player_check = player_check.checkout(comp_created, converted_move);
    player_journal.make_a_move(player_check, converted_move);
    player_journal.show();
    ai_check = ai_check.checkout(created, comp_move);
    ai_journal.make_a_move(ai_check, comp_move);
    ai_journal.show();
    while (!player_check.wincondition() && !ai_check.wincondition()){

        player_check.init();
        // c = getch();
        cin >> move;
        number converted_move = converted_move.convert(move);
        while (converted_move.fwd_conv() != move)
        {
            cin >> move;
            converted_move = converted_move.convert(move);
        }
        announce_multiplayer(i);
        comp_move = guess.make_a_random_move();
        player_check = player_check.checkout(comp_move, converted_move);
        player_journal.make_a_move(player_check, converted_move);
        player_journal.show();
        ai_check = ai_check.checkout(created, comp_move);
        ai_journal.make_a_move(ai_check, comp_move);
        ai_journal.show();
    }
    if (player_check.wincondition()) {
        i = 5;
        announce_comp(i);
    }
    else{
        i = 9;
        announce_comp(i);
    }
    i = 7;
    announce_comp(i);
    c = getch();
    if (c == 89) {
        start();
    }
    else if (c == 78)
        complexed_ai_mode();
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

