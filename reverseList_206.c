#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
typedef struct node
{
	struct node *next;
	int value;
}node;
*/

 struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode *creatnext(int n)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = rand()%100;
	head->next = NULL;

	struct ListNode *last = head;

	while(--n)
	{
		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->val = rand()%100;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return head;
}

struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *current = head;
	struct ListNode *pre = NULL;
	struct ListNode *next = NULL;
	while(current)
	{
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	return pre;
}

void printnode(struct ListNode *head)
{
	struct ListNode *p = head;
	while(p->next != NULL)
	{
		printf("%d\n",p->val);
		p = p->next;
	}
	printf("%d\n",p->val);
}

int main(int argc, char const *argv[])
{
	int lenth = 0;
	int findval = 0;
	struct ListNode *p = NULL;
	p = creatnext(4);
	//p = creathead(6);
	printnode(p);
	p = reverseList(p);

	printnode(p);

	return 0;
}