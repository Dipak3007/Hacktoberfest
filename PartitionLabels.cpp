/*
Question : You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
Example :
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// function to partition the string into labels 
vector<int> partitionLabels (string str)
{
	// creating unordered map
	unordered_map <char, int> map;
	int n = str.length();
	
	// storing the last occurence index of characters into map
	for (int i=0; i<n; i++)
	{
		map[str[i]] = i;
	}
	
	vector<int> v;
	int prev = -1, getMax = 0;
	for (int i=0; i<n; i++)
	{
		char ch = str.at(i);
		getMax = max(getMax, map.at(ch));
		
		if (getMax == i)
		{
			v.push_back( getMax - prev );
			prev = getMax;
		}
	}
	return v;
}

// driver method
int main ()
{
	int t;
	cout << "Enter the number of test cases : ";
	cin >> t;
	while (t--)
	{
		// taking string input from the user
		string s;
		cout << "Enter the string : ";
		cin >> s;
		
		// creating vector
		vector<int> output;
		output = partitionLabels (s);
		
		// printing the output
		for (int i=0; i<output.size(); i++)
		{
			cout << output[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
