package activity13;

public class Appointment extends KeyedItem<Date> {
    private String description;

    public Appointment(Date key, String description) {
        super(key);
        this.description = description;
    }

	@Override
    public String toString() {
        return getKey().getDate() + ", " + description;
    }
}