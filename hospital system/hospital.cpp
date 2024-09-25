#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct my_queue {
    deque<pair<string, bool > > q ;
    bool statis ;
};
my_queue patient [20] ;
void add_patient () {
    cout << "enter your specialization , name , statis\n" ;
    ll specialization ; bool statis  ; string name ;
    cin >> specialization >> name >> statis ;
    if (specialization < 1 || specialization > 20) {
        cout << "Invalid specialization number. Please enter a number between 1 and 20.\n";
        return;
    }
    if(patient[specialization-1].q.size()< 5) {
        if (patient[specialization-1].q.size() < 5) {
            if (statis) {
                patient[specialization-1].q.push_front({name, statis});
            } else {
                patient[specialization-1].q.push_back({name, statis});
            }
        }
        else
            cout << "Sorry we can't add any patient for this specialization\n" ;
    }
}
void print_patient () {
    cout << "Please enter specialization \n " ;
    ll specialization ; cin >> specialization ;
    if (specialization < 1 || specialization > 20) {
        cout << "Invalid specialization number. Please enter a number between 1 and 20.\n";
        return;
    }
    if (patient[specialization-1].q.empty()) {
        cout << "No patients in this specialization.\n";
    } else {
        cout << "Patients in specialization " << specialization << ":\n";
        ll n = patient[specialization-1].q.size() ;
        for(int i=0 ; i< n ; ++i ) {
            cout << patient[specialization-1].q[i].first << " ";
            if(patient[specialization-1].q[i].second)
                cout << "Urgent\n" ;
            else
                cout << "Regular" ;
        }
    }
}
void get_next_patient() {
    cout << "Please enter specialization \n " ;
    ll specialization ; cin >> specialization ;
    if(!patient[specialization-1].q.empty()) {
        cout << "Please Mr " << patient[specialization-1].q.front().first << " come to doctor \n" ;
        patient[specialization-1].q.pop_front() ;
    }else
        cout << "No more patients take a rest \n " ;
}
void menu () {
        while (true) {
            cout << "\n1) Add new patient\n";
            cout << "2) Print all patients for a specialization\n";
            cout << "3) Get the next patient\n";
            cout << "4) Exit\n";

            ll choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    add_patient();
                break;
                case 2:
                    print_patient();
                break;
                case 3:
                    get_next_patient();
                break;
                case 4:
                    cout << "Exiting...\n";
                return;
                default:
                    cout << "Invalid choice. Please select a valid option.\n";
            }
        }

}

signed main() {
        menu() ;
    return 0;
}