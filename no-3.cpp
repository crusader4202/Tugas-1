#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int no;
    data *next;
}*head1 = NULL, *tail1 = NULL;

data *insert(int no){
    data *temp = (data*)malloc(sizeof(data));
    temp->no = no;
    temp->next = NULL;
    return temp;
}

void cari(){
    data *temp=head1;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    count/=2;
    data *t=head1;
    for(int i=0;i<=count;i++){
        if(i==count){
            printf("%d",t->no);
        }
        t=t->next;
    }
}

void pushTail1(int no){
    data *temp = insert(no);
    if(!head1) head1 = tail1 = insert(no);
    else{
        tail1->next = temp;
        tail1 = temp;
    }
}

int main(){
    pushTail1(1);
    pushTail1(2);
    pushTail1(3);
    pushTail1(4);
    pushTail1(5);
    pushTail1(6);
    pushTail1(7);
    cari();
}