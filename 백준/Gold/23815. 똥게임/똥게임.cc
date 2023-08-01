#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
using namespace std;

int n,a,b;
int p = 1;
int p2 = 1;
int a2,b2;
int cal(char i, int v,int cnt){
	if(i == '+'){
		return cnt += v;
	}
	else if (i == '-')
	{
		return cnt -= v;
	}
	else if (i == '*')
	{
		return cnt *= v;
	}
	else
	{
		return cnt /= v;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	string s;
	int skip = 1;
	int skip2 = 1;
	
	bool can = true;
	while (n--)
	{
		cin >> s;
		a = cal(s[0],s[1]-'0',p);
		a2 = cal(s[0],s[1]-'0',p2);
		cin >> s;
		b = cal(s[0],s[1]-'0',p);
		b2 = cal(s[0],s[1]-'0',p2);
		if (a <= 0 && b <= 0)
		{
			if (skip == 1)
			{
				skip = 0;
				skip2 = 0;
				p2 = p;
			}
			else{
				if (max(a2,b2) > 0 && skip2 == 1)
				{
					p = max(a2,b2);
					p2 = max(a2,b2);
					skip = 1;
				}
				else{
					can = false;
				}
			}
		}
		else if (a < p && b < p)
		{
			if (skip == 1)
			{
				skip = 0;
				p2 = max(a2,b2);
			}
			else{
				if (max(a,b) <= p2 && skip2 == 1)
				{
					skip = 0;
					p = p2;
					p2 = max(a2,b2);
				}
				else{
					p = max(a,b);
					p2 = max(a2,b2);
				}
			}			
		}
		else{
			p = max(a,b);
			p2 = max(a2,b2);
		}
		if (p2 <= 0)
		{
			skip2 = 0;
		}
	}

	if (skip2 == 1)
	{
		p = max(p,p2);
	}
	
	if (can)
	{
		cout << p;
	}
	else{
		cout << "ddong game";
	}
}