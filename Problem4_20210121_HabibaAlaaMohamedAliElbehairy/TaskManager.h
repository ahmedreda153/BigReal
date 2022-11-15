#ifndef TaskManager_H
#define TaskManager_H
#include <bits/stdc++.h>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;
string imageName="",PID="",sessionName="",Session_="",MemUsage="";

int idx;
class TaskManager{
private:
    string image_name,session_name,sessIon_;
    int pid,mem_usage;
public:
    friend bool compare_name(TaskManager a,TaskManager b);
    friend bool compare_pid(TaskManager a,TaskManager b);
    friend bool compare_memuse(TaskManager a,TaskManager b);
    //setters
    void setimageName(string s);
    void setSessionName(string s);
    void setPid(int i);
    void setMemusage(int i);
    void setSessIon_(string s);
    //getters
    string getimageName();
    string getSessionName();
    int getPid();
    int getMemusage();
    string getSessIon_();

};
vector<TaskManager>v;
string exec(const char* cmd);
void Erase(string &s);
void ImageName(string &x);
void splitter(string x);
bool compare_name(TaskManager a,TaskManager b);
bool compare_pid(TaskManager a,TaskManager b);
bool compare_memuse(TaskManager a,TaskManager b);
#endif