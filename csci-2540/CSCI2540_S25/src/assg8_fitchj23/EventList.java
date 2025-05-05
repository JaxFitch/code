/*
 * EventList.java
 * Jackson Fitch
 * 4/17/2025
 */

package assg8_fitchj23;

import java.util.ArrayList;

public class EventList {
    private ArrayList<Event> events;
    
    /**
     * Default constructor - creates an empty event list
     */
    public EventList() {
        events = new ArrayList<>();
    }
    
    /**
     * Check if the event list is empty
     * @return true if the list is empty, false otherwise
     */
    public boolean isEmpty() {
        return events.isEmpty();
    }
    
    /**
     * Insert an event into the list, maintaining the sorted order
     * @param event The event to insert
     */
    public void insert(Event event) {
        int i = 0;
        // Find the correct position to insert
        while (i < events.size() && event.compareTo(events.get(i)) > 0) {
            i++;
        }
        events.add(i, event);
    }
    
    /**
     * Remove and return the first event in the list
     * @return The first event (earliest in time)
     */
    public Event removeFirst() {
        if (isEmpty()) {
            return null;
        }
        return events.remove(0);
    }
    
    /**
     * Return the first event without removing it
     * @return The first event (earliest in time)
     */
    public Event getFirst() {
        if (isEmpty()) {
            return null;
        }
        return events.get(0);
    }
    
    /**
     * Return a string representation of the event list
     */
    @Override
    public String toString() {
        return events.toString();
    }
}