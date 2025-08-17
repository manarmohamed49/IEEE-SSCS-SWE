import java.util.ArrayList;
public class Movies{
     private ArrayList<Movie>movies;
      public Movies() {
        this.movies = new ArrayList<>();
    }
public void addMovie(String name, String rating, int watched){
      for(Movie movie : movies){
         if(movie.getName().equalsIgnoreCase(name)){
           System.out.println("Error: Movie with name '" + name + "' already exists!");
          return;
}
}
        movies.add(new Movie(name, rating, watched));
        System.out.println("Movie '" + name + "' added successfully.");
    }
public void incrementWatched(String name){
       for(Movie movie : movies){
          if(movie.getName().equalsIgnoreCase(name)){
            movie.incrementWatched();
             System.out.println("Watched count incremented for '" + name + "'.");
                return;
            }
        }
        System.out.println("Error: Movie with name '" + name + "' not found!");
    }
public void displayMovies(){
    if(movies.isEmpty()){
      System.out.println("no movies to display");
      return;
}
         System.out.println("=== Stored Movies ===");
        for (Movie movie : movies) {
            System.out.println(movie);
        }
    }
}
