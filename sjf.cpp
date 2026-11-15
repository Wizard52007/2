#include <iostream>
using namespace std;

int main() {
    int n;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    bool done[10] = {false};

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i << ": ";
        cin >> at[i] >> bt[i];
    }

    int time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    while(completed < n) {
        int index = -1;
        int minBT = 999999;

        for(int i = 0; i < n; i++) {
            if(!done[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                index = i;
            }
        }

        if(index == -1) {
            time++;
            continue;
        }

        time += bt[index];
        ct[index] = time;

        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - bt[index];

        avgWT += wt[index];
        avgTAT += tat[index];

        done[index] = true;
        completed++;
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