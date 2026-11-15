#include <iostream>
using namespace std;

int main() {
    int n;
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i << ": ";
        cin >> at[i] >> bt[i];

        rt[i] = bt[i];
    }

    int time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    while(completed < n) {
        int index = -1;
        int minRT = 999999;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                index = i;
            }
        }

        if(index == -1) {
            time++;
            continue;
        }

        rt[index]--;
        time++;

        if(rt[index] == 0) {
            ct[index] = time;
            completed++;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            avgWT += wt[index];
            avgTAT += tat[index];
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