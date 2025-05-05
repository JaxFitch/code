/*
 * Simulation.java
 * Jackson Fitch
 * 4/17/2025
 */

package assg8_fitchj23;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * The main class that runs the bank simulation
 */
public class Simulation {
    private static Queue<Event> bankQueue = new LinkedList<>();
    private static EventList eventList = new EventList();
    private static int totalCustomers = 0;
    private static int totalWaitingTime = 0;
    
    /**
     * Process an arrival event
     * @param event The arrival event to process
     */
    public static void processArrival(Event event) {
        System.out.println("Processing an arrival event at time: " + event.getTime());
        
        // Add customer to the bank queue
        bankQueue.add(event);
        totalCustomers++;
        
        // If this is the only customer, start service immediately and schedule departure
        if (bankQueue.size() == 1) {
            int departureTime = event.getTime() + event.getTransTime();
            Event departure = new Event('D', departureTime);
            eventList.insert(departure);
        }
    }
    
    /**
     * Process a departure event
     * @param event The departure event to process
     */
    public static void processDeparture(Event event) {
        System.out.println("Processing a departure event at time: " + event.getTime());
        
        // Remove the customer who just finished
        Event completedCustomer = bankQueue.remove();
        
        // Calculate waiting time for this customer
        int waitingTime = completedCustomer.getTime() == event.getTime() - completedCustomer.getTransTime() ? 
                          0 : (event.getTime() - completedCustomer.getTransTime()) - completedCustomer.getTime();
        totalWaitingTime += waitingTime;
        
        // If there are more customers waiting, start serving the next one
        if (!bankQueue.isEmpty()) {
            Event nextCustomer = bankQueue.peek();
            int departureTime = event.getTime() + nextCustomer.getTransTime();
            Event departure = new Event('D', departureTime);
            eventList.insert(departure);
        }
    }
    
    /**
     * Main method to run the simulation
     */
    public static void main(String[] args) {
        try {
            // Read input file
            Scanner scanner = new Scanner(new File("assg8_input.txt"));
            
            System.out.println("Simulation Begins");
            
            // Add first arrival to event list
            if (scanner.hasNextInt()) {
                int arrivalTime = scanner.nextInt();
                int transactionTime = scanner.nextInt();
                Event firstArrival = new Event(arrivalTime, transactionTime);
                eventList.insert(firstArrival);
            }
            
            // Process events until no more events
            while (!eventList.isEmpty()) {
                Event currentEvent = eventList.removeFirst();
                
                // Process event based on type
                if (currentEvent.isArrival()) {
                    processArrival(currentEvent);
                    
                    // Check if there's another arrival to read from file
                    if (scanner.hasNextInt()) {
                        int arrivalTime = scanner.nextInt();
                        int transactionTime = scanner.nextInt();
                        Event nextArrival = new Event(arrivalTime, transactionTime);
                        eventList.insert(nextArrival);
                    }
                } else {
                    processDeparture(currentEvent);
                }
            }
            
            scanner.close();
            
            // Print final statistics
            System.out.println("\nFinal Statistics:");
            System.out.println("Total number of people processed: " + totalCustomers);
            double averageWaitingTime = (double) totalWaitingTime / totalCustomers;
            System.out.println("Average of time spent waiting: " + averageWaitingTime);
            
        } catch (FileNotFoundException e) {
            System.out.println("Input file not found: " + e.getMessage());
        }
    }
}