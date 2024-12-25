#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"



void registration(int i, struct people *viewer){
 

FILE *fptr;
      fptr = fopen ("user_data.txt", "a+");//fptr pointer to read user_data.txt file
      if (fptr == NULL) {
         printf("ERROR 404\n");
      }
      char name2[20];
      int count2;
      i=0;

      //while loop that reads each line of user_data.txt to store each name and its count into viewer struct
      while (fscanf(fptr, "%19s %d\n", name2, &count2) != EOF) { // Limit the string length to avoid buffer overflow
        viewer[i].name = malloc(20);
        if (viewer[i].name == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE); // or handle the error appropriately
        }
        strcpy(viewer[i].name, name2);//copies value of name2(from scanning each line) into viewer[i].name
        viewer[i].count=count2;
        i++; //increments index for next itteration of while loop
      }
    
    char name3[20];
    //start loop(loop until non-existing user name entered)
    for (int z=0;z<10;z++) {
      printf("Enter user name for registration: ");
      scanf("%19s", name3); // Limit the string length to avoid buffer overflow
      int verify= 0;//variable used inside loop(if verify=1, then valid existing name entered and loop restarts with value z=0)
      for(int j=0; j<i; j++) {//(if verify=0, new name entered and user registered, loop stops with value z=200)
         int nameValidation = strcasecmp(viewer[j].name, name3);
        if (nameValidation==0) {
        verify =1;
        z=0;//will reset outer loop
        }
      }
      if(verify==1) {
        printf("User already exists. Please choose a different name.\n");
      }
      else {
        printf("User %s is successfully registered.\n", name3);

        z=200;//will end loop
        //appends new name(name3) and its count(int i) in user_data.txt file
        int txtNbUser=i+1;
        fprintf(fptr, "%s %d\n", name3, txtNbUser);
        //puts new name(name3) and new count(i+1) in index i of viewer array
        viewer[i].name = malloc(20);
        strcpy(viewer[i].name, name3);
        viewer[i].count=i+1;
        int nbUser=i+1;
       //print the array to verify
       /**
        for(int y=0;y<nbUser;y++){
          printf("%s %d\n",viewer[y].name, viewer[y].count);
        }
        **/

      }
    }
    
fclose(fptr);

FILE *fptrMovie;
      fptrMovie = fopen ("user_ratings.txt", "r+"); //fptrMovie pointer to read user_ratings.txt
      if (fptrMovie == NULL) {
         printf("ERROR 404\n");
      }
      int skipFirstLine=0;
      int film=0;
      float film1; //film values to read rating of each movie
      float film2;
      float film3;
      float film4;
      float film5;
      float film6;
      float film7;
      float film8;
      float film9;
      float film10;

      // Read the first line to determine its length
      int firstLineLength = 0;
      char ch;
      while ((ch = fgetc(fptrMovie)) != '\n' && ch != EOF) {
      firstLineLength++;
      }

      // Move to the beginning of the second line
      fseek(fptrMovie, firstLineLength + 1, SEEK_SET);
      while (fscanf(fptrMovie, "%f %f %f %f %f %f %f %f %f %f\n", &film1, &film2, &film3, &film4, &film5, &film6, &film7, &film8, &film9, &film10) != EOF) { 
       //each film value(ratings) read from each line(corresponding to a user) stored in viewer[film].movieX 
        viewer[film].movie1=film1;
        viewer[film].movie2=film2;
        viewer[film].movie3=film3;
        viewer[film].movie4=film4;
        viewer[film].movie5=film5;
        viewer[film].movie6=film6;
        viewer[film].movie7=film7;
        viewer[film].movie8=film8;
        viewer[film].movie9=film9;
        viewer[film].movie10=film10;
        film++; 
       
      }
      viewer[film].movie1=0.0;//put ratings of 0 for each movie of new user registered
      viewer[film].movie2=0.0;
      viewer[film].movie3=0.0;
      viewer[film].movie4=0.0;
      viewer[film].movie5=0.0;
      viewer[film].movie6=0.0;
      viewer[film].movie7=0.0;
      viewer[film].movie8=0.0;
      viewer[film].movie9=0.0;
      viewer[film].movie10=0.0;

      fclose(fptrMovie);

      FILE *fptrMovie2;
      fptrMovie2 = fopen ("user_ratings.txt", "w"); //fptrMovie2 to write user ratings into user_ratings.txt
      if (fptrMovie2 == NULL) {
         printf("ERROR 404\n");
      }
      int filmCount=film+1;//number of users
      fprintf(fptrMovie2, "%d 10\n", filmCount);// write number of user and 10 (for number of movies) in first line of user_ratings.txt
      for (int movieCount=0;movieCount<(filmCount);movieCount++){ //fptrMovie2 pointer to write ratings for each movie(columns) and each user(rows) in user_ratings.txt
        fprintf(fptrMovie2, "%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", viewer[movieCount].movie1, viewer[movieCount].movie2, viewer[movieCount].movie3, viewer[movieCount].movie4, viewer[movieCount].movie5, viewer[movieCount].movie6, viewer[movieCount].movie7, viewer[movieCount].movie8, viewer[movieCount].movie9, viewer[movieCount].movie10);

      }
      fclose(fptrMovie2);

}

