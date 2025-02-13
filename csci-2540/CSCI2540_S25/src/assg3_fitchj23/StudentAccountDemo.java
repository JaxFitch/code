/**
* StudentAccountDemo.java
* Jackson Fitch
* 2/11/2025
*/
package assg3_fitchj23;

public class StudentAccountDemo {
	
    public static void main(String[] args) {
    	
        // Test basic StudentAccount functionality
        System.out.println("=== Testing Basic StudentAccount ===\n");
        StudentAccount basicAcct = new StudentAccount(500);
        System.out.println("Initial balance: $" + basicAcct.getBalance());
        
        // Test deposit
        basicAcct.deposit(200);
        System.out.println("\nAfter depositing $200: $" + basicAcct.getBalance());
        
        // Test charge
        basicAcct.charge(150);
        System.out.println("After charging $150: $" + basicAcct.getBalance());
        
        // Test transfer
        StudentAccount transferTarget = new StudentAccount(1000);
        System.out.println("\nTransferring $300 to account " + transferTarget.getAcctNo());
        basicAcct.transfer(300, transferTarget);
        System.out.println("Source balance after transfer: $" + basicAcct.getBalance());
        System.out.println("Target balance after transfer: $" + transferTarget.getBalance());
        
        // Test account comparison
        System.out.println("\nAccount comparison:");
        System.out.println("Account " + basicAcct.getAcctNo() + " vs " + transferTarget.getAcctNo() + 
                           ": " + basicAcct.compareTo(transferTarget));
        System.out.println("Account " + transferTarget.getAcctNo() + " vs " + basicAcct.getAcctNo() +
        				   ": " + transferTarget.compareTo(basicAcct));
        transferTarget.charge(1050);
		System.out.println("Account " + basicAcct.getAcctNo() + " vs " + transferTarget.getAcctNo() + 
				           ": " + basicAcct.compareTo(transferTarget) + " (same balance)");
        
		
        // Test RewardsAccount functionality
        System.out.println("\n\n=== Testing RewardsAccount ===\n");
        RewardsAccount rewardsAcct = new RewardsAccount(200);
        System.out.println("Initial balance: $" + rewardsAcct.getBalance());
        System.out.println("Initial rewards: $" + rewardsAcct.getRewards());
        
        // Test deposit with reward qualification
        System.out.println("\nDepositing $150 (qualifies for rewards)");
        rewardsAcct.deposit(150);
        System.out.println("New balance: $" + rewardsAcct.getBalance());
        System.out.println("Rewards balance: $" + rewardsAcct.getRewards());
        
        // Test deposit without reward qualification
        System.out.println("\nDepositing $50 (no rewards)");
        rewardsAcct.deposit(50);
        System.out.println("New balance: $" + rewardsAcct.getBalance());
        System.out.println("Rewards balance: $" + rewardsAcct.getRewards());

        // Test reward redemption scenarios
        System.out.println("\nAttempting to redeem rewards with $20 threshold:");
        System.out.println("Current rewards: $" + rewardsAcct.getRewards());
        rewardsAcct.redeemRewards();
        
        // Build up rewards
        System.out.println("\nMaking qualifying deposit of $500");
        rewardsAcct.deposit(500);
        System.out.println("Rewards balance: $" + rewardsAcct.getRewards());
       
        // Successful redemption
        System.out.println("\nRedeeming rewards:");
        rewardsAcct.redeemRewards();
        System.out.println("New balance: $" + rewardsAcct.getBalance());
        System.out.println("Rewards after redemption: $" + rewardsAcct.getRewards());

        
        // Test edge cases
        System.out.println("\n\n=== Testing Edge Cases ===\n");
        // Negative balance test
        StudentAccount overdraftAcct = new StudentAccount(100);
        System.out.println("nAttempting to charge $150 from $100 balance");
        overdraftAcct.charge(150);
        System.out.println("Resulting balance: $" + overdraftAcct.getBalance());

        // Test account information methods
        System.out.println("\nTesting account information methods:");
        System.out.println("toString() output:\n" + rewardsAcct.toString());
        System.out.println("\nprintInfo() output:");
        rewardsAcct.printInfo();

        
        // Test multiple account creation
        System.out.println("\n\n=== Testing Account Number Sequencing ===\n");
        StudentAccount acct1 = new StudentAccount();
        StudentAccount acct2 = new StudentAccount();
        System.out.println("Account 5 number: " + acct1.getAcctNo());
        System.out.println("Account 6 number: " + acct2.getAcctNo());
    }
}
