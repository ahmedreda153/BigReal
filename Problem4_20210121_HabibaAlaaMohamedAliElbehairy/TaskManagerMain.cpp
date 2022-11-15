#include "TaskManager.h"
#include "TaskManager.cpp"
using namespace std;

int main(){
    string task=exec("tasklist");
    string x="";
    for(int i=155;i<task.size();i++){
        if(task[i]!='\n'){
            x+=task[i];}
        else {
            imageName="",PID="",sessionName="",Session_="",MemUsage="";
            splitter(x);
            TaskManager a;
            a.setimageName(imageName);
            a.setSessionName(sessionName);
            a.setPid(stoi(PID));
            a.setMemusage(stoi(MemUsage));
            a.setSessIon_(Session_);
            v.push_back(a);
            x="";
        }
    }
    int choice;
    cout<<"Enter\n1 for Name\n2 for PID\n3 for Memory Usage: \n";
    cin>>choice;
    if(choice==1){
        sort(v.begin(),v.end(),compare_name);
    }
    else if(choice==2){
        sort(v.begin(),v.end(),compare_pid);
    }
    else {
        sort(v.begin(),v.end(),compare_memuse);
    }
    //cout first 3 lines
    for(int i=0;i<155;i++){
        cout<<task[i];
    }
    cout<<"\n";
    for(int i=0;i<v.size();i++){
    cout<<setw(30)<<left<<v[i].getimageName()<<setw(10)<<v[i].getPid()<<setw(20)<<v[i].getSessionName()<<setw(10)<<v[i].getSessIon_()<<setw(10)<<v[i].getMemusage()<<"K"<<endl;
    }
}
