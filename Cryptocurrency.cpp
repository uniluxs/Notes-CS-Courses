#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

// Struct to represent a cryptocurrency
struct Cryptocurrency {
    std::string name;
    double price;
};

// Function to generate random price changes for cryptocurrencies
double generateRandomPriceChange() {
    return ((std::rand() % 201) - 100) / 100.0; // Random value between -1.0 and 1.0
}

// Function to update the prices of all cryptocurrencies
void updateCryptocurrencyPrices(std::vector<Cryptocurrency>& cryptocurrencies) {
    for (auto& crypto : cryptocurrencies) {
        crypto.price += crypto.price * generateRandomPriceChange();
    }
}

// Function to display the player's portfolio
void displayPortfolio(const std::vector<Cryptocurrency>& cryptocurrencies, const std::vector<int>& holdings) {
    std::cout << "-------------------\n";
    std::cout << "   CRYPTO PORTFOLIO\n";
    std::cout << "-------------------\n";
    std::cout << "Cryptocurrency\t\tHoldings\t\tValue ($)\n";
    std::cout << "---------------------------------------------------\n";
    
    for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
        const Cryptocurrency& crypto = cryptocurrencies[i];
        int holding = holdings[i];
        double value = holding * crypto.price;
        
        std::cout << std::left << std::setw(16) << crypto.name;
        std::cout << std::left << std::setw(16) << holding;
        std::cout << std::fixed << std::setprecision(2) << value << std::endl;
    }
    std::cout << "---------------------------------------------------\n";
}

// Function to display the current prices of cryptocurrencies
void displayCryptocurrencyPrices(const std::vector<Cryptocurrency>& cryptocurrencies) {
    std::cout << "-------------------\n";
    std::cout << "  CRYPTO PRICES\n";
    std::cout << "-------------------\n";
    std::cout << "Cryptocurrency\t\tPrice ($)\n";
    std::cout << "--------------------------------\n";
    
    for (const Cryptocurrency& crypto : cryptocurrencies) {
        std::cout << std::left << std::setw(16) << crypto.name;
        std::cout << std::fixed << std::setprecision(2) << crypto.price << std::endl;
    }
    std::cout << "--------------------------------\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Initialize cryptocurrencies
    std::vector<Cryptocurrency> cryptocurrencies = {
        {"Bitcoin", 45000.0},
        {"Ethereum", 3000.0},
        {"Litecoin", 150.0},
        // Add more cryptocurrencies if desired
    };

    std::vector<int> holdings(cryptocurrencies.size(), 0); // Initialize holdings to zero

    double cashBalance = 10000.0; // Starting cash balance
    
    // Game loop
    bool isGameRunning = true;
    while (isGameRunning) {
        updateCryptocurrencyPrices(cryptocurrencies);
        displayCryptocurrencyPrices(cryptocurrencies);
        displayPortfolio(cryptocurrencies, holdings);

        // Display menu options
        std::cout << "\n1. Buy Cryptocurrency\n";
        std::cout << "2. Sell Cryptocurrency\n";
        std::cout << "3. Exit\n";

        // Get user input
        int choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Buy cryptocurrency
                // TODO: Add code for buying cryptocurrencies
                break;
            }
            case 2: {
                // Sell cryptocurrency
                // TODO: Add code for selling cryptocurrencies
                break;
            }
            case 3: {
                // Exit the game
                isGameRunning = false;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// ...

// Function to buy a cryptocurrency
void buyCryptocurrency(std::vector<Cryptocurrency>& cryptocurrencies, std::vector<int>& holdings, double& cashBalance) {
    displayCryptocurrencyPrices(cryptocurrencies);

    std::cout << "Enter the index of the cryptocurrency you want to buy: ";
    int cryptoIndex;
    std::cin >> cryptoIndex;

    if (cryptoIndex < 0 || cryptoIndex >= cryptocurrencies.size()) {
        std::cout << "Invalid cryptocurrency index.\n";
        return;
    }

    Cryptocurrency& selectedCrypto = cryptocurrencies[cryptoIndex];

    std::cout << "Enter the quantity to buy: ";
    int quantity;
    std::cin >> quantity;

    if (quantity <= 0) {
        std::cout << "Invalid quantity.\n";
        return;
    }

    double totalCost = selectedCrypto.price * quantity;

    if (totalCost > cashBalance) {
        std::cout << "Insufficient funds.\n";
        return;
    }

    holdings[cryptoIndex] += quantity;
    cashBalance -= totalCost;

    std::cout << "Successfully bought " << quantity << " " << selectedCrypto.name << " for $" << totalCost << ".\n";
}

// Function to sell a cryptocurrency
void sellCryptocurrency(std::vector<Cryptocurrency>& cryptocurrencies, std::vector<int>& holdings, double& cashBalance) {
    displayPortfolio(cryptocurrencies, holdings);

    std::cout << "Enter the index of the cryptocurrency you want to sell: ";
    int cryptoIndex;
    std::cin >> cryptoIndex;

    if (cryptoIndex < 0 || cryptoIndex >= cryptocurrencies.size()) {
        std::cout << "Invalid cryptocurrency index.\n";
        return;
    }

    Cryptocurrency& selectedCrypto = cryptocurrencies[cryptoIndex];

    std::cout << "Enter the quantity to sell: ";
    int quantity;
    std::cin >> quantity;

    if (quantity <= 0 || quantity > holdings[cryptoIndex]) {
        std::cout << "Invalid quantity.\n";
        return;
    }

    double totalSale = selectedCrypto.price * quantity;

    holdings[cryptoIndex] -= quantity;
    cashBalance += totalSale;

    std::cout << "Successfully sold " << quantity << " " << selectedCrypto.name << " for $" << totalSale << ".\n";
}

int main() {
    // ...

    while (isGameRunning) {
        // ...

        switch (choice) {
            case 1: {
                buyCryptocurrency(cryptocurrencies, holdings, cashBalance);
                break;
            }
            case 2: {
                sellCryptocurrency(cryptocurrencies, holdings, cashBalance);
                break;
            }
            // ...
        }
    }

    // ...

    return 0;
}

// Function to calculate the total value of the player's portfolio
double calculatePortfolioValue(const std::vector<Cryptocurrency>& cryptocurrencies, const std::vector<int>& holdings) {
    double totalValue = 0.0;
    for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
        const Cryptocurrency& crypto = cryptocurrencies[i];
        int holding = holdings[i];
        totalValue += crypto.price * holding;
    }
    return totalValue;
}

// Function to display the player's cash balance and portfolio value
void displayPlayerStatus(double cashBalance, double portfolioValue) {
    std::cout << "-------------------\n";
    std::cout << "    PLAYER STATUS\n";
    std::cout << "-------------------\n";
    std::cout << "Cash Balance: $" << cashBalance << std::endl;
    std::cout << "Portfolio Value: $" << portfolioValue << std::endl;
    std::cout << "-------------------\n";
}

// Function to display the transaction history
void displayTransactionHistory(const std::vector<std::string>& history) {
    std::cout << "-------------------\n";
    std::cout << "  TRANSACTION HISTORY\n";
    std::cout << "-------------------\n";
    for (const std::string& transaction : history) {
        std::cout << transaction << std::endl;
    }
    std::cout << "-------------------\n";
}

// ...

// Function to buy a cryptocurrency
void buyCryptocurrency(std::vector<Cryptocurrency>& cryptocurrencies, std::vector<int>& holdings, double& cashBalance, std::vector<std::string>& history) {
    // ...

    std::string transaction = "Bought " + std::to_string(quantity) + " " + selectedCrypto.name + " for $" + std::to_string(totalCost);
    history.push_back(transaction);

    std::cout << "Successfully bought " << quantity << " " << selectedCrypto.name << " for $" << totalCost << ".\n";
}

// Function to sell a cryptocurrency
void sellCryptocurrency(std::vector<Cryptocurrency>& cryptocurrencies, std::vector<int>& holdings, double& cashBalance, std::vector<std::string>& history) {
    // ...

    std::string transaction = "Sold " + std::to_string(quantity) + " " + selectedCrypto.name + " for $" + std::to_string(totalSale);
    history.push_back(transaction);

    std::cout << "Successfully sold " << quantity << " " << selectedCrypto.name << " for $" << totalSale << ".\n";
}

int main() {
    // ...

    std::vector<std::string> transactionHistory; // Track transaction history

    while (isGameRunning) {
        // ...

        switch (choice) {
            case 1: {
                buyCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 2: {
                sellCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 4: {
                // Display transaction history
                displayTransactionHistory(transactionHistory);
                break;
            }
            // ...
        }
    }

    // ...

    return 0;
}

// Function to check if a cryptocurrency exists in the list
bool isCryptocurrencyExists(const std::vector<Cryptocurrency>& cryptocurrencies, const std::string& cryptoName) {
    for (const Cryptocurrency& crypto : cryptocurrencies) {
        if (crypto.name == cryptoName) {
            return true;
        }
    }
    return false;
}

// Function to get the index of a cryptocurrency in the list
int getCryptocurrencyIndex(const std::vector<Cryptocurrency>& cryptocurrencies, const std::string& cryptoName) {
    for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
        if (cryptocurrencies[i].name == cryptoName) {
            return i;
        }
    }
    return -1; // Cryptocurrency not found
}

// Function to add a new cryptocurrency to the list
void addCryptocurrency(std::vector<Cryptocurrency>& cryptocurrencies, const std::string& cryptoName, double initialPrice) {
    cryptocurrencies.push_back({cryptoName, initialPrice});
}

// ...

int main() {
    // ...

    // Game loop
    while (isGameRunning) {
        // ...

        switch (choice) {
            case 1: {
                buyCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 2: {
                sellCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 5: {
                // Add new cryptocurrency
                std::string cryptoName;
                double initialPrice;

                std::cout << "Enter the name of the new cryptocurrency: ";
                std::cin >> cryptoName;

                if (isCryptocurrencyExists(cryptocurrencies, cryptoName)) {
                    std::cout << "Cryptocurrency already exists.\n";
                } else {
                    std::cout << "Enter the initial price of " << cryptoName << ": $";
                    std::cin >> initialPrice;

                    addCryptocurrency(cryptocurrencies, cryptoName, initialPrice);
                    holdings.push_back(0); // Add initial holding as 0

                    std::cout << "Successfully added " << cryptoName << " to the game.\n";
                }
                break;
            }
            // ...
        }
    }

    // ...

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    std::cout << "\n-------------------\n";
    std::cout << "       MAIN MENU\n";
    std::cout << "-------------------\n";
    std::cout << "1. Buy Cryptocurrency\n";
    std::cout << "2. Sell Cryptocurrency\n";
    std::cout << "3. Display Portfolio\n";
    std::cout << "4. Display Cryptocurrency Prices\n";
    std::cout << "5. Add Cryptocurrency\n";
    std::cout << "6. Exit\n";
    std::cout << "-------------------\n";
}

// Function to clear the input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to handle invalid input
void handleInvalidInput() {
    std::cout << "Invalid input. Please try again.\n";
    clearInputBuffer();
}

// ...

int main() {
    // ...

    while (isGameRunning) {
        displayMainMenu();

        // Get user input
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        clearInputBuffer();

        switch (choice) {
            case 1: {
                buyCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 2: {
                sellCryptocurrency(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 3: {
                displayPortfolio(cryptocurrencies, holdings);
                double portfolioValue = calculatePortfolioValue(cryptocurrencies, holdings);
                displayPlayerStatus(cashBalance, portfolioValue);
                break;
            }
            case 4: {
                displayCryptocurrencyPrices(cryptocurrencies);
                break;
            }
            case 5: {
                // ...
                break;
            }
            case 6: {
                isGameRunning = false;
                break;
            }
            default: {
                handleInvalidInput();
                break;
            }
        }
    }

    // ...

    return 0;
}

// Function to save the game state to a file
void saveGameState(const std::vector<Cryptocurrency>& cryptocurrencies, const std::vector<int>& holdings, double cashBalance, const std::vector<std::string>& transactionHistory) {
    std::ofstream file("game_state.txt");
    if (file.is_open()) {
        file << "CashBalance: " << cashBalance << "\n";

        for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
            const Cryptocurrency& crypto = cryptocurrencies[i];
            int holding = holdings[i];
            file << crypto.name << " " << holding << "\n";
        }

        for (const std::string& transaction : transactionHistory) {
            file << transaction << "\n";
        }

        std::cout << "Game state saved successfully.\n";
    } else {
        std::cout << "Failed to save game state.\n";
    }
    file.close();
}

// Function to load the game state from a file
void loadGameState(std::vector<Cryptocurrency>& cryptocurrencies, std::vector<int>& holdings, double& cashBalance, std::vector<std::string>& transactionHistory) {
    std::ifstream file("game_state.txt");
    if (file.is_open()) {
        cryptocurrencies.clear();
        holdings.clear();
        transactionHistory.clear();

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("CashBalance: ") == 0) {
                cashBalance = std::stod(line.substr(13));
            } else {
                std::istringstream iss(line);
                std::string cryptoName;
                int holding;
                if (iss >> cryptoName >> holding) {
                    cryptocurrencies.push_back({cryptoName, 0.0});
                    holdings.push_back(holding);
                } else {
                    transactionHistory.push_back(line);
                }
            }
        }

        std::cout << "Game state loaded successfully.\n";
    } else {
        std::cout << "Failed to load game state.\n";
    }
    file.close();
}

// ...

int main() {
    // ...

    while (isGameRunning) {
        // ...

        switch (choice) {
            // ...

            case 7: {
                // Save game state
                saveGameState(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            case 8: {
                // Load game state
                loadGameState(cryptocurrencies, holdings, cashBalance, transactionHistory);
                break;
            }
            default: {
                handleInvalidInput();
                break;
            }
        }
    }

    // ...

    return 0;
}
// Function to check if a string is numeric
bool isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

// Function to convert a string to lowercase
std::string toLowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to search for a cryptocurrency by name
int searchCryptocurrency(const std::vector<Cryptocurrency>& cryptocurrencies, const std::string& searchName) {
    for (size_t i = 0; i < cryptocurrencies.size(); ++i) {
        const std::string& cryptoName = cryptocurrencies[i].name;
        if (toLowercase(cryptoName) == toLowercase(searchName)) {
            return i;
        }
    }
    return -1; // Cryptocurrency not found
}

// Function to display cryptocurrency details
void displayCryptocurrencyDetails(const std::vector<Cryptocurrency>& cryptocurrencies, const std::string& cryptoName) {
    int cryptoIndex = searchCryptocurrency(cryptocurrencies, cryptoName);
    if (cryptoIndex != -1) {
        const Cryptocurrency& crypto = cryptocurrencies[cryptoIndex];
        std::cout << "\n-------------------\n";
        std::cout << "   CRYPTO DETAILS\n";
        std::cout << "-------------------\n";
        std::cout << "Name: " << crypto.name << std::endl;
        std::cout << "Price: $" << crypto.price << std::endl;
        std::cout << "-------------------\n";
    } else {
        std::cout << "Cryptocurrency not found.\n";
    }
}

// ...

int main() {
    // ...

    while (isGameRunning) {
        // ...

        switch (choice) {
            // ...

            case 9: {
                // Search cryptocurrency by name
                std::string cryptoName;
                std::cout << "Enter the name of the cryptocurrency to search: ";
                std::cin >> cryptoName;
                displayCryptocurrencyDetails(cryptocurrencies, cryptoName);
                break;
            }
            // ...
        }
    }

    // ...

    return 0;
}
// Function to check if a string ends with a specific suffix
bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() >= suffix.length()) {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    }
    return false;
}

// Function to validate a cryptocurrency symbol
bool validateCryptocurrencySymbol(const std::string& symbol) {
    return symbol.length() > 0 && symbol.length() <= 5 && endsWith(symbol, "COIN");
}

// Function to add a cryptocurrency with user input
void addCryptocurrencyWithInput(std::vector<Cryptocurrency>& cryptocurrencies) {
    std::string name, symbol;
    double price;

    std::cout << "Enter the name of the cryptocurrency: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter the symbol of the cryptocurrency (ending with COIN): ";
    std::cin >> symbol;

    if (!validateCryptocurrencySymbol(symbol)) {
        std::cout << "Invalid cryptocurrency symbol. Please ensure it ends with COIN and has a length between 1 and 5 characters.\n";
        return;
    }

    std::cout << "Enter the initial price of " << name << ": $";
    std::cin >> price;

    cryptocurrencies.push_back({name, symbol, price});

    std::cout << "Successfully added " << name << " (" << symbol << ") to the game.\n";
}

// Function to display cryptocurrency details by symbol
void displayCryptocurrencyDetailsBySymbol(const std::vector<Cryptocurrency>& cryptocurrencies, const std::string& symbol) {
    bool found = false;

    for (const Cryptocurrency& crypto : cryptocurrencies) {
        if (crypto.symbol == symbol) {
            found = true;
            std::cout << "\n-------------------\n";
            std::cout << "   CRYPTO DETAILS\n";
            std::cout << "-------------------\n";
            std::cout << "Name: " << crypto.name << std::endl;
            std::cout << "Symbol: " << crypto.symbol << std::endl;
            std::cout << "Price: $" << crypto.price << std::endl;
            std::cout << "-------------------\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Cryptocurrency with symbol " << symbol << " not found.\n";
    }
}

// ...

int main() {
    // ...

    while (isGameRunning) {
        // ...

        switch (choice) {
            // ...

            case 10: {
                // Add cryptocurrency with user input
                addCryptocurrencyWithInput(cryptocurrencies);
                break;
            }
            case 11: {
                // Display cryptocurrency details by symbol
                std::string symbol;
                std::cout << "Enter the symbol of the cryptocurrency to search: ";
                std::cin >> symbol;
                displayCryptocurrencyDetailsBySymbol(cryptocurrencies, symbol);
                break;
            }
            // ...
        }
    }

    // ...

    return 0;
}
