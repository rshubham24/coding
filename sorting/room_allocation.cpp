/*There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

Input

The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

Output

Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k.

*/
#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define lli long long int
#define li long int
#define ld long double
#define vii vector<int, int>
#define pii pair<int, int>
using namespace std;
const lli mod = 1e9 + 7;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y;
	cin >> n;
	vector<pair<int, pii>> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		v.pb({x, {-1, i}}); // comes in
		v.pb({y, {1, i}});  // goes out
	}
	sort(v.begin(), v.end());
 
	vector<int> rooms;
	int occupied = 0, max_rooms = 0, in_or_out, ind;
	int ans[200005];
	for (auto ele : v)
	{
		in_or_out = ele.second.first;
		ind = ele.second.second;
 
		if (in_or_out == 1)
		{
			// going out, so add that room number to rooms
			rooms.pb(ans[ind]);
		}
		else if (occupied == rooms.size())
		{
			// no more vacant rooms, so increase number of rooms
			ans[ind] = ++max_rooms;
		}
		else
		{
			// give a room and increase occupancy count
			ans[ind] = rooms[occupied++];
		}
	}
	cout << max_rooms << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}