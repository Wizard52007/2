#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, tq;

    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    bool added[10] = {false};

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter AT and BT for P" << i << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;

    int time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    while(completed < n) {

        for(int i = 0; i < n; i++) {
            if(!added[i] && at[i] <= time) {
                q.push(i);
                added[i] = true;
            }
        }

        if(q.empty()) {
            time++;
            continue;
        }

        int p = q.front();
        q.pop();

        int execute = min(tq, rt[p]);

        time += execute;
        rt[p] -= execute;

        for(int i = 0; i < n; i++) {
            if(!added[i] && at[i] <= time) {
                q.push(i);
                added[i] = true;
            }
        }

        if(rt[p] > 0) {
            q.push(p);
        }
        else {
            ct[p] = time;
            completed++;

            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            avgWT += wt[p];
            avgTAT += tat[p];
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << i << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avgWT/n;
    cout << "\nAverage Turnaround Time: " << avgTAT/n;

    return 0;
}