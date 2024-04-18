#include<iostream>

using namespace std;

//Initailze all global arrays
int productID[101];
string productBrand[101];
string productName[101];
double productWholesalePrice[101];
double productPrice[101];
int productCount[101];
int menuChoice;

//Display the menu options
void displayMenu() {
    cout << "*** Menu ***" << endl;
    cout << "1. Add a new product" << endl;
    cout << "2. Update product wholesale based in ID" << endl;
    cout << "3. Update product sale price based on ID" << endl;
    cout << "4. Update product count based on ID" << endl;
    cout << "5. Calculate total profit" << endl;
    cout << "6. Check low in stock (<10)" << endl;
    cout << "7. Remove a product by ID" << endl;
    cout << "8. Display all the products" << endl;
    cout << "9. Quit!" << endl;
}

//Add new project to the inventory
void newProduct() {
    int idChoice = 0;
    
    cout << "Please enter ID number 1-100: "; 
    cin >> idChoice; //Get the ID number from the user
    while(idChoice <= 0 || idChoice > 100 || productID[idChoice] != 0) { // check if the ID number is valid
        cout << "Invalid ID number" << endl;
        cout << "Please enter ID number 1-100: ";
        cin >> idChoice;
    }
    productID[idChoice] = idChoice;
    cout << "Enter the brand name: ";
    cin >> productBrand[idChoice]; //Get the brand name from the user
    cout << "Enter the product name: ";
    cin >> productName[idChoice]; //Get the product name from the user
    cout << "Enter the wholesale price: $";
    cin >> productWholesalePrice[idChoice]; //Get the wholesale price from the user
    cout << "Enter the sale price: $";
    cin >> productPrice[idChoice]; //Get the sale price from the user
    cout << "Enter the count of the product: ";
    cin >> productCount[idChoice]; //Get the count of the product from the user

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Update the wholesale price of a product
void updateWholesale() {
    int idChoice = 0;
    double newWholesalePrice = 0;

    cout << "Please enter an ID: ";
    cin >> idChoice; //Get the ID number from the user
    if(productID[idChoice] == 0){ //Check if the ID number is valid
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    //Display the product information
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current wholesale price is: $" << productWholesalePrice[idChoice] << endl;
    cout << "Please enter a new price: $";
    cin >> newWholesalePrice; //Get the new wholesale price from the user
    productWholesalePrice[idChoice] = newWholesalePrice;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Update the sale price of a product
void updateSale() {
    int idChoice = 0;
    double newSalePrice = 0;

    cout << "Please enter ID: ";
    cin >> idChoice; //Get the ID number from the user
    if(productID[idChoice] == 0){ //Check if the ID number is valid
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    //Display the product information
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current sale price is: $" << productPrice[idChoice] << endl;
    cout << "Please enter a new price: $";
    cin >> newSalePrice; //Get the new sale price from the user
    productPrice[idChoice] = newSalePrice;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Update the count of a product
void updateCount() {
    int idChoice = 0;
    int newCount = 0;

    cout << "Please enter an ID: ";
    cin >> idChoice; //Get the ID number from the user
    if(productID[idChoice] == 0){ //Check if the ID number is valid
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice; //Get the ID number from the user
        } while(productID[idChoice] == 0);
    }
    //Display the product information
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current count is: " << productCount[idChoice] << endl;
    cout << "Please enter a new count number: ";
    cin >> newCount; //Get the new count from the user
    productCount[idChoice] = newCount;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Calculate the total profit of all products in stock
void calculateTotal() {
    double total = 0;

    //Calculate the total profit
    for (int i = 0; i < 101; i++) {
        total += (productPrice[i] - productWholesalePrice[i]) * productCount[i];
    }

    //Display the total profit
    cout << "The total profit is: $" << total << endl;

    cout << "Press enter to EXIT" << endl;
    cin.ignore(); //Wait for user to press enter
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Check for products that are low in stock (<10)
void checkLow() {
    cout << "The following products are low in stock:" << endl;
    cout << "ID\tBrand\t\tProduct\t\tCount" << endl;

    //Display products that are low in stock
    for (int i = 0; i < 101; i++) {
        if (productCount[i] < 10 && productID[i] != 0) {
            cout << productID[i] << "\t" << productBrand[i] << "\t\t" << productName[i] << "\t\t" << productCount[i] << endl;
        }
    }

    cout << "Press enter to EXIT" << endl;
    cin.ignore(); //Wait for user to press enter
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Remove a product from the inventory
void removeProduct() {
    int idChoice = 0;

    cout << "Please enter ID: ";
    cin >> idChoice; //Get the ID number from the user
    if(productID[idChoice] == 0){ //Check if the ID number is valid
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    //Empty the product information in all arrays
    productID[idChoice] = 0;
    productBrand[idChoice] = "";
    productName[idChoice] = "";
    productWholesalePrice[idChoice] = 0;
    productPrice[idChoice] = 0;
    productCount[idChoice] = 0;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Display all products in the inventory
void displayProducts() {
    cout << "ID\tBrand\t\tProduct\t\tCount" << endl;

    //Display all products in stock
    for (int i = 0; i < 101; i++) {
        if(productID[i] != 0) {
            cout << productID[i] << "\t" << productBrand[i] << "\t\t" << productName[i] << "\t\t" << productCount[i] << endl;
        }
    }

    cout << "Press enter to EXIT" << endl;
    cin.ignore(); //Wait for user to press enter
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #elif __linux__
    system("clear") ;
    #endif
}

//Main function
int main() {
    do {
        displayMenu(); //Show the menu options

        cout << "Enter choice: ";
        cin >> menuChoice; //Get the menu choice from the user

        //Clear the terminal
        #ifdef _WIN32
        system("cls") ;
        #elif __APPLE__
        system("clear") ;
        #elif __linux__
        system("clear") ;
        #endif

        if(menuChoice > 9) { //Check if the menu choice is valid
            do {
                displayMenu();
                cout << "Invalid choice!" << endl;
                cout << "Enter choice: ";
                cin >> menuChoice;

                //Clear the terminal
                #ifdef _WIN32
                system("cls") ;
                #elif __APPLE__
                system("clear") ;
                #elif __linux__
                system("clear") ;
                #endif
            } while(menuChoice > 9);
        }

        //Switch case for menu options
        switch (menuChoice) {
            case 1:
                newProduct();
                break;
            case 2:
                updateWholesale();
                break;
            case 3:
                updateSale();
                break;
            case 4:
                updateCount();
                break;
            case 5:
                calculateTotal();
                break;
            case 6:
                checkLow();
                break;
            case 7:
                removeProduct();
                break;
            case 8:
                displayProducts();
                break;
            case 9:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (menuChoice > 0 && menuChoice < 9);

    return 0;
}