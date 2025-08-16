public class Main{
   public static void main(String[] args){
    try {
            Movie movie1 = new Movie("Inception", "PG-13", 2);
            Movie movie2 = new Movie("The Lion King", "G", 5);
            System.out.println(movie1);
            System.out.println(movie2);


             movie1.incrementWatched();
            System.out.println("After watching again: " + movie1);

} catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
