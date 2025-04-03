#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 100

/*
	Code Abbey - Palindromes problem
*/

//Character filtering
//Returns 0 if ignored
//Returns lower case if lower case
//Returns lower case if upper case (convert)
char chr_filter(char t);

//Pallindrome Function
int isPallindrome(char* text);

int main(void){
	char container[STR_SIZE] = "123abc321";

	if (isPallindrome(container))
		printf("it is not a pallindrome");
		
	else		
		printf("it is pallindrome");
	

	return 0;
}


int isPallindrome(char* text) {
	if (strlen(text) > STR_SIZE)
		return 0;

	int i, f;
	int size = strlen(text)+1; 
	int isPallin;
	//Create the origin text container
	char* orig = (char*)calloc(size, sizeof(char));
	char* filter = (char*)calloc(size, sizeof(char));
	char* pallin = (char*)calloc(size, sizeof(char));
	

	strcpy_s(orig, size, text);
	
	
	//Character filtering 
	f = 0;
	char r;
	for (i = 0; i <= size; i++) {
		if (r = chr_filter(orig[i])) {
			filter[f] = r;
			f++;
		}


	}
	i = strlen(filter)-1;
	f = 0;
	for (i; i >= 0; i--) {
		pallin[f] = filter[i];
		f++;
	}
	
	isPallin = strcmp(filter, pallin);
	free(filter);
	free(orig);
	free(pallin);

	return isPallin;
}



char chr_filter(char t) {
	if (t >= 97 && t <= 122) {
		return t;
	}
	else if (t >= 65 && t <= 90) {
		t = tolower(t);
		return t;
	}
	else {
		return 0;
	}

}

