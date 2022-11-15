#include <bits/stdc++.h>
#include <stdexcept>
#include <stdio.h>
using namespace std;
string exec(const char *cmd)
{
    char buffer[128];
    string result = "";
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
        throw runtime_error("popen() failed!");
    try
    {
        while (fgets(buffer, sizeof buffer, pipe) != NULL)
        {
            result += buffer;
        }
    }
    catch (...)
    {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}
// process function
class TaskManager
{
private:
    string image_name, session_name, sessIon_;
    int pid, mem_usage;

public:
    friend bool compare_name(TaskManager a, TaskManager b);
    friend bool compare_pid(TaskManager a, TaskManager b);
    friend bool compare_memuse(TaskManager a, TaskManager b);

    // setters
    void setimageName(string s) { image_name = s; }
    void setSessionName(string s) { session_name = s; }
    void setPid(int i) { pid = i; }
    void setMemusage(int i) { mem_usage = i; }
    void setSessIon_(string s) { sessIon_ = s; }

    // getters
    string getimageName() { return image_name; }
    string getSessionName() { return session_name; }
    int getPid() { return pid; }
    int getMemusage() { return mem_usage; }
    string getSessIon_() { return sessIon_; }
};

// compare functions
bool compare_name(TaskManager a, TaskManager b) { return a.image_name < b.image_name; }
bool compare_pid(TaskManager a, TaskManager b) { return a.pid < b.pid; }
bool compare_memuse(TaskManager a, TaskManager b) { return a.mem_usage < b.mem_usage; }

// objects vector
vector<TaskManager> vOb;

vector<string> vectorWord(string s, char delimiter)
{
    string sub = s.substr(0, 25);
    vector<string> v;
    string temp = "";
    v.push_back(sub);
    for (int i = 25; i < s.length(); i++)
    {
        if (s[i] != delimiter)
        {
            temp += s[i];
        }
        else if (s[i] == delimiter && s[i + 1] == delimiter)
            continue;
        else
        {
            if (!temp.empty())
                v.push_back(temp);
            temp = "";
        }
    }
    v.push_back(temp);
    return v;
}
void Line(string s)
{
    vector<string> words;
    stringstream ss(s);
    string temp;
    getline(ss, temp);
    getline(ss, temp);
    getline(ss, temp);
    while (getline(ss, temp))
    {
        words = vectorWord(temp, ' ');
        TaskManager T;
        T.setimageName(words[0]);
        T.setPid(stoi(words[1]));
        T.setSessionName(words[2]);
        T.setSessIon_(words[3]);
        // removing (,) for ability to use stoi
        words[4].erase(remove(words[4].begin(), words[4].end(), ','), words[4].end());
        T.setMemusage(stoi(words[4]));
        vOb.push_back(T);
    }
}

int main()
{
    string sentence = exec("tasklist");
    Line(sentence);
    int choice;
    cout << "Enter 1 for name\n2 for id\n3 for memory use: \n";
    cin >> choice;
    if (choice == 1)
        sort(vOb.begin(), vOb.end(), compare_name);
    else if (choice == 2)
        sort(vOb.begin(), vOb.end(), compare_pid);
    else
        sort(vOb.begin(), vOb.end(), compare_memuse);
    for (auto i : vOb)
    {
        cout << setw(30) << left << i.getimageName() << setw(10) << i.getPid() << setw(20) << i.getSessionName() << setw(10) << i.getSessIon_() << setw(10) << i.getMemusage() << "K" << endl;
    }
}