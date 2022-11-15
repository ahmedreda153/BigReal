#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class stringset
{
private:
    vector<string> v1;
    set<string> set1;

public:
    stringset(){};
    set<string> getset(){return set1;}
    stringset(char a[30]);
    stringset(string s);
    void add(string s);
    void remove(string s);
    void clear();
    int size();
    void output();
    stringset operator+(stringset obj1);
    stringset operator*(stringset obj1);
    float similarity(stringset obj1);
};


stringset::stringset(char a[30])
{
    fstream file;
    file.open(a, ios::in);
    string word;
    while (!file.eof())
    {
        file >> word;
        v1.push_back(word);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        for (auto &c : v1[i])
        {
            c = tolower(c);
            auto it = remove_if(v1[i].begin(), v1[i].end(), ::ispunct);
            v1[i].erase(it, v1[i].end());
        }
    }
    for (size_t i = 0; i < v1.size() - 1; i++)
    {
        set1.insert(v1[i]);
    }
    // for (auto it = set1.begin(); it != set1.end(); ++it)
    //     cout << ' ' << *it;
}

stringset::stringset(string s)
{
    string zadd = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            zadd += s[i];
        }
        if (s[i] >= 65 && s[i] <= 90)
        {
            zadd += s[i];
        }
        if (s[i] == ' ' || s[i] == '.')
        {
            v1.push_back(zadd);
            zadd = "";
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        for (auto &c : v1[i])
        {
            c = tolower(c);
        }
    }
    for (size_t i = 0; i < v1.size() - 1; i++)
    {
        set1.insert(v1[i]);
    }
}


void stringset::add(const string s)
{
    set1.insert(s);
}
void stringset::remove(string s)
{
    set1.erase(s);
}
void stringset::clear()
{
    set1.clear();
}
int stringset::size()
{
    return set1.size();
}
void stringset::output()
{
    for (auto it = set1.begin(); it != set1.end(); ++it)
        cout << ' ' << *it;
}

stringset stringset::operator+(stringset obj1){
    stringset res;
    for (auto it = set1.begin(); it != set1.end(); ++it){

        res.add(*it);
    }
    set<string> set2=obj1.getset();
    for (auto it = set2.begin(); it != set2.end(); ++it){

        res.add(*it);
    }
    return res;

}

stringset stringset::operator*(stringset obj1){
    stringset res;
    
    set<string> set2=obj1.getset();
    for (auto it1 = set2.begin(); it1 != set2.end(); ++it1){
        for (auto it2 = set1.begin(); it2 != set1.end(); ++it2){
            if(*it1==*it2)
            {
                res.add(*it1);
                break;
            }
    }
       
    }

    return res;

}
float stringset::similarity(stringset obj1){
stringset result= *this*obj1;
int size1(result.getset().size()) ,size2(set1.size()),size3(obj1.getset().size());
return size1/(sqrt(size2)*sqrt(size3));
}

int main()
{
    string a="“Choclate icecream, chocolate milk, and chocolate bars are delicious .”";
    char file[30]="sample.txt";
    stringset x(file);
    stringset y(a);
    // stringset r = x*y;
    // r.getset().size();
    cout<<x.similarity(y);
    // r.add("a5dar");
    // y.output();
}