/**
 * StudentTest.java
 * Jackson Fitch
 * 2/20/25
 */
package activity6;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class StudentTest {

    @Test
    public void testDefaultConstructor() {
        Student student = new Student();
        assertEquals(0, student.getId());
        assertEquals("unknown", student.getName());
    }

    @Test
    public void testParameterizedConstructor() {
        Student student = new Student(1, "John Doe");
        assertEquals(1, student.getId());
        assertEquals("John Doe", student.getName());
    }

    @Test
    public void testGetId() {
        Student student = new Student(1, "John Doe");
        assertEquals(1, student.getId());
    }

    @Test
    public void testGetName() {
        Student student = new Student(1, "John Doe");
        assertEquals("John Doe", student.getName());
    }

    @Test
    public void testSetId() {
        Student student = new Student();
        student.setId(2);
        assertEquals(2, student.getId());
    }

    @Test
    public void testSetName() {
        Student student = new Student();
        student.setName("Jane Doe");
        assertEquals("Jane Doe", student.getName());
    }

    @Test
    public void testToString() {
        Student student = new Student(1, "John Doe");
        String expected = "ID: 1\nName: John Doe";
        assertEquals(expected, student.toString());
    }
}
