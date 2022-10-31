#include<bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
	string result = "";
	int n = b.size(),i;
	for(i = 1; i < n; i++){
        result += (a[i] == b[i])? "0" : "1";
	}
	return result;
}

string mod2div(string divident, string divisor)
{
	int pick = divisor.size(),n = divident.size();
	string tmp = divident.substr(0, pick);
	while (pick < n){
		if (tmp[0] == '1')
			tmp = xor1(divisor, tmp); ///regular XOR
		else
			tmp = xor1(string(pick, '0'), tmp);

        tmp+=divident[pick++];
	}

	// For the last n bits, we have to carry it out
	// normally as increased value of pick will cause
	// Index Out of Bounds.
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(string(pick, '0'), tmp);

	return tmp;
}

void decodeData(string codeword, string key){
    string rem = mod2div(codeword,key);
    cout<<((rem.find('1')==-1)? "No error Found" : "The data has errors")<<endl;
}

void encodeData(string data, string key){
	int l_key = key.size();
	string appended_data = (data +string(l_key - 1,'0'));

	string remainder = mod2div(appended_data, key);

	string codeword = data + remainder;
	cout << "Remainder : "<< remainder << "\n";
	cout << "Encoded Data (Data + Remainder) :"<< codeword << "\n";
    decodeData(codeword,key);
}

int main()
{
	string data = "100100";
	string key = "1101";

	encodeData(data, key);

	return 0;
}






///With love from Brainless_Loco
