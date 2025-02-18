#include <stdio.h>
#include <stdlib.h>
#define PAGINAS 100000
typedef struct PageFrame{
    int page_number;
} PageFrame;
void LRU(PageFrame *frames, int num_frames, int P){
    int i;
    for (i = 0; i < num_frames; i++){
        if (frames[i].page_number == P) break;}
    for (int j = i; j < num_frames - 1; j++){
        frames[j] = frames[j + 1];}
    frames[num_frames - 1].page_number = P;}
int main(){
    int Q, N, P, page_faults = 0, count = 0; PageFrame frames[PAGINAS];
    scanf("%d %d", &Q, &N);
    scanf("%d", &P);
    frames[count++].page_number = P;
    page_faults++;
    N--;
    while (N--){
        scanf("%d", &P);
        int found = 0;
        for (int i = 0; i < count; i++){
            if (frames[i].page_number == P){
                found = 1;
                LRU(frames, count, P);
                break;}}
        if (!found){
            if (count < Q){
                frames[count++].page_number = P;
            } else{
                for (int i = 0; i < count - 1; i++){
                    frames[i] = frames[i + 1];}
                frames[count - 1].page_number = P;}
            page_faults++;}}
    printf("%d\n", page_faults);
    return 0;}