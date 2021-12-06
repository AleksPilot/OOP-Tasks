class game_table{
    vector<pair<int, numValue>> journal;
    void show(){
        vector<pair<int, numValue>>::iterator it;
        cout.width(11);
        cout << "num of try" << cout.width(5) << "bull" << cout.width(5) << "cow" << cout.width(5) << "miss\n";
        int i = 1;
        for (it = journal.begin(); it < journal.end(); ++it) {
            cout.width(11);
            cout << i << ' ';
            it->second.print();
            i++;
        }
    }
    void make_a_move(numValue new_turn){
        journal.push_back(pair<int, numValue> {journal.size(), new_turn});
    }

};

