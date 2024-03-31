#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int Input_text = 0;
map<string,int> k;
vector<string> answer;

void taunt();
void sentence();
void noun_phrase();
void modified_noun();
void modifier();
void present_rel();
void past_rel();
void present_person();
void past_person();
void noun();
void present_verb();
void past_verb();
void article();
void adjective();
void adverb();

void solve()
{
    string a, t;
    string table[] = {"taunt","sentence","noun-phrase","modified-noun",          "modifier","present-rel","past-rel","present-person","past-person","noun","present-verb","past-verb","article","adjective","adverb"};

    string special = "theholygrail";
    string SPECIAL = "THEHOLYGRAIL";
    
    for (auto& s : table) k[s] = 0;

    while (getline(cin,a))
    {
        int idx = 0;
        Input_text = 0;
        istringstream ia(a);
        cout << "Knight:";
        while (getline(ia, t, ' '))
        {
            if (t == "") continue;

            cout << " " << t;
            
            bool isword = false;
            for (auto c : t)
            {
                if (special[idx] == c || SPECIAL[idx] == c) idx++;
                if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) isword = true;
            }
            if (isword) Input_text++;
        }
        cout << "\n";
        if (idx == 12)
        {
            Input_text -= 3;
            cout << "Taunter: (A childish hand gesture).\n";
        }
        while (Input_text > 0)
        {
            answer.clear();
            taunt();
            answer[0][0] = toupper(answer[0][0]);
            if (answer[0][answer[0].size()-1] == '!') answer[1][0] = toupper(answer[1][0]);
            cout << "Taunter:";
            for (auto c : answer) cout << " " << c;
            cout << ".\n";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

void taunt()
{
    Input_text -= 3;
    k["taunt"]++;
    int c = (k["taunt"]-1)%4 + 1;
    if (c == 1)
    {
        sentence();
    }
    if (c == 2)
    {
        taunt();
        sentence();
    }
    if (c == 3)
    {
        noun();
        answer[answer.size()-1].push_back('!');
    }
    if (c == 4)
    {
        sentence();
    }
}

void sentence()
{
    k["sentence"]++;
    int c = (k["sentence"]-1)%3 + 1;
    if (c == 1)
    {
        past_rel();
        noun_phrase();
    }
    if (c == 2)
    {
        present_rel();
        noun_phrase();
    }
    if (c == 3)
    {
        past_rel();
        article();
        noun();
    }
}

void noun_phrase()
{
    article();
    modified_noun();
}

void modified_noun()
{
    k["modified-noun"]++;
    int c = (k["modified-noun"]-1)%2 + 1;
    if (c == 1)
    {
        noun();
    }
    if (c == 2)
    {
        modifier();
        noun();
    }
}

void modifier()
{
    k["modifier"]++;
    int c = (k["modifier"]-1)%2 + 1;
    if (c == 1)
    {
        adjective();
    }
    if (c == 2)
    {
        adverb();
        adjective();
    }
}

void present_rel()
{
    answer.push_back("your");
    present_person();
    present_verb();
}

void past_rel()
{
    answer.push_back("your");
    past_person();
    past_verb();
}

void present_person()
{
    k["present-person"]++;
    int c = (k["present-person"]-1)%3 + 1;
    if (c == 1)
    {
        answer.push_back("steed");
    }
    if (c == 2)
    {
        answer.push_back("king");
    }
    if (c == 3)
    {
        answer.push_back("first-born");
    }
}

void past_person()
{
    k["past-person"]++;
    int c = (k["past-person"]-1)%5 + 1;
    if (c == 1)
    {
        answer.push_back("mother");
    }
    if (c == 2)
    {
        answer.push_back("father");
    }
    if (c == 3)
    {
        answer.push_back("grandmother");
    }
    if (c == 4)
    {
        answer.push_back("grandfather");
    }
    if (c == 5)
    {
        answer.push_back("godfather");
    }
}

void noun()
{
    k["noun"]++;
    int c = (k["noun"]-1)%11 + 1;
    if (c == 1)
    {
        answer.push_back("hamster");
    }
    if (c == 2)
    {
        answer.push_back("coconut");
    }
    if (c == 3)
    {
        answer.push_back("duck");
    }
    if (c == 4)
    {
        answer.push_back("herring");
    }
    if (c == 5)
    {
        answer.push_back("newt");
    }
    if (c == 6)
    {
        answer.push_back("peril");
    }
    if (c == 7)
    {
        answer.push_back("chicken");
    }
    if (c == 8)
    {
        answer.push_back("vole");
    }
    if (c == 9)
    {
        answer.push_back("parrot");
    }
    if (c == 10)
    {
        answer.push_back("mouse");
    }
    if (c == 11)
    {
        answer.push_back("twit");
    }
}

void present_verb()
{
    k["present-verb"]++;
    int c = (k["present-verb"]-1)%2 + 1;
    if (c == 1)
    {
        answer.push_back("is");
    }
    if (c == 2)
    {
        answer.push_back("masquerades as");
    }
}

void past_verb()
{
    k["past-verb"]++;
    int c = (k["past-verb"]-1)%2 + 1;
    if (c == 1)
    {
        answer.push_back("was");
    }
    if (c == 2)
    {
        answer.push_back("personified");
    }
}

void article()
{
    answer.push_back("a");
}

void adjective()
{
    k["adjective"]++;
    int c = (k["adjective"]-1)%7 + 1;
    if (c == 1)
    {
        answer.push_back("silly");
    }
    if (c == 2)
    {
        answer.push_back("wicked");
    }
    if (c == 3)
    {
        answer.push_back("sordid");
    }
    if (c == 4)
    {
        answer.push_back("naughty");
    }
    if (c == 5)
    {
        answer.push_back("repulsive");
    }
    if (c == 6)
    {
        answer.push_back("malodorous");
    }
    if (c == 7)
    {
        answer.push_back("ill-tempered");
    }
}

void adverb()
{
    k["adverb"]++;
    int c = (k["adverb"]-1)%5 + 1;
    if (c == 1)
    {
        answer.push_back("conspicuously");
    }
    if (c == 2)
    {
        answer.push_back("categorically");
    }
    if (c == 3)
    {
        answer.push_back("positively");
    }
    if (c == 4)
    {
        answer.push_back("cruelly");
    }
    if (c == 5)
    {
        answer.push_back("incontrovertibly");
    }
}