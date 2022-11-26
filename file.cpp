#include<bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    int price, gst, amount;
    itemDetails()
    {
        n = "";
        pr = 0, gst = 0, amt = 0;
    }
};

double GST(itemDetails& item)
{
    double ans = (item.price * item.amount);
    ans = (ans * item.gst)/100.0;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<itemDetails> arr(n);
    map<double, vector<string>> mp;
    double totalAmount = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = itemDetails();
        cin >> arr[i].name >> arr[i].price >> arr[i].gst >> arr[i].amt;

        double gstAmount = GST(arr[i]);
        mp[gstAmount].push_back(arr[i].name);

        totalAmount += (gstAmount + (1.0 * arr[i].amt * arr[i].pr));
    }

    auto it = (mp.rbegin());
    for (auto& curr : it->second)
        cout << curr <<" ";
    cout << endl;
    cout << totalAmount << endl;

    return 0;
}