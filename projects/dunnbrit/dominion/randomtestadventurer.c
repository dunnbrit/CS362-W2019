#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

int main(){

	//Setup variables
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState pre;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int testCard = adventurer;

	//Random Variables
	int randomSeed;
	int players;
	int p;
	int treasures;

	//Test Tracking
	int overall = 1;
	int handCountTest = 1;
	int zero = 0;
	int one = 0;
	int two = 0;
	int greater = 0;
 	int treasureZero = 0;
 	int treasureOne = 0;
 	int treasureTwo = 0;
 	int treasureGreater = 0;
 	int deckCountTest = 1;
 	int deckZero = 0;
 	int deckOne = 0;
 	int deckTwo = 0;
 	int deckGreater = 0;
 	int handZero = 0;
 	int handOne = 0;
 	int handTwo = 0;
 	int handGreater = 0;
 	int handTest = 1;
 	int handFail = 0;

	printf("Testing adventurer\n");	

	//Number of Iterations of Test 
	for(int n = 0; n < 2000; n++){

		//Get random number of players
		players = rand() % MAX_PLAYERS + 1;
		//Get randomSeed
		randomSeed = rand();

		//Intialize gameState
		initializeGame(players, kingdomCards, randomSeed, &pre);
		
		//Randomize a sane gameState
		//Choose player for random test
		p = floor(Random() * players); 
		pre.whoseTurn = p;
		//Set deckCount within max range (deck must have at least 5 because of random treasures)
		pre.deckCount[p] = floor(Random() * (MAX_DECK - 5)) + 5;
		for(int i = 0; i < pre.deckCount[p]; i++){
    		//Fill deck with valid cards that are not treasures
    		pre.deck[p][i] = floor(Random() * 21) + 7;
    	}
		//Set discardCount within max range
		pre.discardCount[p] = floor(Random() * MAX_DECK);
    	for(int i = 0; i < pre.discardCount[p]; i++){
    		//Fill discard with valid cards that are not treasures
    		pre.discard[p][i] = floor(Random() * 21) + 7;
    	}
		//Set handCount within max range
		pre.handCount[p] = floor(Random() * MAX_HAND);
    	for(int i = 0; i < pre.handCount[p]; i++){
    		//Fill hand with valid cards that are not treasures
    		pre.hand[p][i] = floor(Random() * 21) + 7;
    	}


		//Get random number of treasures 
		treasures = floor(Random() * 5);
		//Set greater than 2 to false
		int greaterThan2 = 0;
		//Track treausre counts
		if(treasures == 0){
			++treasureZero;
		}
		else if(treasures == 1){
			++treasureOne;
		}
		else if(treasures == 2){
			++treasureTwo;
		}
		else{
			++treasureGreater;
		}
		//Update deck to have random number of treasures
		for(int i = 0; i < treasures; i++){
			//Add a treasure
			pre.deck[p][i] = floor(Random() * 3) + 4;
		}


		//Testing of Adventurer

		//Create a copy of pre
		struct gameState post;
		memcpy(&post, &pre, sizeof(struct gameState));

		//Call card effect to play adventurer
		cardEffect(testCard, choice1, choice2, choice3, &post, handpos, &bonus);	

		//If treasure is greater than 2
		if (treasures > 2){
			//Then set treasures to 2
			treasures = 2;
			//Set greater than 2 to true
			greaterThan2 = 1;
		}		

		//Update pre to expected results of playing card adventurer
		for(int i = 0; i < treasures; i++){
			//Increase handCount
			pre.handCount[p]++;
			//Move card from deck to hand
    		pre.hand[p][pre.handCount[p]-1] = pre.deck[p][i];
    		//Decrease deckCount
    		pre.deckCount[p]--;
		}

		//Test Treasures added to hand

		//Check hand count is correct
		if(pre.handCount[p] != post.handCount[p]){
			//If not, test failed
			handCountTest = 0;
			overall = 0;

			//Mark fail at which treasure count
			if(treasures == 0){
				++zero;
			}
			else if(treasures == 1){
				++one;
			}
			else if(treasures == 2 && greaterThan2 == 0){
				++two;
			}
			else{
				++greater;
			}
	
		}

		//Check hand contains correct number of treasure
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
		//If failed mark where
		if(handFail == 1){
			if(treasures == 0){
				++handZero;
			}
			else if(treasures == 1){
				++handOne;
			}
			else if(treasures == 2 && greaterThan2 == 0){
				++handTwo;
			}
			else{
				++handGreater;
			}
		}

		//Test Treasure subtracted from deck

		//Check deck count is correct
		if(pre.deckCount[p] != post.deckCount[p]){		

			//If not, test failed
			deckCountTest = 0;
			overall = 0;

			//Mark fail at which treasure count
			if(treasures == 0){
				++deckZero;
			}
			else if(treasures == 1){
				++deckOne;
			}
			else if(treasures == 2 && greaterThan2 == 0){
				++deckTwo;
			}
			else{
				++deckGreater;
			}
		}


	}

	//Results of tests

	if(overall == 1){
		printf("Tests for adventurer: ALL PASSED \n");
	}
	else{
		printf("Tests for adventurer: FAILED \n");
		if(handCountTest == 0){
			printf("	Increase Hand Count Correctly Test: FAILED %d/2000 \n", zero + one + two + greater);
			printf("		Test Failed %d/%d times for Zero Tresure in Deck\n", zero, treasureZero);
			printf("		Test Failed %d/%d times for One Tresure in Deck\n", one, treasureOne);
			printf("		Test Failed %d/%d times for Two Tresure in Deck\n", two, treasureTwo);
			printf("		Test Failed %d/%d times for Greater Than 2 Tresure in Deck\n", greater, treasureGreater);
		}
		if(deckCountTest == 0){
			printf("	Decrease Deck Count Correctly Test: FAILED %d/2000 \n", deckZero + deckOne + deckTwo + deckGreater);
			printf("		Test Failed %d/%d times for Zero Tresure in Deck\n", deckZero, treasureZero);
			printf("		Test Failed %d/%d times for One Tresure in Deck\n", deckOne, treasureOne);
			printf("		Test Failed %d/%d times for Two Tresure in Deck\n", deckTwo, treasureTwo);
			printf("		Test Failed %d/%d times for Greater Than 2 Tresure in Deck\n", deckGreater, treasureGreater);
		}
		if(handTest == 0){
			printf("	Hand Contains Correct Cards Test: FAILED %d/2000 \n", handZero + handOne + handTwo + handGreater);
			printf("		Test Failed %d/%d times for Zero Tresure in Deck\n", handZero, treasureZero);
			printf("		Test Failed %d/%d times for One Tresure in Deck\n", handOne, treasureOne);
			printf("		Test Failed %d/%d times for Two Tresure in Deck\n", handTwo, treasureTwo);
			printf("		Test Failed %d/%d times for Greater Than 2 Tresure in Deck\n", handGreater, treasureGreater);
		}

	}












return 0;

}