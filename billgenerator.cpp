#include <iostream>

using namespace std;
class customer
{
public:
    int x = 0, n =0, a,b;
    struct Listofitems
    {
        int item_no;
        int req_count;
    } lt[4];
    void get()
    {
        cout<<" for apple press 0\n for banana press 1\n for orange press 2\n for grapes press 3"<<endl;
        cout<<"how many types of fruits do you want :"<<endl;
        cin>>n;
        while(x<n)
        {
            cout<<"enter code of fruit and how many of it do you want"<<endl;
            cin>>a>>b;
            lt[x].item_no = a;
            lt[x].req_count = b;
            x++;
        }
    }

};
class shop
{
    char items[4][10]= {"apple","banana","orange","grapes"};
    int price[4]= {10,20,5,4};
    int stock[4]= {10,12,10,20};
public:
    void show()
    {
        int i = 0;
        while(i < 4)
        {
            cout<<"there are "<<stock[i]<<" "<<items[i]<<" each of price "<<price[i]<<endl;
            i++;
        }
    }
    void showList(customer cust)
    {
        int j;
        for(j=0; j<=cust.x; j++)
        {
            cout<<cust.lt[j].item_no<<" "<< cust.lt[j].req_count<<endl;
        }
    }
    void bill(customer cust)
    {
        int k,total=0,j;
        for(j=0; j<=cust.x; j++)
        {
            for(k=0; k<4; k++)
            {
                if(cust.lt[j].item_no==k)
                {
                    if(stock[k]!=0)
                    {
                        if(cust.lt[j].req_count<=stock[k])
                        {
                            cout<<items[k]<<"\t\t"<<cust.lt[j].req_count<<"\t\t"<<(price[k])*(cust.lt[j].req_count)<<endl;
                            total+=(price[k])*(cust.lt[j].req_count);
                        }
                        else
                        {
                            cout<<"we dont have this much "<<items[k]<<endl;

                        }
                    }
                    else
                    {
                        cout<<"we are out of stock for "<<items[k]<<endl;
                    }
                }
            }
            }
            cout<<"\n\your total amount is "<<total;
    }
};

int main()
{
    shop p;

    p.show();
    customer c;
    c.get();
    p.bill(c);
    return 0;
}
