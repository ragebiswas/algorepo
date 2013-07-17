/*
 *
 * Solution for 'passrecovery'
 * Author: <rajorshi.biswas@gmail.com>
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>


using namespace std;

static string filter(string word)
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

    // list of valid words
    vector<string> words;

    fin>>pw;
    
    // salt - first two characters
    string salt = pw.substr(0,2);

    // read each word and build map
    while(!fin.eof())
    {
        fin>>word;

        word = filter(word);

        if(word.size() > 8 || word.size() < 1)
            continue;
            
        words.push_back(word);
    }

                        
    size_t numwords = words.size();

    for(size_t i = 0; i < numwords; i++)
    {
        for(size_t j = 0; j < numwords; j++)
        {
            string& word1 = words[i];
            string& word2 = words[j];

            size_t sz = word1.size() + word2.size() + 1;

            if(sz < 5 || sz > 8)
                continue;
        
            for(size_t k = 0; k < digits.size(); k++)
            {
                string possible = word1 + digits[k] + word2;
                string crypted = string(crypt(possible.c_str(), salt.c_str())); 
                
                if(pw == crypted)
                {
                    cout<<possible<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;

}
