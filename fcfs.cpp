#include <iostream>
using namespace std;

int main() {
    int n;
    int at[10], bt[10], ct[10], tat[10], wt[10];

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i << ": ";
        cin >> at[i] >> bt[i];
    }

    // Sort according to arrival time
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    int time = 0;
    float avgWT = 0, avgTAT = 0;

    for(int i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];

        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
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