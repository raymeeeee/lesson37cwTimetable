#include <set>
#include <algorithm>
#include "Train.h"

int main()
{
    set<Train> tableKharkiv;
    tableKharkiv.insert(Train("LV213", "Lviv", Time_(15, 0, 0), 10));
    tableKharkiv.insert(Train("KI219", "KIEV", Time_(9, 20, 0), 10));
    tableKharkiv.insert(Train("OD193", "Odessa", Time_(12, 0, 0), 10));
    tableKharkiv.insert(Train("DN912", "Dnipro", Time_(20, 0, 0), 10));
    set<Train>::iterator p;
    //inOrder (sortedOrder)
    p = tableKharkiv.begin();
    while (p != tableKharkiv.end()) {
        p->showLine();
        cout << endl;
        p++;
    }
    cout << "===========================" << endl;
    string userNum;
    cin >> userNum;

    auto item = find_if(tableKharkiv.begin(), tableKharkiv.end(), [userNum](const Train a) {
        return (a.getNumber() == userNum);
        });
    if (item == tableKharkiv.end()) {
        cout << "No such train" << endl;
    }
    else {
        item->show();
    }
}
