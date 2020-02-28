#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main()
{
    freopen("FIFO.txt","r",stdin);
    int n;
    cin>>n;

    int pages[n];
    for(int i=0; i<n; i++)
        cin>>pages[i];

    int capacity;
    cin>>capacity;

    cout << pageFaults(pages, n, capacity)<<endl;
    return 0;
}
