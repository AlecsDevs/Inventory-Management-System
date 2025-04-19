#include <iostream>
#include <fstream>
#include <string>
#include <sstream>	// sstream the convert to string to intgers
#include <windows.h> //Sleep 
#include <conio.h>  // For _getch() on Windows to press any key

using namespace std;
void display();
void Option();
void loading();
void add_item();
void  edit_item();
void  search_item();
void Delete_item();
void Buy_item();
void recept (string,int,int,int,int);

int main ()
{
	 loading();
	 display();
	return 0;
}
void display(){
cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			_______ _______ _______ _______ _     _ _______ _______ ______       __   __ _______ __   __ _______ __    _ " <<endl;
cout<<"			|       |       |       |       | | _ | |       |   _   |    _ |    |  | |  |   _   |  | |  |       |  |  | |"<<endl;
cout<<"			|    ___|   _   |   _   |_     _| || || |    ___|  |_|  |   | ||    |  |_|  |  |_|  |  |_|  |    ___|   |_| |"<<endl;
cout<<"			|   |___|  | |  |  | |  | |   | |       |   |___|       |   |_||_   |       |       |       |   |___|       |"<<endl;
cout<<"			|    ___|  |_|  |  |_|  | |   | |       |    ___|       |    __  |  |       |       |       |    ___|  _    |"<<endl;
cout<<"			|   |   |       |       | |   | |   _   |   |___|   _   |   |  | |  |   _   |   _   ||     ||   |___| | |   |"<<endl;
cout<<"			|___|   |_______|_______| |___| |__| |__|_______|__| |__|___|  |_|  |__| |__|__| |__| |___| |_______|_|  |__|"<<endl;

                                                                             
                                                                             
                                                                                                   
                                                                                            
	cout << endl
         << endl;
    cout << "				+-------------------------------------------+" << endl;
    cout << "				                                           " << endl;
    cout << "				   [1] Add item                         	" << endl;
    cout << "				   [2] Edit Item                         	" << endl;
    cout << "				   [3] Search Item                      	" << endl;
    cout << "				   [4] Delete Item                       	" << endl;
    cout << "				   [5] Buy Item                       " << endl;
    cout << "				   [6] Exit                            	" << endl;
    cout << "				                                           " << endl;
    cout << "				+-------------------------------------------+" << endl;
    cout << endl
         << endl;
    Option();
}
void Option(){
	int option;
    cout << "\n\n\n\t\t\tChoose your option: ";
    cin >> option;

  switch (option) {
    case 1:
        add_item(); 
       break;
    case 2:
        edit_item();
        break;
    case 3:
       search_item();
        break;
    case 4:
	 Delete_item();
        break;
    case 5:
	Buy_item();
        break;
    case 6:
    	system("cls");
    	cout<<"Thank you For Comming";
    	break;
    default:
        cout << "error\n";
        break;
	}
}
void loading(){
	

	system("cls");
	cout<<"\n\n\n\n\n\n                     Loading ";

	for (int i =0;i<=40;i++)
	{
		
		Sleep(20);
		cout<<"_";
	
	}
	system("cls");
}
void add_item() {
	loading();
	
	cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			 _______  ______   ______     ___   _______  _______  __   __ "<<endl;
cout<<"			|   _   ||      | |      |   |   | |       ||       ||  |_|  | "<<endl;
cout<<"			|  |_|  ||  _    ||  _    |  |   | |_     _||    ___||       |"<<endl;
cout<<"			|       || | |   || | |   |  |   |   |   |  |   |___ |       |"<<endl;
cout<<"			|       || |_|   || |_|   |  |   |   |   |  |    ___||       |"<<endl;
cout<<"			|   _   ||       ||       |  |   |   |   |  |   |___ | ||_|| |"<<endl;
cout<<"			|__| |__||______| |______|   |___|   |___|  |_______||_|   |_|"<<endl;

    string ID,Product_name;
    int quantity;
    int price;
   
    cout<<"\n\n\n\t\t\t Create ID: ";
    cin>>ID;
  	
  	ifstream file("inventory.txt");
  	string line;
  	bool found = false;
  	//check line if same id 
  	while (getline(file,line))
  	{
  		size_t pos = line.find(",");
        string itemID = line.substr(0, pos);
        if (itemID == ID)
        {
        	found = true;
        	break;
		}
			
	}
	file.close();
   if (found)
   {
   		cout << "\n\n\n\t\t\tItem with the same ID already exists.\n";
   		cout << "\n\n\nPress any key to continue..." << endl;
   	_getch();
   	loading();
   	display();
   }
   else{
   	cout<<"\n\n\n\t\t\t Product Name: ";
   	cin>>Product_name;
   	cout<<"\n\n\n\t\t\t Enter Quantity: ";
   	cin>>quantity;
   	cout<<"\n\n\n\t\t\t Enter Price: ";
   	cin>>price;
   	
   	ofstream file("inventory.txt", ios::app);
   	file <<ID<<","<<Product_name<<","<<price<<","<<quantity<<endl;
   	file.close();
   	cout << "\n\n\nPress any key to continue..." << endl;
   	_getch();
   	loading();
   	display();
   }
}
void edit_item(){
	loading();
	cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			 _______  ______   ___   _______    ___   _______  _______  __   __ "<<endl;
cout<<"			|       ||      | |   | |       |  |   | |       ||       ||  |_|  | "<<endl;
cout<<"			|    ___||  _    ||   | |_     _|  |   | |_     _||    ___||       |"<<endl;
cout<<"			|   |___ | | |   ||   |   |   |    |   |   |   |  |   |___ |       |"<<endl;
cout<<"			|    ___|| |_|   ||   |   |   |    |   |   |   |  |    ___||       |"<<endl;
cout<<"			|   |___ |       ||   |   |   |    |   |   |   |  |   |___ | ||_|| |"<<endl;
cout<<"			|_______||______| |___|   |___|    |___|   |___|  |_______||_|   |_|"<<endl;
	string ID;
	string NewID,Newbrand;
    int newquantity;
	int newprice;
    cout << "\n\n\n\t\t\t Enter item name to edit: ";
    cin>>ID;

    ifstream inputFile("inventory.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;
    //check line if same id 
    while (getline(inputFile, line)) {
        size_t pos = line.find(",");
        string name = line.substr(0, pos);
        if (name == ID) {
        	//create a new
     		cout<<"\n\n\n\t\t\tCurrent Item: "<<line<<endl;
    		
            cout<<"\n\n\n\t\t\t Create  New ID: ";
   	 		cin>>NewID;
   	 		
            cout<<"\n\n\n\t\t\t Product New Name: ";
   			cin>>Newbrand;
   			cout<<"\n\n\n\t\t\t Price New : ";
   			cin>>newprice;
   			cout<<"\n\n\n\t\t\t Product New Quantity: ";
   			cin>>newquantity;
   		
           tempFile<<NewID<<","<<Newbrand<<","<<newprice<<","<<newquantity<<endl;
           // re save new
            found = true;
        } else {
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("inventory.txt"); // Delete old file
    rename("temp.txt", "inventory.txt"); // Rename temp file

    if (found){
        cout << "\n\n\n\t\t\t Item edited successfully.\n";
        cout << "\n\n\nPress any key to continue..." << endl;
    _getch();
   	loading();
   	display();
   		}
    else{
    	cout << "\n\n\n\t\t\t Item not found.\n";
    	cout << "\n\n\nPress any key to continue..." << endl;
    _getch();
   	loading();
   	display();

	} 
}
void search_item(){
	loading();
	cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			 _______  _______  _______  ______    _______  __   __    ___   _______  _______  __   __ "<<endl;
cout<<"			|       ||       ||   _   ||    _ |  |       ||  | |  |  |   | |       ||       ||  |_|  |"<<endl;
cout<<"			|  _____||    ___||  |_|  ||   | ||  |       ||  |_|  |  |   | |_     _||    ___||       |"<<endl;
cout<<"			| |_____ |   |___ |       ||   |_||_ |       ||       |  |   |   |   |  |   |___ |       |"<<endl;
cout<<"			|_____  ||    ___||       ||    __  ||      _||       |  |   |   |   |  |    ___||       |"<<endl;
cout<<"			 _____| ||   |___ |   _   ||   |  | ||     |_ |   _   |  |   |   |   |  |   |___ | ||_|| |"<<endl;
cout<<"			|_______||_______||__| |__||___|  |_||_______||__| |__|  |___|   |___|  |_______||_|   |_|"<<endl;
	int opt;
	cout<<"\n\n\n\t\t\t Edit Item\n";
	cout<<"\n\n\n\t\t\t 1.View All\n";
	cout<<"\t\t\t 2.View By ID\n";
	cout<<"\t\t\t 3.View By Brand\n";
	 cout << "\n\n\n\t\t\tChoose your option: ";
	cin>>opt;
	
	switch (opt){
		case 1:
			{
			loading();
				cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			 __   __  ___   _______  _     _    _______  ___      ___  "<<endl;   
cout<<"			|  | |  ||   | |       || | _ | |  |   _   ||   |    |   | "<<endl;   
cout<<"			|  |_|  ||   | |    ___|| || || |  |  |_|  ||   |    |   | "<<endl;   
cout<<"			|       ||   | |   |___ |       |  |       ||   |    |   | "<<endl;   
cout<<"			|       ||   | |    ___||       |  |       ||   |___ |   |___"<<endl; 
cout<<"			 |     | |   | |   |___ |   _   |  |   _   ||       ||       |"<<endl;
cout<<"			  |___|  |___| |_______||__| |__|  |__| |__||_______||_______|"<<endl;			
			ifstream file("inventory.txt");
			cin.get();
		//string stream;
        	string itemID, name;
       		int price, quantity;
            string line;
            int quantitytot = 0;
            int stockitem = 0;
            cout<<"\n\n\n\n";
       		cout<<"\t\t\tID\t\t"<<"Brand  Name\t\t"<<"Price\t\t"<<"Quantity\t\t"<<endl;
       		cout<<"\t\t\t----------------------------------------------------------------"<<endl;
        	while (getline(file, line)) {
        	stringstream ss(line);
	       	getline(ss, itemID, ',');
	        getline(ss, name, ',');
	        ss >> price;
	        ss.ignore();
	        ss >> quantity;
	        cout<<"\t\t\t"<<itemID<<"\t\t"<<name<<"\t\t\t"<<price<<"\t\t"<<quantity<<endl;
	        	quantitytot += quantity;
	        	  stockitem ++;
                }
                cout<<"\t\t\t----------------------------------------------------------------"<<endl;
              cout<<"\n\n\n";
                cout<<"\t\t\tTotal of Item:\t"<<stockitem<<"\t\t\tTotat of Quantity: "<<quantitytot<<endl;
          	
   			 
            file.close();
            cout << "\n\n\nPress any key to continue..." << endl;
          	_getch();
   			loading();
   			display();
			}
			break;
		case 2:
			{
			loading();
cout<<"			 __   __  ___   _______  _     _    _______  __   __    ___   ______ "<<endl; 
cout<<"			|  | |  ||   | |       || | _ | |  |  _    ||  | |  |  |   | |      | "<<endl;
cout<<"			|  |_|  ||   | |    ___|| || || |  | |_|   ||  |_|  |  |   | |  _    |"<<endl;
cout<<"			|       ||   | |   |___ |       |  |       ||       |  |   | | | |   |"<<endl;
cout<<"			|       ||   | |    ___||       |  |  _   | |_     _|  |   | | |_|   |" <<endl;
cout<<"			 |     | |   | |   |___ |   _   |  | |_|   |  |   |    |   | |       |"<<endl;
cout<<"			  |___|  |___| |_______||__| |__|  |_______|  |___|    |___| |______| "<<endl;			
			string id;
            cout << "\n\n\n\t\t\tEnter item ID to search: ";
            cin >> id;
            ifstream file("inventory.txt");
             bool found = false;
                string line;
                cout<<"\t\t\tID\t\t"<<"Brand  Name\t\t"<<"Price\t\t"<<"Quantity\t\t"<<endl;
            while (getline(file, line)) {
            stringstream ss(line);
      		string itemID, name;
        	int price, quantity;
        	getline(ss, itemID, ',');
        	getline(ss, name, ',');
       		 ss >> price;
        	ss.ignore();
        	ss >> quantity;
                	if (id == itemID ){
                		found = true;
                		cout<<"\t\t\t"<<itemID<<"\t\t"<<name<<"\t\t\t"<<price<<"\t\t"<<quantity<<endl;
					}
                }
                 file.close();
                if (!found){
                	 cout << "Item with ID " << id << " not found.\n";
                	 cout << "\n\n\nPress any key to continue..." << endl;
                	_getch();
   					loading();
   					display();
				}else{
					cout << "\n\n\nPress any key to continue..." << endl;
					_getch();
   					loading();
   					display();
				}
                   
            }
            break;
        case 3:
        	{
        	loading();
        		cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"			 __   __  ___   _______  _     _    _______  __   __    _______  ______    _______  __    _  ______ "<<endl;
cout<<"			|  | |  ||   | |       || | _ | |  |  _    ||  | |  |  |  _    ||    _ |  |   _   ||  |  | ||      | "<<endl;
cout<<"			|  |_|  ||   | |    ___|| || || |  | |_|   ||  |_|  |  | |_|   ||   | ||  |  |_|  ||   |_| ||  _    |"<<endl;
cout<<"			|       ||   | |   |___ |       |  |       ||       |  |       ||   |_||_ |       ||       || | |   |"<<endl;
cout<<"			|       ||   | |    ___||       |  |  _   | |_     _|  |  _   | |    __  ||       ||  _    || |_|   |"<<endl;
cout<<"			 |     | |   | |   |___ |   _   |  | |_|   |  |   |    | |_|   ||   |  | ||   _   || | |   ||       |"<<endl;
cout<<"			  |___|  |___| |_______||__| |__|  |_______|  |___|    |_______||___|  |_||__| |__||_|  |__||______| "<<endl;
        	string brand;
            cout << "\n\n\n\t\t\tEnter item Brand to search: ";
            cin >> brand;
            ifstream file("inventory.txt");
             bool found = false;
                string line;
                cout<<"\t\t\tID\t\t"<<"Brand  Name\t\t"<<"Price\t\t"<<"Quantity\t\t"<<endl;
            while (getline(file, line)) {
            stringstream ss(line);
      		string itemID, name;
        	int price, quantity;
        	getline(ss, itemID, ',');
        	getline(ss, name, ',');
       		 ss >> price;
        	ss.ignore();
        	ss >> quantity;
                	if (brand == name ){
                		found = true;
                		cout<<"\t\t\t"<<itemID<<"\t\t"<<name<<"\t\t\t"<<price<<"\t\t"<<quantity<<endl;
					}
                }
                 file.close();
                if (!found){
                	 cout << "Item with brand " << brand << " not found.\n";
                	 cout << "\n\n\nPress any key to continue..." << endl;
                	_getch();
   					loading();
   					display();
				}else{
					cout << "\n\n\nPress any key to continue..." << endl;
					_getch();
   					loading();
   					display();
				}
			}
		break;
           default:
            cout << "\t\t\t Invalid option!\n";
            cout << "\n\n\nPress any key to continue..." << endl;
            	_getch();
   				loading();
   				display();
		
	}
	
}
void  Delete_item(){
	loading();
	string ID;
	cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"		   	 ______   _______  ___      _______  _______  _______    ___   _______  _______  __   __ " <<endl;
cout<<"			|      | |       ||   |    |       ||       ||       |  |   | |       ||       ||  |_|  |"<<endl;
cout<<"			|  _    ||    ___||   |    |    ___||_     _||    ___|  |   | |_     _||    ___||       |"<<endl;
cout<<"			| | |   ||   |___ |   |    |   |___   |   |  |   |___   |   |   |   |  |   |___ |       |"<<endl;
cout<<"			| |_|   ||    ___||   |___ |    ___|  |   |  |    ___|  |   |   |   |  |    ___||       |"<<endl;
cout<<"			|       ||   |___ |       ||   |___   |   |  |   |___   |   |   |   |  |   |___ | ||_|| |"<<endl;
cout<<"			|______| |_______||_______||_______|  |___|  |_______|  |___|   |___|  |_______||_|   |_|"<<endl;
    cout << "\n\n\n\t\t\t Enter ID to delete: ";
    cin>>ID;
	string line;
	 ifstream inputFile("inventory.txt");
    ofstream tempFile("temp.txt");
    bool found = false;
    while (getline(inputFile, line)) {
        
        size_t pos = line.find(",");
        string name = line.substr(0, pos);
        if (name != ID) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("inventory.txt"); // Delete old file
    rename("temp.txt", "inventory.txt"); // Rename temp file

    if (found)
    {
    	 cout << "\n\n\n\t\t\t Item deleted successfully.\n";
    	 cout << "\n\n\nPress any key to continue..." << endl;
    _getch();
   	loading();
   	display();
	}
       
    else{
    	cout << "\n\n\n\t\t\t Item not found.\n";
    	cout << "\n\n\nPress any key to continue..." << endl;
   _getch();
   	loading();
   	display();
	}
        
}
void Buy_item(){
	loading();
    cout << "\n\n\n\n\n\n\n\n\n";
    string ID;
    cout << "			 _______  __   __  __   __    ___   _______  _______  __   __ " << endl;
    cout << "			|  _    ||  | |  ||  | |  |  |   | |       ||       ||  |_|  |" << endl;
    cout << "			| |_|   ||  | |  ||  |_|  |  |   | |_     _||    ___||       |" << endl;
    cout << "			|       ||  |_|  ||       |  |   |   |   |  |   |___ |       |" << endl;
    cout << "			|  _   | |       ||_     _|  |   |   |   |  |    ___||       |" << endl;
    cout << "			| |_|   ||       |  |   |    |   |   |   |  |   |___ | ||_|| |" << endl;
    cout << "			|_______||_______|  |___|    |___|   |___|  |_______||_|   |_|" << endl;
    
    cout << "\n\n\n\t\t\tEnter the ID of the item you want to buy: ";
    cin >> ID;

    ifstream file("inventory.txt");
    ofstream tempFile("temp.txt", ios::app);
    //variables
	string itemID, name;
    int price, quantity;
    
    bool found = false;
    string line;
    cout<<"\t\t\tID\t\t"<<"Brand  Name\t\t"<<"Price\t\t"<<"Quantity\t\t"<<endl;
    while (getline(file, line)) {
        stringstream ss(line);
        
		
        getline(ss, itemID, ',');
        getline(ss, name, ',');
        ss >> price;
        ss.ignore();
        ss >> quantity;
		if (itemID == ID){
  	  found = true;
  	  cout<<"\t\t\t"<<itemID<<"\t\t"<<name<<"\t\t\t"<<price<<"\t\t"<<quantity<<endl;
	    int buyQuantity;
	    cout << "\n\n\n\t\tEnter the quantity to buy: ";
	    cin >> buyQuantity;
	    // Calculate total price
	    double total = buyQuantity * price;
	    if (buyQuantity <= quantity) {
	        double money;
	       
	        cout << "\n\n\n\t\tTotal: "<<total;
	        cout << "\n\n\n\t\tEnter the amount of money you have: ";
	        cin >> money;
	        if (money >= total) {
	            // If the user has enough money
	            // Update inventory
	            tempFile << itemID << "," << name << "," << price << "," << (quantity - buyQuantity) << endl;
	            cout << "\n\n\n\t\tItem purchased successfully.\n";
	            cout << "\n\n\nPress any key to continue..." << endl;
	            _getch();
	           	loading();
	           recept (name,buyQuantity,total, money,price);
				break;   
	        } else {
	        	cout << "\n\n\nPress any key to continue..." << endl;
	        	_getch();
	           cout << "\n\n\n\t\tInsufficient funds.\n";
	        }
	    } else {
	    	cout << "\n\n\nPress any key to continue..." << endl;
	    	_getch();
	        cout << "\n\n\n\t\tInvalid quantity.\n";
	    }
	}else {
	    tempFile << line << endl;}  
    }

    file.close();
    tempFile.close();

    remove("inventory.txt"); // Delete old file
    rename("temp.txt", "inventory.txt"); // Rename temp file

    if (!found) {
        cout << "\n\n\n\t\tItem not found.\n";
        cout << "\n\n\nPress any key to continue..." << endl;
           _getch();
       
    }
    loading();
    display();	
}
void recept (string _name,int _quan,int total,int money,int _price)
{
	ofstream receiptFile("receipt.txt");
	 
	receiptFile<<"\n\n";
	
	receiptFile <<"                            	                Trans No.  12345678"<<endl<<endl;
	receiptFile <<"----------------------------------------------------------------------" << endl;
	receiptFile<<"Item\t\t"<<"Qty \t\t"<<"Price\t\t"<<"Total\t\t"<<endl;
	receiptFile << "				                            " << endl;
	receiptFile <<"----------------------------------------------------------------------" << endl;
    receiptFile << "				                            " << endl;
    receiptFile<<_name<<"\t\t"<<_quan<<"\t\t"<<_price<<"\t\t"<<total<<endl;
    receiptFile << "				                            " << endl;
    receiptFile <<"-----------------------------------------------------------------------" <<endl;
    receiptFile <<"1 ITEM(S)" << endl<<endl<<endl;
	receiptFile <<"                                          Total:   "<<total<<endl<<endl;
	receiptFile <<"                                          Cash:    "<<money<<endl<<endl;
	receiptFile <<"                                          Change:  "<<money - total<<endl<<endl;
  
    receiptFile << "\n\t\tThank you for your purchase to Footware Haven!\n";
          receiptFile.close();
          system("receipt.txt");   
}


