#include <iostream>
using namespace std;

//declare the item as a struct
struct item
{
    int id;
    float price;
} s[50];

int total = 0;

//to add new item in the list
void addData() {
    cout << "Enter an item data " << endl;
    cout << "Enter id: ";
    cin >> s[total].id;
    cout << "Enter price: ";
    cin >> s[total].price;
    cout << "successfully added" << endl << endl;
    total++;
    //to sorting the array of structs by swapping a temp object
    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (s[i].price > s[j].price)
            {
                struct item temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
//to retrieve items from the list by its id
void retrivePrice() {
    int id;
    cout << "enter the element id:";
    cin >> id;
    cout << endl;
    int i;
    for (i = 0; i < total; ++i)
    {
        if (id == s[i].id) {
            cout << "price for this item: " << s[i].price << endl << endl;
            break;
        }
    }
    if (i == total) cout << "item not found" << endl << endl;
}

//to display items from the list within the given range
void displayItems() {
    float range;
    cout << "enter the range:";
    cin >> range;
    cout << endl;
    for (int i = 0; i < total; ++i)
    {
        if (range >= s[i].price) {
            cout << "id: " << s[i].id << " price : " << s[i].price << endl << endl;;
        }
    }

}

//to delete an item from the list by its id
void deleteItem() {
    int id;
    cout << "enter the element id:";
    cin >> id;
    cout << endl;
    int index = -1;
    for (int i = 0; i < total; ++i)
    {
        if (id == s[i].id) {
            index = i;
            cout << "item deleted" << endl << endl;
            break;
        }
    }

    if (index == -1)
        cout << "item not found" << endl << endl;
    else
    {
        for (int i = index; i < total - 1; i++) {
            s[i] = s[i + 1];
        }
    }

    total--;

}

//to display all items in the list
void displayAll() {
    if (total == 0)
        cout << "No items founded..." << endl << endl;

    if (total > 0)
    {
        cout << "the items founded are:" << endl << endl;
        for (int i = 0; i < total; ++i)
        {
            cout << "id=" << s[i].id << "  ";
            cout << "price=" << s[i].price << endl << endl;
        }
    }

}

//to delete all items in the list
void deleteAll() {
    if (total == 0)
        cout << "No items founded " << endl << endl;
    else
    {
        cout << "All items deleted successfully" << endl << endl;
        total = 0;
    }

}

int main()
{
    while (true) {
        int x;
        cout << "Enter 1 for enter item id and price" << endl;
        cout << "Enter 2 for retrieve price for a specific item" << endl;
        cout << "Enter 3 for display all items in specific range of prices" << endl;
        cout << "Enter 4 for delete an item" << endl;
        cout << "Enter 5 for display all items" << endl;
        cout << "Enter 6 for delete all items" << endl;
        cout << "Enter e for exit" << endl << endl;;
        cin >> x;
        cout << endl;
        //switch case to take its choies and execute the needed function
        switch (x) {

        case 1: addData();
            break;

        case 2:
            retrivePrice();
            break;
        case 3:

            displayItems();
            break;
        case 4:
            deleteItem();
            break;

        case 5:displayAll();
            break;

        case 6:deleteAll();
            break;
            //exit if user enter e
        default:cout << "thanks for using my application\n\n";
            exit(0);


        }
    }
    return 0;
}
