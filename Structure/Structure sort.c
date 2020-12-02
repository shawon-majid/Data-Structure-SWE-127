//Bismillahir Rahman-ir Rahim
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
	int reg_number;
	int solved;
	double cgpa;
}student;

int main()
{

    int n;
    scanf("%d", &n);
	student ara[n];
	for(int i = 0 ; i < n; i++){
		scanf("%d %d %lf", &ara[i].reg_number, &ara[i].solved, &ara[i].cgpa);
	}

	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(ara[i].solved == ara[j].solved){
				if(ara[i].cgpa == ara[j].cgpa){
                    if(ara[i].reg_number > ara[j].reg_number){
                        student temp;
                        temp = ara[j];
                        ara[j] = ara[i];
                        ara[i] = temp;
                    }
				}
				else{
                    if(ara[i].cgpa < ara[j].cgpa){
                        student temp;
                        temp = ara[j];
                        ara[j] = ara[i];
                        ara[i] = temp;
                    }
				}
			}
			else{
				if(ara[i].solved < ara[j].solved){
					student temp;
					temp = ara[j];
					ara[j] = ara[i];
					ara[i] = temp;
				}
			}
		}
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d %d %.2lf\n", ara[i].reg_number, ara[i].solved, ara[i].cgpa);
	}


    return 0;
}



