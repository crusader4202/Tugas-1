#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min,max=0;
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

void pushTail1(int no){
    data *temp = insert(no);
    if(!head1) head1 = tail1 = insert(no);
    else{
        tail1->next = temp;
        tail1 = temp;
    }
}

void cari(){
    data *temp = head1;
    min=temp->no;
	while(temp){
		if(max<temp->no){
            max=temp->no;
        }
        if(min>temp->no){
            min=temp->no;
        }
		temp = temp->next;
	}
}

int main(){
    pushTail1(1);
    pushTail1(3);
    pushTail1(4);
    pushTail1(6);
    pushTail1(1);
    cari();
    printf("%d",max-min);
    return 0;
}