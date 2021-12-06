class game_table{
    vector<pair<int, numValue>> journal;
    void show(){
        vector<pair<int, numValue>>::iterator it;
        cout.width(11);
        cout << "num of try" << cout.width(5) << "bull" << cout.width(5) << "cow" << cout.width(5) << "miss\n";
        for (it = journal.begin(); it < journal.end(); ++it) {

        }
    }
};

