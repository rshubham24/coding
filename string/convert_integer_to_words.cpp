#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvb vector<vb>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)

vector<string> int1{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> int2{"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> tens{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};


string numberToWords(int a) {
        if(a == 0){
            return "Zero";   
        }
        else if(a < 10) {
            return int1[a - 1];
        }
        else if(a < 20){
            return tens[a - 10];
        }
        else if(a < 100){
            return int2[a/10 - 1] + (a % 10 == 0 ? "" : (" " + numberToWords(a % 10)));
        }
        else if(a < 1000){
            return int1[a/100 - 1] + " Hundred" + (a % 100 == 0 ? "" : (" " + numberToWords(a % 100)));
        } 
        else if(a < 1000000){
            return numberToWords(a/1000) + " Thousand" + (a % 1000 == 0 ? "" : (" " + numberToWords(a % 1000)));
        }
        else if(a < 1000000000){
            return numberToWords(a/1000000) + " Million" + (a % 1000000 == 0 ? "" : (" " + numberToWords(a % 1000000)));
        }
        else{
            return numberToWords(a/1000000000) + " Billion" + (a % 1000000000 == 0 ? "" : (" " + numberToWords(a % 1000000000)));
        }
        return "";
    }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << numberToWords(n);
	return 0;
}	