#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
void input_showing(int num)
{
	if (num == 1)
		printf(" choosed Stone !\n");
	else if (num == 2)
		printf(" choosed Paper !\n");
	else
		printf(" choosed Scissors !\n");
}
int find_who_win(int num_ch_by_comp, int num_ch_by_you)
{
	if (num_ch_by_comp == num_ch_by_you) {
		printf("Its Tie\n");
		return 0;
	} else if (num_ch_by_you == 1 && num_ch_by_comp == 3) {
		printf("You Won!\n");
		return 1;
	} else if (num_ch_by_you == 3 && num_ch_by_comp == 1) {
		printf("Computer Won!\n");
		return -1;
	} else if (num_ch_by_you > num_ch_by_comp) {
		printf("You Won!\n");
		return 1;
	} else if (num_ch_by_comp > num_ch_by_you) {
		printf("Computer Won!\n");
		return -1;
	}
	return 0;
}
void st_pap_sci_game()
{
	bool gameover = false;
	int points_of_player = 0, points_of_comp = 0, x = 0, num_ch_by_you = 0, num_ch_by_comp = 0, youwin;
	printf("Welcome to the game\n");
	printf("press 1 for stone\npress 2 for paper\npress 3 for scissors\n");
	while (gameover != true) {
		
		printf("Enter your turn\n");
		/* take input num and then choose the computer num for computer */
		if ((x = scanf("%d",&num_ch_by_you)) == 0) {
			printf("Enter the Number or valid input\n");
			break;
		} else if (x == -1) {
			printf("EOF Detected\n");
			exit(1);
		}
		if (num_ch_by_you > 3 || num_ch_by_you < 1) {
			printf("Please enter a valid input\n");
			continue;
		} else {
			printf("You");
			input_showing(num_ch_by_you);
			printf("Computer is choosing");
			for(int i = 0; i < 5; i++) {
				printf(".");
				sleep(1);
				fflush(stdout);
			}
			printf("\n");
			num_ch_by_comp = (rand() % 3) + 1;
			printf("Computer");
			input_showing(num_ch_by_comp);
			youwin = find_who_win(num_ch_by_comp, num_ch_by_you);
			if (youwin == 1)
				points_of_player++;
			else if (youwin == -1)
				points_of_comp++;
		}
		if (points_of_comp >= 2 || points_of_player >= 2) {
			if (points_of_player > points_of_comp) {
				printf("You Won the Match!\n");
			} else {
				printf("Computer Won the Match!\n");
			}
			gameover = true;
		}
	}
}
int main()
{
	//Stone_paper_scissors
	st_pap_sci_game();

}
