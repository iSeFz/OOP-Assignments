#include <iostream>
#include <vector>
#include <iomanip>
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
        cout << left << setw(20) << "Program Name";
            cout << right << setw(10)<< "PID";
            cout << right << setw(15) << "MemoryUsed"<< endl;
        for(auto i : tasks){
            cout << left << setw(20) << i.getName();
            cout << right << setw(10)<< i.getID();
            cout << right << setw(15) << i.getMemory() << "K" << endl;
    }
    
}};

int main(){
    taskManager tm;
    tm.addProccess(proccess("Chrome", 5, "10000000"));
    tm.print();

}