#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "Image.h"
#include "encrypt.h"

using namespace std;

int main (int argc, char *argv[])
{
	string image, message, target;
	
	bool decoding = false;
	
	if (argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			// if the flag is tacked
			if (*argv[i] == '-')
			{	// check the tacked flag letter and assign values accordingly
				if (*(argv[i]+1) == 'i')
					image = argv[i+1];
				else if (*(argv[i]+1) == 'm')
					message = argv[i+1];
				else if (*(argv[i]+1) == 't')
					target = argv[i+1];
				else if (*(argv[i]+1) == 'd')
					decoding = true;
			}
			
		}
	}
	
	else
		return 1;
	

	if (decoding)
	{
		Image neew(image.c_str());
		
		char buffer[256] = {0};
		size_t len = 0;
		neew.decodeMessage(buffer, &len);
		
		printf("Message: %s (%zu)\n", buffer, len);
		cout << decipher(target, buffer) << '\n';
	}
	
	else
	{
		if (message.size() > 0)
		{
			Image neew(image.c_str());
		
			string key = get_key(message, target);
			
			neew.encodeMessage(key.c_str());
			neew.write("new.png");
		}
	}
	
	return 0;
}
