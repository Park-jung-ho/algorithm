#include <vector>
#include <iostream>
#include <deque>
using namespace std;

char p(80);
char a(65);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    deque<char> queue;
    string ppap;
    cin >> ppap;
    if (ppap.length() < 4){
        if (ppap.length() == 1 && ppap[0] == p){
            cout << "PPAP";
        }
        else
            cout << "NP";
        return 0;
    }
    int len;
    for (int i = 0; i < ppap.length(); i++)
    {
        queue.push_back(ppap[i]);
        len = queue.size();
        if (len >= 4){
            while (true){
                len = queue.size();
                if (len < 4){
                    break;
                }
                if(queue[len-4] == p && queue[len-3] == p && queue[len-2] == a && queue[len-1] == p){
                    queue.pop_back();
                    queue.pop_back();
                    queue.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }
    
    if (queue.size() == 1 && queue.front() == p){
        cout << "PPAP";
    }
    else{
        cout << "NP";
    }

}