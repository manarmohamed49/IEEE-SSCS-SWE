public class Movie {
    private String name;
    private String rating;
    private int watched;

    private static final String[] VALID_RATING = {"G", "PG", "PG-13", "R"};

    public Movie(String name, String rating, int watched) {
        setName(name);
        setRating(rating);
        setWatched(watched);
    }

    public String getName() {
        return name;
    }

    public String getRating() {
        return rating;
    }

    public int getWatched() {
        return watched;
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("name of the movie cannot be empty");
        }
        this.name = name.trim();
    }

    public void setRating(String rating) {
        if (!isValidRating(rating)) {
            throw new IllegalArgumentException("invalid rating");
        }
        this.rating = rating;
    }

    public void setWatched(int watched) {
        if (watched < 0) {
            throw new IllegalArgumentException("watched cannot be negative");
        }
        this.watched = watched;
    }

    public void incrementWatched() {
        this.watched++;
    }

    private boolean isValidRating(String rating) {
        for (String valid : VALID_RATING) {
            if (valid.equalsIgnoreCase(rating)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return "Movie{name='" + name + "', rating='" + rating + "', watched=" + watched + "}";
    }
}

