#include <bits/stdc++.h>
using namespace std;

int ignored_l = 0, ignored_r = 1;
int ignored_both = 2, ignored_none = 3;

vector<vector<vector<int>>> dp;
string str;
int finish, lim;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
    return (a + b) % mod;
}

int recurse(int ind, int start, int state)
{
    if(state == ignored_both)
        return (start == finish);

    if(ind >= (int)str.length())
        return (start == finish);

    if(start < 0 or start > lim)
        return 0;

    if(dp[ind][start][state] != -1)
        return dp[ind][start][state];

    int res, take_it, leave_it;

    if(state == ignored_l)
    {
        if(str[ind] == 'r')
        {
            take_it = recurse(ind + 1, start + 1, ignored_none);
            leave_it = recurse(ind + 1, start, ignored_both);
            res = add(take_it, leave_it);
        }
        else
        {
            leave_it = recurse(ind + 1, start, ignored_l);
            res = leave_it;
        }
    }
    
    if(state == ignored_r)
    {
        if(str[ind] == 'l')
        {
            take_it = recurse(ind + 1, start - 1, ignored_none);
            leave_it = recurse(ind + 1, start, ignored_both);
            res = add(take_it, leave_it);
        }
        else
        {
            leave_it = recurse(ind + 1, start, ignored_r);
            res = leave_it;
        }
    }

    if(state == ignored_none)
    {
        if(str[ind] == 'l')
        {
            take_it = recurse(ind + 1, start - 1, ignored_none);
            leave_it = recurse(ind + 1, start, ignored_l);
            res = add(take_it, leave_it);
        }

        if(str[ind] == 'r')
        {
            take_it = recurse(ind + 1, start + 1, ignored_none);
            leave_it = recurse(ind + 1, start, ignored_r);
            res = add(take_it, leave_it);
        }
    }

    dp[ind][start][state] = res;
    return res;
}

int main()
{
    cin >> str;

    int start;

    cin >> lim;
    cin >> start >> finish;


    dp.resize(str.length() + 3);

    for(auto &vec_2d: dp)
        vec_2d.resize(lim + 3, vector<int>(6, -1));

    cout << recurse(0, start, ignored_none) << endl;
    return 0;
}