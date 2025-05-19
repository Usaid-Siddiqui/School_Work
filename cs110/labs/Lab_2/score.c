#include <stdio.h>

int main(){

    //inputs
    int score1, score2, score3, score4, lowestscore=0;
    printf("Enter your your four scores: \n");
    scanf("%d %d %d %d", &score1, &score2, &score3, &score4);

    //finding lowest score
    if (score1<=score2 && score1<=score3 && score1<=score4) {
        lowestscore=score1;
    }
    else if (score2<=score1 && score2<=score3 && score2<=score4){
        lowestscore=score2;
    }
    else if (score3<=score1 && score3<=score2 && score3<=score4){
        lowestscore=score3;
    }
    else if (score4<=score1 && score4<=score2 && score4<=score3){
        lowestscore=score4;
    }

    //calculations
    double avgscore;
    avgscore = (score1+score2+score3+score4-lowestscore)/3.0;

    //output
    printf("%lf\n", avgscore);

    // testing integers printf("%d, %d, %d, %d, %d\n", score1, score2, score3, score4, lowestscore);

}