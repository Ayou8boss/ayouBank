#include <iostream>
#include <string>
using namespace std;
struct acc{
   string CN;
   string pin;
   double balance;
};
void regis(acc &ac){
   cout<<"--- Welcome To AyouBank (ATM) ---"<<endl;
   cout<<"Enter your Card Number: ";
   cin>>ac.CN;
   cout<<"Enter your Card PIN: ";
   cin>>ac.pin;
   while(ac.pin.length()!=4){
      cout<<"Error! PIN must be 4 digits. Try again: "<<endl;
      cin>>ac.pin;
   }
   ac.balance=0;
   cout<<"Registration successful!.\n"<<endl;
}
void deposit(acc &ac){
   double amount;
   cout<<"Enter amount to deposit: ";
   cin>>amount;
   if(amount>0){
      ac.balance+=amount;
      cout<<"Deposit successful!\nNew balance: "<<ac.balance<<"$"<<endl;
   }
   else {
      cout<<"Deposit failed ! \nAmount must be positive."<<endl;
   }
}
void withdarw(acc &ac){
   double amount;
   cout<<"Enter Amount to withdraw: ";
   cin>>amount;
   if(amount>0 && amount<=ac.balance){
      ac.balance-=amount;
      cout<<"Withdraw successful!\nNew Balance: "<<ac.balance<<"$"<<endl;
   }
   else {
      cout<<"Withdraw Failed!\nBalance is insufficient or amount is invalid."<<endl;
   }
}
void Menu(){
   cout<<"--- Menu ---"<<endl;
   cout<<"1. Current Balance"<<endl;
   cout<<"2. Deposit"<<endl;
   cout<<"3. Withdraw"<<endl;
   cout<<"\t\t4. Exit"<<endl;
   cout<<"-------------"<<endl;
}
 int main (){
    system("cls");
      acc myAccount;
      int ch=0;
      regis(myAccount);
      while (ch!=4){
         Menu();
         cout<<"Enter your choice: ";
         cin>>ch;
         switch(ch){
            case 1:
               cout<<"Current Balance: "<<myAccount.balance<<"$"<<endl;
               break;
            case 2:
               deposit(myAccount);
               break;
            case 3:
               withdarw(myAccount);
               break;
            case 4:
               cout<<"Thank you for using AyouBank ATM. Goodbye!"<<endl;
               break;
            default:
               cout<<"Invalid choice! Please try again."<<endl;
         }
      }
   



    return 0;
 }