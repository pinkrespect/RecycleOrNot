#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

class Players {
    private:
        string name;

    public:
        void setName(const string& name) { this->name = name; }
        const string& getName() { return name; }
};

class WordGame {
    private:
        int sequence;
        string before = "", present = "";

    public:
        void setBefore() {
            before = present;
        }

        void setPresent(string _new) {
            present = _new;
        }

        const string& getBefore(){ return before; }
        const string& getPresent(){ return present; }

        int compareWord(string B, string P){
            wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
            u32string beforeEnd = conv.from_bytes(B);
            u32string presentFirst = conv.from_bytes(P);
            u32string bEnd;

            for (auto p : presentFirst){
                presentFirst = p;
                break;
            }

            for (auto b : beforeEnd) {
                bEnd = b ;
            }

            if(bEnd == presentFirst){
                setBefore();
                return 0;
            } else {
                return 1;
            }
        }

        int checkKorean(string tmpPresent){
            wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
            auto utf32string = conv.from_bytes(tmpPresent);
            for(auto character : utf32string){
                char32_t temp[1] = { character };
                auto ch = conv.to_bytes(temp, temp+1);
                if (U'가' <= character && character <= U'힣') {
                    if (!getBefore().compare("")){
                        setBefore();
                        return 1;
                    } else if (!compareWord(getBefore(), tmpPresent) && getBefore().compare("")){
                        return 2;
                    } else{
                        return 3;
                    }
                } else {
                    return 0;
                }
            }
        }

        int playGame(string word) {
            setPresent(word);
            switch(checkKorean(word)){
                case 0:
                    cout << "한글을 입력하세요." << endl;
                    return -1;

                case 1:
                    return 0;

                case 2:
                    return 0;

                case 3:
                    return 1;
            }
        }
};

int main() {
    int gamers;
    string word;
    cout << "끝말잇기 게임을 시작합니다." << endl << "게임에 참가하는 인원은 몇 명입니까? >> " << endl;
    cin >> gamers;

    // TODO: 동적할당 대신 vector로 대체
    Players *players = new Players[gamers];
    WordGame wordgame;

    for (int i = 0 ; i < gamers; i++) {
        string name;
        cout << i + 1 << "번째 플레이어의 이름을 입력해 주세요. >> ";
        cin >> name;
        players[i].setName(name);
    }
    while(true) {
        for (int i = 0; i < gamers; i++) {
            cout << players[i].getName() << " >> ";
            cin >> word;
            switch(wordgame.playGame(word)){
                case -1:
                    i -= 1;
                    break;
                case 1:
                    cout << players[i].getName() << " 게임 패배!" << endl;
                    delete [] players;
                    return 0;
                case 0:
                    break;
            }
        }
    }

}
