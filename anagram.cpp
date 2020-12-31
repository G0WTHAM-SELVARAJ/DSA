#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int checkAnagram(string query, string dictionary){
    int alpha[122];
    char *queryArr = new char[query.length() + 1];
    strcpy(queryArr, query.c_str());
    char *dictionaryArr = new char[dictionary.length()+1];
    strcpy(dictionaryArr,dictionary.c_str());
    for(int i=0;i<query.length()+1;i++){
        alpha[(int)queryArr[i]]++;
        cout<<alpha[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<dictionary.length()+1;i++){
        alpha[(int)dictionaryArr[i]]--;
        cout<<alpha[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<122;i++){
        if(alpha[i]==1){
            return 0;
        }
    }
    return 1;
}

vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    vector<int> anagram;
    for(int i=0;i<query.size();i++){
        int count=0;
        for(int j=0;j<dictionary.size();j++){
            count+=checkAnagram(query[i],dictionary[j]);
        }
        anagram.push_back(count);
    }
    return anagram;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dictionary_count_temp;
    getline(cin, dictionary_count_temp);

    int dictionary_count = stoi(ltrim(rtrim(dictionary_count_temp)));

    vector<string> dictionary(dictionary_count);

    for (int i = 0; i < dictionary_count; i++) {
        string dictionary_item;
        getline(cin, dictionary_item);

        dictionary[i] = dictionary_item;
    }

    string query_count_temp;
    getline(cin, query_count_temp);

    int query_count = stoi(ltrim(rtrim(query_count_temp)));

    vector<string> query(query_count);

    for (int i = 0; i < query_count; i++) {
        string query_item;
        getline(cin, query_item);

        query[i] = query_item;
    }

    vector<int> result = stringAnagram(dictionary, query);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
