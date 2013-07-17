/*
 *
 * Solution for 'passrecovery'
 * Author: <rajorshi.biswas@gmail.com>
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cctype>

using namespace std;

inline string filter(string word)
{
    string res = "";
    for(size_t i=0; i < word.size(); i++)
    {
        if(isalpha(word[i]))
            res += tolower(word[i]);
    }
    return res;
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cerr<<"usage: "<<argv[0]<<" <input file>\n";
        return 1;
    }

    ifstream fin(argv[1]);
    string pw, word;
    string digits = "0248";

    // map of existing words
    map<string, bool> exist;

    // map of length based words
    vector<string> vs;
    vector<vector<string> > wmap(8, vs);

    fin>>pw;

    // salt - first two characters
    string salt = pw.substr(0,2);

    // read each word and build map
    while(!fin.eof())
    {
        fin>>word;

        word = filter(word);

        if(exist.find(word) == exist.end())
        {
            exist[word] = true;

            if(word.size() > 7 || word.size() < 1)
                continue;

            wmap[word.size()].push_back(word);
        }
    }


    // build all possible 5-8 char passwords and match crypts
    for(size_t len = 4; len <= 7; len++)
    {
        for(size_t left = 1; left < len; left++)
        {
            size_t right = len - left;

            vector<string>& lwords = wmap[left];
            vector<string>& rwords = wmap[right];

            if(lwords.empty() || rwords.empty())
                continue;

            for(size_t ls = 0; ls < lwords.size(); ls++)
            {
                for(size_t rs = 0; rs < rwords.size(); rs++)
                {
                    for(size_t ds = 0; ds < digits.size(); ds++)
                    {
                        string match = lwords[ls] + digits[ds] + rwords[rs];

                        string crypted = crypt(match.c_str(), salt.c_str()); 

                        if(crypted == pw)
                        {
                            // found result
                            cout<<match<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }


    return 0;
}
