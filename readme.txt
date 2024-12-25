Name:Asim Rahman
Student I.D.:40207553

To link all the c files together, “gcc main.c user.c display.c rateMovie.c recommendation.c” has to be typed.

People.h:
Creation of struct people variable containing an int count(for the count of users), character array for name and 10 movie floats for the movie ratings. Also, creating extern struct people *viewer.

main.c:
•	struct people *viewer; //from people.h header file where it was declared as extern
•	Prototypes for functions from user.c, display.c, rateMoivie.c recommendation.c
	o	void registration(int i, struct people *viewer); //from user.c
	o	void movieDispay(); //from display.c
	o	void movieRate(int i,struct people *viewer); //from rateMovie.c
	o	void formula(struct people *viewer); //from recommendation.c
•	malloc to allocate memory of size 20 times struct people(array of length 20) from heap to variable viewer
•	fptr pointer to read user_data.txt file
•	char name2[20] is a character array variable to read names from each line of user_data.txt
•	int count2 is a variable to read name counts from each line of user_data.txt
•	while loop that reads each name and its count from every line of user_data.txt and to store those name and their count into viewer (of type struct people)
	o	allocate size 20(characters) to each user name in viewer array
	o	copies value of name2(from scanning each line) into viewer[i].name
	o	increments index for next iteration of while loop
•	fptrMovie pointer to read user_ratings.txt
•	film(film1, film2,…,film10) values to read rating of each movie
•	fseek method to move to the beginning of the second line when starting to read user_ratings.txt (skip first line since it contains the number of users and movies, which we do not want to put in viewer[film].movie1)
•	use a while loop so that each film value(ratings in each column) is read from each line(rows corresponding to a user) stored in viewer[film].movieX, where film is uses as the index that is incremented at the end of iteration
•	for loop so if wrong choice, the loop repeats itself(v will stay 0) and if right choice, loop terminates by setting v to 200

user.c:
•	malloc to allocate memory of size 20 times struct people(array of length 20) from heap to variable viewer
•	fptr pointer to read user_data.txt file
•	char name2[20] is a character array variable to read names from each line of user_data.txt
•	int count2 is a variable to read name counts from each line of user_data.txt
•	while loop that reads each name and its count from every line of user_data.txt and to store those name and their count into viewer (of type struct people)
o	allocate size 20(characters) to each user name in viewer array
o	copies value of name2(from scanning each line) into viewer[i].name
o	increments index for next iteration of while loop
•	for loop(loop until non-existing user name entered)
•	int verify= 0 variable used inside loop. If verify=1, then existing name entered and loop restarts with value z=0. If verify=0, new name entered and user registered, loop stops with value z=200).
•	Inside for loop, we have int nameValidation = strcasecmp(viewer[j].name, name3); to compare name entered(name3) and each name inside viewer array.
•	appends new name(name3) and its count(int i) in user_data.txt file
•	put new name(name3) and new count(i+1) in index i of viewer array
•	fptrMovie pointer to read user_ratings.txt
•	film(film1, film2,…,film10) values to read rating of each movie
•	fseek method to move to the beginning of the second line when starting to read user_ratings.txt (skip first line since it contains the number of users and movies, which we do not want to put in viewer[film].movie1)
•	use a while loop so that each film value(ratings in each column) is read from each line(rows corresponding to a user) stored in viewer[film].movieX, where film is uses as the index that is incremented at the end of iteration
•	put ratings of 0 for each movie of new user registered
•	fptrMovie2 to write user ratings into user_ratings.txt
•	write number of user and 10 (for number of movies) in first line of user_ratings.txt
•	fptrMovie2 pointer to write ratings for each movie(columns) and each user(rows) in user_ratings.txt 

display.c:
printing everything from movie_database.txt file, but with some modifications.

rateMovie.c:
•	fptr4 pointer to read first element from user_ratings.txt, which is the number of users(nbUser2)
•	int verify2= 0 is a variable used inside loop(if verify2=1, then existing name entered)
•	Inside for loop, we have int nameValidation = strcasecmp(viewer[j].name, name4); to compare name entered(name4) and each name inside viewer array. We also have index=j to know which user it is
•	if verify2=1, then existing name entered and display all movies are displayed.
	o	variable movieIndex used with while loop so that we repeatidly ask to enter movie number if the number is not between 1 and 10. If movieIndex=0, loop continues, if number entered is between 1 and 10, then loop stops by putting movieIndex=1
	o	variable validRating so that we repeatidly ask to enter movie rating number if the number is not between 1 and 5. if validRating=1, loop stops and if validRating=0, loop continues.
	o	If rate is between 1 and 5, then we store rate value entered(value between 1 and 5) in corresponding movie(value between 1 and 10) of corresponding user(of specific index when name entered was matched with one of the names from viewer array).
	o	fptrMovie2 pointer to write into user_ratings.txt
	o	write into first line of user_ratings.txt the number of user and the number of movies(10)
	o	fptrMovie2 pointer to write ratings for each movie(columns) and each user(rows) in user_ratings.txt 

recommendation.c:
•	fptr4 pointer to read first element from user_ratings.txt, which is the number of users(nbUser2)
•	int verify2= 0 is a variable used inside loop(if verify2=1, then existing name entered)
•	Inside for loop, we have int nameValidation = strcasecmp(viewer[j].name, name4); to compare name entered(name4) and each name inside viewer array. We also have index=j to know which user it is
•	int movieNb=0; for the indexing of the movie that have not been watched by the corresponding user

	The following is for every movie that are rate 0 for the specific user entered:
•	if the first movie has rating of 0 for the chosen user(user name typed that was matched with one of the names in viewer array) 
	o	float movie1A=0; is a variable to determine the average rating of the movie(with only the people who have watched the movie) that the corresponding user hasn't watched
	o	int N1=0; is the number of people who have watched the movie(not rated 0)
	o	loop trough every user
		-	if the user has not rated the corresponding movie with 0, then we increment the value of movie1A(rating of the movie) with the previous user who has watched the movie
		-	N1++ to increment the number of user who have watched the movie
	o	if no one watched the movie, then do nothing
	o	else 
		-	increment the index of the movie(indexing of the movie that have not been watched by the corresponding user)
		-	calculate the average rating(sum of the ratings(that are not 0) divided by the number of people who have watched the movie(have not rated a 0))
