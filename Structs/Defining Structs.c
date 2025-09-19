/* Implementation of structs */ 

#include <stdio.h>

/* card structure definition */ 
struct card 
{
	/* define pointer face and suit */ 
	const char* face;
	const char* suit;
};

int main(void)
{
	struct card mycard ; /* define one struct card variable */ 

	/* placing values to struct member */ 
	mycard.face = "Ace";
	mycard.suit = "Spades";

	struct card *cardptr = &mycard;

	printf("%s of %s\n", mycard.face, mycard.suit);
	printf("%s of %s\n", cardptr->face, cardptr->suit);
	printf("%s of %s\n", (*cardptr).face, (*cardptr).suit);
}
