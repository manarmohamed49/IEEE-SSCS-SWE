public class Main{
   public static void main(String[] args){

            Movies myMovies = new Movies();
 
         myMovies.addMovie("Inception", "PG-13", 2);
        myMovies.addMovie("Interstellar", "PG-13", 1);
        myMovies.addMovie("inception", "PG-13", 5)
        
         myMovies.displayMovies(); 
         myMovies.incrementWatched("Inception");
         myMovies.incrementWatched("Avatar");

         myMovies.displayMovies();
    }
} 
