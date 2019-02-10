#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

int main()
{
	//Set variables to intialize game
	//Referenced provided code samples
	int numPlayers = 2 ;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int randomSeed = 1000 ;
	struct gameState G;
	struct gameState copyG;
	int testPlayer = 0;
	int otherPlayer = 1;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	//Number of treasure cards which should be added to hand after adventurer used
	int treasureCards;
	//Treasure in hand before adventurer used
	int currentTreasure;

	//Track overall pass or fail
	int overall = 1;

	printf("\n>>>Testing Card: adventurer <<<\n");

	printf("\n......Running Tests......\n");



	//Loop for each test case
	for(int i = 0; i < 5; i++){
		if(i == 0){
			//Intialize a game
			initializeGame(numPlayers,kingdomCards,randomSeed,&G);

			//Update deck to have 0 treasure cards
			for (int i = 0; i < G.deckCount[0]; ++i){
				G.deck[testPlayer][i] = 1;
			}

			//Set treasure cards in deck to 0
			treasureCards = 0;

			//Get current number of treasure cards in hand
			currentTreasure = 0;

			for(int i = 0; i < G.handCount[testPlayer]; i++){
				if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
					//Increase current treasure count by 1
					currentTreasure += 1;
				}
			} 

			//Copy current game state to use later to make sure parts of game state changes correctly
			memcpy(&copyG, &G, sizeof(struct gameState));

			printf("<<Test Case 1: Deck has 0 Treasure cards>>\n");
		}

		else if(i == 1){
			//Clear game state
			memset(&G,23,sizeof(struct gameState));
			memset(&copyG,23,sizeof(struct gameState));

			//Intialize a game
			initializeGame(numPlayers,kingdomCards,randomSeed,&G);

			//Update deck to have 1 treasure cards
			for (int i = 0; i < G.deckCount[0]; ++i){
				if(i == 0){
					G.deck[testPlayer][i] = 4;
				}
				else{
				G.deck[testPlayer][i] = 1;
				}
			}

			//Set treasure cards in deck to 1
			treasureCards = 1;

			//Get current number of treasure cards in hand
			currentTreasure = 0;

			for(int i = 0; i < G.handCount[testPlayer]; i++){
				if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
					//Increase current treasure count by 1
					currentTreasure += 1;
				}
			} 
			//Copy current game state to use later to make sure parts of game state changes correctly
			memcpy(&copyG, &G, sizeof(struct gameState));

			printf("<<Test Case 2: Deck has 1 Treasure card>>\n");			

		}

		else if(i == 2){
			//Clear game state
			memset(&G,23,sizeof(struct gameState));
			memset(&copyG,23,sizeof(struct gameState));

			//Intialize a game
			initializeGame(numPlayers,kingdomCards,randomSeed,&G);

			//Update deck to have 2 treasure cards
			for (int i = 0; i < G.deckCount[0]; ++i){
				if(i == 0){
					G.deck[testPlayer][i] = 4;
				}
				else if(i ==1){
					G.deck[testPlayer][i] = 5;
				}
				else{
				G.deck[testPlayer][i] = 1;
				}
			}

			//Set treasure cards in deck to 2
			treasureCards = 2;

			//Get current number of treasure cards in hand
			currentTreasure = 0;

			for(int i = 0; i < G.handCount[testPlayer]; i++){
				if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
					//Increase current treasure count by 1
					currentTreasure += 1;
				}
			} 
			//Copy current game state to use later to make sure parts of game state changes correctly
			memcpy(&copyG, &G, sizeof(struct gameState));

			printf("<<Test Case 3: Deck has 2 Treasure cards>>\n");			

		}

		else if(i == 3){
			//Clear game state
			memset(&G,23,sizeof(struct gameState));
			memset(&copyG,23,sizeof(struct gameState));

			//Intialize a game
			initializeGame(numPlayers,kingdomCards,randomSeed,&G);

			//Update deck to have 3 treasure cards
			for (int i = 0; i < G.deckCount[0]; ++i){
				if(i == 0){
					G.deck[testPlayer][i] = 4;
				}
				else if(i ==1){
					G.deck[testPlayer][i] = 5;
				}
				else if(i ==2){
					G.deck[testPlayer][i] = 6;
				}
				else{
				G.deck[testPlayer][i] = 1;
				}
			}

			//Set treasure cards in deck to 3
			treasureCards = 3;

			//Get current number of treasure cards in hand
			currentTreasure = 0;

			for(int i = 0; i < G.handCount[testPlayer]; i++){
				if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
					//Increase current treasure count by 1
					currentTreasure += 1;
				}
			} 
			//Copy current game state to use later to make sure parts of game state changes correctly
			memcpy(&copyG, &G, sizeof(struct gameState));

			printf("<<Test Case 4: Deck has 3 Treasure cards>>\n");			

		}		

		else if(i == 4){
			//Clear game state
			memset(&G,23,sizeof(struct gameState));
			memset(&copyG,23,sizeof(struct gameState));

			//Intialize a game
			initializeGame(numPlayers,kingdomCards,randomSeed,&G);

			//Update deck to have 5 treasure cards
			for (int i = 0; i < G.deckCount[0]; ++i){
					G.deck[testPlayer][i] = 4;
			}

			//Set treasure cards in deck to 5
			treasureCards = 5;

			//Get current number of treasure cards in hand
			currentTreasure = 0;

			for(int i = 0; i < G.handCount[testPlayer]; i++){
				if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
					//Increase current treasure count by 1
					currentTreasure += 1;
				}
			} 
			//Copy current game state to use later to make sure parts of game state changes correctly
			memcpy(&copyG, &G, sizeof(struct gameState));

			printf("<<Test Case 4: Deck has 5 Treasure cards>>\n");			

		}



		//Test card using card effect
		cardEffect(adventurer,choice1,choice2,choice3,&G,handpos,&bonus);


		printf("Found Treasures Added to Hand (Hand Count Increased Correctly): ");
		if(copyG.handCount[testPlayer]+ treasureCards == G.handCount[testPlayer]){
			printf("PASSED \n");
		}
		else{
			printf("FAILED - Expected Count: %d  Actual: %d \n",(copyG.handCount[testPlayer] + treasureCards), G.handCount[testPlayer]);	
			overall = 0;
		}


		printf("Found Treasures Added to Hand (Deck Count Decreased Correctly): ");
		if(copyG.deckCount[testPlayer] - treasureCards == G.deckCount[testPlayer]){
			printf("PASSED \n");
		}
		else{
			printf("FAILED - Expected Count: %d  Actual: %d \n",(copyG.deckCount[testPlayer] - treasureCards), G.deckCount[testPlayer]);	
			overall = 0;
		}


		printf("Found Treasures Added to Hand  (Deck + Hand Count Unchanged): ");
		if((copyG.handCount[testPlayer] + copyG.deckCount[testPlayer]) == (G.handCount[testPlayer] + G.deckCount[testPlayer])){
			printf("PASSED \n");
		}
		else{
			printf("FAILED - Expected Count: %d  Actual: %d \n",(copyG.handCount[testPlayer] + copyG.deckCount[testPlayer]), (G.handCount[testPlayer]+G.deckCount[testPlayer]) );
			overall = 0;
		}
	
		printf("Added Cards are Treasure Cards (Current Treasure Count Increased Correctly): ");
		//Use to store treasure currently in had after adventurer
		int treasureInHand = 0;

		for(int i = 0; i < G.handCount[testPlayer]; i++){
			if(G.hand[testPlayer][i] == 4 ||G.hand[testPlayer][i] == 5 ||G.hand[testPlayer][i] == 6){
				//Increase current treasure count by 1
					treasureInHand += 1;
				}
		}		

		if(treasureInHand == currentTreasure + treasureCards){
			printf("PASSED \n");
		}
		else{
			printf("FAILED - Expected Count: %d  Actual: %d \n",(currentTreasure + treasureCards), treasureInHand);
			overall = 0;
		}


		printf("Test Player Discarded adventurer (Discard Pile Contains adventurer): ");
		//Varible for the containing adventurer
		int contains = 0;

		//Loop through player discard pile and check for adventurer
		for(int i = 0; i < G.discardCount[testPlayer]; i++){
			if(G.discard[testPlayer][i] == 7){
				//Card is in discard, set true
				contains = 1;
			}
		}
	
		if(contains == 0){
			printf("FAILED \n");
			overall = 0;
		}
		else{
			printf("PASSED \n");
		}

	

	//Check the game state is unaffected by adventurer by compare previous game state to current game state
	
	printf("Game State Remains Unchanged (Other Player's Hand Count is Unchanged): ");
	//check other player's hand count is the same as before adventurer was used
	if(copyG.handCount[otherPlayer] == G.handCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Hand Count: %d , Actual: %d \n", copyG.handCount[otherPlayer], G.handCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Other Player's Deck Count is Unchanged): ");
	//check other player's deck count is the same as before adventurer was used
	if(copyG.deckCount[otherPlayer] == G.deckCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Deck Count: %d , Actual: %d \n", copyG.deckCount[otherPlayer], G.deckCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Other Player's Discard Count is Unchanged): ");
	//check other player's discard count is the same as before adventurer was used
	if(copyG.discardCount[otherPlayer] == G.discardCount[otherPlayer]){
		printf("PASSED \n");
	}
	else{
		printf("FAILED - Expected Discard Count: %d , Actual: %d \n", copyG.discardCount[otherPlayer], G.discardCount[otherPlayer]) ;
		overall = 0;
	}


	printf("Game State Remains Unchanged (Supply Count for Victory Cards is Unchanged): ");
	//varible to track supply is unchanged
	int supplyUnchanged = 1;

	//Check count of all victory cards
	if(supplyCount(estate, &copyG) != supplyCount(estate, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Estate Count: Expected: %d Actual:%d \n",supplyCount(estate,&copyG), supplyCount(estate, &G) );
	}
	if(supplyCount(duchy, &copyG) != supplyCount(duchy, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Duchy Count: Expected: %d Actual:%d \n",supplyCount(duchy,&copyG), supplyCount(duchy, &G) );
	}	
	if(supplyCount(province, &copyG) != supplyCount(province, &G)){
		supplyUnchanged = 0;
		printf("FAILED For Province Count: Expected: %d Actual:%d \n",supplyCount(province,&copyG), supplyCount(province, &G) );
	}
	

	if(supplyUnchanged == 1){
		printf("PASSED\n");
	}


	printf("Game State Remains Unchanged (Supply Count for Coin Cards is Unchanged): ");
	//varible to track supply is unchanged
	supplyUnchanged = 1;

	//Check count of all coins
	if(supplyCount(copper, &copyG) != supplyCount(copper, &G)){
		supplyUnchanged = 0;
		printf("FAILED For copper Count: Expected: %d Actual:%d \n",supplyCount(copper,&copyG), supplyCount(copper, &G) );
	}
	if(supplyCount(silver, &copyG) != supplyCount(silver, &G)){
		supplyUnchanged = 0;
		printf("FAILED For silver Count: Expected: %d Actual:%d \n",supplyCount(silver,&copyG), supplyCount(silver, &G) );
	}
	if(supplyCount(gold, &copyG) != supplyCount(gold, &G)){
		supplyUnchanged = 0;
		printf("FAILED For gold Count: Expected: %d Actual:%d \n",supplyCount(gold,&copyG), supplyCount(gold, &G) );
	}

	if(supplyUnchanged == 1){
		printf("PASSED\n");
	}

	printf("Game State Remains Unchanged (Supply Count for All Kingdom Cards is Unchanged): ");
	//varible to track supply is unchanged
	supplyUnchanged = 1;

	//Check each kingdom card
	for(int i = 0; i < 10; i++){
		if(supplyCount(kingdomCards[i], &copyG) != supplyCount(kingdomCards[i], &G)){
			supplyUnchanged = 0;
			printf("FAILED For kingdom Card %d Count: Expected: %d Actual:%d \n",i ,supplyCount(kingdomCards[i],&copyG), supplyCount(kingdomCards[i], &G) );
		}
	}

	if(supplyUnchanged == 1){
		printf("PASSED\n\n");
	}
	
}

	//Finished Result
	if(overall == 0){
		printf(">>>Testing of adventurer FAILED <<<\n");
	}

	else{
		printf(">>>Testing of adventurer PASSED <<<\n");
	}

	return 0;
}
