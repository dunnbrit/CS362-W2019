#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

int main(){

	//Setup variables
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState pre;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int testCard = smithy;

	//Random Variables
	int randomSeed;
	int players;
	int p;

	//Test Tracking
	int overall = 1;
	int handCountTest = 1;
	int handCountFail = 0;
	int deckCountTest = 1;
	int deckCountFail = 0;
	int handTest = 1;
	int handFail = 0;
	int numberHandFail = 0;
	int r;

	printf("Testing smithy\n");	

	//Number of Iterations of Test 
	for(int n = 0; n < 2000; n++){

		//Get random number of players
		players = rand() % MAX_PLAYERS + 1;
		//Get randomSeed
		randomSeed = rand();

		//Intialize gameState
		initializeGame(players, kingdomCards, randomSeed,&pre);
		
		//Randomize a sane gameState
		//Choose player for random test
		p = floor(Random() * players); 
		pre.whoseTurn = p;
		//Set deckCount within max range (min of 3 cards to draw from)
		pre.deckCount[p] = floor(Random() * MAX_DECK) + 3;
		for(int i = 0; i < pre.deckCount[p]; i++){
    		//Fill deck with valid cards
    		pre.deck[p][i] = floor(Random() * 28);
    	}
		//Set discardCount within max range
		pre.discardCount[p] = floor(Random() * MAX_DECK);
    	for(int i = 0; i < pre.discardCount[p]; i++){
    		//Fill discard with valid cards
    		pre.discard[p][i] = floor(Random() * 28);
    	}
		//Set handCount within max range
		pre.handCount[p] = floor(Random() * MAX_HAND);
    	for(int i = 0; i < pre.handCount[p]; i++){
    		//Fill hand with valid cards
    		pre.hand[p][i] = floor(Random() * 28);
    	}
		
		//Testing of Smithy

		//Create a copy of pre
		struct gameState post;
		memcpy(&post, &pre, sizeof(struct gameState));

		//Call card effect to play test card: smithy
		r = cardEffect(testCard, choice1, choice2, choice3, &post, handpos, &bonus);

		//Update pre to expected results of playing card smithy
		for(int i = 0; i < 3; i++){
			//Increase handCount
			pre.handCount[p]++;
			//Move card from deck to hand
    		pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p] -1];
    		//Decrease deckCount
    		pre.deckCount[p]--;
		}



		//Check cardEffect returned 0
		assert(r == 0);

		//Check hand count is correct
		if(pre.handCount[p] != post.handCount[p]){
			//If not, test failed
			handCountTest = 0;
			overall = 0;
			++handCountFail;
		}

		//Check deck count is correct
		if(pre.deckCount[p] != post.deckCount[p]){
			//If not, test failed
			deckCountTest = 0;
			overall = 0;
			++deckCountFail;
		}

		//Check hand contains correct cards
		//set handFail to false
		handFail = 0;
		//compare pre and post hands
		for(int i = 0; i < pre.handCount[p] ; i++){
			if(pre.hand[p][i] != post.hand[p][i]){
				overall = 0;
				handTest = 0;
				handFail = 1;
			}
		}
		//If failed
		if(handFail == 1){
			++numberHandFail;
		}
	}

	//Results of tests

	if(overall == 1){
		printf("Tests for smithy: ALL PASSED \n");
	}
	else{
		printf("Tests for smithy: FAILED \n");
		if(handCountTest == 0){
			printf("	Increase Hand Count Correctly Test: FAILED %d/2000 \n", handCountFail);
		}
		if(deckCountTest == 0){
			printf("	Decrease Deck Count Correctly Test: FAILED %d/2000 \n", deckCountFail);
		}
		if(handTest == 0){
			printf("	Correct Cards in Hand: FAILED %d/2000\n", numberHandFail );
		}
	}

	return 0;
}