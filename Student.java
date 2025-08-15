import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Student {
    private static int idCounter = 1;
    private int id;
    private String name;
    private int age;
    private List<Course> courses;

    public Student(String name, int age) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Student name cannot be empty.");
        }
        if (age <= 0) {
            throw new IllegalArgumentException("Age must be positive.");
        }

        this.id = idCounter++;
        this.name = name.trim();
        this.age = age;
        this.courses = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public void addCourse(Course course) {
        for (Course c : courses) {
            if (c.getName().equalsIgnoreCase(course.getName())) {
                System.out.println("Course already exists for this student.");
                return;
            }
        }
        courses.add(course);
    }

    public void removeCourse(String courseName) {
        courses.removeIf(c -> c.getName().equalsIgnoreCase(courseName));
    }

    public double getAverageGrade() {
        if (courses.isEmpty()) return 0;
        double total = 0;
        for (Course c : courses) {
            total += c.getGrade();
        }
        return total / courses.size();
    }

    public void sortCoursesByGrade() {
        courses.sort(Comparator.comparingDouble(Course::getGrade).reversed());
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", courses=" + courses +
                '}';
    }
}

