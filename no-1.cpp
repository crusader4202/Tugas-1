#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int no;
    data *next;
}*head1 = NULL, *tail1 = NULL,*head2 = NULL, *tail2 = NULL;;

data *insert1(int no){
    data *temp = (data*)malloc(sizeof(data));
    temp->no = no;
    temp->next = NULL;
    return temp;
}

data *insert2(int no){
    data *temp = (data*)malloc(sizeof(data));
    temp->no = no;
    temp->next = NULL;
    return temp;
}

void pushTail1(int no){
    data *temp = insert1(no);
    if(!head1) head1 = tail1 = insert1(no);
    else{
        tail1->next = temp;
        tail1 = temp;
    }
}

void pushTail2(int no){
    data *temp = insert2(no);
    if(!head2) head2 = tail2 = insert2(no);
    else{
        tail2->next = temp;
        tail2 = temp;
    }
}

void printAll(){
	data *temp = head1;
	while(temp){
		printf("%d\n",temp->no);
		temp = temp->next;
	}
}

void pushTailAll(){
    data* curr = head1; 
    while(curr){  
        curr = curr->next; 
    }
}

int main(){
    int m,n;
    printf("masukkan banyak data linked list pertama: ");
    scanf("%d",&m);
    for(int i=0,idx=1;i<m;i++){
        int a;
        printf("masukkan no ke %d: ",idx);
        scanf("%d",&a);
        pushTail1(a);
        idx++;
    }
    printf("masukkan banyak data linked list kedua: ");
    scanf("%d",&n);
    for(int i=0,idx=1;i<n;i++){
        int a;
        printf("masukkan no ke %d: ",idx);
        scanf("%d",&a);
        pushTail2(a);
        idx++;
    }
    data *temp1 = tail1;
    data *temp2 = head2;
    int a=temp1->no;
    int b=temp2->no;
    if(a<b){
        pushTailAll();
    }
    printAll();
    return 0;
}