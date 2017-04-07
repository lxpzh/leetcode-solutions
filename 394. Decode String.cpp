class Solution
{
public:
	/*
	s = "3[a]2[bc]", return "aaabcbc".
	s = "3[a2[c]]", return "accaccacc".
	s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
	*/
	string decodeString(char*& str)
	{
	    string result;

		while (*str != '\0')
		{
			if (isdigit(*str))
			{
				char *pend;
				int num = strtol(str, &pend, 10);
                str = pend;

		//		cout << "str: " << str << ", num: " << num << endl;

				if (*str == '[')
				{
					string decodeStr = decodeString(++str);

					while (num--)
					{
						result += decodeStr;
					}
					if (*str == ']')
                        ++str;
		//			cout << "result: " << result << endl;
				}
				else {
                    cerr << " *pend is not [" << endl;
                    return "";
				}
			}
			else if (isalpha(*str))
			{
				string chStr;

				while (isalpha(*str))
				{
					chStr += *str;
					str++;
				}
		//		cout << "chStr: " << chStr << endl;
				if (*str == ']')
                    ++str;
				string temp = result + chStr + decodeString(str);

		//		cout <<"temp: " <<  temp << endl;
				return temp;
			}
			else
			{
				++str;
				cerr << "unexpected character: " << *str << endl;
			}
		}

		return result;
	}

	string decodeString(string s)
	{
	    char* str = new char[s.size() + 1];
		strcpy(str, s.c_str());
        char* pstr = str;


	//	cout << str << "," << strlen(str) << " : " << s.size() << endl;
		string result = decodeString(pstr);

        cout << "result: " << result << endl;
	 	delete[] str;

		return result;
	}
};