#include<stdio.h>
#include<string.h>

struct Activity {
    int start, finish;
    char name;
};
int count = 0; int M = 0;
int activityCompare(struct Activity s1, struct Activity s2) {// Compare function for qsort()
    return s1.finish - s2.finish;
}

void printMaxActivities(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), activityCompare); // sort the activities by finish time

    int i = 0;
    printf("\n\nSelected Activities: \n");
    printf("\n%c ", activities[i].name);
    count++;

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("\n%c ", activities[j].name);
            count++;
            i = j;
        }
    }
}
int main() {

    printf("The charge for each activity: ");
    scanf("%d", &M);

    int n;
    printf("Enter the no. of activity:");
    scanf("%d", &n);

    int finishCal = 0;

    struct Activity activities[n];

    printf("Enter the start time and duration:");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &activities[i].name, &activities[i].start, &finishCal);
        activities[i].finish = finishCal+activities[i].start;
    }

    for (int i = 0; i < n; i++) {
    printf("\nName: %c, Start: %d, Finish: %d", activities[i].name, activities[i].start, activities[i].finish);
    }

    printMaxActivities(activities, n);

    int profit = M*count;

    printf("\n\nThe profit: %d", profit);
    return 0;
}
