#include <iostream>
#include <fstream>
#include<windows.h>
#include <sstream>
#include <string>
using namespace std;
void writeFile()
{
	// Open the file in append mode
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
       // Write comma-separated data to the file
    ifstream file2("users.txt");
    string line;

        // Close the file
        file.close();

    } else {
        cout << "Unable to open file." << endl;
    }
}
int main()	
	{string trans;
	int choice;
	double amount;
	 {
    string accounts[10][4];
	 // Open the file for reading
    ifstream file2("users.txt");
    string line;
    ifstream trans("transaction.txt");
    // Read the file line by line
    int accountItr = 0;
    while (getline(file2, line)) {
        stringstream ss(line);
        string value;

        int itr = 0;
        while (getline(ss, value, ',')) {
            accounts[accountItr][itr] = value;
            itr++;
         }
         accountItr++;
    }
    file2.close();
    
 	/*for(int i = 0; i < 10; i++)
    {
    	cout << accounts[i][1] << " " << accounts[i][2] << endl;
	}*/
	
    string account_no, pin;
    int tries = 0;
    bool found = false;
    int current_user = -1;
    while(tries < 3)
    {	
    	{
    		system("color 2");
	cout<<"LOADING PLEASE WAIT...";
	cout<<"\n\n\n\t\t\tLoading";
	char x=219;
	for(int i=0; i<35; i++)
	{
		cout<<x;
		if(i<10)
		Sleep (300);
		if(i<=10 && i<20);
		Sleep(150);
		if(i<10)
		Sleep(25);
    }
	system ("cls");
	cout<<"\t\t\t==============================================================="<<endl;
	cout<<"\t\t\t=********************Welcome to ATM MACHINE*******************=\n";
	cout<<"\t\t\t==============================================================="<<endl;
		}
        cout << "Please Enter Your Acoount No:" << endl;
        cin >> account_no;
        cout << "Please Enter Your PinCode:" << endl;
        cin >> pin;
        cout << account_no << " " << pin;
        cout<<"\nChecking user...\n";
        
        for(int i = 0; i < 10; i++)
        {
        	if(account_no == accounts[i][1])
        	{
        		if(pin == accounts[i][2])
        		{
	        		cout << "user found :)\n";
	        		found = true;
	        		current_user = i;
	        		break;	
				}
			}
		}
		
        tries++;
        if(found)
        {
        	break;
		}
		cout << "\nuser not found : Please try again with correct Information !\n";
    }
    
    cout << "\n Current User : " << accounts[current_user][0] << " = Account No : " <<  accounts[current_user][1] ;   
    stringstream ss; 
   	ss << accounts[current_user][3];
   	int balance;
   	ss >> balance;
   		cout<<"\n\n\n";
		cout << "\t\t ******************MENU***************" <<endl;
        cout << "\t\t *                                   *" <<endl;
        cout << "\t\t *      1. Check balance             *" << endl;
        cout << "\t\t *      2. Deposit money             *" << endl;
        cout << "\t\t *      3. Withdraw money            *" << endl;
        cout << "\t\t *      4. Transfer money            *" << endl;
        cout << "\t\t *      5. Transtations              *" << endl;
        cout << "\t\t *      6. Exit                      *" << endl;
        cout << "\t\t *************************************" << endl;
   
        cout << "\t\t Enter your choice: ";
        {
		cin >> choice;
        switch(choice) {
            case 1:
                cout<<"Inquiry Balance = ";
                cout<<balance<<"$";
                break;
            case 2:
                cout << "\t Enter Amount $ to deposit: ";
                cin>> amount;
                cout<<"Your new Balance is="<<balance+amount<<"$"<<endl;
                break;
            case 3:
                cout << "\t Enter amount $ to withdraw : ";
                cin >> amount;
                if(amount < balance)
                cout<<"Your remaining balance is = "<<balance-amount<<"$"<<endl;
                else
                cout<<"\t Insufficient Balance !";
                break;
            case 4:
                cout << "\t Enter amount $ to transfer: ";
                cin >> amount;
                if(amount < balance)
                cout<<"Now current balance  = "<<balance-amount<<"$"<<endl;
                else
                cout<<"\t Insufficient Balance !";
                break;
            case 5:	
				cout<<"last 10 transtations are = "<<endl;
                {
                	string trans;

					ifstream MyReadFile("transaction.txt");
					while (getline (MyReadFile, trans)) {
 					 cout << trans<<endl;
                    }
                MyReadFile.close();
				}
                break;
            case 6:
                return 0;

            default:
                cout << "\t Invalid choice" << endl;
                break;
                }
    return 0;
			}
		}
}
