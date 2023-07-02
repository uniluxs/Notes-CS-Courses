class Account:
    def __init__(self, id, name, balance=0):
        self.id = id
        self.name = name
        self.balance = balance
        self.transactions = []
        self.loan = 0

    def deposit(self, amount):
        self.balance += amount
        self.transactions.append(f"Deposited {amount}")
        print(f"Deposited {amount}. New balance is {self.balance}")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient balance!")
            return
        self.balance -= amount
        self.transactions.append(f"Withdrew {amount}")
        print(f"Withdrew {amount}. New balance is {self.balance}")

    def apply_interest(self, interest_rate):
        interest = self.balance * interest_rate
        self.balance += interest
        self.transactions.append(f"Applied interest {interest_rate * 100}%, gained {interest}")
        print(f"Gained interest {interest}. New balance is {self.balance}")

    def take_loan(self, amount):
        if self.loan > 0:
            print("You already have a loan!")
            return
        self.loan += amount
        self.balance += amount
        self.transactions.append(f"Took a loan of {amount}")
        print(f"Took a loan of {amount}. New balance is {self.balance}")

    def pay_loan(self, amount):
        if amount > self.balance:
            print("Insufficient balance!")
            return
        self.balance -= amount
        self.loan -= amount
        self.transactions.append(f"Paid a loan of {amount}")
        print(f"Paid a loan of {amount}. New balance is {self.balance}")

    def display(self):
        print(f"ID: {self.id}, Name: {self.name}, Balance: {self.balance}")
        print("Transactions:")
        for transaction in self.transactions:
            print(transaction)
        if self.loan > 0:
            print(f"Outstanding loan: {self.loan}")


class Bank:
    def __init__(self, interest_rate=0.01):
        self.accounts = {}
        self.interest_rate = interest_rate

    def create_account(self, id, name):
        if id in self.accounts:
            print("Account already exists!")
            return
        self.accounts[id] = Account(id, name)
        print(f"Created account {id} for {name}")

    def deposit(self, id, amount):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].deposit(amount)

    def withdraw(self, id, amount):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].withdraw(amount)

    def apply_interest(self, id):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].apply_interest(self.interest_rate)

    def take_loan(self, id, amount):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].take_loan(amount)

    def pay_loan(self, id, amount):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].pay_loan(amount)

    def display_account(self, id):
        if id not in self.accounts:
            print("Account does not exist!")
            return
        self.accounts[id].display()


def main():
    bank = Bank()
    while True:
        print("\n1. Create Account")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Display Account")
        print("5. Apply Interest")
        print("6. Take Loan")
        print("7. Pay Loan")
        print("8. Quit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            id = int(input("Enter account id: "))
            name = input("Enter account name: ")
            bank.create_account(id, name)
        elif choice == 2:
            id = int(input("Enter account id: "))
            amount = int(input("Enter amount to deposit: "))
            bank.deposit(id, amount)
        elif choice == 3:
            id = int(input("Enter account id: "))
            amount = int(input("Enter amount to withdraw: "))
            bank.withdraw(id, amount)
        elif choice == 4:
            id = int(input("Enter account id: "))
            bank.display_account(id)
        elif choice == 5:
            id = int(input("Enter account id: "))
            bank.apply_interest(id)
        elif choice == 6:
            id = int(input("Enter account id: "))
            amount = int(input("Enter loan amount: "))
            bank.take_loan(id, amount)
        elif choice == 7:
            id = int(input("Enter account id: "))
            amount = int(input("Enter payment amount: "))
            bank.pay_loan(id, amount)
        elif choice == 8:
            break
        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()
