#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int no;
    data *next;
}*head = NULL, *tail = NULL;

int count=1;
data *insert(int no){
	count++;
    data *temp = (data*)malloc(sizeof(data));
    temp->no = no;
    temp->next = NULL;
    return temp;
}

void pushTail1(int no){
    data *temp = insert(no);
    if(!head) head = tail = insert(no);
    else{
        tail->next = temp;
        tail = temp;
    }
}

void popHead(){
	if(!head){
		printf("NO DATA\n");
		return;
	}
	else if(head == tail){
		data *temp;
		temp = head;
		head = tail = NULL;
		free(temp);
	}
	else{
		data *temp;
		temp = head;
		head = head->next;
		temp->next = NULL;
		free(temp);
	}
}

void popTail(){
	if(!head){
		printf("NO DATA\n");
		return;
	}
	else if(head == tail){
		data *temp;
		temp = head;
		head = tail = NULL;
		free(temp);
	}
	else{
		data *temp;
		temp = tail;
		
		data *target = head;
		while(target->next != tail){
			target = target->next;
		}
		tail = target;
		target->next = NULL;
		temp->next = NULL;
		free(temp);
	}
}

void popSearch(int no){
	for(int i=0;i<3;i++){
	if(!head)popHead();
	else if(head->no == no)popHead();
	else if(tail->no == no)popTail();
	else{
		data *target, *prevTarget;
		target = head;
		while(target){
			prevTarget = target;
			if(no==target->no){
				prevTarget->next = target->next;
				target->next = NULL;
				free(target);
			}
			target = target->next;
		}
	}
	}
}

void printAll(){
	data *temp = head;
	while(temp){
		printf("%d\n",temp->no);
		temp = temp->next;
	}
}

int main(){
    pushTail1(1);
    pushTail1(1);
    pushTail1(1);
    pushTail1(2);
    pushTail1(2);
	data *temp=head;
	while(temp){
		popSearch(temp->no);
		temp=temp->next;
	}
	printAll();
}