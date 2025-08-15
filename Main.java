public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Manar", 21);
        
        s1.addCourse(new Course("Math", 90));
        s1.addCourse(new Course("Physics", 85));
        s1.addCourse(new Course("Math", 95)); 

        System.out.println("Average Grade: " + s1.getAverageGrade());

        s1.sortCoursesByGrade();
        System.out.println(s1);

        s1.removeCourse("Physics");
        System.out.println(s1);
    }
}
