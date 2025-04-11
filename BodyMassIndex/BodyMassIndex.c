#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __RECORD record;

struct __RECORD{
    int weight;             //in kg
    float height;          //in cm
};


int main(void){
    int dataN;          //inputted data
    int i;
    float bmi;

    printf("Input data:\n");
    scanf("%d", &dataN);

    record* container = (record*)calloc(dataN, sizeof(record));
    
    i=0;
    for(i;i<dataN;i++){
        scanf("%d %f", &container[i].weight, &container[i].height);           //we store the weight and height in the container
    }

    i=0;
    for(i;i<dataN;i++){
       bmi = (float)container[i].weight / pow(container[i].height, 2.0);
        
        if(bmi < 18.5)
        printf("under ", bmi);
        else if(bmi >= 18.5 && bmi < 25.0)
        printf("normal ", bmi);
        else if(bmi >= 25.0 && bmi < 30.0)
        printf("over ", bmi);
        else if(bmi >= 30.0)
        printf("obese ",bmi);
    }
    
    free(container);
} 