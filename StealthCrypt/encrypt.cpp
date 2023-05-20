
#include <bits/stdc++.h>
#include "encrypt.h"
#include <bitset>
#include <vector>

using namespace std;

// performs exclusive or on the characters of message
// and target and returns the xor values
string get_key(string message, string target)
{
	string key;
	vector<bitset<8>> msgSet, trgSet, keySet;

	// if the message is longer than the target string
	if (message.size() >= target.size())
	{
		for (unsigned i = 0; i < message.size(); ++i)
		{
			msgSet.push_back(message.at(i));

			if (i >= target.size())
			{
				target.append(" ");
				trgSet.push_back(' ');
			}
			else
				trgSet.push_back(target.at(i));
		}

		for (unsigned i = 0; i < msgSet.size(); ++i)
		{
			if (((msgSet[i] ^ trgSet[i]) == 0) || (msgSet[i] == trgSet[i]))
				keySet.push_back(' ');
			else
				keySet.push_back(msgSet[i] ^ trgSet[i]);

			key += (char)(keySet.back().to_ulong());
		}
	}

	// target string is longer
	else
	{
		for (unsigned i = 0; i < target.size(); ++i)
		{
			trgSet.push_back(target.at(i));

			if (i >= message.size())
			{
				message.append(" ");
				msgSet.push_back(' ');
			}
			else
				msgSet.push_back(message.at(i));
		}

		for (unsigned i = 0; i < trgSet.size(); ++i)
		{
			// cout << (char)msgSet[i].to_ulong()
			//      << (char)trgSet[i].to_ulong()
			//      << '\n';

			if (((msgSet[i] ^ trgSet[i]) == 0) || (msgSet[i] == trgSet[i]))
				keySet.push_back(' ');
			else
				keySet.push_back(msgSet[i] ^ trgSet[i]);

			key += (char)(keySet.back().to_ulong());
		}
	}
	
	return key;
}

// performs exclusive or the characters of target and key
// and returns the resulting values (the original message)
string decipher(string target, string key)
{
	string message;
	vector<bitset<8>> msgSet, trgSet, keySet;

	// if the target message is longer than the key
	if (target.size() >= key.size())
	{
		for (unsigned i = 0; i < target.size(); ++i)
		{
			trgSet.push_back(target.at(i));

			if (i >= key.size())
			{
				key.append(" ");
				keySet.push_back(' ');
			}
			else
				keySet.push_back(key.at(i));
		}

		for (unsigned i = 0; i < trgSet.size(); ++i)
		{
			if (((trgSet[i] ^ keySet[i]) == 0) || (trgSet[i] == keySet[i]))
				msgSet.push_back(' ');
			else
				msgSet.push_back(trgSet[i] ^ keySet[i]);

			message += (char)(msgSet.back().to_ulong());
		}
	}

	// the key is longer
	else
	{
		for (unsigned i = 0; i < key.size(); ++i)
		{
			keySet.push_back(key.at(i));

			if (i >= target.size())
			{
				target.append(" ");
				trgSet.push_back(' ');
			}
			else
				trgSet.push_back(target.at(i));
		}

		for (unsigned i = 0; i < keySet.size(); ++i)
		{
			if (((trgSet[i] ^ keySet[i]) == 0) || (trgSet[i] == keySet[i]))
				msgSet.push_back(' ');
			else
				msgSet.push_back(trgSet[i] ^ keySet[i]);

			message += (char)(msgSet.back().to_ulong());
		}
	}
	
	return message;
}
