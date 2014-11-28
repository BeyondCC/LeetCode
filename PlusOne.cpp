#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int jinBit = 1;
	int tmp = 0;

	for(int i = digits.size() - 1; i >= 0; i--) {
		tmp = digits[i];
		digits[i] = (tmp + jinBit) % 10;
		jinBit = (tmp + jinBit) / 10;
	}

	if(jinBit == 1)
		digits.insert(digits.begin(), 1);
	return digits;
}

int main(int argc, char*argv[])
{
	vector<int> v;
	v.push_back(9);
	v.push_back(9);

	plusOne(v);	
	return 1;
}
