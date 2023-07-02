#include<iostream>
#include<fstream>
using namespace std;

class Shopping{
    private:
        int pcode;
        float price,dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void modify();
        void rem();
        void list();
        void receipt();
};

//main menu function
void Shopping :: menu(){
    m:
    int choice;
    string email,password;
    cout<<"\t\t\t\t\t\t\t__________________________\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                          \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t  SUPERMARKET MAIN MENU    \t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t__________________________\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t    1) Administrator          \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t    2) Buyer          \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t    3) Exit         \t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t                           \t\t\t\t\t\t"<<endl;
    cout<<"Please select : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    {
        /* code */
        cout<<"\t\t\t\t Please Login\t\t\t\n";
        cout<<"Enter the email id : ";
        cin>>email;
        cout<<"Enter password : ";
        cin>>password;

        if(email=="admin@gmail.com" && password=="admin"){
            administrator();
        }
        else{
            cout<<"Invalid email/password"<<endl;
        }
        break;
    }
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"Invalid choice"<<endl;
    }
    }
    goto m;
}

//admisntrator function
void Shopping :: administrator(){
     m:
        int choice;
        cout<<"\t\t\t\tAdministrator Menu\t\t\t\t"<<endl;
        cout<<"\t\t___1)Add a product___"<<endl;
        cout<<"\t\t___2)Modify a product___"<<endl;
        cout<<"\t\t___3)Remove a product___"<<endl;
        cout<<"\t\t___4)Back to main menu___"<<endl;
        cout<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            modify();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
     goto m;
}

//Buyer function
void Shopping :: buyer(){
    m:
        int choice;
        cout<<"\t\t\t\tBuyer Menu\t\t\t\t"<<endl<<endl;
        cout<<"\t\t___1)Buy a product___"<<endl;
        cout<<endl;
        cout<<"\t\t___2)Back to main menu___"<<endl;
        cout<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
    goto m;
}

void Shopping :: add(){
    m:
    fstream data;  //creating an object of fstream
    int c,token=0;
    float p,d;
    string n;
    cout<<"\n\n\t\t\t\t\tAdd a new product"<<endl<<endl;
    cout<<"Enter the product code of the product to be added : ";
    cin>>pcode;
    cout<<"Enter the name of the product to be added : ";
    cin>>pname;
    // getline(cin,pname);
    cout<<"Enter the price of the product to be added : ";
    cin>>price;
    cout<<"Enter the discount on the product to be added : ";
    cin>>dis;
    //creating a text file and opening it in reading mode
    data.open("dataBase.txt",ios::in);

    //if the file doesnot exit
    //open it in appende mode or writing mode
    if(!data){
        data.open("dataBase.txt",ios::app|ios::out);
        //writing inside the file
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else{
        //if the file exits then we will read from the file
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;    //for the iteratiorn of the file we are reading it
        }
        data.close();
    
        //if the product already exits beforehand
        if(token==1){
            cout<<"Product already exists ! Try again\n";
            goto m;
        }
        else{
            data.open("dataBase.txt",ios::app|ios::out);
            //writing inside the file
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            data.close();
        }
    }
    cout<<"\t\t\t\tRecord Inserted"<<endl;
}


//modify function
void Shopping :: modify(){
    fstream data,data1;  //creating two object of fstream
    int c,token=0,pkey;
    float p,d;
    string n;
    cout<<"\n\n\t\t\t\t\tModify the record"<<endl<<endl;
    cout<<"Enter the product code of the product to be added : ";
    cin>>pkey;
    //creating a text file and opening it in reading mode
    data.open("dataBase.txt",ios::in);

    //if the file doesnot exit
    //open it in appende mode or writing mode
    if(!data){
       cout<<endl<<"File doesnot exxist!"<<endl;
    }
    else{
        //if the file exits then we will read from the file
        data1.open("dataBase1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\t\t\tEnter the New Code of the Product : ";
                cin>>c;
                cout<<"\t\tEnter the New Name of the Product : ";
                cin>>n;
                cout<<"\t\t\tEnter the New Price of the Product : ";
                cin>>p;
                cout<<"\t\t\tEnter the New Discount on the Product : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<endl<<"\t\t\tRecord Edited"<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            //for incrementing the while loop
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        //now we have to rename the dataBase1 back to the original database
        remove("dataBase.txt");
        rename("dataBase1.txt","dataBase.txt");
        if(token==0){
            cout<<endl<<"Record not found sorry!"<<endl;
        }
    }
}

//remove function
void Shopping:: rem(){
    fstream data,data1;
    int token=0,pkey;
    cout<<endl<<endl<<"\t\t\t\tDelete Product"<<endl<<endl;
    cout<<endl<<"\t\t\tEnter the product code : ";
    cin>>pkey;
    //creating a text file and opening it in reading mode
    data.open("dataBase.txt",ios::in);
    if(!data){
        cout<<"File doesnot exist"<<endl;
    }
    else{
        //if the file exits then we will read from the file
        data1.open("dataBase1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\t\tProduct deleted succcessfully!"<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            //for incrementing the while loop
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("dataBase.txt");
        rename("dataBase1.txt","datBase.txt");
        if(token==0){
            cout<<"Record not found!"<<endl;
        }
    }
}

//list function
void Shopping :: list(){
    fstream data;
    //open the file in reading mode
    data.open("dataBase.txt",ios::in);
    cout<<endl<<"\t\t\t\t\t____________________\t\t\t\t"<<endl;
    cout<<" "<<"Product No."<<" "<<"Product Name"<<" "<<"Product Price"<<" "<<"Product Discount"<<endl;
    cout<<endl<<"\t\t\t\t\t____________________\t\t\t\t"<<endl;
    //reading the data
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<endl;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

//receipt function
void Shopping::receipt() {
    fstream data;
    // creation array of codes and array of quantity
    int arrc[100], arrq[100];
    int c = 0;
    float amount = 0, dis = 0, total = 0;
    char choice;
    cout << endl << "\t\t\tReceipt" << endl;
    data.open("dataBase.txt", ios::in);
    if (!data) {
        cout << "Empty Database" << endl;
    }
    else {
        // close the data
        data.close();
        // call the list function
        list();
        cout << endl << endl << "\t\t\t\t_______________________________________________\t\t\t\t" << endl;
        cout << "\t\t\t\t                                  \t\t\t\t" << endl;
        cout << "\t\t\t\t    PLACE THE ORDER                              \t\t\t\t" << endl;
        cout << "\t\t\t\t                                  \t\t\t\t" << endl;
        cout << endl << endl << "\t\t\t\t_______________________________________________\t\t\t\t" << endl;
        do {
            m:
            cout << "Enter product code : ";
            cin >> arrc[c];
            cout << "Enter product quantity : ";
            cin >> arrq[c];
            // to check if the same product is entered again
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << endl << "\t\tDuplicate product code entered, Please try again!" << endl;
                    goto m;
                }
            }
            c++;
            cout << "Do you want to buy another product ? Y/N : ";
            cin >> choice;
        } while (choice == 'y');

        cout << endl << endl;
        cout << "\t\t\t\t______________RECEIPT______________\t\t\n";
        cout << "\nProduct Code \tProduct Name\tProduct Quantity\tProduct Price\tProduct after Discount\n";

        // iterate through the file
        for (int i = 0; i < c; i++) {
            data.open("dataBase.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                // if the product code matches the product code entered by the buyer
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    float discountedAmount = amount - (amount * dis / 100);
                    total = total + discountedAmount;
                    cout << endl << pcode << "\t\t " << pname << "\t\t " << arrq[i] << "\t\t " << amount << "\t\t " << discountedAmount << endl;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close(); // Move the data file close inside the for loop
        }
    }
    cout << "_________________________" << endl;
    cout << "\t\t\tTotal Amount : " << total << endl;
}

int main(){
    //create an object of the class Shopping
    Shopping s;
    //call the menu function first
    s.menu();
    return 0;
}