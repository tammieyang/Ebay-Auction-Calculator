//Tammie Yang 
//This implements different functions to read through arrays and perform what the function is supposed to do.

#include <iostream>
#include <string>
#include <climits>
#include <cassert>

using namespace std;
int findMinimum(const string array[], int n); //defining all the functions
int countAllPunctuation(const string array[], int n);
int countFloatingPointValues(const string array[], int   n);
int removeDuplicatedValues(string array[], int  n);
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill);
int shiftRight(string array[], int n, int amount, string   placeholder);



int findMinimum(const string array[], int n)  //finds the lowest character in accordance with the ASCII table (or earliest letter) in the array
{
	int place = 0;
	int i = 0;						
	string minimum = array[0];
	if (n <= 0)
	{
		return -1;
	}
	for (i = 0; i < n; i++) //parse through the strings in the array
	{
		string entry = array[i]; //keep redefining variable entry
		if (entry < minimum)
		{
			minimum = array[i]; //set minimum to whatever is the 'smallest'
			place = i; //record the position of the minimum
		}
		
	}
	return place;
}

int countAllPunctuation(const string array[], int n) //finds, counts, and returns all the punctuation marks in the array 
{
	int i = 0;
	int total = 0;
	if (n <= 0)
	{
		return -1;
	}
	for (i = 0; i < n; i++) //parse through the strings in the array
	{
		string entry = array[i];
		int length = entry.size();
		for (int k = 0; k < length; k++) //parse through the characters in the string
		{
			if (entry[k] == '.' || entry[k] == ',' || entry[k] == 33 /*exclamation*/ || entry[k] == 59 /*;*/ || entry[k] == 45 /*-*/ || entry[k] == 47 /*/*/ || entry[k] == 58 /*:*/ || entry[k] == 63/*?*/ || entry[k] == 34/*"*/|| entry[k]==39)
				total++; 
		}
	}
	return total;
}

int countFloatingPointValues(const string array[], int n) //counts and returns the number of floating values in the array
{
	int i = 0;
	int total = 0;
	bool floatingValue = true;
	int decimalCount = 0;
	int k = 0;
	if (n <= 0)
	{
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		string entry = array[i]; //define a string variable to be whatever string of the array
		int length = entry.size(); //get its length
		
		for (k = 0; k < length; k++) //parse through the string to read through characters
		{
			
			if (floatingValue == false) //if it's not a floating value, break out of the loop to go to next string in the array
			{
				floatingValue = true;
				break;
			}
			char c = entry[k]; //define a character to be whatever character in the string
			//cerr << c; used to debug and check
			switch (c)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				if (k==length-1) //if c is the last character in the string
				{
					total++;
					decimalCount = 0;
					floatingValue = true;
					break;
				}
				break;
			}
			case '.':
			{
				decimalCount++;
				if (decimalCount > 1 && k==length-1)
				{
					floatingValue = true;
					decimalCount = 0; //making sure decimalCount resets for the next string in the array
					break;
				}
				else if (decimalCount > 1)
				{
					floatingValue = false;
					break;
				}
				if (k == length - 1 && length == 1) //single decimal case
				{
					decimalCount = 0;
					floatingValue = true;
					break;
				}
				else if (k == length - 1) //if c is the last character in the string
				{
					total++;
					decimalCount = 0;
					floatingValue = true;
					break;
				}
				break;
			}
			default: //if it's not a number or decimal point, break out of the loop
			{
				
				floatingValue = false;
				if (decimalCount > 0)
				{
					decimalCount = 0;
				}
				if (k == length - 1)
				{
					floatingValue = true;
					decimalCount = 0;
				}
				break;
			}
			

			}
		}
	}

	return total;
}

int removeDuplicatedValues(string array[], int  n) //removes the duplicated words or numbers in the arrays and counts and returns the number of repeats
{
	int i = 0;
	int duplicates = 0;
	if (n <= 0)
	{
		return -1;
	} 
	int k = 0; 
	
	for (i = 1; i < n; i++) //comparing values behind initial i to it, kind of like working backwards
	{
		for (k = 0; k < i; k++) 
		{
			if (array[k] == array[i]) //if they are the same, replace the one closer to the end of the string with an empty string
			{
				array[i]= "";
			}
		}
	}
	
	
	for (i = 0; i < n; i++) //count how many empty strings there are for the number of duplicates
	{
		if (array[i] == "")
		{
			duplicates++;
		}
	}
	
	for (i = n - 1; i >= 0; i--) //shifting stuff to the left
	{
		for (int l = 1; l < i; l++)
		{
			if (array[i] != "" && array[i - l] == "") //make sure array isn't empty, and that the one before it is
			{
				if (i - l >= 0) //make sure it doesn't go out of bounds
				{
					array[i - l] = array[i]; //making empty string equal value before it
					array[i] = ""; // making string before it empty
				}
			}
		}

	}
	
	/*for (i = 0; i < n; i++) //printing out array to make sure the function was right
	{
		//cerr << array[i]<< endl;
	}*/
	return duplicates;
}
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill) //parses through array to replace all specified characters with other specified characters, returns how many it replaced
{
	int i = 0;
	
	int replaced = 0; //how many characters were replaced
	if (n <= 0)
	{
		return -1;
	}
	char c = letterToReplace; //define characters
	char d = letterToFill;
	
	for (i = 0; i < n; i++)
	{
		string entry = array1[i]; //set a variable to the string
		int length = entry.size(); //get length of the string
		for (int k = 0; k < length; k++) //parse through characters in the string to check for and replace specified characters
		{
			if (entry[k] == c)
			{
				entry[k] = d;
				replaced++;
			}
			array1[i] = entry; //set array to new supposed string
		}
	}
	/*for (i = 0; i < n; i++) //used to print out array and check if it's right
	{
		cerr << array1[i] << endl;
	}*/
	return replaced;
}

int shiftRight(string array[], int n, int amount, string   placeholder) //shifts the string to the right
{
	int i = n-1;
	int timesUsed = 0; //timesUsed is how many times strings were replaced by placeholder
	if (n <= 0)
	{
		return -1;
	}
	
	if (amount < 0)
	{
		return -1;
	}
	if (amount == 0)
	{
		return 0;
	}

	for (i = n - 1; i >= 0; i--) //shifting values to the right
	{
		if (amount + i >= n) //making sure doesn't go out of bounds
		{
			array[i] = placeholder; //set it to placeholder
		}
		else if (amount +i < n) //if it's in the defined conditions
		{
			if (array[i + amount] == placeholder)
			{
				array[i + amount] = array[i];
				array[i] = placeholder;
			}
			else 
			{
				array[i + amount] = array[i];
				array[i] = placeholder;
			}
			
		}
	}

	for (i = 0; i < n; i++) //count how many resultant placeholders there were
	{
		if (array[i] == placeholder) 
		{
			timesUsed++;
		}
		//cerr << array[i] << endl; //used to print out and confirm
	}
	return timesUsed;
}

int main() {
	 
	//writing strings to test with asserts
	string a[6] = { "al.p,h!a", "b-e'mta", "ga?m:ma", "gamma", "beta", "delta" };
	string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
	string c[6] = { "del-/ta", "g;am\"ma", "beta", "alpha", "beta", "alpha" };
	string data[4] = { "4.4.3.3", "44", "33.098", "33.098a" };
	string people[5] = { "Mom" , "Dad",  "Sister" , "Brother", "Weird Uncle no one likes" };
	string d[3] = { "pencils", "cell", "code" };
	string e[3] = { "pe.n,c!i;l's", "c-/:e?\"ll", "code" };
	string f[5] = { "1.", ".0123", "1", "", "asdqwe" };
	string g[5] = { "1", "2" , "1", "3", "2" };
	string h[5] = { "1", "3." , ".", "01.23", "2" };
	string i[3] = { "AA", "a", "b" };
	string j[3] = { "0.1", "-0.1", "0" };
	string k[3] = {"1./-;", "..." , "\\\\"};
	string l[3] = {"!wef!", "?asdq/" , "qqweeee,':; " };
	string m[7] = { "", "0", "1.", ".", ".a", ".123q", "0!" };
	string n[6] = { "buddy", "old", "pal", "pal", "sucks", "old" };
	string o[6] = { "hell", "heaven",  "hell", "a sauna", "hell", "engineering" };
	assert(countAllPunctuation(a, 6) ==7);
	assert(countAllPunctuation(c, 6) == 4);
	assert(countAllPunctuation(a, -14) == -1);
	assert(countAllPunctuation(d, 3) == 0);
	assert(countAllPunctuation(data, 4) == 5);
	assert(countAllPunctuation(e, 3) == 10);
	assert(countAllPunctuation(j, 3) == 3);
	assert(countAllPunctuation(i, 3) == 0);
	assert(countAllPunctuation(k, 3) == 7);
	assert(countAllPunctuation(l, 3) == 8);
	assert(findMinimum(a, 3) == 0);
	assert(findMinimum(b, 3) == 2);
	assert(findMinimum(c, 4) == 3);
	assert(findMinimum(d, 3) == 1);
	assert(findMinimum(d, 0) == -1);
	assert(findMinimum(e, 3) == 1);
	assert(findMinimum(f, 3) == 1);
	assert(findMinimum(people, 4) == 3);
	assert(findMinimum(i, 3) == 0);
	assert(findMinimum(j, 3) == 1);
	assert(countFloatingPointValues(data, 0) == -1);
	assert(countFloatingPointValues(a, 6) == 0);
	assert(countFloatingPointValues(h, 5) == 4);
	assert(countFloatingPointValues(m, 7) == 2);
	assert(countFloatingPointValues(data, 4) == 2);
	assert(countFloatingPointValues(f, 5) == 3);
	assert(removeDuplicatedValues(n, 6) == 2);
	assert(removeDuplicatedValues(l, 3) == 0);
	assert(removeDuplicatedValues(b, 0) == -1);
	assert(removeDuplicatedValues(b, 6) == 2); 
	assert(removeDuplicatedValues(g, 5) == 2);
	assert(removeDuplicatedValues(o, 6) == 2);

	assert(replaceAll(d, 0, 'e', 'a') == -1);
	assert(replaceAll(d, 3, 'p', 'a') == 1); 
	assert(replaceAll(d, 3, 'c', 'C') == 3);
	assert(replaceAll(people, 5, 'o', 'O') == 4);
	assert(replaceAll(m, 7, '1', '!') == 2);
	assert(shiftRight(d, 0, 2, "lol") == -1);
	assert(shiftRight(d, 3, 2, "lol") == 2);
	assert(shiftRight(e, 3, 1, "okay") == 1);
	assert(shiftRight(people, 5, 25, "foo") == 5);
	assert(shiftRight(people, 5, 3, "dork") == 3);
	assert(shiftRight(o, 6, 3, "dork") == 3);
	

	
	
}