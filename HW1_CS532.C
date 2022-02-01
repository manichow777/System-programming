#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct keywords{
    char keyword[10];
    int count;
};
//To increment the count
void update_count(struct keywords *keyword, int n)
{
    (keyword+n)->count++; //The count of a keyword gets incremented whenever the keyword is found in the input
}
//Disokays the ketword and the associated counts
void print_table(struct keywords *k, int n)
{
    int i;
	for (i = 0; i < n-1; i++)
    printf ("%s:\t %d\n", (k + i)->keyword, (k + i)->count);
}
int main(int argc, char* argv[])
{
    struct keywords *key;
    char *split_string=" ";
    const char s[2]=" ";
    char *input_line = NULL;
    int i=0;
    int j=0;	
  	size_t max_length = 255;
  	ssize_t input_strings_count=0;
    key = (struct keywords *) calloc (argc, sizeof (struct keywords));
    
    for (i =0; i< argc-1; i++){
        (key+i)->count = 0;
        strcpy((key+i)->keyword,argv[i+1]);
    }
  /* read the user input using the getline()*/
  while ((input_strings_count = getline (&input_line, &max_length, stdin)) > 0)
    {
    split_string = strtok (input_line, s); //Whenever a space is found split the word and repeat the process until the NULL is found
    while (split_string != NULL)
    {
      for (j = 0; j < argc; j++)
	{
    /*Compare the split string with the keywords and if a match is found, increment the count */
	  if (!strcmp (split_string, (key + j)->keyword))
	    {
	      update_count(key,j);
	    }
	}
      split_string = strtok (NULL, " ,.\n");
    }
    }
    print_table(key,argc); //Display the keywords and counts
    free (input_line);
    return 0;
}