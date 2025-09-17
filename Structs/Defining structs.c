/* Definining structs */ 

#include <stdio.h>

struct card {
	char *face ; /* define pointer face */ 
	char *suit ; /* define pointer suit */ 
};

int main(void)
{
	struct card MyCard; /* define one struct card variable */ 

	/* place strings into the card */
	MyCard.face = "Ace";
	MyCard.suit = "Spades";

	struct card *cardPtr = &MyCard; /* assign address of a card to cardPtr */ 

	printf("%s%s%s\n%s%s%s\n%s%s%s\n", MyCard.face, " of ", MyCard.suit,
cardPtr->face, " of ", cardPtr->suit,
	(*cardPtr).face, " of ", (*cardPtr).suit);
	return 0;
}
