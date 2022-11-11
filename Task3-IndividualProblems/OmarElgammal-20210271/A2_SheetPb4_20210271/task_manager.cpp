#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class proccess{
    protected:
        string name;
        int id;
        string memory;
    public:
        proccess(string name_, int id_, string memory_){
            name = name_;
            id = id_;
            memory = memory_;
        }
        string getMemory(){
            return memory;
        }
        int getID(){
            return id;
        }
        string getName(){
            return name;
        }
};
class taskManager{
    protected:
    vector<proccess> tasks;
    public:
    void addProccess(proccess p){
        tasks.push_back(p);
    }
    void print(){
        cout << left << setw(35) << "Program Name";
            cout << right << setw(10)<< "PID";
            cout << right << setw(15) << "MemoryUsed"<< endl;
        for(auto i : tasks){
            cout << left << setw(35) << i.getName();
            cout << right << setw(10)<< i.getID();
            cout << right << setw(15) << i.getMemory() << "K" << endl;
        }
    }
    void getCurrentTasks(){
        system("tasklist > tasks.txt");
        ifstream file("tasks.txt");
        string line;
        string trash;
        // ignoring first 2 lines
        getline(file, line);
        getline(file, line);
        getline(file, line);
        // using stringstream to get each word
        while(getline(file, line)){
            string name, memory;
            name = line.substr(0, 25);
            while(name.back() == ' '){
                name.pop_back();
            }
            line = line.substr(25, line.length() - 1);
            stringstream ss(line);
            int id;
            ss >> id >> trash >> trash >> memory;
            proccess p(name, id, memory);
            addProccess(p);
        }
    }
    void sort_by_memory(char order = 'd'){
        if(order == 'a'){
            sort(tasks.begin(), tasks.end(), [](proccess a, proccess b){
            if(a.getMemory().size() < b.getMemory().size()){
                return true;
            }
            else if(a.getMemory().size() == b.getMemory().size()){
                return a.getMemory() < b.getMemory();
            }
            return false;
        });
        }
        else{
            sort(tasks.begin(), tasks.end(), [](proccess a, proccess b){
            if(a.getMemory().size() > b.getMemory().size()){
                return true;
            }
            else if(a.getMemory().size() == b.getMemory().size()){
                return a.getMemory() > b.getMemory();
            }
            return false;
        });
        }
        
    }
    void sort_by_id(){
        sort(tasks.begin(), tasks.end(), [](proccess a, proccess b){
            return a.getID() < b.getID();
        });
    }
    
    void sort_by_name(){
        sort(tasks.begin(), tasks.end(), [](proccess a, proccess b){
            return a.getName() < b.getName();
        });
    }
};

int main(){
    taskManager tm;
    tm.getCurrentTasks();
    tm.sort_by_memory('a');
    // tm.sort_by_name();
    // tm.sort_by_id();
    tm.print();

}