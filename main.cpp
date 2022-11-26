#include<bits/stdc++.h>
using namespace std;

struct itemDet
{
    string nm;
    int pr, gst, amt;
    itemDet()
    {
        nm = "";
        pr = 0, gst = 0, amt = 0;
    }
};

double GST(itemDet& item)
{
    double ans = (item.pr * item.amt);
    ans = (ans * item.gst)/100.0;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<itemDet> arr(n);
    map<double, vector<string>> mp;
    double totalAmount = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = itemDet();
        cin >> arr[i].nm >> arr[i].pr >> arr[i].gst >> arr[i].amt;

        double gstAmount = GST(arr[i]);
        mp[gstAmount].push_back(arr[i].nm);

        totalAmount += (gstAmount + (1.0 * arr[i].amt * arr[i].pr));
    }

    auto it = (mp.rbegin());
    for (auto& curr : it->second)
        cout << curr <<" ";
    cout << endl;
    cout << totalAmount << endl;

    return 0;
}