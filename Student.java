import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Student {

    private String name;
    private int age;
    private int id;

    private static int nextId = 1;
    private static String fileName = "students.csv";
    private static ArrayList<Student> students = new ArrayList<>();

    public Student(String name, int age) {
        setName(name);
        setAge(age);
        this.id = nextId++;
        students.add(this); // نضيفه للقائمة عشان نقدر نبحث
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && !name.isEmpty()) {
            this.name = name;
        } else {
            System.out.println("Name cannot be null or empty.");
        }
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age > 0) {
            this.age = age;
        } else {
            System.out.println("Age must be greater than 0.");
        }
    }

    public int getId() {
        return id;
    }

    public void saveFile() {
        try (FileWriter fw = new FileWriter(fileName, true)) {
            fw.write(id + "," + name + "," + age + "\n");
            System.out.println("Student saved: " + this);
        } catch (IOException e) {
            System.out.println("Error saving student: " + e.getMessage());
        }
    }

    public static void searchByName(String searchName) {
        boolean found = false;
        for (Student s : students) {
            if (s.getName().equalsIgnoreCase(searchName)) {
                System.out.println("Found student: " + s);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No student found with name: " + searchName);
        }
    }

    public String toString() {
        return "Student[ID=" + id + ", Name=" + name + ", Age=" + age + "]";
    }

    public static void main(String[] args) {
        Student s1 = new Student("Manar", 21);
        s1.saveFile();
        Student s2 = new Student("Ahmed", 21);
        s2.saveFile();

        searchByName("Manar");
        searchByName("Hoda");
    }
}

