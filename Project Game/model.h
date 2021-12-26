#include <time.h>
using namespace std;

class number
{
public:
    int digit[4];

    void reset()
    {
        for (int i = 0; i < 4; ++i) {
            digit[i] = 0;
        }
    }

    void generate()
    {
        for (int i = 0; i < 4; ++i) {
            digit[i] = (rand() % 10);
        };
        if (digit[0]==0)
            generate();
    }

    void print()
    {
        for (int i = 0; i < 4; ++i) {
            cout << digit[i] << " ";
        }
        cout << "\n";
    }

    number convert(int n)
    {
        number result;
        result.reset();
        try {
            if (n < 1000 || n > 9999)
                throw -1;
        }
        catch (int a){
            std::cerr << "\nCaught exception '" << a << "': invalid int for converting" << '\n';
            result.reset();
            return result;
        }
        int i = 3;
        while (n){
            result.digit[i] = n % 10;
            n /= 10;
            i--;
        }
        return result;
    }

    int fwd_conv()
    {
        return digit[0]*1000+digit[1]*100+digit[2]*10+digit[3];
    }

    string easy_search(number a, int n, int standing)
    {
        string result = "miss";
        for (int i = 0; i < 4; ++i) {
            if ((n == a.digit[i]) && (standing == i)) {
                result = "bull";
                return result; //NOTE HERE: IF ONE NUMBER IS BOTH "COW" & "BULL" THE BEST RESULT IS DEFINED
            }
            else if (n == a.digit[i])
                result = "cow";
        }
        return result;
    }

private:

};

class numValue{
public:
    map<string,int> value;
    void init() {

        pair<string, int> temp;
        temp.second = 0;
        temp.first = "bull";
        value.insert(temp);
        temp.first = "cow";
        value.insert(temp);
        temp.first = "miss";
        value.insert(temp);
    }
    numValue checkout(number a, number b)
    {
        numValue result;
        result.init();
        std::map<string, int>::iterator it;
        for (int i = 0; i < 4; ++i) {
            result.value.find(a.easy_search(b, a.digit[i], i))->second++;
        }
        return result;
    }
    void print() {
        std::map<string, int>::iterator it;
        for (it=value.begin(); it != value.end(); it++) {
            cout.width(5);
            cout << it->second << " ";
        }
    }

    bool wincondition(){
        if (value.find("bull")->second == 4)
            return true;
        else
            return false;
    }

};

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

number produce(vector<int> hypothesis){
    vector<int> placements;
    int temp;
    srand(time(NULL));
    while (placements.size() < 5){
        temp = rand() % 4 + 1;
        while (std::find(placements.begin(), placements.end(), temp) == placements.end()){
            temp = rand() % 4 + 1;
        }
        placements.push_back(temp);
    }
    number result;
    result.reset();
    //vector<int>::iterator it;
    while (hypothesis.size()){
        result.digit[(*placements.begin())] = *hypothesis.begin();
        hypothesis.erase(hypothesis.begin());
        placements.erase(placements.begin());
    }
    return result;
}

class ai_guessing{
public:
    int state[10][4];
    void init(){
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 4; ++j) {
                state[i][j] = 0;
            }
        }
    }
    string decrypt(int i, int j){
        switch (state[i][j]) {
            case 0:
                return "Not checked";
            case 1:
                return "Not defined";
            case 2:
                return "Miss";
            case 3:
                return "Bull or Cow";
            case 4:
                return "Bull";
            case 5:
                return "Cow";
            default:
                return "Error";
        }
    }
    void turn(game_table table){
        vector<pair<int, numValue>>::iterator it;
        for (it = table.journal.begin(); it < table.journal.end(); it++) {
            if (it->second.value.find("miss")->second == 4){
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        state[i][j] = 2;
                    }
                }
            }
            else if (it->second.value.find("miss")->second == 0){
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        state[i][j] = 3;
                    }
                }
            }
            else{
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        state[i][j] = 1;
                    }
                }
            }

        }
    }
    number make_a_move(){
        vector<pair<int,int>> undef, unchecked, hits;
        pair<int, int> temp;
        vector<int> hypothesis;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 4; ++j) {
                temp.first = i;
                temp.second = j;
                if (state[i][j] == 1){
                    undef.push_back(temp);
                    break;
                }
                else if (state[i][j] == 0){
                    unchecked.push_back(temp);
                    break;
                }
                else if (state[i][j] == 3){
                    hits.push_back(temp);
                    break;
                }
            }
        }
        while (hypothesis.size() < 5){
            vector<pair<int,int>>::iterator it;
            if (!(hits.empty())){
                it = hits.begin();
                hypothesis.push_back(it->first);
                hits.erase(hits.begin());
            }
            else if (!(undef.empty())){
                it = undef.begin();
                hypothesis.push_back(it->first);
                undef.erase(undef.begin());
            }
            else if (!(unchecked.empty())){
                it = unchecked.begin();
                hypothesis.push_back(it->first);
                unchecked.erase(unchecked.begin());
            }
        }
        return produce(hypothesis);

    }
    number make_a_random_move(){
        srand(time(NULL));
            int temp = ((rand() % 9000) + 1000);
        number result;
        return result.convert(temp);
    }

};

