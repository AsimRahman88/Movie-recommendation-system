#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"



void movieRate(int i,struct people *viewer) {  
FILE *fptr4;
      fptr4 = fopen ("user_ratings.txt", "a+");//fptr4 pointer to read first element from user_ratings.txt, which is the number of users(nbUser2)
      if (fptr4 == NULL) {
         printf("ERROR 404\n");
      }
   int nbUser2;
   fscanf(fptr4, "%d\n", &nbUser2);
   //printf("%d\n", nbUser2);
   fclose(fptr4);
    char name4[20];
    
    
    
      printf("Enter your username: ");
      scanf("%19s", name4); // Limit the string length to avoid buffer overflow
      getchar(); // Consume the newline character in the input buffer
      int verify2= 0; //variable used inside loop(if verify2=1, then existing name entered)
      int index; 
      for(int j=0; j<nbUser2; j++) {
         int nameValidation2 = strcasecmp(viewer[j].name, name4);
        if (nameValidation2==0) {
          verify2 =1;
         index=j;//index stored to know which user it is
        }
      }
      if(verify2==1) {//if verify2=1, then existing name entered 
        printf("\n"); //display all the movies
        printf("**** Movie Database ****\n");
        printf("1. The Shawshank Redemption (Drama) - 9.3\n");
        printf("2. The Godfather (Crime) - 9.2\n");
        printf("3. The Dark Knight (Action) - 9.0\n");
        printf("4. Pulp Fiction (Crime) - 8.9\n");
        printf("5. The Lord of the Rings: The Return of the King (Adventure) - 8.9\n");
        printf("6. Forest Gump (Drama) - 8.8\n");
        printf("7. The Matrix (Action) - 8.7\n");
        printf("8. The Silence of the Lambs (Crime) - 8.6\n");
        printf("9. Schindler's List (Biography) - 8.6\n");
        printf("10. Inception (Action) - 8.6\n");
        int movieIndex=0;
        int movie;
        while (movieIndex==0) {// variable movieIndex so that we repeatidly ask to enter movie number if the number is not between 1 and 10
          printf("Enter the number of the movie you want to rate: ");
          
          scanf("%d", &movie);
          if(movie>=1 && movie<=10){
            movieIndex=1;//if movieIndex=1, loop stops
          }
          else{
            printf("Invalid movie. Please enter a movie between 1 and 10.\n");
          }
        }
        float rate;
        int validRating=0;// variable validRating so that we repeatidly ask to enter movie rating number if the number is not between 1 and 5
        while(validRating==0){
        printf("Enter your rating(1-5): ");
        scanf("%f", &rate);
        if(rate>=1 && rate<=5){
          validRating=1;//if validRating=1, loop stops
          printf("Rating recorded successfully.\n");
          //store rate value entered(value between 1 and 5) in corresponding movie(value between 1 and 10) of corresponding user(of specific index when name entered was matched with one of the names from viewer array)
          if(movie==1){
            viewer[index].movie1=rate;
          }
          if(movie==2){
            viewer[index].movie2=rate;
          }
          if(movie==3){
            viewer[index].movie3=rate;
          }
          if(movie==4){
            viewer[index].movie4=rate;
          }
          if(movie==5){
            viewer[index].movie5=rate;
          }
          if(movie==6){
            viewer[index].movie6=rate;
          }
          if(movie==7){
            viewer[index].movie7=rate;
          }
          if(movie==8){
            viewer[index].movie8=rate;
          }
          if(movie==9){
            viewer[index].movie10=rate;
          }
          if(movie==10){
            viewer[index].movie10=rate;
          }
          FILE *fptrMovie2;
          fptrMovie2 = fopen ("user_ratings.txt", "w"); //fptrMovie2 pointer to write into user_ratings.txt
          if (fptrMovie2 == NULL) {
            printf("ERROR 404\n");
          }
          
          fprintf(fptrMovie2, "%d 10\n", nbUser2);//write into first line of user_ratings.txt the number of user and the number of movies(10)
          for (int movieCount=0;movieCount<(nbUser2);movieCount++){//fptrMovie2 pointer to write ratings for each movie(columns) and each user(rows) in user_ratings.txt
            fprintf(fptrMovie2, "%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", viewer[movieCount].movie1, viewer[movieCount].movie2, viewer[movieCount].movie3, viewer[movieCount].movie4, viewer[movieCount].movie5, viewer[movieCount].movie6, viewer[movieCount].movie7, viewer[movieCount].movie8, viewer[movieCount].movie9, viewer[movieCount].movie10);
          }
          fclose(fptrMovie2);
        }
        else{
          printf("Invalid rating. Please enter a rating between 1 and 5.\n");
        }
        
      }
      }
      else {
        printf("User not found. Please register first.\n");
        
        
      }
    
    
}
