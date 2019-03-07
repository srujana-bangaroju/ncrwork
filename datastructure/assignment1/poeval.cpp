#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
using namespace std;
int main() {
	stack<int> st;
	st.push(0);
	string s;
	cin >> s;
	int c1, c2;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])) {
			int a = (int)s[i];
			//cout<<a-48;
			st.push(a - 48);
		}
		else {
			if (s[i] == '*') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = c2*c1;
				st.push(s);
			}
			if (s[i] == '/') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = c2 / c1;
				st.push(s);
			}
			if (s[i] == '+') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = c2 + c1;
				st.push(s);
			}
			if (s[i] == '-') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = c2 - c1;
				st.push(s);
			}
		}

	}
	cout << st.top();
	return 0;
}