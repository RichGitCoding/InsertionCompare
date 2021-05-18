#include "stdio.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*
int strcmp(const char *leftStr, const char *rightStr )
{
	if(leftStr < rightStr)
	{
		return -1; 
	}
	else if(leftStr== rightStr)
	{
		return 0;
	}
	else if(leftStr > rightStr)
	{
		return 1;
	}
}
*/
int comp_length(const char *leftStr, const char* rightStr)
{
	if( strlen(leftStr) < strlen(rightStr))
	{
		return -1;
		
	}
	else if( strlen(leftStr) == strlen(rightStr))
	{
		return 0;
	}
	else if( strlen(leftStr) > strlen(rightStr))
	{
		return 1;
	}
	
}

int comp_mixt(const char *leftStr, const char* rightStr)
{
	if(strlen(leftStr) == strlen(rightStr))
	{
		return strcmp(leftStr, rightStr);
	}
	else
	{
		return comp_length(leftStr , rightStr);
	}
}


int comp_greater(const char *leftStr, const char *rightStr )
{	
	return -strcmp(leftStr, rightStr);
}




void insertion_sort( int(function)(const char *leftStr,const char *rightStr) , char **arr , int n) //char **arr, int n, int(function)(const char *leftStr,const char *rightStr))
{
	int right, left; 
	char *temp;
	//use str arrays , not int array from regular sort
	
    for (right = 1; right < n; right++) 
	{ 
        left = right - 1; 
		temp = arr[right]; 
		
		//strcpy(temp,arr[i]);
		//while (j > 0 && function( (dynames+j-1, dynames+j) > 0) ) 
		while(left>=0 && function(temp,arr[left])<0)
		{ 	
			arr[left+1] = arr[left];
			//strcpy(arr[j+1] , arr[j]);
			left = left-1;
			/*
			//have to swap
			//temp = arr[j];
			//printf("%s",temp);
			//arr[j] = arr[i];
			//arr[i] = arr[j];
			strcpy(temp, arr[j]);
			strcpy(arr[j], arr[i]);
			strcpy(arr[i], temp);
			j=j-1;
			*/
		}
		//strcpy(temp, arr[j+1]);
		arr[left+1] = temp;
		//strcpy(arr[i], temp);
			/*
			if( function(arr[j],arr[i]) ==-1)
			{
				//j is left , i is right
				//-1 is if right is greater than left i>j
				//do nothing but move j index
				printf("-1");
				j++;
			}
			else if( function(arr[j],arr[i]) == 0)
			{
				// 0 if they are equal then the numbers are the same, move the j and i index forward
				j++;
				//i++;
				printf("0");
				
				
			}
			else if( function(arr[j],arr[i]) == 1)
			{
				
				//1 if left is greater than right, swap left and right
				//temp = arr[j];
				strcpy(temp, arr[j]);
				//arr[j] = arr[i];
				strcpy(arr[j] , arr[i]);
				//arr[i] = temp;
				strcpy(arr[i],temp);
				
				
				printf("1");
				j++;
			}*/
			
			//printf("out");
	
			/*
            arr[j + 1] = arr[j]; 
            j = j - 1;
			*/
      //  } 
         
    } 
	
	
}


void print(char **dynames,int n)
{
	
	while(*dynames)
	{
		printf("%s",*dynames++);
	}
	
}

int main(int argc, char* argv)
{
	printf("Please enter a file name.-> ");
	
	char* filename = (char *)malloc(sizeof(char)*101);
	scanf("%s",filename);
	//char filename[] = "Hi";
	
	

	FILE* file= fopen(filename,"r");
	FILE* file2 = fopen(filename,"r");
	
	
	
	int numberofnames=0;
	int backup=0;
	char line[101];
	//get number of names in the file
	while(fgets(line,sizeof(line),file))
	{
		numberofnames++;
		//doesntchange = numberofnames;
	}
	
	fclose(file);
	
	backup = numberofnames;
	
	//printf("%d",numberofnames);
	//printf("%d", backup);
	
	
	//create dynamic array to store char arrays(strings)
	char **dynames = malloc((numberofnames)*(sizeof(char*)));
	
	
	char name[101];
	int lengthofname = 0;
	
	//variable to get exact number of chars
	int charcounter=0;
	
	//variable to track where we are in the array
	int a=0;
	int counter = 0;
	int i =0;
	printf("------------------original-------------------\n\n");
	while(!feof(file2))
	{
		
		
		fgets(name,sizeof(name)+1,file2);
		//printf("%s",name);
		
		
		
		//printf("%d",counter);
		
		charcounter = charcounter + strlen(name);
		//printf("%d",strlen(name));
		dynames[a] = malloc(sizeof(char)*sizeof(name)+1);
		//printf("%s",dynames[a]);
		strcpy(dynames[a], name);
		//printf("%s",dynames[a]);
		
		a++;
		
	}
	//printf("%d",charcounter);
	//print(dynames, numberofnames);
	
	int bytes = numberofnames*8;
	
	//int filebytes = strlen(filename) - 2;
	
	int total = bytes + charcounter-28; //+ filebytes;
	
	printf("# of bytes: %d\n",total);
	
	print(dynames, numberofnames);
	
	
	//print length
	printf("\n-------------By LENGTH only-------------\n");
	insertion_sort(comp_length,dynames,numberofnames);
	print(dynames , numberofnames);
	
	//print cmp
	printf("\n------------By CMP only-----------------\n");
	insertion_sort(strcmp,dynames,numberofnames);
	print(dynames , numberofnames);
	
	//print greater
	printf("\n-------------By GREATER only------------\n");
	insertion_sort(comp_greater,dynames,numberofnames);
	print(dynames , numberofnames);
	
	//print mix
	printf("\n--------------By MIX only----------------\n");
	insertion_sort(comp_mixt,dynames,numberofnames);
	print(dynames , numberofnames);
	
	
	fclose(file2);
	for(int k = 0; k<numberofnames;k++)
	{
		free(dynames[k]);
	}
	free(dynames);
	dynames = NULL;
	free(filename);
	filename = NULL;
	
	return 0;
}