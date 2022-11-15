#include "TaskManager.h"
using namespace std;

void TaskManager::setimageName(string s){
        image_name=s;
}
void TaskManager::setSessionName(string s){
        session_name=s;
}
void TaskManager::setPid(int i){
        pid=i;
}
void TaskManager::setMemusage(int i){
        mem_usage=i;
}
void TaskManager::setSessIon_(string s){
        sessIon_=s;
}
string TaskManager::getimageName(){
        return image_name;
}
string TaskManager::getSessionName(){
        return session_name;
}
int TaskManager::getPid(){
        return pid;
}
int TaskManager::getMemusage(){
        return mem_usage;
}
string TaskManager::getSessIon_(){
        return sessIon_;
}

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void Erase(string &s){
    while(s[0]==' ')
        s.erase(0,1);
}

void ImageName(string &x){
    for(int i=0;i<x.size();i++){
        if(x[i]==' '&&x[i+1]==' ')
            break;
        else
            imageName+=x[i];
    }
    x.erase(0,imageName.size());
    Erase(x);
}

void splitter(string x){
    ImageName(x);
    idx=x.find(" ");
    PID=x.substr(0,idx);
    x.erase(0,PID.size());
    Erase(x);
    idx=x.find(" ");
    sessionName=x.substr(0,idx);
    x.erase(0,sessionName.size());
    Erase(x);
    idx=x.find(" ");
    Session_=x.substr(0,idx);
    x.erase(0,Session_.size());
    Erase(x);
    reverse(x.begin(),x.end());
    x.erase(0,2);
    reverse(x.begin(),x.end());
    x.erase(remove(x.begin(), x.end(),','), x.end());
    MemUsage=x;
}

bool compare_name(TaskManager a,TaskManager b){
    return a.image_name<b.image_name;
}
bool compare_pid(TaskManager a,TaskManager b){
    return a.pid<b.pid;
}
bool compare_memuse(TaskManager a,TaskManager b){
    return a.mem_usage<b.mem_usage;
}
