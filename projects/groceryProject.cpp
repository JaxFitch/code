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
    cin >> idChoice;
    while(idChoice <= 0 || idChoice > 100 || productID[idChoice] != 0) {
        cout << "Invalid ID number" << endl;
        cout << "Please enter ID number 1-100: ";
        cin >> idChoice;
    }
    productID[idChoice] = idChoice;
    cout << "Enter the brand name: ";
    cin >> productBrand[idChoice];
    cout << "Enter the product name: ";
    cin >> productName[idChoice];
    cout << "Enter the wholesale price: $";
    cin >> productWholesalePrice[idChoice];
    cout << "Enter the sale price: $";
    cin >> productPrice[idChoice];
    cout << "Enter the count of the product: ";
    cin >> productCount[idChoice];

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Update the wholesale price of a product
void updateWholesale() {
    int idChoice = 0;
    double newWholesalePrice = 0;

    cout << "Please enter an ID: ";
    cin >> idChoice;
    if(productID[idChoice] == 0){
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current wholesale price is: $" << productWholesalePrice[idChoice] << endl;
    cout << "Please enter a new price: $";
    cin >> newWholesalePrice;
    productWholesalePrice[idChoice] = newWholesalePrice;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Update the sale price of a product
void updateSale() {
    int idChoice = 0;
    double newSalePrice = 0;

    cout << "Please enter ID: ";
    cin >> idChoice;
    if(productID[idChoice] == 0){
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current sale price is: $" << productPrice[idChoice] << endl;
    cout << "Please enter a new price: $";
    cin >> newSalePrice;
    productPrice[idChoice] = newSalePrice;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Update the count of a product
void updateCount() {
    int idChoice = 0;
    int newCount = 0;

    cout << "Please enter an ID: ";
    cin >> idChoice;
    if(productID[idChoice] == 0){
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    cout << "The brand is " << productBrand[idChoice] << endl;
    cout << "The product is " << productName[idChoice] << endl;
    cout << "The current count is: " << productCount[idChoice] << endl;
    cout << "Please enter a new count number: ";
    cin >> newCount;
    productCount[idChoice] = newCount;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Calculate the total profit of all products in stock
void calculateTotal() {
    double total = 0;

    for (int i = 0; i < 101; i++) {
        total += (productPrice[i] - productWholesalePrice[i]) * productCount[i];
    }

    cout << "The total profit is: $" << total << endl;
    cout << "Press enter to EXIT" << endl;
    cin.ignore();
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Check for products that are low in stock (<10)
void checkLow() {
    cout << "The following products are low in stock:" << endl;
    cout << "ID\tBrand\t\tProduct\t\tCount" << endl;
    for (int i = 0; i < 101; i++) {
        if (productCount[i] < 10 && productID[i] != 0) {
            cout << productID[i] << "\t" << productBrand[i] << "\t\t" << productName[i] << "\t\t" << productCount[i] << endl;
        }
    }

    cout << "Press enter to EXIT" << endl;
    cin.ignore();
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Remove a product from the inventory
void removeProduct() {
    int idChoice = 0;

    cout << "Please enter ID: ";
    cin >> menuChoice;
    if(productID[idChoice] == 0){
        do {
            cout << "Invalid ID number" << endl;
            cout << "Please enter an ID: ";
            cin >> idChoice;
        } while(productID[idChoice] == 0);
    }
    productID[menuChoice] = 0;
    productBrand[menuChoice] = "";
    productName[menuChoice] = "";
    productWholesalePrice[menuChoice] = 0;
    productPrice[menuChoice] = 0;
    productCount[menuChoice] = 0;

    cout << "Remove success!" << endl;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Display all products in the inventory
void displayProducts() {
    cout << "ID\tBrand\t\tProduct\t\tCount" << endl;
    for (int i = 0; i < 101; i++) {
        if(productID[i] != 0) {
            cout << productID[i] << "\t" << productBrand[i] << "\t\t" << productName[i] << "\t\t" << productCount[i] << endl;
        }
    }

    cout << "Press enter to EXIT" << endl;
    cin.ignore();
    cin.get();

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif
}

//Main function
int main() {
    do {
        displayMenu();

        cout << "Enter choice: ";
        cin >> menuChoice;

        //Clear the terminal
        #ifdef _WIN32
        system("cls") ;
        #elif __APPLE__
        system("clear") ;
        #endif

        if(menuChoice > 9) {
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