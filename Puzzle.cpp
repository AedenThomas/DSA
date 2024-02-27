// A gas station inspector needs to inspect n > 1 gas stations located
// equidistantly along a straight highway. The stations are numbered
// consecutively from 1 to n. The inspector starts at station 1, which he
// will need to visit one more time. He will also need to visit station n twice,
// where he may but does not have to finish his tour. As to stations 2 through
// n- 1, he needs to inspect them an equal number of times. For exe,
// he might go from station 1 to station n, turn back and return to station 1,
// and then go to station n again to complete his task there. (It is assumed,
// of course, that the inspector visits the stations every time he passes them.)
// The question is whether this is the shortest tour possible that satisfies all
// the requirements stated. If it is, prove it: if it is not, find the shortest one.

#include <iostream>


using namespace std;
typedef struct node
{
    int station_no;
    struct node *prev;
    struct node *next;
} ab;
ab *head, *tempptr, *ptr;
int total_distance = 0;
void createhighway(int num)
{
    // creation of the doubly linked list to imitate the 2 way highway with incomings and outgoings from a particular gas station
    head = (ab *)malloc(sizeof(ab)); // head is the first gas station
    head->station_no = 1;
    head->prev = NULL;
    head->next = NULL;
    tempptr = head;
    ptr = head; // ptr is the current gas station
    for (int i = 2; i <= num; i++)
    {
        tempptr->next = (ab *)malloc(sizeof(ab)); // tempptr is the previous gas station
        tempptr->next->station_no = i;
        tempptr->next->next = NULL;
        tempptr->next->prev = tempptr;
        tempptr = tempptr->next;
    }
    tempptr = head; // tempptr ptr and head pointing at the first gas station right now
}

void output(int visited[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << visited[i] << "       ";
    }
    cout << endl;
}

void findEvenPath(int visited[], int num)
{
    int i = 0;
    while (i < num) // helps in taking into consideration the pair of stations and their path
    {
        if (i == num - 1) // breaking the loop when the last station is reached.
            break;
        if (i % 2 == 0) // pair of stations which are even numbered
        {
            for (int j = 0; j < 3; j++) // pair of stations and the total number of times each station has been visited.
            {
                // If the station number is equal to the station number of the station that is being considered,
                // then the distance is incremented by 1.
                // If the station number is not equal to the station number of the station that is being considered,
                // then the distance is not incremented and the pointer is set to the station that is being considered.
                if (ptr->station_no != tempptr->station_no)
                {
                    ptr = tempptr; // returning back to the first station of the pair taken into consideration
                    total_distance++;
                    continue;
                }
                // total number of times the first station of the pair is increased by one
                visited[i]++;
                ptr = tempptr->next;
                total_distance++;
                // total number of times the second station of the pair is increased by one
                visited[i + 1]++;
            }
            output(visited, num);
            tempptr = tempptr->next;
            i++;
        }
        else
        {
            tempptr = tempptr->next;
            ptr = ptr->next;
            total_distance++;
            i++;
        }
    }
    tempptr = head;
    ptr = head;
}

void findOddPath(int visited[], int num)
{
    int i = 0;
    while (i < num)
    {
        if (i == num - 1) // breaking the loop when the last station is reached.
            break;
        else
        {
            for (int j = 0; j < 3; j++) // pair of stations and the total number of times each station has been visited.
            {
                // If the station number is equal to the station number of the station that is being considered,
                // then the distance is incremented by 1.
                // If the station number is not equal to the station number of the station that is being considered,
                // then the distance is not incremented and the pointer is set to the station that is being considered.
                // total number of times the first station of the pair is increased by one
                if (i == 0)
                {
                    if (ptr->station_no != tempptr->station_no)
                    {
                        ptr = tempptr; // returning back to the first station of the pair taken into consideration
                        total_distance++;
                        continue;
                    }
                    visited[i]++;
                    ptr = tempptr->next;
                    total_distance++;
                    // total number of times the second station of the pair is increased by one
                    visited[i + 1]++;
                }
                else
                {
                    if (ptr->station_no != tempptr->station_no)
                    {
                        visited[i]++;
                        ptr = tempptr; // returning back to the first station of the pair taken into consideration
                        total_distance++;
                        continue;
                    }
                    ptr = tempptr->next;
                    total_distance++;
                    // total number of times the second station of the pair is increased by one
                    visited[i + 1]++;
                }
            }
            output(visited, num);
            tempptr = tempptr->next;
            i++;
        }
    }
    tempptr = head;
    ptr = head;
}

void printhighway()
{
    // print till the last station except the last station
    while (tempptr->next != NULL)
    {
        cout << tempptr->station_no << "<----->";
        tempptr = tempptr->next;
    }
    cout << tempptr->station_no << endl;

    cout << endl;
    tempptr = head;
}
int main()
{
    int num;
    cout << "Please enter the total number gas station you want to inspect\n";
    cin >> num;
    int visited[num]; // to keep track whether the first and the last node is visited 2 times and all the others inbetween are visited the same amount
    for (int i = 0; i < num; i++)
    {
        visited[i] = 0;
    }
    createhighway(num); 
    printhighway();

    clock_t start = clock();

    if (num % 2 != 0)
    {
        // find time complexity of this function
        findOddPath(visited, num);
    }

    else
    {
        findEvenPath(visited, num);
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "Hence after satisfying the said conditions, the shortest distance that should be travelled is: " << total_distance << "x , where x implies the distance between each gas station which is of same length" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << visited[i] << "   ";
    }
    cout << endl;
    // printf("Time taken to execute the program is %f seconds", time_taken);
}
