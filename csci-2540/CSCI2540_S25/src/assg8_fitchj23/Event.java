/*
 * Event.java
 * Jackson Fitch
 * 4/17/2025
 */

package assg8_fitchj23;

public class Event implements Comparable<Event> {
    private char type;       // 'A' for arrival, 'D' for departure
    private int time;        // Time of the event
    private int transTime;   // Transaction time (only for arrival events)
    
    /**
     * Constructor for an arrival event
     * @param time Arrival time
     * @param transTime Transaction time
     */
    public Event(int time, int transTime) {
        this.type = 'A';
        this.time = time;
        this.transTime = transTime;
    }
    
    /**
     * Constructor for a departure event
     * @param time Departure time
     */
    public Event(char type, int time) {
        this.type = type;
        this.time = time;
        this.transTime = 0;  // Not relevant for departure events
    }
    
    /**
     * Check if this is an arrival event
     * @return true if this is an arrival event, false otherwise
     */
    public boolean isArrival() {
        return type == 'A';
    }
    
    /**
     * Check if this is a departure event
     * @return true if this is a departure event, false otherwise
     */
    public boolean isDeparture() {
        return type == 'D';
    }
    
    /**
     * Get the time of this event
     * @return the time
     */
    public int getTime() {
        return time;
    }
    
    /**
     * Get the transaction time of this event
     * @return the transaction time
     */
    public int getTransTime() {
        return transTime;
    }
    
    /**
     * Compare events based on time
     * If times are equal, arrivals come before departures
     */
    @Override
    public int compareTo(Event other) {
        if (this.time == other.time) {
            if (this.isArrival() && other.isDeparture()) {
                return -1;  // Arrival comes before departure
            } else if (this.isDeparture() && other.isArrival()) {
                return 1;   // Departure comes after arrival
            } else {
                return 0;   // Same type, same time
            }
        }
        return this.time - other.time;
    }
    
    /**
     * Return a string representation of this event
     */
    @Override
    public String toString() {
        if (isArrival()) {
            return "(A, " + time + ", " + transTime + ")";
        } else {
            return "(D, " + time + ")";
        }
    }
}