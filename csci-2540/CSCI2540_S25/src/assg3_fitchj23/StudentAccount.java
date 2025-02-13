/**
 * StudentAccount.java
 * Jackson Fitch
 * 2/11/2025
 */

package assg3_fitchj23;

public class StudentAccount implements Comparable<StudentAccount> {
	
	// Instance variables
	private static long counter = 1;
	private long acctNo;
	private double balance;

	/**
	 * Default constructor
	 * Initializes account number and balance
	 */
	public StudentAccount() {
		acctNo = counter;
        counter++;
        balance = 0;
    }
	
	/**
	 * Constructor with initial balance 
	 * Initializes account number and balance
	 * 
	 * @param initialBalance
	 */
	public StudentAccount(double initialBalance) {
		acctNo = counter;
        counter++;
        balance = initialBalance;
    }
	
	/**
	 * @return account number
	 */
	public long getAcctNo() {
        return acctNo;
    }
	
	/**
	 * @return balance
	 */
	public double getBalance() {
        return balance;
    }
	
	/**
	 * @return counter
	 */
	public long getCounter() {
        return counter;
    }
	
	/**
	 * Set balance to newBalance
	 * 
	 * @param newBalance: new balance to set
	 */
	public void setBalance(double newBalance) {
		balance = newBalance;
	}
	
	/**
	 * Deposit amount into account
	 * 
	 * @param amount: amount to deposit
	 */
	public void deposit(double amount) {
		balance += amount;
	}
	
	/**
	 * Charge amount from account
	 * 
	 * @param amount: amount to charge
	 */
	public void charge(double amount) {
		balance -= amount;
	}
	
	/**
	 * Transfer amount from this account to newAcct
	 * 
	 * @param amount:  amount to transfer
	 * @param newAcct: account to transfer to
	 */
	public void transfer(double amount, StudentAccount newAcct) {
		balance -= amount;
		newAcct.deposit(amount);
	}
	
	/**
	 * Print account number and balance
	 */
	public void printInfo() {
		System.out.println("Account number: " + acctNo);
		System.out.println("Current balance: " + balance);
	}
	
	
	/**
	 * @return account number and balance in string format
	 */
	@Override
	public String toString() {
		return "Account number: " + acctNo + "\nCurrent balance: " + balance;
	}
	
	/**
	 * Compare this account to other account
	 * 
	 * @param other: account to compare to
	 * @return -1 if this account is less than other account, 1 if this account is
	 *         greater than other account, 0 if they are equal
	 */
	public int compareTo(StudentAccount other) {
        if (this.getBalance() == other.getBalance()) {
            return 0;
        } else if (this.getBalance() < other.getBalance()) {
            return -1;
        } else {
            return 1;
        }
    }
}
