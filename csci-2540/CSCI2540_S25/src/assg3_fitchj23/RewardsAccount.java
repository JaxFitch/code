/**
 * RewardsAccount.java
 * Jackson Fitch
 * 2/11/2025
 */

package assg3_fitchj23;

public class RewardsAccount extends StudentAccount {

	// Instance variables
	private double rewards;
	
	/**
	 * Default constructor 
	 * Initializes account number, balance, and rewards
	 */
	public RewardsAccount() {
		super();
		rewards = 0;
	}
	
	/**
	 * Constructor with initial balance 
	 * Initializes account number, balance, and
	 * rewards
	 * 
	 * @param initialBalance
	 */
	public RewardsAccount(double initialBalance) {
		super(initialBalance);
		if (initialBalance >= 100) {
			rewards = initialBalance * 0.04;
		} else {
			rewards = 0;
		}
	}
	
	/**
	 * @return rewards
	 */
	public double getRewards() {
        return rewards;
    }
	
	/**
	 * Redeems rewards for cash
	 */
	public void redeemRewards() {
		if (rewards >= 20) {
			super.deposit(rewards);
			rewards = 0;
		} else {
			System.out.println("You do not have enough rewards to redeem!");
		}
	}
	
	/**
	 * @return account number, balance, and rewards
	 */
	@Override
	public String toString() {
	    return super.toString() + "\nRewards: " + rewards;
	}
	
	/**
	 * Deposits amount into account
	 * 
	 * @param amount: amount to deposit
	 */
	@Override
	public void deposit(double amount) {
		super.deposit(amount);
		if (amount >= 100) {
			rewards += amount * 0.04;
		}
	}
	
	/**
	 * Prints account number, balance and rewards
	 */
	@Override
	public void printInfo() {
		super.printInfo();
		System.out.println("Rewards: " + rewards);
	}
}
